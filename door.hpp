//
// Created by HP User on 12/1/2018.
//

#ifndef LAB09_MAZE_DOOR_HPP
#define LAB09_MAZE_DOOR_HPP

#include <set>
#include "room.hpp"
#include <ostream>

using namespace std;

class door {
protected:
    virtual void print(ostream& os) const = 0;
public:
    set<room *> rooms;
    door(room& room1, room& room2){
        rooms.insert(&room1);
        rooms.insert(&room2);
        room1.doors.insert(this);
        room2.doors.insert(this);
    }
    friend ostream& operator<<(ostream& os, const door& d){
        d.print(os);
        return os;
    }
    virtual ~door() = default;
};


#endif //LAB09_MAZE_FACTORY_HPP
