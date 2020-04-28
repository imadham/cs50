from cs50 import get_int
import math


def main():
    # prompt for input
    while True:
        card = get_int("Number: ")
        if card > 0:
            break

    # help vaiables
    counter, numbers, help1, befor_last, last = 0, 0, 0, 0, 0
    temp = card
    # to change once multuply and once not
    x = False
    # do throught each number
    while temp > 0:
        numbers += 1
        if temp < 100 and temp > 9:
            befor_last = temp % 10

        elif temp < 10 and temp >= 0:
            last = temp
        # divide to go to the second number
        help1 = temp % 10
        temp = math.trunc(temp / 10)
        if x:
            help1 *= 2
            if help1 > 9:
                help1 -= 9

            counter += help1

        else:
            counter += help1

        x = not x
    # if the card is real find which company
    if counter % 10 == 0:
        if numbers == 15 and last == 3 and (befor_last == 4 or befor_last == 7):
            print("AMEX")

        elif (numbers == 16 or numbers == 13) and last == 4:
            print("VISA")

        elif numbers == 16 and last == 5 and (befor_last == 1 or befor_last == 2 or befor_last == 3 or befor_last == 4 or befor_last == 5):
            print("MASTERCARD")

        else:
            print("INVALID")

    else:
        print("INVALID")


if __name__ == "__main__":
    main()