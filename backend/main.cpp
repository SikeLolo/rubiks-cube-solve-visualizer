#include <iostream>
#include "includes/cube.h"
using namespace std;

int main(){
    Cube cube;
    cube.turnFace("RCC", 1);
    cube.display();
    cube.turnFace("RC", 1);
    cube.turnFace("RCC", 2);
    cube.display();
    return 0;
}
