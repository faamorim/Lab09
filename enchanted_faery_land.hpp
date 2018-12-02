//
// Created by HP User on 12/2/2018.
//

#ifndef LAB09_ENCHANTED_FAERY_LAND_HPP
#define LAB09_ENCHANTED_FAERY_LAND_HPP

#include "maze_factory.hpp"


class enchanted_faery_land_factory : public maze_factory{
    maze* make_maze() const override;
    room* make_room() const override;
    wall* make_wall() const override;
    door* make_door(room& room1, room& room2) const override;
};

class enchanted_faery_land : public maze {
public:
    void print(ostream& os) const override;
};

class enchanted_faery_room : public room {
protected:
    void print(ostream& os) const override;
};

class enchanted_faery_wall : public wall {
public:
    void print(ostream& os) const override;
};

class enchanted_faery_door : public door {
public:
    enchanted_faery_door(room& room1, room& room2) : door(room1, room2) {};
    void print(ostream& os) const override;
};



#endif //LAB09_ENCHANTED_FAERY_LAND_HPP
