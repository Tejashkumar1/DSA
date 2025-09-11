class Solution {
public:
    int m, n;
    vector<vector<int>> del{{-1,0},{0,1},{1,0},{0,-1}};

    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int pos) {
        if(pos == word.size()) return true;
        if(r<0 || r>=m || c<0 || c>=n || board[r][c] != word[pos]) return false;

        char temp = board[r][c];
        board[r][c] = '#'; // mark visited

        for(auto &d : del){
            if(dfs(board, word, r+d[0], c+d[1], pos+1))
                return true;
        }

        board[r][c] = temp; // backtrack
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        // Early check: impossible to form word
        unordered_map<char,int> freqWord, freqBoard;
        for(char c : word) freqWord[c]++;
        for(auto &row : board) for(char c : row) freqBoard[c]++;
        for(auto &[c,f] : freqWord) if(freqBoard[c]<f) return false;

        // Optional: reverse word if last char rarer
        if(freqBoard[word[0]] > freqBoard[word.back()])
            reverse(word.begin(), word.end());

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(board[i][j] == word[0] && dfs(board, word, i, j, 0))
                    return true;

        return false;
    }
};