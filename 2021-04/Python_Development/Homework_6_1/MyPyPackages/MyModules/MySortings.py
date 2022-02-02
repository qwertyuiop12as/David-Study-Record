def selectionSort(L) :
    for i in range(len(L) - 1) :
        for j in range(i + 1, len(L)) :
            if L[i] > L[j] :
                temp = L[i]
                L[i] = L[j]
                L[j] = temp