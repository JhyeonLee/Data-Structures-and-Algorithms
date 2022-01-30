class invalidRankException(Exception):
    def __init__(self):
        super().__init__("invalid Rank Exception")
# class fullListException(Exception):
#     def __init__(self):
#         super().__init__("full List Exception")
class emptyListException(Exception):
    def __init__(self):
        super().__init__("empty List Exception")