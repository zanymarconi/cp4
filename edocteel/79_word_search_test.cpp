#include "79_word_search.cpp"
using namespace std;

class WordSearch79Test: public WordSearch79 {
private: 
    string cases = R"(
            3 4
            A B C E
            S F C S
            A D E E
            ABCCED
            true
            3 4
            A B C E
            S F C S
            A D E E
            SEE
            true
            3 4
            A B C E
            S F C S
            A D E E
            ABCB
            false
            1 1
            A
            B
            false
        )";
public:
    void runTests() {
        int tc = 0;
        stringstream ss(cases);
        ss >> boolalpha; // Enable reading "true"/"false" as booleans

        int row, col;
        vector<vector<char>> board;
        string word;
        bool expected;
        while (ss >> row >> col) {
            board.assign(row, vector<char>(col, ' '));
            for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                ss >> board[i][j];
            ss >> word;
            ss >> expected;
            // printf ("\t Debug: Mat %dx%d Word = %s Expected = %d WordSearch %d\n", board.size(), board[0].size(), word.c_str(), expected, wordSearch(board, word));
            printf("Test Case %d: %s\n", ++tc, wordSearch(board, word) == expected? "PASS": "FAIL");
        }
    }
};

int main() {
    WordSearch79Test test;
    test.runTests();
    return 0;
}