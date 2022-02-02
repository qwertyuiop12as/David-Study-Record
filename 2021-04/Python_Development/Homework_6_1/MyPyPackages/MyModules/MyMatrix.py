def mtrxAdd(A, B) :
    sum = [[] for _ in range(len(A))]
    for i in range(len(A)) :
        for j in range(len(A[i])) :
            sum[i].append(A[i][j] + B[i][j])

    return sum

def mtrxSub(A, B) :
    sub = [[] for _ in range(len(A))]
    for i in range(len(A)) :
        for j in range(len(A[i])) :
            sub[i].append(A[i][j] - B[i][j])

    return sub

def mtrxMul(A, B) :
    mul = [[] for _ in range(len(A))]
    for i in range(len(A)) :
        for j in range(len(A[i])) :
            mul[i].append(A[i][j] * B[i][j])

    return mul