from typing import Type


li = ['a', 'b', 'c', 11, 9]
for i in li:
    try :
        val = i ** 2

    except TypeError :
        print("TypeError")

    else :
        print(val)
