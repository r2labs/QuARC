//
//  Point.cpp
//  User Interface
//
//  Created by Stormy Mauldin on 10/21/15.
//  Copyright © 2015 QuARC. All rights reserved.
//

#include "Point.hpp"
#include <string.h>
#include <iostream>

using namespace std;

Point::Point()
{
    x = 0;
    y = 0;
    z = 0;
}

Point::Point(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void Point::setPoint(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void Point::userPoint(bool object)
{
    int temp = -1;
    string message = " is the object located? ";
    if(object == false)
    {
        message = " would you like to place the object? ";
    }
    
    cout<<"Where"<<message<<"Enter the x coordinate: ";
    do
    {
        while(temp == -1)             //loop until acceptable input type
        {
            temp = getCoordinate();
        }
    }
    while(checkRange(temp) == false); //loop until acceptable input range
    x = temp;
    temp = -1;
    
    cout<<"Where"<<message<<"Enter the y coordinate: ";
    do
    {
        while(temp == -1)             //loop until acceptable input type
        {
            temp = getCoordinate();
        }
    }
    while(checkRange(temp) == false); //loop until acceptable input range
    y = temp;
    temp = -1;
    
    cout<<"Where"<<message<<"Enter the z coordinate: ";
    do
    {
        while(temp == -1)             //loop until acceptable input type
        {
            temp = getCoordinate();
        }
    }
    while(checkRange(temp) == false); //loop until acceptable input range
    z = temp;
}

void Point::setX(double x)
{
    this->x = x;
}

void Point::setY(double y)
{
    this->y = y;
}

void Point::setZ(double z)
{
    this ->z = z;
}

double Point::getX()
{
    return x;
}

double Point::getY()
{
    return y;
}

double Point::getZ()
{
    return z;
}

void Point::printPoint()
{
    cout<<"("<<x<<", "<<y<<", "<<z<<")";
}

double Point::getCoordinate()
{
    double coordinate = 0;
    if(!(cin>>coordinate))
    {
        cout<<"Invalid entry. Please try again. ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }
    return coordinate;
}

bool Point::checkRange(double coordinate)
{
    if(coordinate > MAX_COORDINATE || coordinate < MIN_COORDINATE)
    {
        return false;
    }
    return true;
}

