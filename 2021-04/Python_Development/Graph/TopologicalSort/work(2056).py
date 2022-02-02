from collections import defaultdict


class Graph:
    def __init__(self, numberofNodes):
        self.graph = defaultdict(list)
        self.numberofNodes = numberofNodes
        self.sum = 0
        self.NodetoCost = defaultdict()


    def __str__(self):
        print(self.graph)
        return ""


    def applycost(self, vertex, cost) :
        self.NodetoCost[vertex] = cost


    def addEdge(self, vertex, edge):
        self.graph[vertex].append(edge)


    def topologicalSortUtil(self, vertex, visited, stack):
        visited.append(vertex)

        max_value = 0
        for related_vertex in self.graph[vertex]:
            if related_vertex not in visited:

                self.topologicalSortUtil(related_vertex, visited, stack)

                if max_value < self.NodetoCost[related_vertex] :
                    max_value = self.NodetoCost[related_vertex]
                    print(related_vertex)
        
        print("sum :", self.sum, "max_value :", max_value)
        self.sum += max_value

        stack.insert(0, vertex)


    def topologicalSort(self):

        visited = []
        stack = []

        for vertex in list(self.graph):
            if vertex not in visited:
                self.sum += self.NodetoCost[vertex]
                self.topologicalSortUtil(vertex, visited, stack)

        # print("visited", visited)
        # print("stack", stack)
        print("sum", self.sum)


def make_Graph(edge_num, WorkGraph) :

    for numberofEdge in range(edge_num) :
        input_list = list(map(int, input().split()))

        cost, parent_num = input_list[0], input_list[1]
        parents = input_list[2 : ]

        WorkGraph.applycost(numberofEdge + 1, cost)

        for parent in parents :
            WorkGraph.addEdge(parent, numberofEdge + 1)


def start() :
    edge_num = int(input())
    WorkGraph = Graph(edge_num)

    make_Graph(edge_num, WorkGraph)
    
    WorkGraph.topologicalSort()
    

start()

# customGraph.addEdge('A', 'C')
# customGraph.addEdge('C', 'E')
# customGraph.addEdge('E', 'H')
# customGraph.addEdge('E', 'F')
# customGraph.addEdge('F', 'G')
# customGraph.addEdge('B', 'D')
# customGraph.addEdge('B', 'C')
# customGraph.addEdge('D', 'F')

# customGraph.topologicalSort()