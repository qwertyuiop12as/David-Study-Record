# Topological Sort

**Topological Sort:**

Sorts given actions in such a way that if there is a dependency of one action on another, then the dependent action always comes later than its parent action.

위상 정렬은 `directed graph`의 꼭짓점(Vertex or Node)을 변의 방향을 거스르지 않도록 나열하는 것을 의미한다. 위상정렬을 가장 잘 설명해 줄 수 있는 예는 대학의 선수과목(prerequisite) 구조를 생각할 수 있다. 만약 특정 수강과목에 선수과목이 있다면, 그 선수 과목부터 수강해야 하므로, 특정 과목들을 수강해야 할 때 위상 정렬을 통해 올바른 수강 순서를 찾아낼 수 있다.

이와 같이 선후 관계가 정의된 그래프 구조 상에서, 선후 관계에 따라 정렬하기 위해 위상 정렬을 이용할 수 있다. 정렬의 순서는 `directed graph`의 구조에 따라 여러개의 종류가 나올 수 있다. `directed graph`이 성립하기 위해서는 반드시 `graph`에 순환이 존재하지 않아야 한다. 즉 그래프가 `directed acyclic graph` 형태여야 한다.

위상 정렬의 적용은 주로 업무의 일정을 일어나야 할 순서에 따라 배치하기 위하는 것으로, 이 알고리즘은 프로젝트 관리 기법을 평가 및 분석하기 위한 기법(PERT)에 적용하기 위한 목적을 위해 1960년대 초반부터 연구되었다. 이때 해당 업무는 꼭짓점(Vertex or Node)로 표현되었고, 각 꼭짓점(Vertex or Node)을 연결하는 변은 해당 업무 간의 선후 관계를 표현했다. 가령, 옷을 다리기 위한 업무는 반드시 옷을 세탁기에 돌리는 업무 뒤에 배치되어야 한다. 이와 같이, 위상정렬은 각 업무를 수행하기 위한 순서를 제공했다.

[![An example PERT/CPM network of 11 tasks | Download Scientific Diagram](https://camo.githubusercontent.com/3d7433829cb03adf01684fdc866a117ffa80de4f1a78b6aef08ecc62cbfced7a/68747470733a2f2f7777772e7265736561726368676174652e6e65742f70726f66696c652f546170616e2d4261676368692d322f7075626c69636174696f6e2f3332313134343933322f6669677572652f666967312f41533a35363138393031373439343733323940313531303937363436353836352f416e2d6578616d706c652d504552542d43504d2d6e6574776f726b2d6f662d31312d7461736b732e706e67)](https://camo.githubusercontent.com/3d7433829cb03adf01684fdc866a117ffa80de4f1a78b6aef08ecc62cbfced7a/68747470733a2f2f7777772e7265736561726368676174652e6e65742f70726f66696c652f546170616e2d4261676368692d322f7075626c69636174696f6e2f3332313134343933322f6669677572652f666967312f41533a35363138393031373439343733323940313531303937363436353836352f416e2d6578616d706c652d504552542d43504d2d6e6574776f726b2d6f662d31312d7461736b732e706e67)

[![img](https://camo.githubusercontent.com/340f0bc054eea6f7a304e87e827bea844abe084d2ce50ceeb564183c6c4c430c/68747470733a2f2f63646e2d696d616765732d312e6d656469756d2e636f6d2f6d61782f313030302f312a457941792d34586d736834665778386b4e35436247412e706e67)](https://camo.githubusercontent.com/340f0bc054eea6f7a304e87e827bea844abe084d2ce50ceeb564183c6c4c430c/68747470733a2f2f63646e2d696d616765732d312e6d656469756d2e636f6d2f6d61782f313030302f312a457941792d34586d736834665778386b4e35436247412e706e67)

1. 아침에 먹을 과일을 구입한다.
2. 구입한 과일을 먹기위해 손질한다 (과일을 구입하지 않고, 과일을 준비할 수 없다).
   - 과일을 손질하는 단계는 과일을 구입하는 단계에 의존한다.
3. 아침을 먹는다 (과일을 손질하지 않고 아침을 먹을 수 없다).
   - 아침을 먹는 단계는, 과일을 손질하는 단계와, 과일을 구입하는 단계에 의존한다.

위 그림의 구조는 어떤 행위를 하기 위해 반드시 선수 되어야 하는 행위가 반드시 먼저 일어나야 다음 순서에 위치한 행위가 발생할 수 있음을 보여준다.

### 위상 정렬의 (Topological Sorting) 수행과정

1. 자기 자신을 가리키는 변이 없는 꼭짓점을 찾음.
2. 찾은 꼭짓점을 출력하고 출력한 꼭짓점과 그 꼭짓점에서 출발하는 변을 삭제.
3. 아직 그래프에 꼭짓점에 남아있다면 단계 1로 돌아가고, 아니면 알고리즘을 종료시킨다.

## Topological Sort Algorithm

[![img](https://camo.githubusercontent.com/470fc87b4de71dff02fb9b031f6f975c0044e5460e900d01ab86bb5ac47b293a/68747470733a2f2f63646e2d696d616765732d312e6d656469756d2e636f6d2f6d61782f313030302f312a6177557a64445244553177737746445277767a696a412e706e67)](https://camo.githubusercontent.com/470fc87b4de71dff02fb9b031f6f975c0044e5460e900d01ab86bb5ac47b293a/68747470733a2f2f63646e2d696d616765732d312e6d656469756d2e636f6d2f6d61782f313030302f312a6177557a64445244553177737746445277767a696a412e706e67)

[![img](https://camo.githubusercontent.com/77df49e47857add71ba389091112c02eac4eb834b7c6498113627acc7be43345/68747470733a2f2f63646e2d696d616765732d312e6d656469756d2e636f6d2f6d61782f313030302f312a4b4868307735306b38394770325257484e36546b6c512e706e67)](https://camo.githubusercontent.com/77df49e47857add71ba389091112c02eac4eb834b7c6498113627acc7be43345/68747470733a2f2f63646e2d696d616765732d312e6d656469756d2e636f6d2f6d61782f313030302f312a4b4868307735306b38394770325257484e36546b6c512e706e67)

[![img](https://camo.githubusercontent.com/0b42c4b20573c85b64dd857c72d1610068764573fc7b978fecd4901f3b791aff/68747470733a2f2f63646e2d696d616765732d312e6d656469756d2e636f6d2f6d61782f313030302f312a326361554157413062424a6d574f51554331796471512e706e67)](https://camo.githubusercontent.com/0b42c4b20573c85b64dd857c72d1610068764573fc7b978fecd4901f3b791aff/68747470733a2f2f63646e2d696d616765732d312e6d656469756d2e636f6d2f6d61782f313030302f312a326361554157413062424a6d574f51554331796471512e706e67)

[![img](https://camo.githubusercontent.com/2ecfe6ca2c35afd637a749671114a8755e0e662d462fa0a2a42f7190e0c89c34/68747470733a2f2f63646e2d696d616765732d312e6d656469756d2e636f6d2f6d61782f313030302f312a7030447546315a2d754274666d54666947464a497a512e706e67)](https://camo.githubusercontent.com/2ecfe6ca2c35afd637a749671114a8755e0e662d462fa0a2a42f7190e0c89c34/68747470733a2f2f63646e2d696d616765732d312e6d656469756d2e636f6d2f6d61782f313030302f312a7030447546315a2d754274666d54666947464a497a512e706e67)

[![img](https://camo.githubusercontent.com/dde6068f4668d05657e47279cc631ae264bdb3daf332f851d2993a8d64be020e/68747470733a2f2f63646e2d696d616765732d312e6d656469756d2e636f6d2f6d61782f313030302f312a5434465645694551363463596c66394762524c7742412e706e67)](https://camo.githubusercontent.com/dde6068f4668d05657e47279cc631ae264bdb3daf332f851d2993a8d64be020e/68747470733a2f2f63646e2d696d616765732d312e6d656469756d2e636f6d2f6d61782f313030302f312a5434465645694551363463596c66394762524c7742412e706e67)

[![img](https://camo.githubusercontent.com/653ab8ff9c55dd675bd2ed2cfba8ab2dd2a3b6ee80eafb300209449c501c6251/68747470733a2f2f63646e2d696d616765732d312e6d656469756d2e636f6d2f6d61782f313030302f312a44514c6f4c5a365164724c42763357725459424832512e706e67)](https://camo.githubusercontent.com/653ab8ff9c55dd675bd2ed2cfba8ab2dd2a3b6ee80eafb300209449c501c6251/68747470733a2f2f63646e2d696d616765732d312e6d656469756d2e636f6d2f6d61782f313030302f312a44514c6f4c5a365164724c42763357725459424832512e706e67)

[![img](https://camo.githubusercontent.com/898177d6deca2586987a296abd8dc4fe489bb42176bcb93ce373379fa93a92c5/68747470733a2f2f63646e2d696d616765732d312e6d656469756d2e636f6d2f6d61782f313030302f312a386849383938324b664b307551376357376f6a7865772e706e67)](https://camo.githubusercontent.com/898177d6deca2586987a296abd8dc4fe489bb42176bcb93ce373379fa93a92c5/68747470733a2f2f63646e2d696d616765732d312e6d656469756d2e636f6d2f6d61782f313030302f312a386849383938324b664b307551376357376f6a7865772e706e67)

[![img](https://camo.githubusercontent.com/e75e995d8a91b580d8ddf46a871f26b44fc87286875337ae077bb058889c9f49/68747470733a2f2f63646e2d696d616765732d312e6d656469756d2e636f6d2f6d61782f313030302f312a793365745178656756675f534952546f6552386348672e706e67)](https://camo.githubusercontent.com/e75e995d8a91b580d8ddf46a871f26b44fc87286875337ae077bb058889c9f49/68747470733a2f2f63646e2d696d616765732d312e6d656469756d2e636f6d2f6d61782f313030302f312a793365745178656756675f534952546f6552386348672e706e67)

[![img](https://camo.githubusercontent.com/c160af67a43d83d9fda278e62d4d379e66a4739c156377c7e9f817eca799260f/68747470733a2f2f63646e2d696d616765732d312e6d656469756d2e636f6d2f6d61782f313030302f312a34783478754b314632705470445f56703949313637412e706e67)](https://camo.githubusercontent.com/c160af67a43d83d9fda278e62d4d379e66a4739c156377c7e9f817eca799260f/68747470733a2f2f63646e2d696d616765732d312e6d656469756d2e636f6d2f6d61782f313030302f312a34783478754b314632705470445f56703949313637412e706e67)

All dependencies are respected. None of them are violated.

Our solution depends on from which vertex we start.

For example, if we start from B, we will have another solution over here. So based on the starting point, our solutions might be different.

다른 요소의 `Pre-requisite` 스택에 나중에 들어가야 한다. 왜냐하면 스택은(LIFO) 마지막에 들어간 요소가 처음으로 나오기 때문이다. `Pre-requisite`이 먼저 나와야, 그다음 단계가 나오는데 논리적으로 말이 되기 때문이다. 이러한 이유 때문에 재귀 방식을 사용한다.

```python
from collections import defaultdict


class Graph:
    def __init__(self, numberofVertices):
        self.graph = defaultdict(list)
        self.numberofVertices = numberofVertices

    def __str__(self):
        print(self.graph)
        return ""

    def addEdge(self, vertex, edge):
        self.graph[vertex].append(edge)

    def topologicalSortUtil(self, vertex, visited, stack):
        print("visited", visited)
        print("stack", stack)
        visited.append(vertex)

        for related_vertex in self.graph[vertex]:
            if related_vertex not in visited:
                print(related_vertex)
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

# All dependencies are respected
customGraph.topologicalSort()
```

## Details

```python
{
    "A": ["C"],
    "C": ["E"],
    "E": ["H", "F"],
    "F": ["G"],
    "B": ["D", "C"],
    "D": ["F"]
}

visited = []
stack = []
# I will call topologicalSortUtil

topologicalSort()

topologicalSortUtil("A", [], [])
visited.append("A")
# visited = ["A"]
# "C" Not in visited == True

topologicalSortUtil("C", ["A"], [])
# visited = ["A", "C"]
# "E" Not in visited == True

topologicalSortUtil("E", ["A", "C", "E"], [])
# visited = ["A", "C", "E"]
# "H" Not in visited == True

topologicalSortUtil("H", ["A", "C", "E", "H"], [])
# visited = ["A", "C", "E", "H"]
# H는 related_vertex 가 존재하지 않기 때문에, 바로 stack에 넣어준다.
stack.insert(0, "H")
# stack = ["H"]

# "E"의 두 번째 related_vertex인 "F"를 확인한다.
# "F" Not in visited == True
topologicalSortUtil("F", ["A", "C", "E", "H"], ["H"])
# visited = ["A", "C", "E", "H", "F"]
# "G" Not in visited = True

topologicalSortUtil("G", ["A", "C", "E", "H"], ["H"])
# visited = ["A", "C", "E", "H", "F", "G"]
# G는 related_vertex 가 존재하지 않기 때문에, 바로 stack에 넣어준다.
stack.insert(0, "G")
# stack = ["G", "H"]

# F에 존재하는 모든 related_vertex를 순회했기 때문에 (재귀 종료)
stack.insert(0, "F")
# stack = ["F", "G", "H"]

# H는 이전에 끝났기 때문에, E에 존재하는 모든 related_vertex를 순회했기 때문에 (재귀 종료)
stack.insert(0, "E")
# stack = ["E", "F", "G", "H"]

# C에 존재하는 모든 related_vertex를 순회했기 때문에 (재귀 종료)
stack.insert(0, "C")
# stack = ["C", "E", "F", "G", "H"]

# A에 존재하는 모든 related_vertex를 순회했기 때문에 (재귀 종료)
stack.insert(0, "A")
# stack = ["A", "C", "E", "F", "G", "H"]

# topologicalSort 에서 첫번째 key_vertex "A"가 끝났고, 다음으로 넘어간다.
# visited = ["A", "C", "E", "H", "F", "G"]
# "C" (Key_vertex) not in visited == False (Pass)
# "E" (Key_vertex) not in visited == False (Pass)
# "F" (Key_vertex) not in visited == False (Pass)

# "B" (Key_vertex) not in visited == True
topologicalSortUtil("B", ["A", "C", "E", "H", "F", "G"], ["A", "C", "E", "F", "G", "H"])
# visited = ["A", "C", "E", "H", "F", "G", "B"]
# "D" Not in visited = True

topologicalSortUtil("D", ["A", "C", "E", "H", "F", "G"], ["A", "C", "E", "F", "G", "H"])
# visited = ['A', 'C', 'E', 'H', 'F', 'G', 'B', "D"]
# "F" Not in visited = False

# D에 존재하는 모든 related_vertex를 순회했기 때문에 (재귀 종료)
stack.insert(0, "D")
# stack = ["D","A", "C", "E", "F", "G", "H"]


# "B"의 두 번째 related_vertex인 "C"는 visited에 이미 존재하기 때문에, 모든 related_vertex 순회 종료 (재귀 종료)
stack.insert(0, "B")
# visited = ['A', 'C', 'E', 'H', 'F', 'G', 'B', "D"]
# stack = ["B", "D", "A", "C", "E", "F", "G", "H"]

# 결과
# visited []
# stack []
# visited ['A']
# stack []
# visited ['A', 'C']
# stack []
# visited ['A', 'C', 'E']
# stack []
# visited ['A', 'C', 'E', 'H']
# stack ['H']
# visited ['A', 'C', 'E', 'H', 'F']
# stack ['H']
# visited ['A', 'C', 'E', 'H', 'F', 'G']
# stack ['A', 'C', 'E', 'F', 'G', 'H']
# visited ['A', 'C', 'E', 'H', 'F', 'G', 'B']
# stack ['A', 'C', 'E', 'F', 'G', 'H']
# visited ['A', 'C', 'E', 'H', 'F', 'G', 'B', 'D']
# stack ['B', 'D', 'A', 'C', 'E', 'F', 'G', 'H']
```