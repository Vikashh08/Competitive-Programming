class MyLinkedList {
public:
    struct Node {
        int val;
        Node* next;

        Node(int x) {
            val = x;
            next = nullptr;
        }
    };

    Node* dummy;
    int sz;

    MyLinkedList() {
        dummy = new Node(0);
        sz = 0;
    }

    int get(int index) {
        if (index < 0 || index >= sz)
            return -1;

        Node* curr = dummy->next;

        while (index--)
            curr = curr->next;

        return curr->val;
    }

    void addAtHead(int val) {
        Node* node = new Node(val);
        node->next = dummy->next;
        dummy->next = node;
        sz++;
    }

    void addAtTail(int val) {
        Node* curr = dummy;

        while (curr->next)
            curr = curr->next;

        curr->next = new Node(val);
        sz++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > sz)
            return;

        Node* prev = dummy;

        while (index--)
            prev = prev->next;

        Node* node = new Node(val);
        node->next = prev->next;
        prev->next = node;

        sz++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= sz)
            return;

        Node* prev = dummy;

        while (index--)
            prev = prev->next;

        Node* temp = prev->next;
        prev->next = temp->next;
        delete temp;

        sz--;
    }
};