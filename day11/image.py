import numpy

GALAXY = "#"


class Image:
    def __init__(self, raw_data, expansion_factor=1):
        self._data = numpy.array(raw_data)
        self._empty_rows = self._mark_empty(self._data)
        self._empty_columns = self._mark_empty(numpy.transpose(self._data))
        self._expansion_factor = expansion_factor

    def get_distances(self):
        galaxies = self._get_galaxies()
        distances = []
        for i in range(len(galaxies)):
            for j in range(i):
                distance = self._distance(galaxies[i], galaxies[j])
                distances.append(distance)
        return distances

    def _distance(self, point_a, point_b):
        base_distance = abs(point_a[0]-point_b[0]) + abs(point_a[1] - point_b[1])
        start_y = min(point_a[0], point_b[0])
        end_y = max(point_a[0], point_b[0])
        start_x = min(point_a[1], point_b[1])
        end_x = max(point_a[1], point_b[1])
        empty_rows_traversed = len(set(range(start_y, end_y)) & self._empty_rows)
        empty_columns_traversed = len(set(range(start_x, end_x)) & self._empty_columns)
        return base_distance + self._expansion_factor * (empty_columns_traversed + empty_rows_traversed)

    def _get_galaxies(self):
        return numpy.argwhere(self._data == GALAXY)

    def _mark_empty(self, data):
        empty_rows = []
        for i in range(len(data)):
            if GALAXY not in data[i]:
                empty_rows.append(i)
        return set(empty_rows)
