# Array Lists

class ArrayList():
    def __init__(self):
        # super(ArrayList, self).__init__()
        
        Elements = []
        front = 0
        last = 0

    # 리스트의 크기, 즉 원소 수 반환
    def size(self):
        return self.last
    
    # 리스트가 비어 있는지 여부를 반환
    def isEmpty(self):
        return self.size() == 0
    
    # 원소 전체를 반환
    def elements(self):
        return self.Elements
    
    # 순위 r에 저장된 원소를 반환
    def get(self, r):
        if r < 0:
            raise invalidRankException
        return self.Elements[r]
     
     # 순위 r에 저장된 원소를 e로 대체
    def set(self, r, e):
        if r < 0:
             raise invalidRankException
        self.Elements[r] = e
        return e
    
    # 순위 r 앞에 원소 e를 삽입
    def add(self, r, e):
        if r < 0:
            raise invalidRankException
        self.Elements.insert(r, e)
    
    # 순위 r에 저장된 원소를 삭제하여 반환
    def remove(self, r):
        if self.size() == 0:
            raise emptyListException
        if r < 0:
            raise invalidRankException
        e = self.Elements.pop(r)
        return e

        

class invalidRankException(Exception):
    def __init__(self):
        super().__init__("invalid Rank Exception")
# class fullListException(Exception):
#     def __init__(self):
#         super().__init__("full List Exception")
class emptyListException(Exception):
    def __init__(self):
        super().__init__("empty List Exception")