from math import *

def haversine(lon1, lat1, lon2, lat2) :
    # convert decimal degrees to radians
    lon1, lat1, lon2, lat2 = map(radians, [lon1, lat1, lon2, lat2])
    # haversine formula
    dlon = lon2 - lon1
    dlat = lat2 - lat1
    a = sin(dlat/2)**2 + cos(lat1) * cos(lat2) * sin(dlon/2)**2
    c = 2 * asin(sqrt(a))
    # Radius of earth in kilometers is 6371
    km = 6371 * c
    return km


def demo(readFile) :
    f = open(readFile, "r")
    
    cities = []
    locations = {
        "latitude" : [],
        "longitude" : []    
    }

    header = f.readline().strip().split(",")
    body = f.readlines()
    # print(header)

    for content in body :
        content_list = content.strip().split(",")
        cities.append(content_list[header.index("label")].lower())
        locations["latitude"].append(content_list[header.index("latitude")])
        locations["longitude"].append(content_list[header.index("longitude")])

        # print(content)


    print(cities)
    print("Please input two cities")
    
    # city1 = ""
    # while city1 not in cities :
    #     city1 = input("City 1 : ").lower()
    # city1_idx = cities.index(city1)

    # city2 = ""
    # while city2 not in cities or city1 == city2:
    #     city2 = input("City 2 : ").lower()
    # city2_idx = cities.index(city2)

    city1 = ""
    city2 = ""
    while True:
        city1 = input("City 1 : ").lower()

        if city1 in cities:
            # print("Does not exist!")
            while city2 not in cities or city1 == city2:
                city2 = input("City 2 : ").lower()

            break

    city1_idx = cities.index(city1)
    city2_idx = cities.index(city2)
        

    city1_lat = float(locations["latitude"][city1_idx])
    city1_lon = float(locations["longitude"][city1_idx])
    city2_lat = float(locations["latitude"][city2_idx])
    city2_lon = float(locations["longitude"][city2_idx])

    print(haversine(city1_lon, city1_lat, city2_lon, city2_lat))
    



demo("CityPop.csv") 