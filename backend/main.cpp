#include <iostream>
#include "includes/cube.h"
#include "includes/httplib.h"
#include "includes/json.hpp"
using namespace std;

int main(){
    Cube cube;
    httplib::Server svr;
    svr.Get("/getCube", [&cube](const httplib::Request& req, httplib::Response& res){
        //res.set_content("Hello", "text/plain");
        nlohmann::json j = cube.toJson();
        res.set_content(j.dump(), "application/json");
    });
    svr.listen("0.0.0.0", 8080);
    return 0;
}
