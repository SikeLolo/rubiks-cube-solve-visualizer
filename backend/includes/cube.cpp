#include <iostream>
#include "cube.h"
using namespace std;

Cube::Cube(){
    for(int currentSide=0;currentSide<6;currentSide++){
        for(int col=0;col<3;col++){
            for(int row=0;row<3;row++){
                side[currentSide][col][row]=currentSide;
            }
        }
    }
}
void Cube::display(){
    for(int currentSide=0;currentSide<6;currentSide++){
        for(int col=0;col<3;col++){
            for(int row=0;row<3;row++){
                cout << side[currentSide][col][row] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
   cout<<"Display cube here"<<endl;
}
void Cube::turnFace(string direction, int times){
    for(int iterate=0;iterate<times;iterate++){
        if(direction == "RC"){
            int top = side[0][0][2], mid = side[0][1][2], bot = side[0][2][2];
            side[0][0][2] = side[1][0][2], side[0][1][2] = side[1][1][2], side[0][2][2] = side[1][2][2];
            side[1][0][2] = side[5][0][2], side[1][1][2] = side[5][1][2], side[1][2][2] = side[5][2][2];
            side[5][0][2] = side[3][2][0], side[5][1][2] = side[3][1][0], side[5][2][2] = side[3][0][0];
            side[3][2][0] = top, side[3][1][0] = mid, side[3][0][0] = bot;
            int query = side[2][0][0];
            side[2][0][0] = side[2][2][0];
            side[2][2][0] = side[2][2][2];
            side[2][2][2] = side[2][0][2];
            side[2][0][2] = query;
        }
        else if(direction == "RCC"){
            int top = side[0][0][2], mid = side[0][1][2], bot = side[0][2][2];
            side[0][0][2] = side[3][2][0], side[0][1][2] = side[3][1][0], side[0][2][2] = side[3][0][0];
            side[3][0][0] = side[5][2][2], side[3][1][0] = side[5][1][2], side[3][2][0] = side[5][0][2];
            side[5][0][2] = side[1][0][2], side[5][1][2] = side[1][0][2], side[5][2][2] = side[1][0][2];
            side[1][0][2] = top, side[1][1][2] = mid, side[1][2][2] = bot;
            int query = side[2][0][0];
            side[2][0][0] = side[2][0][2];
            side[2][0][2] = side[2][2][2];
            side[2][2][2] = side[2][0][2];
            side[2][0][2] = query;
        }
    }
}