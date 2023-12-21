class Grid:
    def __init__(self, grid_lines):
        self._grid = grid_lines
        self._marked = set()

    def reset(self):
        self._marked = set()

    def size(self):
        return len(self._grid[0]), len(self._grid)

    def get(self, point):
        return self._grid[point.y][point.x]

    def contains(self, point):
        return point.x >= 0 and point.y >= 0 and point.x < len(self._grid[0]) and point.y < len(self._grid)

    def mark(self, point, direction):
        self._marked.add((point, direction))

    def marked(self, point, direction):
        return (point, direction) in self._marked

    def energy(self):
        return len({element[0] for element in self._marked})
