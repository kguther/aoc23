class Navigation:
    def __init__(self, instructions, map):
        self._instructions = instructions
        self._map = map

    def traverse(self, start, targets):
        node = start
        steps = 0
        while True:
            instruction = self._instructions[steps % len(self._instructions)]
            node = self._map.move(node, instruction)
            steps += 1
            if node in targets:
                break
        return steps

    def get_target_loops(self):
        target_nodes = self._map.get_target_nodes()
        return [
            self.traverse(node, {node}) for node in target_nodes
        ]

    def get_initial_loops(self):
        initial_nodes = self._map.get_start_nodes()
        target_nodes = set(self._map.get_target_nodes())
        return [
            self.traverse(node, target_nodes) for node in initial_nodes
        ]



