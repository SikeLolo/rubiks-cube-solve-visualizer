#ifndef CUBE_H
#define CUBE_H
#include <iostream>
#include "json.hpp"

class Cube {
    public:
        Cube();
        void turnFace(std::string, int);
        void display();
        //auto getCube();
        nlohmann::json toJson();
    private:
        int side[6][3][3];
};

#endif
