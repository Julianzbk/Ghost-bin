#
#   ghost_bin.py
#   Julianzbk
#
LITERAL_SYMBOLS = [' ', ',', '.', '!', '?', '&', '"', ':', '$', '~']

def to_bin(alph_string: str, /, *, encoding="ascii"):
    encoding = encoding.lower()
    bin_string = []
    if encoding == "ascii":
        for char in alph_string:
            if char in LITERAL_SYMBOLS:
                bin_string.append(char)
            else:
                char = bin(ord(char))
                for b in char[2:]:
                    if b == '0':
                        bin_string.append('o')
                    elif b == '1':
                        bin_string.append('O')
                    else:
                        raise SyntaxError
        return ''.join(bin_string)
    elif encoding == "utf-8":
        return NotImplemented
    else:
        raise LookupError(f"unknown encoding: {encoding}")

def to_bin_1line(string: str, /, *, encoding="ascii") -> str:
    """ Cannot raise errors."""
    return ''.join(['o' if b == '0' else 'O' if b == '1' else b for char in
                    [c if c in LITERAL_SYMBOLS else bin(ord(c))[2:] for c in string] for b in char]) \
            if encoding.lower() == "ascii" else \
            NotImplemented \
            if encoding.lower() == "utf-8" else \
            None


def to_alph(bin_string: str, /, *, encoding="ascii"):
    encoding = encoding.lower()
    #bin_string = [c if c in LITERAL_SYMBOLS else c for c in bin_string]
    #bin_string = [bin_string[i] if bin_string[i] in LITERAL_SYMBOLS else bin_string[i:i+7] \
    #              for i in range(0, len(bin_string), 7)]
    alph_string = []
    i = 1
    char = []
    for b in bin_string:
        char.append(b)
        if i % 8 == 0:
            alph_string.append(''.join(char))
            char = []
            i = 1
        if b in LITERAL_SYMBOLS:
            alph_string.append(b)
        i += 1

    return alph_string


def main():
    print("ui")
    print(to_alph(to_bin("waddup, bludwagon?")))

if __name__ == "__main__":
    main()