def demo(readFile) :
    f = open(readFile, "r")

    # readline을 쓰면 한줄만 읽어옴
    print(f.readline())
    # print(f.readline())

def demo2(readFile) :
    records = []

    f = open(readFile, "r")

    # readlines를 쓰면 전부를 읽어옴
    data = f.readlines()
    # 그 중 첫번째(0번방)를 csv형태로 저장함
    header = data[0].strip().split(",")
    # print(header)
    # print("-------------------------")

    # 나머지는 body에 저장
    body = data[1:]
    # print(body)

    records.append(header)

    for record in body:
        records.append(record.strip().split(","))

    for test in records:
        print(test)
        print("---------------------------")

def demo3(writeFile, field, data) :
    f = open(writeFile, "w")

    f.write(",".join(field))

    for record in data:
        f.write(",".join(record))

def demo4(writeFile, field, data) :
    container = []
    f = open(writeFile, "w")

    container.append(",".join(field))

    for record in data:
        container.append(",".join(record))

    f.writelines(container)

test_data = [
    ["Yongsu", "15", "1", "\n"],
    ["Su", "20", "2", "\n"],
    ["Hi", "30", "3", "\n"]
]

demo("CityPop.csv")
# demo2("CityPop.csv")
# demo3("hello.csv", ["name", "age", "id", "\n"], test_data)
# demo4("hi.csv", ["name", "age", "id", "\n"], test_data)