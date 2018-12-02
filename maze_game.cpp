//
// Created by HP User on 12/2/2018.
//

#include "maze_game.hpp"

// Returns a pointer to a maze created based on a given maze factory.
maze* maze_game::create_maze(maze_factory& factory){
    maze* mp = factory.make_maze();
    createdMazes.insert(mp);
    room* r1 = create_room(factory);
    room* r2 = create_room(factory);
    mp->add(r1);
    mp->add(r2);
    door* d1 = create_door(factory, *r1, *r2);
    mp->add(r2);
    return mp;
}

// Returns a pointer to a room created based on a given maze factory, and stores the pointer for later delete.
room* maze_game::create_room(maze_factory& factory){
    room* rp = factory.make_room();
    createdRooms.insert(rp);
    return rp;
}

// Returns a pointer to a door created based on a given maze factory, and stores the pointer for later delete.
door* maze_game::create_door(maze_factory& factory, room& room1, room& room2){
    door* dp = factory.make_door(room1, room2);
    createdDoors.insert(dp);
    return dp;
}

// Returns a pointer to a wall created based on a given maze factory, and stores the pointer for later delete.
wall* maze_game::create_wall(maze_factory& factory){
    wall* wp = factory.make_wall();
    createdWalls.insert(wp);
    return wp;
}

// Destructor that calls deleteAll()
maze_game::~maze_game() {
    deleteAll();
}

// Method that frees all the memory and deletes the pointers used for the mazes, rooms, walls and doors.
void maze_game::deleteAll() {
    for(auto it = createdMazes.begin(); it != createdMazes.end(); ){
        delete *it;
        it = createdMazes.erase(it);
    }
    for(auto it = createdRooms.begin(); it != createdRooms.end(); ){
        delete *it;
        it = createdRooms.erase(it);
    }
    for(auto it = createdDoors.begin(); it != createdDoors.end(); ){
        delete *it;
        it = createdDoors.erase(it);
    }
    for(auto it = createdWalls.begin(); it != createdWalls.end(); ){
        delete *it;
        it = createdWalls.erase(it);
    }
}

// Prints the Game to the output string.
ostream& operator<<(ostream& os, const maze_game& mg){
    os << "Maze Game: ";
    int count = 1;
    os << "Contains " << mg.createdMazes.size() << " mazes." << endl;
    for(auto it = mg.createdMazes.begin(); it != mg.createdMazes.end(); ++it){
        os << "Maze " << count++ << ": " << **it << endl << endl;
    }
    return os;
}