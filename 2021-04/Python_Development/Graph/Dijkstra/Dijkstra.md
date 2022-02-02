# Dijkstra

```Weighted Graph```에서 어떻게 최소 비용만으로 각 지점까지 갈 수 있는지를 구하는 ```algorithm```

![img](https://camo.githubusercontent.com/bd3aaf2bee64a4d1ed960ed75761b2f4582f461bbf1133666239eca41d876a8d/68747470733a2f2f63646e2d696d616765732d312e6d656469756d2e636f6d2f6d61782f313030302f312a32467a574f46754342664a4c4c4f79714a65694d72512e706e67)

위 Graph에서 임의의 시작 정점을 기준으로 각 정점까지 이동하기 위한 최소 비용을 구해준다.



**Dijkstra**의 작동 과정

- 현재 값이 지정되어 있는 node 중에서 가장 값이 작은 node를 선택해 출발할 node로 지정한다.

- 출발한 node와 연결되어 있는 node 중에서 한 번도 방문하지 않았거나 **저장되어 있는 값이 현재 node까지의 값 + 방문해야 할 node 사이의 값보다 클 경우**에는 더 작은 값을 반영해 준다.                                                                                                                                    (A에서 시작했다고 가정하고 B가 출발할 node 일 때 E의 현재 값이 7(2 + 1 + 4)인데 B(2)에서 E로 가는 비용은 3, 따라서 총비용은 5이므로 기존의 7보다 작기 때문에 작은 값을 반영해 준다.)

- 위 과정을 모든 경로를 확인할 때까지 반복한다.

  

![img](https://cdn-images-1.medium.com/max/800/1*DYBJ6857WrAYDEMviswlSw.jpeg)



```python
from collections import defaultdict


class Graph:
    def __init__(self):
        self.nodes = set()
        self.edges = defaultdict(list)
        self.distances = {}

    def addNode(self, value):
        self.nodes.add(value)

    def addEdge(self, fromNode, toNode, distance):
        self.edges[fromNode].append(toNode)
        self.distances[(fromNode, toNode)] = distance


def dijkstra(graph, initial):
    visited = {initial: 0}
    path = defaultdict(list)

    nodes = set(graph.nodes)

    while nodes:
        minNode = None
        for node in nodes:
            if node in visited:
                if minNode is None:
                    minNode = node
                elif visited[node] < visited[minNode]:
                    minNode = node

        if minNode is None:
            break

        nodes.remove(minNode)
        currentWeight = visited[minNode]

        print(graph.edges)
        for edge in graph.edges[minNode]:
            print(graph.distances[(minNode, edge)])
            weight = currentWeight + graph.distances[(minNode, edge)]
            if edge not in visited or weight < visited[edge]:
                visited[edge] = weight
                path[edge].append(weight)

    return visited, path


customGraph = Graph()
customGraph.addNode("A")
customGraph.addNode("B")
customGraph.addNode("C")
customGraph.addNode("D")
customGraph.addNode("E")
customGraph.addNode("F")
customGraph.addNode("G")
customGraph.addEdge("A", "B", 2)
customGraph.addEdge("A", "C", 5)
customGraph.addEdge("B", "C", 6)
customGraph.addEdge("B", "D", 1)
customGraph.addEdge("B", "E", 3)
customGraph.addEdge("C", "F", 8)
customGraph.addEdge("D", "E", 4)
customGraph.addEdge("E", "G", 9)
customGraph.addEdge("F", "G", 7)

print(dijkstra(customGraph, "A"))
```



### class Graph

```python
class Graph:
    def __init__(self):
        self.nodes = set()
        self.edges = defaultdict(list)
        self.distances = {}

    def addNode(self, value):
        self.nodes.add(value)

    def addEdge(self, fromNode, toNode, distance):
        self.edges[fromNode].append(toNode)
        self.distances[(fromNode, toNode)] = distance
```

- ```nodes``` 
  - node들을 저장해주는 set
  - 