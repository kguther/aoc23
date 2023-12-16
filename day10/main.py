from grid import Grid


def parse_input(filename):
    with open(filename) as ifile:
        pipes = [line.strip() for line in ifile.readlines()]
        return Grid(pipes)


def main():
    grid = parse_input("input")
    max_dist = grid.traverse()
    print(max_dist)
    area = grid.get_area()
    print(area)


if __name__ == '__main__':
    main()

