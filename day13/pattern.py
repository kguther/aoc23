import copy

import numpy

class Pattern:
    def __init__(self, lines):
        self._lines = lines

    def _flip(self, x, y):
        flipped_lines = copy.deepcopy(self._lines)
        flipped_char = self._lines[y][x]
        if flipped_char == '.':
            flipped_lines[y][x] = '#'
        else:
            flipped_lines[y][x] = '.'
        return flipped_lines

    def get_reflection_with_smudge(self):
        parent_reflection = self.get_reflection()
        for y in range(len(self._lines)):
            for x in range(len(self._lines[y])):
                flipped_lines = self._flip(x, y)
                flipped_pattern = Pattern(flipped_lines)
                flipped_reflection = flipped_pattern.get_reflection(parent_reflection)
                if flipped_reflection:
                    return flipped_reflection
        for line in self._lines:
            print("".join(line))
        raise ValueError(f"No flipped reflection for pattern with parent reflection {parent_reflection}")

    def get_reflection(self, parent_reflection=None):
        horizontal_parent_reflection = parent_reflection / 100 if parent_reflection and parent_reflection >= 100 else None
        horizontal_reflection = self._get_horizontal_reflection(horizontal_parent_reflection)
        if horizontal_reflection:
            horizontal_reflection *= 100
        vertical_parent_reflection = parent_reflection if parent_reflection and parent_reflection < 100 else None
        vertical_reflection = self._get_vertical_reflection(vertical_parent_reflection)
        if horizontal_reflection and vertical_reflection:
            raise ValueError
        return horizontal_reflection or vertical_reflection

    def _get_vertical_reflection(self, parent_reflection):
        transposed_lines = numpy.transpose(numpy.array(self._lines))
        transposed_pattern = Pattern(transposed_lines)
        return transposed_pattern._get_horizontal_reflection(parent_reflection)

    def _get_horizontal_reflection(self, parent_reflection):
        n_lines = len(self._lines)
        for i in range(n_lines-1):
            rest = n_lines - i - 1
            window_size = min(i+1, rest)
            first_window = self._lines[i - window_size + 1:i + 1]
            second_window = self._lines[i + 1:i + window_size + 1]
            second_window = second_window[::-1]
            reflection = i + 1
            if numpy.equal(first_window, second_window).all() and not (reflection == parent_reflection):
                return i + 1
        return None
