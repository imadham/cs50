from nltk.tokenize import sent_tokenize


def lines(a, b):
    """Return lines in both a and b"""
    # split by lines
    first = set(a.splitlines())
    second = set(b.splitlines())
    # compare 2 sets then convert to list
    list1 = list(first & second)

    # TODO
    return list1


def sentences(a, b):
    """Return sentences in both a and b"""

    # TODO
    # library to tace sentences
    first = set(sent_tokenize(a))
    second = set(sent_tokenize(b))
    list1 = list(first & second)
    return list1


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    # TODO
    list1 = list()
    list2 = list()
    j = n
    d = ""
    for i in range(len(a)):
        d = a[i:j]
        # to only take words with length n
        if len(d) == n:
            list1.append(d)
        # if a[i:j] == '.\n"It':
        j += 1
    set1 = set(list1)
    j = n
    for i in range(len(b)):
        d = b[i:j]
        if len(d) == n:
            list2.append(d)
        #  a[i:j] == '.\n"It':
        j += 1
    set2 = set(list2)
    set1 = set1.intersection(list2)

    list3 = list(set1)
    return list3
