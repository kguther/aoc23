from functools import reduce
from operator import mul

from race import Race


def parse_line(line):
    values_string = line.split(":")[1].strip()
    return [int(value) for value in values_string.split(" ") if value != ""]


def parse_input(filename):
    with open(filename) as ifile:
        times_line = ifile.readline()
        records_line = ifile.readline()
        times = parse_line(times_line)
        records = parse_line(records_line)
        return [Race(value[0], value[1]) for value in zip(times, records)]

def parse_line_second_part(line):
    value = line.split(":")[1].strip()
    return int("".join(value.split(" ")))

def parse_input_second_part(filename):
    with open(filename) as ifile:
        times_line = ifile.readline()
        records_line = ifile.readline()
        time = parse_line_second_part(times_line)
        record = parse_line_second_part(records_line)
        return Race(time, record)

def main():
    races = parse_input("input")
    ways = reduce(mul, [race.get_factor() for race in races], 1)
    print(ways)
    second_race = parse_input_second_part("input")
    print(second_race.get_factor())

if __name__ == '__main__':
    main()


