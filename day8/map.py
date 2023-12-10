class Map:
    def __init__(self, node_lines):
        self._nodes = {}
        for node_line in node_lines:
            components = node_line.split("=")
            source = components[0].strip()
            target_components = components[1].strip("\n").split(",")
            targets = [target.strip("( )") for target in target_components]
            self._nodes[source] = targets

    def move(self, node, instruction):
        target = self._nodes[node]
        if instruction == "L":
            return target[0]
        return target[1]

    def get_start_nodes(self):
        return [
            node for node in self._nodes.keys() if node[-1] == "A"
        ]

    def get_target_nodes(self):
        return [
            node for node in self._nodes.keys() if node[-1] == "Z"
        ]
