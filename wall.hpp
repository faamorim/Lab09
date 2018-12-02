//
// Created by HP User on 12/1/2018.
//

#ifndef LAB09_MAZE_WALL_HPP
#define LAB09_MAZE_WALL_HPP

#include <ostream>

using namespace std;

class wall {
protected:
    virtual void print(ostream& os) const = 0;
public:
    friend ostream& operator<<(ostream& os, const wall& w){
        w.print(os);
        return os;
    }
    virtual ~wall() = default;
};


#endif //LAB09_MAZE_FACTORY_HPP
