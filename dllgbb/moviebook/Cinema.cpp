#include "moviebook.h"
using namespace std;

class Cinema {
public:
    Cinema(const string& name) : name(name) {}

    void addRoom(shared_ptr<Room> room) {
        rooms.push_back(room);
    }

    shared_ptr<Room> getRoom(const string& roomName) const {
        for (const auto& room : rooms) {
            if (room->getRoomName() == roomName) {
                return room;
            }
        }
        return nullptr; // Room not found
    }

    string getName() const {
        return name;
    }
    
private:
    string name;
    vector<shared_ptr<Room>> rooms;
};