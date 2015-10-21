//
//  main.cpp
//  User Interface
//
//  Created by Stormy Mauldin on 10/21/15.
//  Copyright © 2015 QuARC. All rights reserved.
//

#include <iostream>
#include "Point.hpp"

using namespace std;

//while we have z-axis functionality, we may want to always input this as 0.

int main()
{
    Point *objectPoint = new Point();
    Point *locationPoint = new Point();
    objectPoint->userPoint(true);
    locationPoint->userPoint(false);
    cout<<"The object is located at point ";
    objectPoint->printPoint();
    cout<<".\nYou would like to move the object to point ";
    locationPoint->printPoint();
    cout<<".";
    //Send coordinates to the IK library
}


