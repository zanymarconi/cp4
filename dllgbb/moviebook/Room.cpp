#include "moviebook.h"
using namespace std;

class Room {
public:
    Room(const string& roomName, shared_ptr<Layout> layout)
        : roomName(roomName), layout(layout) {}

    shared_ptr<Layout> getLayout() const {
        return layout;
    }

    string getRoomName() const {
        return roomName;
    }
private:
    string roomName;
    shared_ptr<Layout> layout;
};