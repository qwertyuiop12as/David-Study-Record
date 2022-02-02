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

    def BFS(self, vertex) :
        visited = [vertex]
        queue = [vertex]
        while queue :
            deVertex = queue.pop(0)
            print(deVertex)
            for adjacentVertex in self.gdict[deVertex] :
                if adjacentVertex not in visited :
                    visited.append(adjacentVertex)
                    queue.append(adjacentVertex)

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


# Qu B C D
# Vi A B C D


# Qu C D E
# Vi A B C D E

# Qu D E
# Vi A B C D E

# Qu E
# Vi A B C D E

# Qu
# Vi A B C D E


graph = Graph(customDict)

graph.BFS("A")