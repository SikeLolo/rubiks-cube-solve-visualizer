#ifndef CUBE_H
#define CUBE_H
#include <iostream>

class Cube {
    public:
        Cube();
        void turnFace(std::string, int);
        void display();
    private:
        int side[6][3][3];
};

#endif
