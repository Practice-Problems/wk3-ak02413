#include "Box.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
Box::Box()
{
    length = rand() % (26) + 5;
    width = rand () % (26) + 5;
    height = rand() % (26) + 5;
}

void Box::getter(){//Outputs the dimensions of the box.
    cout << "The width of the box is: " << width << " inches." << endl;
    cout << "The length of the box is: " << length << " inches." << endl;
    cout << "The height of the box is: " << height << " inches." << endl;
}

int Box::Volume()//returns the volume.
{
    return length * width * height ;
}
