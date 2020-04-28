
def main():
    a = "imadhamkammmlljlfdimadeee"
    b = "imad\n aa\nbb\n cc\n dd\nee"
    list1 = list()
    for i in range(len(a)):
        x = a[:2]
        c = a[1:]
        a = c
        list1.append(x)

    #second = set(b.splitlines())
    print(set(list1))
    #return [first & second]

def lines(a, b):
    """Return lines in both a and b"""
    first = set(a.splitlines())
    second = set(b.splitlines())


    # TODO
    return [first & second]

if __name__ == "__main__":
    main()