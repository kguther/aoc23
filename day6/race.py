class Race:
    def __init__(self, time, record):
        self._time = time
        self._record = record

    def get_factor(self):
        return len(self.get_winning_charges())

    def get_winning_charges(self):
        return [charge for charge in range(self._time) if self._distance(charge) > self._record]

    def _distance(self, charge):
        return charge * (self._time - charge)