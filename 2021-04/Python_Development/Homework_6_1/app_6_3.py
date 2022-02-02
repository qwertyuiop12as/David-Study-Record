import random, time, sys
from array import *
sys.path.append("C:/")
from MyPyPackages.MyModules import MyList, MySortings

# i는 array를 int로 사용하는 거
AR = array('i') 
L = []
size = 100
MyList.genRandList(L, size)

for x in L :
    AR.append(x)

print("Array (size : {}) before sorting : ".format(size))
MyList.printListSample(AR, size, 10, 2)

t1 = time.time()
MySortings.selectionSort(AR)
t2 = time.time()

print("Array (size : {}) after sorting : ".format(size))
MyList.printListSample(AR, size, 10, 2)
print("Selevtion sorting for array of {} integers took {} sec".format(size, t2-t1))


print("\nList (size : {}) before sorting : ".format(size))
MyList.printListSample(L, size, 10, 2)

t1 = time.time()
MySortings.selectionSort(L)
t2 = time.time()

print("Array (size : {}) after sorting : ".format(size))
MyList.printListSample(AR, size, 10, 2)
print("Selection sorting for list of {} integers took {} sec".format(size, t2-t1))