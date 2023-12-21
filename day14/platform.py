from enum import Enum


class Direction(Enum):
    NORTH = "NORTH"
    WEST = "WEST"
    SOUTH = "SOUTH"
    EAST = "EAST"


ROUND_ROCK = "O"


class Platform:
    def __init__(self, rock_map):
        self._rock_map = rock_map
        self._iterated = []

    def __repr__(self):
        return "-"*len(self._rock_map) + "\n" + "\n".join("".join(line) for line in self._rock_map)

    def spin(self, number):
        periodicity, offset = self.get_periodicity()
        effective_number = (number - offset) % periodicity
        for _ in range(effective_number):
            self.spin_iteration()

    def get_periodicity(self):
        counter = 0
        while(str(self) not in self._iterated):
            self._iterated.append(str(self))
            counter += 1
            self.spin_iteration()
        offset = self._iterated.index(str(self))
        periodicity = len(self._iterated) - offset
        return periodicity, offset

    def spin_iteration(self):
        self.tilt_direction(Direction.NORTH)
        self.tilt_direction(Direction.WEST)
        self.tilt_direction(Direction.SOUTH)
        self.tilt_direction(Direction.EAST)

    def tilt_direction(self, direction):
        if direction in {Direction.NORTH, Direction.SOUTH}:
            self._tilt_y_direction(direction)
        else:
            self._tilt_x_direction(direction)

    def _tilt_x_direction(self, direction):
        x_coordinates = range(len(self._rock_map[0]))
        if direction == Direction.EAST:
            x_coordinates = x_coordinates[::-1]
        for x in x_coordinates:
            for y in range(len(self._rock_map)):
                if self._rock_map[y][x] == ROUND_ROCK:
                    self._roll_x(x, y, direction)

    def _tilt_y_direction(self, direction):
        y_coordinates = range(len(self._rock_map))
        if direction == Direction.SOUTH:
            y_coordinates = y_coordinates[::-1]
        for y in y_coordinates:
            for x in range(len(self._rock_map[y])):
                if self._rock_map[y][x] == ROUND_ROCK:
                    self._roll_y(x, y, direction)

    def get_load(self):
        total_load = 0
        for i in range(len(self._rock_map)):
            load = len(self._rock_map) - i
            total_load += self._rock_map[i].count(ROUND_ROCK) * load
        return total_load

    def _roll_y(self, x, y, direction):
        y_current = y
        if direction == Direction.NORTH:
            path = range(y - 1, -1, -1)
        else:
            path = range(y + 1, len(self._rock_map))
        for y_new in path:
            if self._rock_map[y_new][x] not in {ROUND_ROCK, "#"}:
                self._rock_map[y_current][x] = "."
                self._rock_map[y_new][x] = ROUND_ROCK
                y_current = y_new
            else:
                return

    def _roll_x(self, x, y, direction):
        x_current = x
        if direction == Direction.WEST:
            path = range(x - 1, -1, -1)
        else:
            path = range(x + 1, len(self._rock_map[y]))
        for x_new in path:
            if self._rock_map[y][x_new] not in {ROUND_ROCK, "#"}:
                self._rock_map[y][x_current] = "."
                self._rock_map[y][x_new] = ROUND_ROCK
                x_current = x_new
            else:
                return

