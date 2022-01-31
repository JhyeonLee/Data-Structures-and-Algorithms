from utils.utils import emptyDequeException

class SequentialDeque():
    def __init__(self):

        self.elements = []
        self.front = 0
        self.rear = -1

    def size(self):
        return self.rear + 1
    
    def isEmpty(self):
        return self.size() == 0

    def push(self, e):
        self.rear += 1
        self.elements.insert(0, e)
    
    def pop(self):
        if self.isEmpty():
            return emptyDequeException
        e = self.elements.pop(0)
        self.rear -= 1
        return e
    
    def inject(self, e):
        self.rear += 1
        self.elements.append(e)
    
    def eject(self):
        if self.isEmpty():
            return emptyDequeException
        e = self.elements.pop(self.rear)
        self.rear -= 1
        return e