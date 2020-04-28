from cs50 import get_string
import sys


def main():
    # check command line argument
    if(len(sys.argv) != 2):
        print("error")
        sys.exit(1)
    # storage for cipher key in chars
    keystr = sys.argv[1]
    # storage for cypher in numbers
    key = []
    n = len(keystr)
    # check keys char to build cipher numbers
    for c in keystr:
        if c.islower():
            key.append((ord(c) - ord('a')) % 26)

        else:
            key.append((ord(c) - ord('A')) % 26)
        # exit if key not a word
        if not c.isalpha():
            print("error")
            sys.exit(1)
    # temp storage for result
    ciphered = ""
    # help variables
    j, temp = 0, 0
    # get text
    plainText = get_string("plaintext:  ")
    # change each char in plain text
    for c in plainText:
        if c.isalpha():
            if c.islower():
                temp = ord(c) - ord('a')
                temp += key[j]
                j = (j + 1) % n
                temp %= 26
                c = chr(temp + ord('a'))

            else:
                temp = ord(c) - ord('A')
                temp += key[j]
                j = (j + 1) % n
                temp %= 26
                c = chr(temp + ord('A'))
        ciphered += c

    print(f"ciphertext: {ciphered}")


if __name__ == "__main__":
    main()