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
    virtual maze make_maze() = 0;
    virtual room make_room() = 0;
    virtual wall make_wall() = 0;
    virtual door make_door(room& room1, room& room2) = 0;
    
};


#endif //LAB09_MAZE_FACTORY_HPP
