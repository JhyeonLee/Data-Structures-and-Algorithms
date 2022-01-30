from utils.utils import invalidRankException, emptyListException
from . import SinglyLinkedNode

class SinglyLinkedList():
    def __init__(self):
        self.headNode = SinglyLinkedNode()
        self.tailNode = None
        self.header = None
        self.trailer = SinglyLinkedNode()
        self.headNode.link
