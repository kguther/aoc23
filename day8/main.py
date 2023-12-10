from math import lcm
from map import Map
from navigation import Navigation


def parse_input(filename):
    with open(filename) as ifile:
        content = ifile.readlines()
    instructions = content[0].strip()
    nodes = content[2:]
    return Navigation(instructions, Map(nodes))


def main():
    navigation = parse_input("input")
    steps = navigation.traverse("AAA", "ZZZ")
    print(steps)
    loop_lenghts = navigation.get_initial_loops()
    print(loop_lenghts)
    # Fortunately, these are the same as the initial loop lengths -> no offset in the lcm
    print(navigation.get_target_loops())
    print(lcm(*loop_lenghts))


if __name__ == '__main__':
    main()


