class Graph :
    def __init__(self, gdict=None) :  
        if gdict is None :
            gdict = {}
        self.gdict = gdict

    def BFS(self, start, end) :
        queue = []
        queue.append([start])
        while queue :
            path = queue.pop(0)
            node = path[-1]
            if node == end :
                return path
            for adjacent in self.gdict.get(node, []) :
                # get(node, []) --> A value to return if the specified key does not exist
                new_path = list(path)
                new_path.append(adjacent)
                queue.append(new_path)


customDict = {
    "A": ["B", "C"],
    "B": ["D", "G"],
    "C": ["D", "E"],
    "D": ["F"],
    "E": ["F"],
    "G": ["F"]
}

graph = Graph(customDict)
print(graph.BFS("A", "F"))


# queue = [["A"]]
# path = ['A']       node = 'A'
# queue = [['A', 'B'], ['A', 'C']]


# queue = [['A', 'B'], ['A', 'C']]
# path = ["A", "B"]       node = "B"
# queue = [['A', 'C'], ['A', 'B', 'D'], ['A', 'B', 'G']]


# queue = [['A', 'C'], ['A', 'B', 'D'], ['A', 'B', 'G']]
# path = ['A', 'C']       node = "C"
# queue = [['A', 'B', 'D'], ['A', 'B', 'G'], ['A', 'C', 'D'], ['A', 'C', 'E']]


# queue = [['A', 'B', 'D'], ['A', 'B', 'G'], ['A', 'C', 'D'], ['A', 'C', 'E']]
# path = ['A', 'B', 'D']       node = "D"
# queue = [['A', 'B', 'G'], ['A', 'C', 'D'], ['A', 'C', 'E'], ['A', 'B', 'D', 'F']]


# queue = [['A', 'B', 'G'], ['A', 'C', 'D'], ['A', 'C', 'E'], ['A', 'B', 'D', 'F']]
# path = [['A', 'B', 'G']]       node = "G"
# queue = [['A', 'C', 'D'], ['A', 'C', 'E'], ['A', 'B', 'D', 'F'], ['A', 'B', 'G', 'F']]


# queue = [['A', 'C', 'D'], ['A', 'C', 'E'], ['A', 'B', 'D', 'F'], ['A', 'B', 'G', 'F']]
# path = ['A', 'C', 'D']       node = "D"
# queue = [['A', 'C', 'E'], ['A', 'B', 'D', 'F'], ['A', 'B', 'G', 'F'], ['A', 'C', 'D', 'F']]


# queue = [['A', 'C', 'E'], ['A', 'B', 'D', 'F'], ['A', 'B', 'G', 'F'], ['A', 'C', 'D', 'F']]
# path = ['A', 'C', 'E']       node = "E"
# queue = [['A', 'B', 'D', 'F'], ['A', 'B', 'G', 'F'], ['A', 'C', 'D', 'F'], ['A', 'C', 'E', 'F']]


# queue = [['A', 'B', 'D', 'F'], ['A', 'B', 'G', 'F'], ['A', 'C', 'D', 'F'], ['A', 'C', 'E', 'F']]
# path = ['A', 'B', 'D', 'F']       node = "F"
# node == end => True 라서
# path = ['A', 'B', 'D', 'F']를 리턴해줌