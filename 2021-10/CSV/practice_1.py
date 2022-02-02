city = ""
year = ""


def demo(readFileName):
    f = open(readFileName, "r")
    info = f.readline().strip().split(",")
    # print(info)000

    cities = []
    data_list = []
    
    for data in f.readlines():
        converted_data = data.strip().split(",")
        cities.append(converted_data[4])
        data_list.append(converted_data)

    # print(cities)
    # print("도시를 입력해")
    # city_name = input()

    print("년도를 입력해 (yr####)")
    year = input()
    # year_num = (int)(year[2:])
    year_index = -1
    if year in info[5:]:
        year_index = info.index(year)
    else:
        print("년도가 잘못됐어")
        return

    print("도시를 입력해")
    city = input()

    if city in cities :
        city_index = cities.index(city)
        print(data_list[city_index][year_index])
    else :
        print("도시 이름이 잘못됐어")
        return

    # print(year_num)
    # f = open(readFileName, "r")
    # title = f.readline()
    # print(title)


# if ((int)(year[2:]) ) :

demo("./CityPop.csv")
