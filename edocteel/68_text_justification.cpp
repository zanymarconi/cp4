#include <bits/stdc++.h>
using namespace std;

class TextJustification68 {
private:
    int maxWidth;
    vector<string> words;
    vector<string> justified;

    string justifyFromTo(int start, int end) {
        int totalLength = 0;
        for (int i = start; i < end; ++i) {
            totalLength += words[i].size();
        }

        // special case, single word
        if (end == start + 1) {
            string line = words[start];
            line.append(maxWidth - line.size(), ' ');
            return line;
        }

        // special case, last line would be left justified
        if (end == words.size()) {
            string line = "";
            for (int i = start; i < end; ++i)
                line += words[i] + " ";
            line.pop_back(); // remove last space
            line.append(maxWidth - line.size(), ' ');
            return line; 
        }

        int wordsCount = end - start;
        int spacesRequired = maxWidth - totalLength;
        int evenSpaces = spacesRequired / (wordsCount-1);
        int leftOver = spacesRequired % (wordsCount-1);
        string line = ""; 
        for (int i = start; i < end; ++i) {
            if (i == end-1) {
                line += words[i];
                break;
            }
            line += words[i];
            line.append(evenSpaces, ' ');
            if (leftOver > 0) line.push_back(' '), --leftOver;
        }
        return line;
    }

    pair<string, int> justifyFromIndex(int index) {
        int curr = index;
        int length = 0;
        while (curr < words.size()) {
            int wsize = words[curr].size();
            if (length + wsize > maxWidth) 
                break;
            curr++;
            length += wsize + 1; // add extra space
        }
        if (curr == index) {
            string message = "Invalid input, word " + words[curr] + " (" + to_string(words[curr].size()) + 
                             ") larger than maxWidth " + to_string(maxWidth) + "\n";
            throw invalid_argument(message);
        }

        string line = justifyFromTo(index, curr);
        return {line, curr};
    }

    vector<string> justify() {
        int wordCounter = 0;
        do {
            pair<string, int> lineIndexPair = justifyFromIndex(wordCounter);
            justified.push_back(lineIndexPair.first);
            wordCounter = lineIndexPair.second;
        } while (wordCounter < words.size());

        return justified;
    }

public:
    vector<string> fullyJustify(const vector<string>& words, int maxWidth) {
        if (words.empty()) {
            string line = "";
            line.append(maxWidth, ' ');
            justified.push_back(line);
            return justified;
        }

        this->maxWidth = maxWidth;
        this->words = words;
        justified.clear();

        return justify();
    }
};