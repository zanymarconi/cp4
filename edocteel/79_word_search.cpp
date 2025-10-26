#include <bits/stdc++.h>
using namespace std;

class WordSearch79 {
private:
    int N, M;
    optional<reference_wrapper<const vector<vector<char>>>> mat;
    string word;

    vector<vector<int>> visited;
    bool found;

    vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    bool isValid(int x, int y) {
        return x >=0 && x < N && y >=0 && y < M;
    }

    void backtrack(int index, int r, int c) {
        if (index == word.size()) {
            found = true; return;
        }
        if (found) return;
        for (int i = 0; i < 4; ++i) {
            int x = r + dir[i][0], y = c + dir[i][1];
            if (!isValid(x, y)) continue;
            if (visited[x][y]) continue;
            if (word[index] != mat->get()[x][y]) continue;
            visited[x][y] = 1;
            backtrack(index + 1, x, y);
            visited[x][y] = 0;
        }
    }

public:
    bool wordSearch(const vector<vector<char>>& board, string word) {
        if (word.empty()) return true;

        mat = cref(board);
        N = mat->get().size();
        M = mat->get()[0].size();
        this->word = word;

        visited.assign(N, vector<int>(M, 0));
        found = false;
        for (int i = 0; i < N && !found; ++i)
        for (int j = 0; j < M && !found; ++j) {
            if (mat->get()[i][j] == word[0]) {
                visited[i][j] = 1;
                backtrack(1, i, j);
                visited[i][j] = 0;
            }
        }
        return found;
    }
};