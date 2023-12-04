import string

DIGITS = {"one": "1", "two": "2", "three": "3", "four": "4", "five": "5", "six": "6", "seven": "7", "eight": "8", "nine": "9"}
def read_input(filename):
    with open(filename) as ifile:
        return [line.rstrip() for line in ifile.readlines()]

def convert_strings(line):
    new_line = ''
    pos = 0
    while pos < len(line):
        for name, digit in DIGITS.items():
            if pos < len(line) - len(name) + 1:
                if line[pos:pos+len(name)] == name:
                    pos += 1
                    new_line += digit
                    continue
        new_line += line[pos]
        pos += 1
    return new_line

def get_calibration(line):
    digits = [char for char in line if char in string.digits]
    return int(digits[0] + digits[-1])
def main():
    input = read_input("input")
    calibrations = [get_calibration(convert_strings(line)) for line in input]
    print(sum(calibrations))


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    main()

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
