
class SequentialHeap():
    def __init__(self, typeOfOrder):
        self.keys = [0]
        self.elements = {}
        self.n = 0
        self.typeOrOrder = typeOfOrder
    
    def isRoot(self, k):
        return k == self.keys[0]
    
    def parent(self, k):
        try:
            index = self.keys.index(k)
            return self.keys[index/2]          
        except IndexError:
            pass
    
    def isExternal(self, k):
        try:
            index = self.keys.index(k)
            return False         
        except IndexError:
            return True
    def isInternal(self, k):
        try:
            index = self.keys.index(k)
            return True
        except IndexError:
            return False
    
    def leftChild(self, k):
        try:
            index = self.keys.index(k)
        except IndexError:
            return
        index = 2 * index
        if self.isExternal(self.keys[index]):
            return
        return self.keys[index]
    def rightChild(self, k):
        try:
            index = self.keys.index(k)
        except IndexError:
            return
        index = 2 * index + 1
        if self.isExternal(self.keys[index]):
            return
        return self.keys[index]
    
    def swap(self, k1, k2):
        try:
            index1 = self.keys.index(k1)
            index2 = self.keys.index(k2)
        except IndexError:
            return
        self.keys[index1] = k2
        self.keys[index2] = k1
    
    def upHeap_minHeap(self, k):
        if self.isRoot(k):
            return
        parent = self.parent(k)
        if k <= parent:
            return
        self.swap(k, parent)
        self.upHeap_minHeap(parent)
    
    def downHeap_minHeap(self, k):
        leftK = self.leftChild(k)
        rightK = self.rightChild(k)
        if self.isExternal(leftK) and self.isExternal(rightK):
            return
        smaller = leftK
        if self.isInternal(rightK):
            if rightK < smaller:
                smaller = rightK
        if k <= smaller:
            return
        self.swap(k, smaller)
        self.downHeap_minHeap(smaller)

    def insertItem_minHeap(self, k, e):
        self.n += 1
        self.keys.append(k)
        self.elements[k] = e
        self.upHeap_minHeap(k)
    
    def removeMin_minHeap(self):
        k = self.keys[1]
        e = self.elements[k]
        self.keys[1] = self.keys[self.n]
        self.elements[1] = self.elements[self.n]
        self.n -= 1
        self.downHeap_minHeap(self.keys[1])
        return e
    
    def upHeap_maxHeap(self, k):
        if self.isRoot(k):
            return
        parent = self.parent(k)
        if k >= parent:
            return
        self.swap(k, parent)
        self.upHeap_maxHeap(parent)
    
    def downHeap_maxHeap(self, k):
        leftK = self.leftChild(k)
        rightK = self.rightChild(k)
        if self.isExternal(leftK) and self.isExternal(rightK):
            return
        bigger = leftK
        if self.isInternal(rightK):
            if rightK > bigger:
                bigger = rightK
        if k >= bigger:
            return
        self.swap(k, bigger)
        self.downHeap_minHeap(bigger)

    def insertItem_maxHeap(self, k, e):
        self.n += 1
        self.keys.append(k)
        self.elements[k] = e
        self.upHeap_maxHeap(k)
    
    def removeMin_maxHeap(self):
        k = self.keys[1]
        e = self.elements[k]
        self.keys[1] = self.keys[self.n]
        self.elements[1] = self.elements[self.n]
        self.n -= 1
        self.downHeap_maxHeap(self.keys[1])
        return e

    # Build Bottom-Up Sequential Heap
    def recursiveBuildHeap_minHeap(self):
        self.rBuildHeap_minHeap(self.keys[1])
    def rBuildHeap_minHeap(self, k):
        try:
            index = self.keys.index(k)     
        except IndexError:
            return
        leftK = self.leftChild(k)
        self.rBuildHeap_minHeap(leftK)
        rightK = self.rightChild(k)
        self.rBuildHeap_minHeap(rightK)
        self.downHeap_minHeap(k)
    
    def nonRecursiveBuildHeap_minHeap(self):
        for i in range(self.N / 2, 0, -1):
            self.downHeap_minHeap(self.keys[i])
    
    def recursiveBuildHeap_maxHeap(self):
        self.rBuildHeap_maxHeap(self.keys[1])
    def rBuildHeap_maxHeap(self, k):
        try:
            index = self.keys.index(k)     
        except IndexError:
            return
        leftK = self.leftChild(k)
        self.rBuildHeap_maxHeap(leftK)
        rightK = self.rightChild(k)
        self.rBuildHeap_maxHeap(rightK)
        self.downHeap_maxHeap(k)
    
    def nonRecursiveBuildHeap_maxHeap(self):
        for i in range(self.N / 2, 1, -1):
            self.downHeap_maxHeap(self.keys[i])