from sequence import Sequence


def parse_input(filename):
    with open(filename) as ifile:
        return [Sequence(line) for line in ifile.readlines()]


def main():
    sequences = parse_input("input")
    total = sum(sequence.extrapolate() for sequence in sequences)
    print(total)

if __name__ == '__main__':
    main()

