from collections import defaultdict


class Graph:
    def __init__(self, numberofNodes):
        self.graph = defaultdict(list)
        self.numberofNodes = numberofNodes

    def __str__(self):
        print(self.graph)
        return ""

    def addEdge(self, vertex, edge):
        self.graph[vertex].append(edge)

    def topologicalSortUtil(self, vertex, visited, stack):
        visited.append(vertex)

        for related_vertex in self.graph[vertex]:
            if related_vertex not in visited:
                # print(related_vertex)
                self.topologicalSortUtil(related_vertex, visited, stack)

        stack.insert(0, vertex)

    def topologicalSort(self):

        visited = []
        stack = []

        for key_vertex in list(self.graph):
            if key_vertex not in visited:
                self.topologicalSortUtil(key_vertex, visited, stack)

        print("visited", visited)
        print("stack", stack)


customGraph = Graph(8)
customGraph.addEdge('A', 'C')
customGraph.addEdge('C', 'E')
customGraph.addEdge('E', 'H')
customGraph.addEdge('E', 'F')
customGraph.addEdge('F', 'G')
customGraph.addEdge('B', 'D')
customGraph.addEdge('B', 'C')
customGraph.addEdge('D', 'F')

# customGraph = Graph(8)
# customGraph.addEdge('H', 'F')
# customGraph.addEdge('H', 'G')
# customGraph.addEdge('F', 'C')
# customGraph.addEdge('F', 'E')
# customGraph.addEdge('C', 'B')
# customGraph.addEdge('B', 'A')
# customGraph.addEdge('G', 'E')
# customGraph.addEdge('G', 'D')
# customGraph.addEdge('D', 'B')

customGraph.topologicalSort()


# topologicalSortUtil(vertex : "A", visited : [], stack : [])
# vertex = "A"
# visited = ["A"]
# stack = []

# topologicalSortUtil(vertex : "C", visited : ["A"], stack : [])
# vertex = "C"
# visited = ["A", "C"]
# stack = []

# topologicalSortUtil(vertex : "E", visited : ["A", "C"], stack : [])
# vertex = "E"
# visited = ["A", "C", "E"]
# stack = []

# #아직 E에서 연결된 H도 남음. 일단 F먼저 방문
# topologicalSortUtil(vertex : "F", visited : ["A", "C", "E"], stack : [])
# vertex = "F"
# visited = ["A", "C", "E", "F"]
# stack = []

# topologicalSortUtil(vertex : "G", visited : ["A", "C", "E", "F"], stack : [])
# vertex = "G"
# visited = ["A", "C", "E", "F", "G"]
# stack.insert(0, "G")
# stack = ["G"]

# #G와 연결된 자식 node는 없으니까 for문이 바로 끝나서 stack에 G를 넣음

# #G가 끝났으니 return되어서 다시 F로 돌아옴
# topologicalSortUtil(vertex : "F", visited : ["A", "C", "E", "F", "G"], stack : ["G"])
# vertex = "F"
# visited = ["A", "C", "E", "F", "G"]
# stack.insert(0, "F")
# stack = ["F", "G"]

# #F를 insert할 때 (0, "F")를 해서 기존 애를 뒤로 밀어내고 "F"가 0번방에 감

# #F도 끝나서 E로 돌아감
# topologicalSortUtil(vertex : "E", visited : ["A", "C", "E", "F", "G"], stack : ["F", "G"])
# vertex = "E"
# visited = ["A", "C", "E", "F", "G"]
# stack = ["F", "G"]

# topologicalSortUtil(vertex : "H", visited : ["A", "C", "E", "F", "G"], stack : ["F", "G"])
# vertex = "H"
# visited = ["A", "C", "E", "F", "G", "H"]
# stack.insert(0, "H")
# stack = ["H", "F", "G"]

# #H가 끝나서 E의 모든 자식이 끝남 -> E가 있던 함수로 return
# topologicalSortUtil(vertex : "E", visited : ["A", "C", "E", "F", "G", "H"], stack : ["F", "G"])
# vertex = "E"
# visited = ["A", "C", "E", "F", "G", "H"]
# stack.insert(0, "E")
# stack = ["E", "H", "F", "G"]

# topologicalSortUtil(vertex : "C", visited : ["A", "C", "E", "F", "G", "H"], stack : ["E", "H", "F", "G"])
# vertex = "C"
# visited = ["A", "C", "E", "F", "G", "H"]
# stack.insert(0, "C")
# stack = ["C", "E", "H", "F", "G"]

# topologicalSortUtil(vertex : "A", visited : ["A", "C", "E", "F", "G", "H"], stack : ["C", "E", "H", "F", "G"])
# vertex = "A"
# visited = ["A", "C", "E", "F", "G", "H"]
# stack.insert(0, "A")
# stack = ["A", "C", "E", "H", "F", "G"]

# #A의 자식들은 모두 돌았으므로 이제 새로운 부모 B를 탐색
# topologicalSort()
# key_vertex = "B"

# topologicalSortUtil(vertex : "B", visited : ["A", "C", "E", "F", "G", "H"], stack : ["C", "E", "H", "F", "G"])
# vertex = "B"
# visited = ["A", "C", "E", "F", "G", "H", "B"]
# stack = ["A", "C", "E", "H", "F", "G"]

# topologicalSortUtil(vertex : "D", visited : ["A", "C", "E", "F", "G", "H", "B"], stack : ["C", "E", "H", "F", "G"])
# vertex = "D"
# visited = ["A", "C", "E", "F", "G", "H", "B", "D"]
# stack.insert(0, "D")
# #D는 방문할 자식이 없으므로(F가 이미 visited에 있어서) 바로 insert
# stack = ["D", "A", "C", "E", "H", "F", "G"]


# topologicalSortUtil(vertex : "B", visited : ["A", "C", "E", "F", "G", "H", "B", "D"], stack : ["D", "C", "E", "H", "F", "G"])
# vertex = "B"
# visited = ["A", "C", "E", "F", "G", "H", "B", "D"]
# stack.insert(0, "B")
# stack = ["B", "D", "A", "C", "E", "H", "F", "G"]
