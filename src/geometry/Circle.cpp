#include "geometry/Circle.hpp"
#include "geometry/Point.hpp"
#include <vector>

Circle::Circle(double radius):
    radius(radius)
{}

std::vector<Point> Circle::getVerticies(){
    std::vector<Point> verticies;
    
    int x = 0;
    int y = -radius;
    int p = -radius;

    while(x < -y){
        if(p > 0){
            y++;
            p += 2*(x+y) + 1;
        }

        else
            p += 2*x + 1;

        verticies.push_back(Point( x,  y));
        verticies.push_back(Point(-x,  y));
        verticies.push_back(Point( x, -y));
        verticies.push_back(Point(-x, -y));
        verticies.push_back(Point( y,  x));
        verticies.push_back(Point(-y,  x));
        verticies.push_back(Point( y, -x));
        verticies.push_back(Point(-y, -x));

        x++;
    }

    return verticies;
}

int Circle::getVerticiesNumber(){
    return getVerticies().size();
}
