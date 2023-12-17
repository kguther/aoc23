from image import Image


def parse_input(filename):
    with open(filename) as ifile:
        expansion_factor = 1000000 - 1
        return Image([[char for char in line.strip()] for line in ifile.readlines()], expansion_factor=expansion_factor)


def main():
    image = parse_input("input")
    distances = image.get_distances()
    print(len(distances))
    print(sum(distances))


if __name__ == '__main__':
    main()
