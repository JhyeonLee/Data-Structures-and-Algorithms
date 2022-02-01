from utils.utils import emptyQueueException


class SequentialPriorityQueue():
    def __init__(self):

        self.keys = []
        self.elements = {}
        self.front = 0
        self.rear = -1
    
    def size(self):
        return len(self.keys)
    
    def isEmpty(self):
        return self.size() == 0
    
    def swap(self, A, B):
        k = self.keys[A]
        self.keys[A] = self.keys[B]
        self.keys[B] = k
    
    def insertItem(self, k, e):
        self.rear += 1
        self.keys[self.rear] = k
        self.elements[k] = e
    
    def minKey(self):
        if self.isEmpty():
            return emptyQueueException()
        
        min = self.keys[0]
        for key, value in self.elements:
            if self.elements[min] > value:
                min = key
        return min

    def removeMin(self):
        if self.isEmpty():
            return emptyQueueException()
        min = self.minKey()
        e = self.elements[min]
        self.swap(min, self.keys[0])
        self.rear -= 1
        return e
    
    def minElement(self):
        if self.isEmpty():
            return emptyQueueException()
        min = self.minKey()
        return self.elements[min]