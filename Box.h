#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Box
{
private:
    //int length, width, height;
public:
    int length, width, height;
    Box();
    int Volume();
    void getter();
};
