from DataStructures.ArrayLists import ArrayList

class MergeSort(ArrayList):
        def __init__(self):
            super(MergeSort, self).__init__()

        # orderType: 오름차순(Ascending), 내림차순(Descending)
        def MergeSort(self, orderType="Ascending"):
            self.rMergeSort(self.front, self.last, orderType)

        def rMergeSort(self, left, right, orderType="Ascending"):
            if left < right :
                m = (left + right) // 2
                self.rMergeSort(left, m, orderType)
                self.rMergeSort(m, right, orderType)
                self.merge(left, m, right, orderType)
        
        def merge(self, left, middle, right, orderType="Ascending"):
            i = left
            k = left
            j = middle
            B = ArrayList()
            while i <= middle and j <= right :
                # 오름차순(Ascending)
                if orderType == "Ascending":
                    if self.Elements[i] <= self.Elements[j] :
                        B.addLast(self.Elements[i])
                        k += 1
                        i + 1
                    else:
                        B.addLast(self.Elements[j])
                        k += 1
                        j + 1
                # 내림차순(Descending)
                elif orderType == "Descending": 
                    if self.Elements[i] >= self.Elements[j] :
                        B.addLast(self.Elements[i])
                        k += 1
                        i + 1
                    else:
                        B.addLast(self.Elements[j])
                        k += 1
                        j + 1
                else:
                    return
            while i <= middle:
                B.addLast(self.Elements[i])
                k += 1
                i += 1
            while j <= middle:
                B.addLast(self.Elements[j])
                k += 1
                j += 1
            for k in range(left, B.size()):
                e = B.removeFirst()
                self.Elements[k] = e