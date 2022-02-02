# TopologicalSort

- 그래프 중에서는 특정 node에 방문하기 전에 필수로 방문해야 하는 node가 있는데 이를 ```prerequisite```라고 한다

- 순서가 있으므로 무조건 **directed graph**가 나온다

  ![img](https://cdn-images-1.medium.com/max/1000/1*WKi8GVPw423-Nqy2-zsC-g.png)

  (샤워를 하기 전에 운동을 해야 하듯이 어떤 node에 도착하기 전에 필수로 방문해야 하는 node가 있다.)

- ```TopologicalSort```는 어떤 node에 가기 전에 필수로 거쳐야 하는 node가 있는 그래프의 방문 순서를 구해주는 프로그램





```python
    def topologicalSortUtil(self, vertex, visited, stack) :
        visited.append(vertex)

        for related_vertex in self.graph[vertex] :
            if related_vertex not in visited :
                # print(related_vertex)
                self.topologicalSortUtil(related_vertex, visited, stack)

        stack.insert(0, vertex)
```



- 시작하는 node가 있을 때 바로 stack(결과)에 넣어주지 않고 자신의 자식 node(자신과 연결되어 있는 node)를 방문한 다음 더 이상 방문할 node가 없다면 stack에 값을 넣는다
- topologicalSort 작동이 되는 함수에서 for 문이 다 돌고 나서(자식 node를 다 체크하고 나서) stack에 넣기 때문에 가장 먼저 검사한 node가 순서상 나중에 stack에 들어간다.
- **But,  stack.insert(0, vertex)를 해줘서 더 늦게 들어가는 node가 기존의 값을 밀어내면서 0번 방에 들어가기 때문에 최종 stack에는 순서대로 값이 들어간다.**



```python
class Graph :
    def __init__(self, numberofNodes) :
        self.graph = defaultdict(list)
        self.numberofNodes = numberofNodes

    def __str__(self) :
        print(self.graph)
        return ""

    def addEdge(self, vertex, edge) :
        self.graph[vertex].append(edge)

    def topologicalSortUtil(self, vertex, visited, stack) :
        visited.append(vertex)

        for related_vertex in self.graph[vertex] :
            if related_vertex not in visited :
                # print(related_vertex)
                self.topologicalSortUtil(related_vertex, visited, stack)

        stack.insert(0, vertex)

    def topologicalSort(self) :

        visited = []
        stack = []

        for key_vertex in list(self.graph) :
            if key_vertex not in visited :
                self.topologicalSortUtil(key_vertex, visited, stack)
        
        print("visited", visited)
        print("stack", stack)
#Example 1
customGraph = Graph(8)
customGraph.addEdge('A', 'C')
customGraph.addEdge('C', 'E')
customGraph.addEdge('E', 'H')
customGraph.addEdge('E', 'F')
customGraph.addEdge('F', 'G')
customGraph.addEdge('B', 'D')
customGraph.addEdge('B', 'C')
customGraph.addEdge('D', 'F')

#Example 2
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
```



- ```visited ``` list를 사용해서 **이미 방문한 node는 방문하지 않도록 하기**
- ```graph``` list에 자신 방번째에 **append**로 값을 넣기



## class Graph

```python
def __init__(self, numberofNodes):
        self.graph = defaultdict(list)
        self.numberofNodes = numberofNodes
```

- ```graph```를 만들어 주는 함수 

- 나중에 ```graph```를 사용해서 연결된 node를 정리해줌

  

```python
def __str__(self):
        print(self.graph)
        return ""
```

- ```graph```를 출력해 주는 함수



```python
def addEdge(self, vertex, edge):
        self.graph[vertex].append(edge)
```

- ```graph```에 값을 append 해줌 (node 사이의 연결 관계 저장)



```python
def topologicalSortUtil(self, vertex, visited, stack):
        visited.append(vertex)

        for related_vertex in self.graph[vertex]:
            if related_vertex not in visited:
                # print(related_vertex)
                self.topologicalSortUtil(related_vertex, visited, stack)

        stack.insert(0, vertex)
```

- Topological Sort 기능이 있는 함수
- 인자 값으로 받은 ```vertex```값과 ```graph``` 리스트를 활용하여 연결되어 있는 모든 node를 탐색
- ```visited``` list를 사용해서 한번 방문한 node는 다시 방문하지 않도록 함
- 순서상으로 나중에 탐색한 node가 먼저 ```stack```에 들어감
- 하지만 insert(0, vertex)를 사용해서 나중에 들어오는 애가 기존에 애들을 뒤로 밀어내고 자신이 가장 첫 번째 방으로 들어감                
- 탐색한 순서의 반대로 들어가지만 insert(0, vertex) 때문에 나중에 들어오는 애가 먼저 들어와서 순서가 맞게 됨



```python
def topologicalSort(self):

        visited = []
        stack = []

        for key_vertex in list(self.graph):
            if key_vertex not in visited:
                self.topologicalSortUtil(key_vertex, visited, stack)

        print("visited", visited)
        print("stack", stack)
```

- ```topologicalSortUtil```을 호출 해주는 함수
- ```topologicalSortUtil```랑 같은 ```visited```를 사용해서 한번 방문한 node는 다시 안 가게 함
- 마지막에 ```visited```랑 ```stack```을 출력해줌 (최종 결과 확인)

### Example 1

![img](https://cdn-images-1.medium.com/max/1000/1*nWcq7HahqqZ2bIYVqS9urg.png)

![img](https://cdn-images-1.medium.com/max/1000/1*kCm9fBrh5Lil7Izh1cwxhg.png)

#### **순서도**

```python
topologicalSortUtil(vertex : "A", visited : [], stack : [])
vertex = "A"
visited = ["A"]
stack = []

topologicalSortUtil(vertex : "C", visited : ["A"], stack : [])
vertex = "C"
visited = ["A", "C"]
stack = []

topologicalSortUtil(vertex : "E", visited : ["A", "C"], stack : [])
vertex = "E"
visited = ["A", "C", "E"]
stack = []

#아직 E에서 연결된 H도 남음. 일단 F먼저 방문
topologicalSortUtil(vertex : "F", visited : ["A", "C", "E"], stack : [])
vertex = "F"
visited = ["A", "C", "E", "F"]
stack = []

topologicalSortUtil(vertex : "G", visited : ["A", "C", "E", "F"], stack : [])
vertex = "G"
visited = ["A", "C", "E", "F", "G"]
stack.insert(0, "G")
stack = ["G"]

#G와 연결된 자식 node는 없으니까 for문이 바로 끝나서 stack에 G를 넣음

#G가 끝났으니 return되어서 다시 F로 돌아옴
topologicalSortUtil(vertex : "F", visited : ["A", "C", "E", "F", "G"], stack : ["G"])
vertex = "F"
visited = ["A", "C", "E", "F", "G"]
stack.insert(0, "F")
stack = ["F", "G"]

#F를 insert할 때 (0, "F")를 해서 기존 애를 뒤로 밀어내고 "F"가 0번방에 감

#F도 끝나서 E로 돌아감
topologicalSortUtil(vertex : "E", visited : ["A", "C", "E", "F", "G"], stack : ["F", "G"])
vertex = "E"
visited = ["A", "C", "E", "F", "G"]
stack = ["F", "G"]

topologicalSortUtil(vertex : "H", visited : ["A", "C", "E", "F", "G"], stack : ["F", "G"])
vertex = "H"
visited = ["A", "C", "E", "F", "G", "H"]
stack.insert(0, "H")
stack = ["H", "F", "G"]

#H가 끝나서 E의 모든 자식이 끝남 -> E가 있던 함수로 return
topologicalSortUtil(vertex : "E", visited : ["A", "C", "E", "F", "G", "H"], stack : ["F", "G"])
vertex = "E"
visited = ["A", "C", "E", "F", "G", "H"]
stack.insert(0, "E")
stack = ["E", "H", "F", "G"]

topologicalSortUtil(vertex : "C", visited : ["A", "C", "E", "F", "G", "H"], stack : ["E", "H", "F", "G"])
vertex = "C"
visited = ["A", "C", "E", "F", "G", "H"]
stack.insert(0, "C")
stack = ["C", "E", "H", "F", "G"]

topologicalSortUtil(vertex : "A", visited : ["A", "C", "E", "F", "G", "H"], stack : ["C", "E", "H", "F", "G"])
vertex = "A"
visited = ["A", "C", "E", "F", "G", "H"]
stack.insert(0, "A")
stack = ["A", "C", "E", "H", "F", "G"]

#A의 자식들은 모두 돌았으므로 이제 새로운 부모 B를 탐색
topologicalSort()
key_vertex = "B"

topologicalSortUtil(vertex : "B", visited : ["A", "C", "E", "F", "G", "H"], stack : ["C", "E", "H", "F", "G"])
vertex = "B"
visited = ["A", "C", "E", "F", "G", "H", "B"]
stack = ["A", "C", "E", "H", "F", "G"]

topologicalSortUtil(vertex : "D", visited : ["A", "C", "E", "F", "G", "H", "B"], stack : ["C", "E", "H", "F", "G"])
vertex = "D"
visited = ["A", "C", "E", "F", "G", "H", "B", "D"]
stack.insert(0, "D")
#D는 방문할 자식이 없으므로(F가 이미 visited에 있어서) 바로 insert 
stack = ["D", "A", "C", "E", "H", "F", "G"]


topologicalSortUtil(vertex : "B", visited : ["A", "C", "E", "F", "G", "H", "B", "D"], stack : ["D", "C", "E", "H", "F", "G"])
vertex = "B"
visited = ["A", "C", "E", "F", "G", "H", "B", "D"]
stack.insert(0, "B")
stack = ["B", "D", "A", "C", "E", "H", "F", "G"]
```





### Example 2

![img](https://cdn-images-1.medium.com/max/1000/1*3cMIIhdypo5dHRFNxpXi8A.png)

![img](https://cdn-images-1.medium.com/max/1000/1*oy7bSEz94E7AnzBorIvDIQ.png)



- ```visited```를 쓰는 목적은 일단 방문 한지 안 한 지 체크하기 위한 건데 **실제 함수가 작동한 순서가 담겨있음**



