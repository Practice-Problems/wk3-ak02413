#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Box.h"

using namespace std;
#ifndef TRUCK_H
#define TRUCK_H


class Truck
{
    private:
    char m_driver[32];
    float m_fuel_gauge;
    float m_funds;
    float m_loaded_economy;
    float m_unloaded_economy;
    int num_of_boxes;
    bool make_trip;
    Box *m_cargo;
public:
    Truck();
    Truck(const Truck &truckobj);
    ~Truck();
    void setter(char driver[32], float fuel_gauge, float funds, float loaded_economy, float unloaded_economy, int numboxes);
    void getter();
    void Load();
    void Unload();
    void trip_possible();
    bool trip_getter();
    char* return_name();
    float return_funds();
    float return_fuel();
    int return_namelength();



};

#endif // TRUCK_H
