import numpy


class Sequence:
    def __init__(self, line):
        self._values = [int(value) for value in line.strip().split(" ")]

    def extrapolate(self):
        value_lists = []
        current_values = self._values
        while not all(value == 0 for value in current_values):
            value_lists.append(current_values)
            current_values = list(numpy.diff(current_values))
        value_lists.append(current_values)
        value_lists.reverse()
        for i in range(1, len(value_lists)):
            value_lists[i].append(value_lists[i][0] - value_lists[i-1][-1])
        return self._values[-1]



