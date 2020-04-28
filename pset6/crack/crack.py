from cs50 import get_string
import sys
import crypt


def main():
    # check command line argument
    if(len(sys.argv) != 2):
        print("error")
        sys.exit(1)
    # get the hash
    hasha = sys.argv[1]
    # get salt
    salt = hasha[:2]
    # temp var
    generate = "abcde"
    list1 = list(generate)
    list1[0] = 'A'
    # try each word starting from A to ZZZZZ
    while list1[0] <= 'z':
        password = ""
        if list1[0].isalpha():
            # add list1 elements to password
            password = ''.join(list1)
            if hasha == crypt.crypt(password[:1], salt):
                # print result
                print(password[:1])
                # exit with sucsess
                sys.exit(0)
            list1[1] = 'A'
            while list1[1] <= 'z':
                if list1[1].isalpha():
                    password = ''.join(list1)
                    if hasha == crypt.crypt(password[:2], salt):
                        print(password[:2])
                        sys.exit(0)
                    list1[2] = 'A'
                    while list1[2] <= 'z':
                        if list1[2].isalpha():
                            password = ''.join(list1)
                            if hasha == crypt.crypt(password[:3], salt):
                                print(password[:3])
                                sys.exit(0)

                            list1[3] = 'A'
                            while list1[3] <= 'z':
                                if list1[3].isalpha():
                                    password = ''.join(list1)
                                    if hasha == crypt.crypt(password[:4], salt):
                                        print(password[:4])
                                        sys.exit(0)
                                    list1[4] = 'A'
                                    while list1[4] <= 'z':
                                        if list1[4].isalpha():
                                            password = ''.join(list1)
                                            if hasha == crypt.crypt(password[:5], salt):
                                                print(password[:5])
                                                sys.exit(0)
                                        list1[4] = chr(ord(list1[4]) + 1)
                                list1[3] = chr(ord(list1[3]) + 1)
                        list1[2] = chr(ord(list1[2]) + 1)
                list1[1] = chr(ord(list1[1]) + 1)
        list1[0] = chr(ord(list1[0]) + 1)


if __name__ == "__main__":
    main()