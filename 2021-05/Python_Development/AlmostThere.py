def almost_there(n) :
    # if abs(100 - number) <= 10 or abs(200 - number) <= 10 :
    #     return True
    # else : 
    #     return False
    return ((abs(100 - n) <= 10) or (abs(200 - n) <= 10))


print("almose_there(89) -->",almost_there(89))