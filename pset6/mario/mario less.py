from cs50 import get_int


def main():
    # prompt user for right input
    while True:
        height = get_int("Height: ")
        if height >= 0 and height <= 23:
            break
    n = height - 1
    # iterate row by row
    for i in range(0, height):
        # itereate column by column
        for j in range(height + 1):
            if j < n:
                print(" ", end='')
            else:
                print('#',end='')
        n -= 1
        print()




if __name__ == "__main__":
    main()