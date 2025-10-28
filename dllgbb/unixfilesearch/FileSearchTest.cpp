#include "unixfilesearch.h"
using namespace std;

class FileSearchTest : public FileSearch {
public:
    void runTests() {
        // Create a root directory and two files with different owners
        shared_ptr<File> a = make_shared<File>(true, "a", 0);
        shared_ptr<File> aa = make_shared<File>(false, "aa", 2000);
        shared_ptr<File> ab = make_shared<File>(true, "ab", 0);
        shared_ptr<File> aba = make_shared<File>(false, "aba", 3000);
        shared_ptr<File> abb = make_shared<File>(false, "abb", 4000);

        // Add files to the root directory
        a->addChild(aa);
        a->addChild(ab);
        ab->addChild(aba);
        ab->addChild(abb);

        // Search criteria: Find non-directory file names matching ".*a.*"
        shared_ptr<SimplePredicate<string>> namePredicate = make_shared<SimplePredicate<string>>(
            AttributeType::NAME,
            make_shared<RegexMatchOperator<string>>(),
            std::string(".*a.*")
        );
        shared_ptr<SimplePredicate<bool>> typePredicate = make_shared<SimplePredicate<bool>>(
            AttributeType::IS_DIRECTORY, 
            make_shared<EqualsOperator<bool>>(),
            false
        );
        shared_ptr<CompositePredicate> compositePredicate = make_shared<AndPredicate>(
            vector<shared_ptr<Predicate>>{namePredicate, typePredicate}
        );
        shared_ptr<FileSearchCriteria> criteria = make_shared<FileSearchCriteria>(compositePredicate);

        // Execute the search and get results
        shared_ptr<FileSearch> fileSearch = make_shared<FileSearch>();
        vector<shared_ptr<File>> result = fileSearch->search(a, criteria);

        // Debug output of matched file names
        for (const auto& file : result) {
            printf("Matched File: %s\n", file->getName().c_str());
        }

        // Verify that only one file matches the criteria
        assert(3 == result.size());
        
        // Verify that the matching file are "aa", "aba" and "abb"
        set<string> actualNames;
        for (const auto& file : result) {
            actualNames.insert(file->getName());    
        }
        set<string> expectedNames = {"aa", "aba", "abb"};
        assert(actualNames == expectedNames);

        printf("All tests passed!\n");
    }
};

int main() {
    FileSearchTest test;
    test.runTests();
    return 0;
}