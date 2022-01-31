from utils.utils import emptyStackException

class Sequentialstack():
    def __init__(self):

        self.elements = []
        self.top = -1

    def size(self):
        return self.top + 1
    
    def isEmpty(self):
        return self.top == -1
    
    def top(self):
        if self.isEmpty():
            return emptyStackException
        return self.elements[self.top]
    
    def push(self, e):
        # fullStackException

        self.top += 1
        self.elements[self.top] = e
    
    def pop(self):
        if self.isEmpty():
            return emptyStackException
        self.top -= 1
        return self.elements[self.top + 1]