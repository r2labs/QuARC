//
//  Point.hpp
//  User Interface
//
//  Created by Stormy Mauldin on 10/21/15.
//  Copyright © 2015 QuARC. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>
#include <string.h>
#define MAX_COORDINATE 100.0
#define MIN_COORDINATE 0


class Point{
private:
    double x;
    double y;
    double z;
    
public:
    Point();
    Point(double x, double y, double z);
    
    void setPoint(double x, double y, double z);
    void userPoint(bool object); //boolean tells if point designates object (T) or destination (F)
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    
    double getX();
    double getY();
    double getZ();
    
    void printPoint();
    
private:
    double getCoordinate();
    bool checkRange(double coordinate);
};

#endif /* Point_hpp */
