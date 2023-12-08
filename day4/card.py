class Card:
    def __init__(self, line):
        content = line.split(":")
        numbers = content[1].split("|")
        self._id = int(content[0].split(" ")[-1])
        self._own_numbers = set(self._parse_numbers(numbers[0])) - {""}
        self._winning_numbers = set(self._parse_numbers(numbers[1])) - {""}

    def __repr__(self):
        return f"{self._own_numbers}|{self._winning_numbers} - winning {self.score()}"

    @property
    def id(self):
        return self._id

    def _parse_numbers(self, numbers):
        return numbers.strip().split(" ")

    def win_count(self):
        return len(self._winning_numbers & self._own_numbers)

    def win_ids(self):
        win_count = self.win_count()
        return range(self._id + 1, self._id + win_count + 1)

    def score(self):
        win_count = self.win_count()
        if win_count > 0:
            return 2 ** (win_count-1)
        return 0

