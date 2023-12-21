from pattern import Pattern


def read_patterns(filename):
    patterns = []
    with open(filename) as ifile:
        pattern_lines = []
        for line in ifile.readlines():
            if len(line.strip()) == 0:
                patterns.append(Pattern(pattern_lines))
                pattern_lines = []
            else:
                pattern_lines.append([char for char in line.strip()])
    patterns.append(Pattern(pattern_lines))
    return patterns

def main():
    patterns = read_patterns("input")
    print(sum(pattern.get_reflection() for pattern in patterns))
    print(sum(pattern.get_reflection_with_smudge() for pattern in patterns))


if __name__ == '__main__':
    main()
