//
// Created by HP User on 12/2/2018.
//

#include "maze_game.hpp"


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

room* maze_game::create_room(maze_factory& factory){
    room* rp = factory.make_room();
    createdRooms.insert(rp);
    return rp;
}

door* maze_game::create_door(maze_factory& factory, room& room1, room& room2){
    door* dp = factory.make_door(room1, room2);
    createdDoors.insert(dp);
    return dp;
}

wall* maze_game::create_wall(maze_factory& factory){
    wall* wp = factory.make_wall();
    createdWalls.insert(wp);
    return wp;
}

maze_game::~maze_game() {
    deleteAll();
}

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

ostream& operator<<(ostream& os, const maze_game& mg){
    os << "Maze Game: ";
    int count = 1;
    os << "Contains " << mg.createdMazes.size() << " mazes." << endl;
    for(auto it = mg.createdMazes.begin(); it != mg.createdMazes.end(); ++it){
        os << "Maze " << count++ << ": " << **it << endl << endl;
    }
    return os;
}