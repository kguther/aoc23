from platform import Platform, Direction


def read_input(filename):
    with open(filename) as ifile:
        return Platform([[char for char in line.strip()] for line in ifile.readlines()])

def main():
    platform = read_input("input")
    print(platform.get_periodicity())
    platform.spin(1000000000)
    print(platform.get_load())


if __name__ == '__main__':
    main()


