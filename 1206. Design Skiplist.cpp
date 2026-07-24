class Skiplist {
    struct Node {
        int val;
        vector<Node*> next;

        Node(int v, int level)
            : val(v), next(level, nullptr) {}
    };

    static const int MAX_LEVEL = 16;

    Node* head;

    int randomLevel() {
        int lvl = 1;
        while ((rand() & 1) && lvl < MAX_LEVEL)
            lvl++;
        return lvl;
    }

public:
    Skiplist() {
        head = new Node(-1, MAX_LEVEL);
    }

    bool search(int target) {
        Node* cur = head;

        for (int lvl = MAX_LEVEL - 1; lvl >= 0; lvl--) {
            while (cur->next[lvl] &&
                   cur->next[lvl]->val < target)
                cur = cur->next[lvl];
        }

        cur = cur->next[0];

        return cur && cur->val == target;
    }

    void add(int num) {
        vector<Node*> update(MAX_LEVEL);

        Node* cur = head;

        for (int lvl = MAX_LEVEL - 1; lvl >= 0; lvl--) {
            while (cur->next[lvl] &&
                   cur->next[lvl]->val < num)
                cur = cur->next[lvl];

            update[lvl] = cur;
        }

        int lvl = randomLevel();

        Node* node = new Node(num, lvl);

        for (int i = 0; i < lvl; i++) {
            node->next[i] = update[i]->next[i];
            update[i]->next[i] = node;
        }
    }

    bool erase(int num) {
        vector<Node*> update(MAX_LEVEL);

        Node* cur = head;

        for (int lvl = MAX_LEVEL - 1; lvl >= 0; lvl--) {
            while (cur->next[lvl] &&
                   cur->next[lvl]->val < num)
                cur = cur->next[lvl];

            update[lvl] = cur;
        }

        cur = cur->next[0];

        if (!cur || cur->val != num)
            return false;

        for (int i = 0; i < cur->next.size(); i++) {
            update[i]->next[i] = cur->next[i];
        }

        delete cur;
        return true;
    }
};