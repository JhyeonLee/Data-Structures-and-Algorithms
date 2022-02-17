from DataStructures.ArrayLists import ArrayList
from utils.utils import wrongOrderTypeException
import random

class QuickSort(ArrayList):
        def __init__(self):
            super(QuickSort, self).__init__()
        
        # orderType: 오름차순(Ascending), 내림차순(Descending)
        def QuickSort(self, orderType="Ascending"):
            self.inPlaceQuickSort(0, self.size(), orderType)
        def inPlaceQuickSort(self, left, right, orderType="Ascending"):
            if left >= right:
                return
            k = self.findPivot(left, right)
            index = self.inPlacePartition()
            self.inPlaceQuickSort(left, index-1, orderType)
            self.inPlaceQuickSort(index+1, right, orderType)
        
        def findPivot(left, right):
            return random.randrange(left, right)
        
        def inPlacePartition(self, left, right, k, orderType="Ascending"):
            pivotValue = self.Elements[k]
            self.swap(k, right)
            i = left
            j = right
            while i <= j: 
                if orderType == "Ascending": # 오름차순(Ascending)
                    while i <= j and self.Elements[i] <= pivotValue:
                        i += 1
                    while j >= i and self.Elements[j] >= pivotValue:
                        j += 1
                elif orderType == "Descending": # 내림차순(Descending)
                    while i <= j and self.Elements[i] >= pivotValue:
                        i += 1
                    while j >= i and self.Elements[j] <= pivotValue:
                        j += 1
                else:
                    wrongOrderTypeException()

                if i < j:
                    self.swap(i, j)
            self.swap(i, right)
            return i