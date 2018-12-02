//
// Created by HP User on 12/2/2018.
//

#include "enchanted_faery_land.hpp"
maze* enchanted_faery_land_factory::make_maze() const {
    return new enchanted_faery_land();
}
room* enchanted_faery_land_factory::make_room() const {
    return new enchanted_faery_room();
}
wall* enchanted_faery_land_factory::make_wall() const {
    return new enchanted_faery_wall();
}
door* enchanted_faery_land_factory::make_door(room& room1, room& room2) const {
    return new enchanted_faery_door(room1, room2);
}


void enchanted_faery_land::print(ostream& os) const{
    os << "An enchanted land of mystery, wonders, magic and fantastic beasts." << endl;
    printAll(os);
}
void enchanted_faery_room::print(ostream& os) const{
    os << "An enchanted room, full of magic energies." << endl;
    printAll(os);
}
void enchanted_faery_wall::print(ostream& os) const{
    os << "A mystical wall. Not even magic can cross this wall.";
}
void enchanted_faery_door::print(ostream& os) const{
    os << "A magical door to a mysterious place. What wonders may lie ahead?";
}


