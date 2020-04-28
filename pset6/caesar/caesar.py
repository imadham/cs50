from cs50 import get_string
import sys


def main():
    if len(sys.argv) != 2:
        print("error")
        sys.exit(1)
    # get key and make it less than 26
    key = int(sys.argv[1]) % 26
    # temp storage
    temp = 0
    # ciphered text
    cipher = ""
    # plain text
    plainText = get_string("plaintext: ")
    for c in plainText:
        if c.isalpha():
            if c.islower():
                temp = ord(c) - ord('a')
                temp += key
                temp %= 26
                c = chr(temp + ord('a'))

            else:
                temp = ord(c) - ord('A')
                temp += key
                temp %= 26
                c = chr(temp + ord('A'))
        cipher += c
    # print ciphered text
    print(f"ciphertext: {cipher}")


if __name__ == "__main__":
    main()
