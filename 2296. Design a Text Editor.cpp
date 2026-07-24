class TextEditor {
    string left, right;

public:
    TextEditor() {}

    void addText(string text) {
        left += text;
    }

    int deleteText(int k) {
        int cnt = min(k, (int)left.size());
        left.erase(left.size() - cnt);
        return cnt;
    }

    string cursorLeft(int k) {
        while (k-- && !left.empty()) {
            right.push_back(left.back());
            left.pop_back();
        }

        int start = max(0, (int)left.size() - 10);
        return left.substr(start);
    }

    string cursorRight(int k) {
        while (k-- && !right.empty()) {
            left.push_back(right.back());
            right.pop_back();
        }

        int start = max(0, (int)left.size() - 10);
        return left.substr(start);
    }
};