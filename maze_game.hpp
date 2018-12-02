//
// Created by HP User on 12/2/2018.
//

#ifndef LAB09_MAZE_GAME_HPP
#define LAB09_MAZE_GAME_HPP

#include <iostream>
#include "maze_factory.hpp"

class maze_game {
    set<maze *> createdMazes;
    set<room *> createdRooms;
    set<door *> createdDoors;
    set<wall *> createdWalls;
    room* create_room(maze_factory& factory);
    door* create_door(maze_factory& factory, room& room1, room& room2);
    wall* create_wall(maze_factory& factory);
    void deleteAll();
public:
    maze_game() = default;
    maze* create_maze(maze_factory& factory);
    friend ostream& operator<<(ostream& os, const maze_game& mg);
    ~maze_game();
};


#endif //LAB09_MAZE_GAME_HPP
