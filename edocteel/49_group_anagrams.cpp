#include <bits/stdc++.h>
using namespace std;

class GroupAnagrams49 {
public:
    vector<vector<string>> groupAnagrams(const vector<string>& strs) {
        map<vector<int>, vector<string>> anagramMap;
        for (string word: strs) {
            vector<int> key(26, 0);
            for (char ch: word)
                key[ch-'a']++;
            anagramMap[key].push_back(word);
        }
        vector<vector<string>> anagrams;
        for (auto [key, words]: anagramMap)
            anagrams.push_back(words);
        return anagrams;
    }
};