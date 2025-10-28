#include "unixfilesearch.h"
using namespace std;

class FileSearch {
public:
    vector<shared_ptr<File>> search(const shared_ptr<File>& root, const shared_ptr<FileSearchCriteria>& criteria) {
        vector<shared_ptr<File>> result;
        function<void(const shared_ptr<File>&)> dfs = [&](const shared_ptr<File>& current) {
            if (criteria->matches(current)) {
                result.push_back(current);
            }
            for (const auto& child : current->getChildren()) {
                dfs(child);
            }
        };
        dfs(root);
        return result;
    }
};