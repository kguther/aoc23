from dataclasses import dataclass


@dataclass(frozen=True)
class Draw:
    red: int = 0
    green: int = 0
    blue: int = 0

    def __le__(self, other):
        red = self.red <= other.red
        blue = self.blue <= other.blue
        green = self.green <= other.green
        return red & blue & green

    def fuse(self, other):
        return Draw(
            red=max(self.red, other.red),
            green=max(self.green, other.green),
            blue=max(self.blue, other.blue)
        )

    @property
    def power(self):
        return self.red * self.green * self.blue


POOL = Draw(red=12, blue=14, green=13)


class Game:
    def __init__(self, line):
        info = line.split(":")
        self.id = int(info[0].split(" ")[-1])
        draw_strings = info[1].split(";")
        self.draws = [self._parse_draw(draw_string) for draw_string in draw_strings]

    def __repr__(self):
        return str(self.id) + str(self.draws)

    def possible(self):
        return all(draw <= POOL for draw in self.draws)

    def fuse(self):
        min_draw = self.draws[0]
        for draw in self.draws:
            min_draw = min_draw.fuse(draw)
        return min_draw

    def get_power(self):
        return self.fuse().power

    def _parse_draw(self, draw):
        colors = [color.strip() for color in draw.split(",")]
        draw_args = {color.split(" ")[1]: int(color.split(" ")[0]) for color in colors}
        return Draw(**draw_args)
