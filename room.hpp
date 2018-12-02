//
// Created by HP User on 12/1/2018.
//

#ifndef LAB09_MAZE_ROOM_HPP
#define LAB09_MAZE_ROOM_HPP

//#include "door.hpp"
#include <set>
#include <ostream>

using namespace std;

class door;
ostream& operator<<(ostream& os, const door& d);
class room {
protected:
    static int uniqueId;
    int id = uniqueId++;
    virtual void print(ostream& os) const = 0;
    ostream& printAll(ostream& os) const{
        int count = 1;
        os << "Contains " << doors.size() << " doors." << endl;
        for(auto it = doors.begin(); it != doors.end(); ){
            os << "Door " << count++ << ": " << **it;
            if(++it != doors.end()){
                os << endl;
            }
        }
        return os;
    }
public:
    int getId() {return id;}
    set<door*> doors;
    inline bool operator==(const room& other){ return other.id == id; }
    inline bool operator!=(const room& other){ return !(*this == other); }
    friend ostream& operator<<(ostream& os, const room& r){
        r.print(os);
        return os;
    }
    virtual ~room() = default;
};

int room::uniqueId = 0;


#endif //LAB09_MAZE_FACTORY_HPP
