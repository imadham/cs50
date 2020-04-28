from cs50 import get_int


def main():
    # prompt user for right input
    while True:
        height = get_int("Height: ")
        if height >= 0 and height <= 23:
            break
    n = height - 1
    r = 1
    # iterate row by row
    for i in range(height):
        # itereate column by column
        for j in range(2 * height + 2):
            if (j > n - 1 and j <= height - 1) or (j > height + 1) and (j < 2 * height + 2 - n):
                print("#", end ="")

            elif j < height + 2:
                print(" ", end="")
        n -= 1
        print()
        r += 1


if __name__ == "__main__":
    main()