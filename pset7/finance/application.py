import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Ensure responses aren't cached


@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    rows = db.execute("select SYMBOL, sum(number) from history where buyer_id=:idd group by SYMBOL", idd=session["user_id"])
    names = []
    summ = 0
    for symbol in rows:
        result = lookup(symbol['symbol'])
        names.append([result['name'], usd(result['price']), usd(result['price'] * symbol['sum(number)'])])
        summ += float(result['price']) * symbol['sum(number)']
    cash = int(db.execute("select cash from users where id=:idd", idd=session["user_id"])[0]['cash'])
    summ += cash
    return render_template("index.html", rows=rows, names=names, cash=usd(cash), summ=usd(summ))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():

    def isint(x):
        try:
            a = float(x)
            b = int(a)
        except ValueError:
            return False
        else:
            return a == b
    """Buy shares of stock"""
    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("Missing symbol", 400)
        result = lookup(request.form.get("symbol"))
        if not result:
            return apology("invalid symbol", 400)
        price = int(result['price'])
        symbol = result['symbol']
        if not isint(request.form.get("shares")):
            return apology("invalid number", 400)
        number = int(request.form.get("shares"))
        if number <= 0:
            return apology("you cannot buy 0 or negative number of shares", 400)

        row = db.execute("select cash from users where id = :idd", idd=session["user_id"])
        cash = int(row[0]["cash"])
        if price * number > cash:
            return apology("you don't have enough money", 400)

        db.execute("create table if not exists 'history' ('date' PRIMARY KEY, price REAL, 'symbol' text, 'number' INTEGER, 'buyer_id' INTEGER FORIGN KEY)")
        db.execute("INSERT INTO 'history' ('date', 'price', 'symbol','number','buyer_id') VALUES (datetime('now'), :price, :symb, :num, :idd)",
                   price=price, symb=symbol, num=number, idd=session["user_id"])
        db.execute("UPDATE users SET cash = :rest where id=:idd", rest=(cash + (price * number * -1)), idd=session["user_id"])
        return redirect("/")
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    rows = []
    temp = db.execute("select symbol, number, price, date from history where buyer_id=:idd", idd=session["user_id"])
    for data in temp:
        rows.append([data['symbol'], data['number'], usd(data['price']), data['date']])
    return render_template("history.html", rows=rows)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("Missing symbol", 400)
        price = lookup(request.form.get("symbol"))
        if not price:
            return apology("invalid symbol", 400)

        toshow = price['name'] + " (" + price['symbol'] + ") costs " + usd(price['price'])
        return render_template("show.html", toshow=toshow)
    else:
        return render_template("quote.html")

# @app.route("/show", methods=["GET", "POST"])
# def show():
#     return return render_template("show.html", price=price)


@app.route("/register", methods=["GET", "POST"])
def register():

    # Forget any user_id
    session.clear()
    if request.method == "POST":
        """Register user"""
        if not request.form.get("username"):
            return apology("must provide username", 400)
        elif not request.form.get("password"):
            return apology("must provide password", 400)
        elif not request.form.get("password") == request.form.get("confirmation"):
            return apology("password and confirmaton should be the same", 400)
        else:
            rows = db.execute("SELECT * FROM users WHERE username = :username", username=request.form.get("username"))
            if len(rows) != 0:
                return apology("user name already taken", 400)

        idd = db.execute("insert into users ('username', 'hash') values (:username, :hash1)",
                         username=request.form.get("username"), hash1=generate_password_hash(request.form.get("password")))
        session["user_id"] = idd
        return render_template("login.html")
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    rows = db.execute("select SYMBOL, sum(number) from history where buyer_id=:idd group by SYMBOL", idd=session["user_id"])
    names = []
    for symbol in rows:
        names.append(symbol['symbol'])

    if request.method == "POST":
        price = lookup(request.form.get("symbol"))['price']
        number = int(request.form.get("shares"))
        if number <= 0:
            return apology("please enter positive number")
        row = db.execute("select sum(number) from history where buyer_id = :idd and symbol=:symb",
                         idd=session["user_id"], symb=request.form.get("symbol"))

        if row[0]['sum(number)'] < number:
            return apology("sorry, you dont have enough shares")
        db.execute("INSERT INTO 'history' ('date', 'price', 'symbol','number','buyer_id') VALUES (datetime('now'), :price, :symb, :num, :idd)",
                   price=price, symb=request.form.get("symbol"), num=(number * -1), idd=session["user_id"])

        row = db.execute("select cash from users where id = :idd", idd=session["user_id"])
        cash = int(row[0]["cash"])

        db.execute("UPDATE users SET cash = :rest where id=:idd", rest=(cash + (price * number)), idd=session["user_id"])
        return redirect("/")

    else:
        return render_template("sell.html", names=names)


@app.route("/changepassword", methods=["GET", "POST"])
@login_required
def changepassword():
    if request.method == "POST":
        old = request.form.get('oldpassword')
        if not old:
            return apology("please enter the old password", 400)
        new = request.form.get('newpassword')
        if not new:
            return apology("please enter new password", 400)
        rows = db.execute("select hash from users where id=:idd", idd=session["user_id"])
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("oldpassword")):
            return apology("you have entered wrong password", 400)
        db.execute("UPDATE users set hash =:hash1 where id=:idd", hash1=generate_password_hash(new), idd=session["user_id"])
        session.clear()
        return render_template("login.html")
    else:
        return render_template("changepassword.html")


def errorhandler(e):
    """Handle error"""
    return apology(e.name, e.code)


# listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
