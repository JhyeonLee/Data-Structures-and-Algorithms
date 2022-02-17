from DataStructures.ArrayLists import ArrayList
from utils.utils import noSuchKey

# 정렬이 되어있을 경우
class FindIndex_recursive(ArrayList):
        def __init__(self):
            super(FindIndex_recursive, self).__init__()
        
        def FindIndex_recursive(self, k):
            if k < self.Elements[0] or self.Elements[self.size()-1] < k:
                noSuchKey()
            
            return self.rFindIndex(self, k, 0, self.size())
        def rFindIndex(self, k, left, right):
            if left > right:
                noSuchKey()
            
            mid = (left + right) / 2
            if k == self.Elements[mid]:
                return mid
            elif k < self.Elements[mid]:
                return self.rFindIndex(k, left, mid-1)
            else:  # k > self.Elements[mid]
                return self.rFindIndex(k, mid+1, right)
        
        def FindIndex_nonRecursive(self, k):
            left = 0
            right = self.size()
            if k < self.Elements[0] or self.Elements[self.size()-1] < k:
                noSuchKey()
            while 1:
                if left > right:
                    noSuchKey()
                
                mid = (left + right) / 2
                if k == self.Elements[mid]:
                    return mid
                elif k < self.Elements[mid]:
                    right = mid - 1
                else:  # k > self.Elements[mid]
                    left = mid + 1
