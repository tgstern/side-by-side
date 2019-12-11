from cs50 import get_string
from sys import argv


def main():
    # check correct argument usages
    if len(argv) != 2:
        sys.exit("Usage error: incorrect number of arguments")

    for c in argv[1]:
        if not c.isalpha():
            sys.exit("Usage error: key must contain only letters")

    # save the user's key
    inkey = argv[1]
    key = inkey.lower()
    keylen = len(key)

    # get user input string
    plain = get_string("Plaintext: ")

    cipher = []

    # shift text per character
    cycle = 0
    for c in plain:
        if c.isalpha():
            if c.islower():
                shift = ord(key[cycle % keylen]) - 97
                cipher.append(chr(97 + (ord(c) - 97 + shift) % 26))
                cycle += 1
            if c.isupper():
                shift = ord(key[cycle % keylen]) - 97
                cipher.append(chr(65 + (ord(c) - 65 + shift) % 26))
                cycle += 1
        else:
            cipher.append(c)

    # print cipher
    print("ciphertext: " + "".join(cipher))


if __name__ == "__main__":
    main()