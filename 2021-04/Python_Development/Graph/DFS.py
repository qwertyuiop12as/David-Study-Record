class Graph:
    def __init__(self, gdict=None):
        if gdict is None :
            gdict = {}
        self.gdict = gdict

    def addEdge(self, vertex, edge) :
        self.gdict[vertex].append(edge.upper())

    def __str__(self) :
        print(self.gdict)
        return ""

    def DFS(self, vertex) :
        visited = [vertex]
        stack = [vertex]
        while stack :
            popVertex = stack.pop()
            print(popVertex)
            for adjacentVertex in self.gdict[popVertex] :
                if adjacentVertex not in visited :
                    visited.append(adjacentVertex)
                    stack.append(adjacentVertex)

customDict = {
    "A": ["B", "C", "D"],
    "B": ["A", "D", "E"],
    "C": ["A", "D"],
    "D": ["A", "B", "C", "E"],
    "E": ["B", "D"]
}

# Print A B C D E

# Qu A
# Vi A



graph = Graph(customDict)

graph.DFS("A")