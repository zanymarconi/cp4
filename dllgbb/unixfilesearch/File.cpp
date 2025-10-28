#include "unixfilesearch.h"
using namespace std;

using AttributeValueType = variant<string, long long, bool>;

enum class AttributeType {
    NAME,
    SIZE,
    IS_DIRECTORY
};

class File {
public:
    File(bool isDir, const string& fileName, long long fileSize)
        : isDirectory(isDir), name(fileName), size(fileSize) {}

    void addChild(shared_ptr<File> child) {
        children.push_back(child);
    }

    const string& getName() const {
        return name;
    }

    long long getSize() const {
        return size;
    }

    bool isDir() const {
        return isDirectory;
    }

    const vector<shared_ptr<File>>& getChildren() const {
        return children;
    }

    AttributeValueType extract(AttributeType attrType) const {
        switch (attrType) {
            case AttributeType::NAME:
                return name;
            case AttributeType::SIZE:
                return size;
            case AttributeType::IS_DIRECTORY:
                return isDirectory;
            default:
                throw invalid_argument("Unknown attribute type");
        }
    }
    

private:
    bool isDirectory;
    string name;
    long long size;
    vector<shared_ptr<File>> children;
};