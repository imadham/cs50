from cs50 import get_float


def main():
    # prompt user for right input
    while True:
        money = get_float("Change owed: ")
        if money > 0:
            break
    # convert to cents
    cents = round(money * 100)
    counter = 0
    # remove bigger first
    while cents > 0:
        if cents >= 25:
            counter += 1
            cents -= 25

        elif cents >= 10:
            counter += 1
            cents -= 10

        elif cents >= 5:
            counter += 1
            cents -= 5

        else:
            counter += 1
            cents -= 1
    # print result
    print(f"{counter}")


if __name__ == "__main__":
    main()