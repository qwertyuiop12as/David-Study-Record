from typing import final


def test():
    while True :
        try:
            val = int(input("Please Enter an integer: "))

        except:
            print("Value Error")
            continue
            val = int(input("Please try again: "))

        else :
            print("That's an integer!")
            break

        finally:
            pass
            # print("Finally")
        
    print(val)


test()
