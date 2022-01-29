typedef struct SinglyLinkedNode {
    int element;
    struct SinglyLinkedNode* link;
} SinglyLinkedNode;

typedef struct DoublyLinkedNode {
    int element;
    struct DoublyLinkedNode* nextlink;
    struct DoublyLinkedNode* previouslink;
} DoublyLinkedNode;

typedef struct SinglyLinkedList {
    SinglyLinkedNode* headNode;
    SinglyLinkedNode* tailNode;
    SinglyLinkedNode* header;
    SinglyLinkedNode* trailer;
} SinglyLinkedList;

typedef struct DoublyLinkedList {
    DoublyLinkedNode* headNode;
    DoublyLinkedNode* tailNode;
    DoublyLinkedNode* header;
    DoublyLinkedNode* trailer;
} DoublyLinkedList;