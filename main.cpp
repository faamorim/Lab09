#include <iostream>
#include "maze_game.cpp"
#include "futuristic_dystopian_maze.cpp"
#include "enchanted_faery_land.cpp"

int main() {
    maze_game game;
    futuristic_dystopian_maze_factory fdmf;
    enchanted_faery_land_factory eflf;
    game.create_maze(fdmf);
    game.create_maze(eflf);

    cout << game;
    return 0;
}