class invalidRankException(Exception):
    def __init__(self):
        super().__init__("invalid Rank Exception")
# class fullListException(Exception):
#     def __init__(self):
#         super().__init__("full List Exception")
class emptyListException(Exception):
    def __init__(self):
        super().__init__("empty List Exception")

class emptyStackException(Exception):
    def __init__(self):
        super().__init__("empty Stack Exception")
class emptyQueueException(Exception):
    def __init__(self):
        super().__init__("empty Queue Exception")
class emptyDequeException(Exception):
    def __init__(self):
        super().__init__("empty Deque Exception")
class wrongOrderTypeException(Exception):
    def __init__(self):
        super().__init__("wrong OrderType Exception")
class noSuchKey(Exception):
    def __init__(self):
        super().__init__("no Such Key")