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

customDict = {
    "A": ["B", "C", "D"],
    "B": ["A", "E"],
    "C": ["A", "D"],
    "D": ["A", "C"],
    "E": ["B", "D"]
}

graph = Graph(customDict)

# 클래스에게 사용하면 자동으로 __str__ 함수로 넘어감
print(graph)

graph.addEdge("D", "E")
print(graph)