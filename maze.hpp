//
// Created by HP User on 12/1/2018.
//

#ifndef LAB09_MAZE_HPP
#define LAB09_MAZE_HPP

#include "room.hpp"
#include "wall.hpp"
#include <set>

using namespace std;

class maze {
protected:
    virtual void print(ostream& os) const = 0;
    ostream& printAll(ostream& os) const{
        int count = 1;
        os << "Contains " << rooms.size() << " rooms." << endl;
        for(auto it = rooms.begin(); it != rooms.end(); ){
            os << "Room " << count++ << ": " << **it;
            if(++it != rooms.end()){
                os << endl;
            }
        }
        return os;
    }
    set<room *> rooms;
    set<door *> doors;
    set<wall *> walls;
public:
    void add(room* r){
        rooms.insert(r);
    }
    void add(door* d){
        doors.insert(d);
    }
    void add(wall* w){
        walls.insert(w);
    }
    friend ostream& operator<<(ostream& os, const maze& m){
        m.print(os);
        return os;
    }
    virtual ~maze() = default;
};


#endif //LAB09_MAZE_FACTORY_HPP
