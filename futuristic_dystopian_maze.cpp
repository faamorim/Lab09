//
// Created by HP User on 12/2/2018.
//

#include "futuristic_dystopian_maze.hpp"
maze* futuristic_dystopian_maze_factory::make_maze() const {
    return new futuristic_dystopian_maze();
}
room* futuristic_dystopian_maze_factory::make_room() const {
    return new futuristic_dystopian_room();
}
wall* futuristic_dystopian_maze_factory::make_wall() const {
    return new futuristic_dystopian_wall();
}
door* futuristic_dystopian_maze_factory::make_door(room& room1, room& room2) const {
    return new futuristic_dystopian_door(room1, room2);
}


void futuristic_dystopian_maze::print(ostream& os) const{
    os << "A maze in a dehumanized and unpleasant futuristic world." << endl;
    printAll(os);
}
void futuristic_dystopian_room::print(ostream& os) const{
    os << "A futuristic room characterized by human misery." << endl;
    printAll(os);
}
void futuristic_dystopian_wall::print(ostream& os) const{
    os << "A wall that is as futuristic as frightening.";
}
void futuristic_dystopian_door::print(ostream& os) const{
    os << "A futuristic door to an undesirable place. Is it even worth entering?";
}

