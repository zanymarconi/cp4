#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "49_group_anagrams.cpp"

TEST_CASE("EmptyList", "[edocteel][49]") {
    GroupAnagrams49 test;
    vector<string> words;

    vector<vector<string>> ans = test.groupAnagrams(words);
    REQUIRE(ans.empty());
}

TEST_CASE("MultipleAnagrams", "[edocteel][49]") {
    GroupAnagrams49 test;
    vector<string> words = { "eat","tea","tan","ate","nat","bat" };
    
    vector<vector<string>> ans = test.groupAnagrams(words);
    REQUIRE(ans.size() == 3);

    sort(ans.begin(), ans.end(), [](const auto& a, const auto& b){
        return a.size() < b.size();
    });
    REQUIRE((ans[0].size() == 1 && ans[1].size() == 2 && ans[2].size() == 3));
    // Words order maintained
    vector<vector<string>> expected = {
        {"bat"},
        {"tan","nat"},
        {"eat","tea","ate"}
    };
    REQUIRE(ans == expected);
}

TEST_CASE("LoadTest", "[edocteel][49]") {
    int maxLength = 100;
    int wordsSize = 1e6;
    vector<string> words;
    srand(time(0));
    for (int i = 0; i < wordsSize; ++i) {
        int wordLength = (rand() % (maxLength-1)) + 1;
        string word;
        for (int j = 0; j < wordLength; ++j) {
            int k = rand() % 26;
            word.push_back('a' + k);
        }
        words.push_back(word);
    }

    GroupAnagrams49 test;
    vector<vector<string>> ans = test.groupAnagrams(words);
    printf("49 Load Test Completed for %d words created %d groups!\n", 
        words.size(), ans.size());
}