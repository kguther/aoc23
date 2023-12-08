import string


def read_input(filename):
    with open(filename) as ifile:
        return [line.rstrip() for line in ifile.readlines()]

def check_part_number(schematic, row, start, end):
    for y in {max(row-1, 0), row, min(row+1, len(schematic)-1)}:
        for x in set(range(start-1, end+2)) & set(range(len(schematic[y]))):
            if schematic[y][x] not in set(string.digits) | {"."}:
                return True
    return False

def check_gear(schematic, x, y):
    if schematic[y][x] != "*":
        return 0
    number_count = 0
    gear_ratio = 1
    for i in {max(y-1,0), y, min(y+1, len(schematic)-1)}:
        for j in {max(x-1,0), x, min(x+1, len(schematic[y])-1)}:
            if schematic[i][j] in string.digits:
                if j > max(x-1, 0) and schematic[i][j-1] in string.digits:
                    continue
                number_count += 1
                number_start = j
                number_end = j
                for k in range(j, -1, -1):
                    if schematic[i][k] in string.digits:
                        number_start = k
                    else:
                        break
                for k in range(j, len(schematic[i])):
                    if schematic[i][k] in string.digits:
                        number_end = k
                    else:
                        break

                part_number = int(schematic[i][number_start:number_end+1])
                gear_ratio *= part_number
    if number_count == 2:
        return gear_ratio
    return 0


def get_gear_ratios(schematic):
    gear_ratios = 0
    for i in range(len(schematic)):
        for j in range(len(schematic[i])):
            gear_ratios += check_gear(schematic, i, j)
    return gear_ratios

def get_part_numbers(schematic):
    total = 0
    for i in range(len(schematic)):
        number_end = -1
        for j in range(len(schematic[i])):
            if schematic[i][j] in string.digits and j > number_end:
                number_start = j
                number_end = j
                for k in range(j, len(schematic[i])):
                    if schematic[i][k] in string.digits:
                        number_end = k
                    else:
                        break
                is_part_number = check_part_number(schematic, i, number_start, number_end)
                if is_part_number:
                    total += int(schematic[i][number_start:number_end+1])
    return total

def main():
    schematic = read_input("input")
    print(get_part_numbers(schematic))
    print(get_gear_ratios(schematic))


if __name__ == "__main__":
    main()
