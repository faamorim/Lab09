//
// Created by HP User on 12/2/2018.
//

#ifndef LAB09_FUTURISTIC_DYSTOPIAN_MAZE_HPP
#define LAB09_FUTURISTIC_DYSTOPIAN_MAZE_HPP

#include "maze_factory.hpp"


class futuristic_dystopian_maze_factory : public maze_factory{
    maze* make_maze() const override;
    room* make_room() const override;
    wall* make_wall() const override;
    door* make_door(room& room1, room& room2) const override;
};

class futuristic_dystopian_maze : public maze {
public:
    void print(ostream& os) const override;
};

class futuristic_dystopian_room : public room {
protected:
    void print(ostream& os) const override;
};

class futuristic_dystopian_wall : public wall {
public:
    void print(ostream& os) const override;
};

class futuristic_dystopian_door : public door {
public:
    futuristic_dystopian_door(room& room1, room& room2) : door(room1, room2) {};
    void print(ostream& os) const override;
};



#endif //LAB09_FUTURISTIC_DYSTOPIAN_MAZE_HPP
