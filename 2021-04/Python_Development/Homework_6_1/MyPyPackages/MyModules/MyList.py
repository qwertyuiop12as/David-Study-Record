import random as rd


def shuffleList(L):
    return rd.shuffle(L)


def genRandList(L, n):
    for i in range(0, n):
        L.append(i)

    return shuffleList(L)


def printListSample(L, size, per_line, sample_lines):
    counter = 0

    for num in L[: per_line * sample_lines]:
        counter += 1
        print(f"{num:2}", end=" " if counter < 10 else "\n")
        if counter == 10:
            counter = 0

    print('.....')

    for num in L[size - per_line * sample_lines:]:
        counter += 1
        print(f"{num:2}", end=" " if counter < 10 else "\n")
        if counter == 10:
            counter = 0

