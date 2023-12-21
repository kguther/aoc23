from point import Point

LEFT_DIRECTION = Point(-1, 0)
RIGHT_DIRECTION = Point(1, 0)
UP_DIRECTION = Point(0, -1)
DOWN_DIRECTION = Point(0, 1)

SLASH_MIRROR = {
    LEFT_DIRECTION: DOWN_DIRECTION,
    RIGHT_DIRECTION: UP_DIRECTION,
    DOWN_DIRECTION: LEFT_DIRECTION,
    UP_DIRECTION: RIGHT_DIRECTION,
}

BACKSLASH_MIRROR = {
    LEFT_DIRECTION: UP_DIRECTION,
    RIGHT_DIRECTION: DOWN_DIRECTION,
    DOWN_DIRECTION: RIGHT_DIRECTION,
    UP_DIRECTION: LEFT_DIRECTION,
}

class Beam:
    def __init__(self, position, direction):
        self._position = position
        self._direction = direction

    def propagate(self, grid):
        if grid.marked(self._position, self._direction):
            return []
        new_position = self._position + self._direction
        new_beams = []
        grid.mark(self._position, self._direction)
        if grid.contains(new_position):
            space = grid.get(new_position)
            new_directions = self._get_new_directions(space)

            for new_direction in new_directions:
                new_beams.append(Beam(new_position, new_direction))
        return new_beams

    def _get_new_directions(self, space):
        if space == '|':
            if self._direction in {LEFT_DIRECTION, RIGHT_DIRECTION}:
                new_directions = [UP_DIRECTION, DOWN_DIRECTION]
            else:
                new_directions = [self._direction]
        elif space == "-":
            if self._direction in {UP_DIRECTION, DOWN_DIRECTION}:
                new_directions = [RIGHT_DIRECTION, LEFT_DIRECTION]
            else:
                new_directions = [self._direction]
        elif space == '\\':
            new_directions = [BACKSLASH_MIRROR[self._direction]]
        elif space == '/':
            new_directions = [SLASH_MIRROR[self._direction]]
        else:
            new_directions = [self._direction]
        return new_directions
