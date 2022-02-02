def demo(readFileName):
    f = open(readFileName, "r")
    header = f.readline()

    for data in f.readlines():
        print(data.strip().split(','))


demo("CityPop.csv")

'''
도시 이름을 입력해주세여: tokyo
연도를 입력해주세요 (yr####): yr1970
출력 결과: 23.3

도시 이름이 존재x 다시
연도가 존재않거나 형식이 다르다 다시
'''
