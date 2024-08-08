#include <iostream>
#include "cube.h"
#include "json.hpp"
using namespace std;
using json = nlohmann::json;

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
            int buffer = side[2][0][0];
            side[2][0][0] = side[2][2][0];
            side[2][2][0] = side[2][2][2];
            side[2][2][2] = side[2][0][2];
            side[2][0][2] = buffer;
            buffer = side[2][0][1];
            side[2][0][1] = side[2][1][0];
            side[2][1][0] = side[2][2][1];
            side[2][2][1] = side[2][1][2];
            side[2][1][2] = buffer;
        }
        else if(direction == "RCC"){
            int top = side[0][0][2], mid = side[0][1][2], bot = side[0][2][2];
            side[0][0][2] = side[3][2][0], side[0][1][2] = side[3][1][0], side[0][2][2] = side[3][0][0];
            side[3][0][0] = side[5][2][2], side[3][1][0] = side[5][1][2], side[3][2][0] = side[5][0][2];
            side[5][0][2] = side[1][0][2], side[5][1][2] = side[1][1][2], side[5][2][2] = side[1][2][2];
            side[1][0][2] = top, side[1][1][2] = mid, side[1][2][2] = bot;
            int buffer = side[2][0][0];
            side[2][0][0] = side[2][0][2];
            side[2][0][2] = side[2][2][2];
            side[2][2][2] = side[2][2][0];
            side[2][2][0] = buffer;
            buffer = side[2][0][1];
            side[2][0][1] = side[2][1][2];
            side[2][1][2] = side[2][2][1];
            side[2][2][1] = side[2][1][0];
            side[2][1][0] = buffer;
        }
        else if(direction == "LC"){
            int top = side[0][0][0], mid = side[0][1][0], bot = side[0][2][0];
            side[0][0][0] = side[3][2][2], side[0][1][0] = side[3][1][2], side[0][2][0] = side[3][0][2];
            side[3][0][2] = side[5][2][0], side[3][1][2] = side[5][1][0], side[3][2][2] = side[5][0][0];
            side[5][0][0] = side[1][0][0], side[5][1][0] = side[1][1][0], side[5][2][0] = side[1][2][0];
            side[1][0][0] = top, side[1][1][0] = mid, side[1][2][0] = bot;
            int buffer = side[4][0][0];
            side[4][0][0] = side[4][2][0];
            side[4][2][0] = side[4][2][2];
            side[4][2][2] = side[4][0][2];
            side[4][0][2] = buffer;
            buffer = side[4][0][1];
            side[4][0][1] = side[4][1][0];
            side[4][1][0] = side[4][2][1];
            side[4][2][1] = side[4][1][2];
            side[4][1][2] = buffer;
        }
        else if(direction == "LCC"){
            int top = side[0][0][0], mid = side[0][1][0], bot = side[0][2][0];
            side[0][0][0] = side[1][0][0], side[0][1][0] = side[1][1][0], side[0][2][0] = side[1][2][0];
            side[1][0][0] = side[5][0][0], side[1][1][0] = side[5][1][0], side[1][2][0] = side[5][2][0];
            side[5][0][0] = side[3][2][2], side[5][1][0] = side[3][1][2], side[5][2][0] = side[3][0][2];
            side[3][0][2] = bot, side[3][1][2] = mid, side[3][2][2] = top;
            int buffer = side[4][0][0];
            side[4][0][0] = side[4][0][2];
            side[4][0][2] = side[4][2][2];
            side[4][2][2] = side[4][2][0];
            side[4][2][0] = buffer;
            buffer = side[4][0][1];
            side[4][0][1] = side[4][1][2];
            side[4][1][2] = side[4][2][1];
            side[4][2][1] = side[4][1][0];
            side[4][1][0] = buffer;
        }
        else if(direction == "UC"){
            int left=side[1][0][0], mid=side[1][0][1], right=side[1][0][2];
            for(int firstSide = 1;firstSide<=3;firstSide++){
                for(int secondDimen=0;secondDimen<3;secondDimen++){
                    side[firstSide][0][secondDimen] = side[firstSide+1][0][secondDimen]; 
                }
            }
            side[4][0][0] = left, side[4][0][1] = mid, side[4][0][2] = right;
            int buffer = side[0][0][0];
            side[0][0][0] = side[0][2][0];
            side[0][2][0] = side[0][2][2];
            side[0][2][2] = side[0][0][2];
            side[0][0][2] = buffer;
            buffer = side[0][0][1];
            side[0][0][1] = side[0][1][0];
            side[0][1][0] = side[0][2][1];
            side[0][2][1] = side[0][1][2];
            side[0][1][2] = buffer;
        }
        else if(direction == "UCC"){
            int left=side[4][0][0], mid=side[4][0][1], right=side[4][0][2];
            for(int firstSide=3;firstSide>=1;firstSide--){
                for(int secondDimen=2;secondDimen>=0;secondDimen--){
                    side[firstSide+1][0][secondDimen] = side[firstSide][0][secondDimen];
                }
            }
            side[1][0][0] = left, side[1][0][1] = mid, side[1][0][2] = right;
            int buffer = side[0][0][0];
            side[0][0][0] = side[0][0][2];
            side[0][0][2] = side[0][2][2];
            side[0][2][2] = side[0][2][0];
            side[0][2][0] = buffer;
            buffer = side[0][0][1];
            side[0][0][1] = side[0][1][2];
            side[0][1][2] = side[0][2][1];
            side[0][2][1] = side[0][1][0];
            side[0][1][0] = buffer;
        }
        else if(direction == "DC"){
            int left = side[1][2][0], mid = side[1][2][1], right = side[1][2][2];
            side[1][2][0] = side[4][2][0], side[1][2][1] = side[4][2][1], side[1][2][2] = side[4][2][2];
            for(int first=3;first>1;first--){
                for(int secondDimen=0;secondDimen<3;secondDimen++){
                    side[first+1][2][secondDimen] = side[first][2][secondDimen];
                }
            }
            side[2][2][0] = left, side[2][2][1] = mid, side[2][2][2] = right;
            int buffer = side[5][0][0];
            side[5][0][0] = side[5][2][0];
            side[5][2][0] = side[5][2][2];
            side[5][2][2] = side[5][0][2];
            side[5][0][2] = buffer;
            buffer = side[5][0][1];
            side[5][0][1] = side[5][1][0];
            side[5][1][0] = side[5][2][1];
            side[5][2][1] = side[5][1][2];
            side[5][1][2] = buffer;
        }
        else if(direction == "DCC"){
            int left = side[1][2][0], mid = side[1][2][1], right = side[1][2][2];
            for(int first=1;first<=3;first++){
                for(int secondDimen=0;secondDimen<3;secondDimen++){
                    side[first][2][secondDimen] = side[first+1][2][secondDimen];
                }
            }
            side[4][2][0] = left, side[4][2][1] = mid, side[4][2][2] = right;
            int buffer = side[5][0][0];
            side[5][0][0] = side[5][0][2];
            side[5][0][2] = side[5][2][2];
            side[5][2][2] = side[5][2][0];
            side[5][2][0] = buffer;
            buffer = side[5][0][1];
            side[5][0][1] = side[5][1][2];
            side[5][1][2] = side[5][2][1];
            side[5][2][1] = side[5][1][0];
            side[5][1][0] = buffer;
        }
        else if(direction == "FC"){
            int left = side[0][2][0], mid = side[0][2][1], right = side[0][2][2];
            side[0][2][0] = side[4][2][2], side[0][2][1] = side[4][1][2], side[0][2][2] = side[4][0][2];
            side[4][0][2] = side[5][0][0], side[4][1][2] = side[5][0][1], side[4][2][2] = side[5][0][2];
            side[5][0][0] = side[2][2][0], side[5][0][1] = side[2][1][0], side[5][0][2] = side[2][0][0];
            side[2][0][0] = left, side[2][1][0] = mid, side[2][2][0] = right;
            int buffer = side[1][0][0];
            side[1][0][0] = side[1][2][0];
            side[1][2][0] = side[1][2][2];
            side[1][2][2] = side[1][0][2];
            side[1][0][2] = buffer;
            buffer = side[1][0][1];
            side[1][0][1] = side[1][1][0];
            side[1][1][0] = side[1][2][1];
            side[1][2][1] = side[1][1][2];
            side[1][1][2] = buffer;
        }
        else if(direction == "FCC"){
            int left = side[0][2][0], mid = side[0][2][1], right = side[0][2][2];
            side[0][2][0] = side[2][0][0], side[0][2][1] = side[2][1][0], side[0][2][2] = side[2][2][0];
            side[2][0][0] = side[5][0][2], side[2][1][0] = side[5][0][1], side[2][2][0] = side[5][0][1];
            side[5][0][0] = side[4][0][2], side[5][0][1] = side[4][1][2], side[5][0][2] = side[4][2][2];
            side[4][0][2] = right, side[4][1][2] = mid, side[4][2][2] = left;
            int buffer = side[1][0][0];
            side[1][0][0] = side[1][0][2];
            side[1][0][2] = side[1][2][2];
            side[1][2][2] = side[1][2][0];
            side[1][2][0] = buffer;
            buffer = side[1][0][1];
            side[1][0][1] = side[1][1][2];
            side[1][1][2] = side[1][2][1];
            side[1][2][1] = side[1][1][0];
            side[1][1][0] = buffer;
        }
        else if(direction == "BC"){
            int left = side[0][0][0], mid = side[0][0][1], right = side[0][0][2];
            side[0][0][0] = side[2][0][2], side[0][0][1] = side[2][1][2], side[0][0][2] = side[2][2][2];
            side[2][0][2] = side[5][2][2], side[2][1][2] = side[5][2][1], side[2][2][2] = side[5][2][0];
            side[5][2][0] = side[4][0][0], side[5][2][1] = side[4][1][0], side[5][2][2] = side[4][2][0];
            side[4][2][0] = left, side[4][1][0] = mid, side[4][0][0] = right;
            int buffer = side[3][0][0];
            side[3][0][0] = side[3][2][0];
            side[3][2][0] = side[3][2][2];
            side[3][2][2] = side[3][0][2];
            side[3][0][2] = buffer;
            buffer = side[3][0][1];
            side[3][0][1] = side[3][1][0];
            side[3][1][0] = side[3][2][1];
            side[3][2][1] = side[3][1][2];
            side[3][1][2] = buffer;
        }
        else if(direction == "BCC"){
            int left = side[0][0][0], mid = side[0][0][1], right = side[0][0][2];
            side[0][0][0] = side[4][2][0], side[0][0][1] = side[4][1][0], side[0][0][2] = side[4][0][0];
            side[4][2][0] = side[5][2][2], side[4][1][0] = side[5][2][1], side[4][0][0] = side[5][2][0];
            side[5][2][0] = side[2][2][2], side[5][2][1] = side[2][1][2], side[5][2][2] = side[2][0][2];
            side[2][0][2] = left, side[2][1][2] = mid, side[2][2][2] = right;
            int buffer = side[3][0][0];
            side[3][0][0] = side[3][0][2];
            side[3][0][2] = side[3][2][2];
            side[3][2][2] = side[3][2][0];
            side[3][2][0] = buffer;
            buffer = side[3][0][1];
            side[3][0][1] = side[3][1][2];
            side[3][1][2] = side[3][2][1];
            side[3][2][1] = side[3][1][0];
            side[3][1][0] = buffer;
        }
    }
}
/*
auto Cube::getCube(){
    return side;
}*/
json Cube::toJson(){
    json j;
    for(int first=0;first<6;first++){
        j["side" + to_string(first)] = json::array();
        for(int secondDimen=0;secondDimen<3;secondDimen++){
            j["side" + to_string(first)].push_back(json::array());
            for(int thirdDimen=0;thirdDimen<3;thirdDimen++){
                j["side" + to_string(first)][secondDimen].push_back(side[first][secondDimen][thirdDimen]);
            }
        }
    }
    return j;
}