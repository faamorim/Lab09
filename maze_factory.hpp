//
// Created by HP User on 12/1/2018.
//

#ifndef LAB09_MAZE_FACTORY_HPP
#define LAB09_MAZE_FACTORY_HPP

#include "maze.hpp"
#include "room.hpp"
#include "wall.hpp"
#include "door.hpp"

class maze_factory {
public:
    virtual maze* make_maze() const = 0;
    virtual room* make_room() const = 0;
    virtual wall* make_wall() const = 0;
    virtual door* make_door(room& room1, room& room2) const = 0;
};


#endif //LAB09_MAZE_FACTORY_HPP

