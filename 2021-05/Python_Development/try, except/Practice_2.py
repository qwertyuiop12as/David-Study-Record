def test(x, y) :
    try :
        result = x / y
    except ZeroDivisionError :
        print("We can't divide with zero.")
    finally :
        print("All done.")
test(5, 0)