from DataStructures.ArrayLists import ArrayList
from DataStructures.SequentialPriorityQueue import SequentialPriorityQueue

list = ArrayList()

def PQ_Sort(list):
    Pq = SequentialPriorityQueue()
    while not list.isEmpty():
        e = list.RemoveFirst()
        Pq.insertItem(e, e)
    while not Pq.isEmpty():
        e = Pq.removeMin()
        list.addLast(e)

def InPlaceSelectionSort(list):
    for pas in range(0, list.size()-2):
        min = pas
        for j in range(pas+1, list.size()-1):
            if list.elements()[j] < list.elements()[min]:
                min = j
        list.swap(pas, min)

def InPlaceInsertionSort(list):
    for pas in range(1, list.Size()-1):
        save = list.elements()[pas]
        j = pas-1
        while j >= 0 and list.elements()[j] > save:
            list.set(j+1, list.elements()[j])
            j -= 1
        list.set(j+1, save)