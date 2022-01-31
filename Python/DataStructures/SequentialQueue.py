from utils.utils import emptyQueueException

class SequentialQueue():
    def __init__(self):

        self.elements = []
        self.front = 0
        self.rear = -1

    def size(self):
        return self.rear + 1
    
    def isEmpty(self):
        return self.size() == 0

    def enqueue(self, e):
        self.rear += 1
        self.elements.append(e)
    
    def dequeue(self):
        if self.isEmpty():
            return emptyQueueException
        e = self.elements.pop(self.rear)
        self.rear -= 1
        return e