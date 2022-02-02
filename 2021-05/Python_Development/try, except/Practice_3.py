def ask() :
    while True :
        try :
            value = int(input("Please input an integer: "))
            result = value ** 2
        except ValueError :
            print("ValueError")
            continue
        else :
            break
    print(result)

ask()