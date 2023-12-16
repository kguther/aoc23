from dataclasses import dataclass


@dataclass(frozen=True)
class Coordinates:
    x: int
    y: int

    def west_neighbour(self):
        return Coordinates(self.x-1, self.y)

    def east_neighbour(self):
        return Coordinates(self.x+1, self.y)

    def north_neighbour(self):
        return Coordinates(self.x, self.y-1)

    def south_neighbour(self):
        return Coordinates(self.x, self.y+1)


class Grid:
    def __init__(self, pipes):
        self._pipes = pipes
        self._start_pipe = "S"
        self._extent = (len(pipes), len(pipes[0]))
        self._start_point = Coordinates(0, 0)
        for y in range(self._extent[0]):
            if "S" in self._pipes[y]:
                x = self._pipes[y].find("S")
                self._start_point = Coordinates(x, y)
        self._distances = {self._start_point: 0}
        self._start_pipe = self._fix_start_pipe()

    def get_area(self):
        outside = True
        area = 0
        for y in range(self._extent[0]):
            for x in range(self._extent[1]):
                pos = Coordinates(x, y)
                if pos in self._distances:
                    outside = self._toggle_area(pos) ^ outside
                elif not outside:
                    area += 1
        return area

    def _toggle_area(self, pos: Coordinates):
        if self._pipe(pos) in {"|", "F", "7"}:
            return True
        return False

    def traverse(self):
        pos = self._start_point
        connected = set(self.get_connected(pos))
        distance = 0
        while connected:
            new_connected = []
            distance += 1
            for point in connected:
                self._distances[point] = distance
                new_connected += self.get_connected(point)
            connected = set(new_connected) - set(self._distances.keys())
        return max(self._distances.values())

    def _fix_start_pipe(self):
        start_neighbours = set(self.get_connected(self._start_point))
        start_pipe = "S"
        if start_neighbours == {self._start_point.south_neighbour(), self._start_point.north_neighbour()}:
            start_pipe = "|"
        elif start_neighbours == {self._start_point.east_neighbour(), self._start_point.north_neighbour()}:
            start_pipe = "L"
        elif start_neighbours == {self._start_point.west_neighbour(), self._start_point.east_neighbour()}:
            start_pipe = "-"
        elif start_neighbours == {self._start_point.north_neighbour(), self._start_point.west_neighbour()}:
            start_pipe = "J"
        elif start_neighbours == {self._start_point.east_neighbour(), self._start_point.south_neighbour()}:
            start_pipe = "F"
        elif start_neighbours == {self._start_point.west_neighbour(), self._start_point.south_neighbour()}:
            start_pipe = "7"
        return start_pipe

    def get_connected(self, point: Coordinates):
        connected = []
        if self._pipe(point) in {"S", "-", "7", "J"}:
            point_west = point.west_neighbour()
            if self._on_grid(point_west) and self._pipe(point_west) in {"-", "F", "L"}:
                connected.append(point_west)
        if self._pipe(point) in {"S", "-", "F", "L"}:
            point_east = point.east_neighbour()
            if self._on_grid(point_east) and self._pipe(point_east) in {"-", "7", "J"}:
                connected.append(point_east)
        if self._pipe(point) in {"S", "|", "L", "J"}:
            point_north = point.north_neighbour()
            if self._on_grid(point_north) and self._pipe(point_north) in {"|", "7", "F"}:
                connected.append(point_north)
        if self._pipe(point) in {"S", "|", "F", "7"}:
            point_south = point.south_neighbour()
            if self._on_grid(point_south) and self._pipe(point_south) in {"|", "J", "L"}:
                connected.append(point_south)
        return connected

    def get_distance(self, a: Coordinates):
        if dist := self._distances.get(a):
            return dist

    def _on_grid(self, point: Coordinates):
        return point.x >=0 and point.y >= 0 and point.x < self._extent[1] and point.y < self._extent[0]

    def _pipe(self, point: Coordinates):
        if point == self._start_point:
            return self._start_pipe
        return self._pipes[point.y][point.x]
