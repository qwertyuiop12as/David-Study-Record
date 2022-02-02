def demo(readFileName):
    records = []
    cities = []
    file_keys = {}
    idx = 0

    f = open(readFileName, 'r')

    header = f.readline().strip().split(",")
    body = f.readlines()

    for key in header:
        file_keys[key] = idx
        idx = idx + 1

    for record in body:
        records.append(record.strip().split(","))

    for record in records:
        # print(record)
        cities.append(record[file_keys["label"]].lower())

    while True:
        # print(cities)
        city = input("Please Enter city: ").strip().lower()

        if city in cities:
            city_index = cities.index(city)
            date = input(
                "Please Enter the date following the format (yr####): ")

            if date in file_keys.keys():
                print(
                    f'{date} - {city} : {records[city_index][file_keys[date]]}')
                break
            else:
                print("Please Enter Valid Date...")

        else:
            print("Please Enter Valid City Name...")

    # print(file_keys)
    # print(cities)


demo("CityPop.csv")
