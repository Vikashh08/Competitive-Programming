class TrieNode {
public:
    TrieNode* children[26];
    string word;

    TrieNode() {
        word = "";
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();
    vector<string> ans;

    void insert(string word) {
        TrieNode* node = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (!node->children[idx])
                node->children[idx] = new TrieNode();

            node = node->children[idx];
        }

        node->word = word;
    }

    void dfs(vector<vector<char>>& board,
             int i, int j,
             TrieNode* node) {

        char ch = board[i][j];

        if (ch == '#' || node->children[ch - 'a'] == nullptr)
            return;

        node = node->children[ch - 'a'];

        if (!node->word.empty()) {
            ans.push_back(node->word);
            node->word = "";   // avoid duplicates
        }

        board[i][j] = '#';

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x >= 0 && x < board.size() &&
                y >= 0 && y < board[0].size()) {

                dfs(board, x, y, node);
            }
        }

        board[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        for (string &w : words)
            insert(w);

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root);
            }
        }

        return ans;
    }
};