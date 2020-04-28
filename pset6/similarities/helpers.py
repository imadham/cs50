from enum import Enum


class Operation(Enum):
    """Operations"""

    DELETED = 1
    INSERTED = 2
    SUBSTITUTED = 3

    def __str__(self):
        return str(self.name.lower())


def distances(a, b):
    """Calculate edit distance from a to b"""

    # TODO
    sublist = []
    # define matrix (list of lists) in which each element is a list
    listoflists = [sublist] * (len(a) + 1)
    for i in range(0, len(a) + 1):
        listoflists[i] = [sublist] * (len(b) + 1)
    # initialize matrix
    for i in range(0, len(b) + 1):
        sublist = []
        sublist.append(i)
        sublist.append(Operation.INSERTED)
        # print(i)
        listoflists[0][i] = sublist
    for i in range(0, len(a) + 1):
        sublist = []
        sublist.append(i)
        sublist.append(Operation.DELETED)
        # print(i)
        listoflists[i][0] = sublist
    # first element should be empty
    sublist = []
    sublist.append(0)
    sublist.append('')  # Operation.DELETED)
    listoflists[0][0] = sublist

    # for i in range(0, len(a) + 1):
    #     print(listoflists[i])

    for i in range(1, len(a) + 1):
        for j in range(1, len(b) + 1):
            # method to calculate each cell
            sublist = mi(listoflists, i, j, a, b)
            listoflists[i][j] = sublist

    # for i in range(0, len(a)+1):
    #     print(listoflists[i])

    return listoflists


def mi(x, i, j, a, b):
    u = 0
    l = 0
    d = 0

    # get values for up(u) left(l) diaginal(d) for the cell
    u = x[i - 1][j][0]

    l = x[i][j - 1][0]

    d = x[i - 1][j - 1][0]

    # if the chars are not same increase diagonal by 1
    if a[i - 1:i] != b[j - 1:j]:
        d += 1
    # increase each up and left with 1
    u += 1
    l += 1

    # print(x[i-1] [j])
    # print(x[i] [j - 1])
    # print(x[i-1] [j - 1])

    # print(f"{i} {j}")
    # calculate minimum
    m = min(u, l, d)

    # print(m)
    # return which cell have minimum
    if m == u:
        return [u, Operation.DELETED]
    if m == l:
        return [l, Operation.INSERTED]
    if m == d:
        return [d, Operation.SUBSTITUTED]
