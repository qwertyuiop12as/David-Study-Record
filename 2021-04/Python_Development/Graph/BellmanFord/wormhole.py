class Graph:
    def __init__(self, vertices):
        self.vertices = vertices
        self.graph = []
        self.nodes = []


    def add_edge(self, source, destination, weight):
        self.graph.append([source, destination, weight])


    def add_node(self, value):
        self.nodes.append(value)

    
    def Track_BellmanFord_Process(self, src) :
        dist = {i: float("Inf") for i in self.nodes}
        dist[src] = 0

        for _ in range(self.vertices - 1):
            for source, destination, weight in self.graph:
                if dist[source] != float("Inf") and dist[source] + weight < dist[destination]:
                    print(source, destination, dist[destination], "New :", dist[source] + weight)
                    dist[destination] = dist[source] + weight

        for source, destination, weight in self.graph:
            if dist[source] != float("Inf") and dist[source] + weight < dist[destination]:
                print("There is Negative Cycle\t", source, destination, dist[destination], "\tNew :", dist[source] + weight)

        return


    def BellmanFord(self, src):
        dist = {i: float("Inf") for i in self.nodes}
        dist[src] = 0

        for _ in range(self.vertices - 1):
            for source, destination, weight in self.graph:
                if dist[source] != float("Inf") and dist[source] + weight < dist[destination]:
                    dist[destination] = dist[source] + weight

        for source, destination, weight in self.graph:
            if dist[source] != float("Inf") and dist[source] + weight < dist[destination]:
                return True

        return False




def TestCase():
    node, road, wormhole = map(int, input().split())
    results = []

    g = Graph(node)

    for i in range(1, node+1):
        g.add_node(i)

    for _ in range(road):
        node_A, node_B, time = map(int, input().split())
        g.add_edge(node_A, node_B, time)
        g.add_edge(node_B, node_A, time)

    for _ in range(wormhole):
        start, end, time = map(int, input().split())
        g.add_edge(start, end, time * -1)

    isNegative = g.BellmanFord(1)
    #g.Track_BellmanFord_Process(1)

    if isNegative :
        results.append("YES")
    else :
        results.append("NO")

    for result in results :
        print(result)


def start():
    TCNum = int(input())
    for _ in range(TCNum):
        TestCase()

start()