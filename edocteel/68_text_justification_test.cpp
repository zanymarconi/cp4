#include "68_text_justification.cpp"
using namespace std;

class TextJustification68Test: public TextJustification68 {

public:
    void runTests() {
        vector<pair<vector<string>, int>> cases = {
            { {}, 10}, // empty words
            { {"This", "is", "an", "example", "of", "text", "justification."}, 16},
            { {"What","must","be","acknowledgment","shall","be"}, 16},
            { {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"}, 20}
        };
        int tc = 0;
        for (auto [words, maxWidth]: cases) {
            printf("Test Case: %d\n", ++tc);
            vector<string> justifiedText = 
                fullyJustify(words, maxWidth);
            printf("Output:\n");
            for (auto line: justifiedText) {
                printf("\"%s\"\n", line.c_str());
                assert(line.size() == maxWidth);
            }
            printf("\n");   
        }
    }

    void invalidInputTest() {
        vector<string> words = {"Thiswordiswaytoolongtobejustified"};
        int maxWidth = 10;
        
        bool exceptionThrown = false;
        try {
            fullyJustify(words, maxWidth);
        } catch (const invalid_argument& e) {
            exceptionThrown = true;
            printf("Caught expected exception: %s\n", e.what());
        } catch (const std::exception& e) {
            printf("Caught unexpected exception: %s\n", e.what());
            assert(false);
        }
        assert(exceptionThrown && "expected fullyJustify to throw for invalid input");
    }
};

int main() {
    TextJustification68Test test;
    test.runTests();
    test.invalidInputTest();
    return 0;
}
