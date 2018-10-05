#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
#include "Truck.h"


    Truck::Truck(){//Default constructor
        m_driver[0] = '\0';
        m_fuel_gauge = m_funds = m_loaded_economy = m_unloaded_economy = num_of_boxes = 0;
        m_cargo = NULL;
    }
    Truck::~Truck(){//Default destructor.
        delete [] m_cargo;
        m_driver[0] = '\0';
        m_fuel_gauge = m_funds = m_loaded_economy = m_unloaded_economy = num_of_boxes = 0;
    }

    Truck::Truck(const Truck &truckobj){
        for(int i = 0; i < 32; i++){
            m_driver[i] = truckobj.m_driver[i];
        }
        m_fuel_gauge = truckobj.m_fuel_gauge;
        m_funds = truckobj.m_funds;
        m_unloaded_economy = truckobj.m_unloaded_economy;
        m_loaded_economy = truckobj.m_loaded_economy;
    }

    void Truck::setter(char driver[32], float fuel_gauge, float funds, float loaded_economy, float unloaded_economy, int numboxes){
            for(int i = 0; i < 32; i++){//Sets the values of the members based on the variables it receives.
                m_driver[i] = driver[i];
            }
            m_fuel_gauge = fuel_gauge;
            m_funds = funds;
            m_loaded_economy = loaded_economy;
            m_unloaded_economy = unloaded_economy;
            num_of_boxes = numboxes;
            }

    void Truck::getter(){//Gets the values of the members and displays them to the console.
        int x = 0;
        for(int i = 0; i < 32; i++){//This checks the length of the name so that the output does not contain garbage.
            if(m_driver[i] != '\0'){
                x++;
            }
            else{
                break;
            }
        }
        for(int m = 0; m < x; m++){
            cout << m_driver[m];
        }
        cout << m_fuel_gauge << endl << m_funds << endl << m_loaded_economy << endl << m_unloaded_economy << endl;
    }

    void Truck::Load(){
        cout << "The contents while loading." << endl;
        m_cargo = new Box[num_of_boxes];//Dynamic array of boxes. The number of boxes is random and stored as a member so the unload function also has access to it.
        cout << "Load of " << m_driver << "There are " << num_of_boxes << " boxes in this truck." << endl;
        for(int i = 0; i < num_of_boxes; i ++){
            m_cargo[i].getter();//Getter function of boxes to access the private variables of the box.
            cout << "The volume of the box being loaded is: " << m_cargo[i].Volume() << endl;
        }
    }
    void Truck::Unload(){
        for(int i = 0; i < num_of_boxes; i++){
            m_cargo[i].getter();
            cout << "The volume of the box being unloaded is: " << m_cargo[i].Volume() << endl;
        }
        delete [] m_cargo;//Deallocates the cargo dynamic array and sets it to null.
        m_cargo = NULL;
    }

    void Truck::trip_possible(){//Fills up the tank to capacity and assigns a new value to the funds available. Or fills up based on how much money is available.
        if((m_fuel_gauge + (m_funds/2.73)) > 50){
            m_funds = m_funds - (50 - m_fuel_gauge)*2.73;
            m_fuel_gauge = 50;
        }
        else{
            m_fuel_gauge = m_fuel_gauge + (m_funds/2.73);
            m_funds = 0;
        }
        float fuel_required = (60 / m_unloaded_economy) + (60 / m_loaded_economy);
        if(m_fuel_gauge > fuel_required){
            make_trip = true;
            m_fuel_gauge = m_fuel_gauge - fuel_required;
        }
        else{
            make_trip = false;
        }
    }

    bool Truck::trip_getter(){//Used to check the value of the bool variable in main.
        return make_trip;
    }

    char* Truck::return_name(){//The remaining functions were all used to write to the file, reading from the dynamic array of trucks that would make the trip.
        return m_driver;
    }

    float Truck::return_fuel(){
        return m_fuel_gauge;
    }

    float Truck::return_funds(){
        return m_funds;
    }

    int Truck::return_namelength(){
        int nl = 0;
        for(int n = 0; n < 32; n++){
            if(m_driver[n] != 0){
                nl++;
            }
            else{
                break;
            }
        }
        return nl;
    }
