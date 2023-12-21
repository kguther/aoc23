from beam import Beam, RIGHT_DIRECTION, DOWN_DIRECTION, UP_DIRECTION, LEFT_DIRECTION
from grid import Grid
from point import Point


def read_grid(filename):
    with open(filename) as ifile:
        return Grid([line.strip() for line in ifile.readlines()])

def get_beam_energy(grid, start_beam):
    beams = [start_beam]
    grid.reset()
    while beams:
        new_beams = []
        for beam in beams:
            new_beams += beam.propagate(grid)
        beams = new_beams

    return grid.energy() - 1

def main():
    grid = read_grid("input")
    max_energy = 0
    grid_size = grid.size()
    for x in range(grid_size[0]):
        start_beam = Beam(Point(x, -1), DOWN_DIRECTION)
        energy = get_beam_energy(grid, start_beam)
        if energy > max_energy:
            max_energy = energy
        start_beam = Beam(Point(x, grid_size[1]), UP_DIRECTION)
        energy = get_beam_energy(grid, start_beam)
        if energy > max_energy:
            max_energy = energy
    for y in range(grid_size[1]):
        start_beam = Beam(Point(-1, y), RIGHT_DIRECTION)
        energy = get_beam_energy(grid, start_beam)
        if energy > max_energy:
            max_energy = energy
        start_beam = Beam(Point(grid_size[0], y), LEFT_DIRECTION)
        energy = get_beam_energy(grid, start_beam)
        if energy > max_energy:
            max_energy = energy

    print(max_energy)


if __name__ == '__main__':
    main()
