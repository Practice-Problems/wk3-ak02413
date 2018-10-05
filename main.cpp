#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "Truck.h"
#include "Box.h"

using namespace std;


int LineCounter(char* fileName)
{
    FILE* filePointer;                          //Declaring a file pointer
    char buff[32];                              //Declaring a character array to store a line

    filePointer = fopen(fileName, "r");         //Opening file as read only

    if (filePointer == NULL)                    //If file is not found
    {
        perror ("Error opening file");          //Show Error
        return 0;
    }

    int counter = 0;                            //Counts the lines in file

    while(fgets(buff, 32, (FILE*)filePointer) != NULL)   //If line read is not NULL
    {
        counter++;                                      //increase line count
    }
    fclose(filePointer);                                //close file when done
    return counter;                                     //return line count
}


int main()
{   srand(time(NULL));

    int Truck_Count = (LineCounter("Drivers.txt") / 5);
    Truck *all_trucks = new Truck[Truck_Count]; //Declaring a dynamic array of truck objects, created with the default constructor.
    FILE* filePointer;                          //Declaring a file pointer
    char buff[32];

    filePointer = fopen("Drivers.txt", "r");

    if (filePointer == NULL)
    {
        perror ("Error opening file");
        return 0;
    }

    if (filePointer == NULL)
    {
        perror ("Error opening file");
        return 0;
    }

    for(int i = 0; i < Truck_Count; i++){//The loop reads through the text file five lines at a time, storing the values read into member variables.
        char driver[32];//These are temporary variables required for the copying.
        int fuel_gauge;
        int funds;
        int loaded_economy;
        int unloaded_economy;

        fgets(driver, 32, (FILE*)filePointer); //Reading the name of the driver directly

        fgets(buff, 32, (FILE*)filePointer);        //Reading the next line as string
        fuel_gauge = atoi(buff);                   //Converting the string to integer

        fgets(buff, 32, (FILE*)filePointer);
        funds = atoi(buff);

        fgets(buff, 32, (FILE*)filePointer);
        loaded_economy = atoi(buff);

        fgets(buff, 32, (FILE*)filePointer);
        unloaded_economy = atoi(buff);

        int numboxes = rand() % (9) + 12;

        all_trucks[i].setter(driver, fuel_gauge, funds, loaded_economy, unloaded_economy, numboxes);//Calling the constructor with values stored
                                                                                                    //in the temporary variables.
        all_trucks[i].trip_possible();//This assigns a value of true or false to a boolean member, which tells us if this particular truck object is able
                                      //to make the trip.
        all_trucks[i].Load();//Loads a random number of boxes and returns their dimensions and volume.

    }

    fclose(filePointer);

    int num_trucks_tripping = 0;
    for(int i = 0; i < Truck_Count; i++){
        if(all_trucks[i].trip_getter() == true){//This loop counts how many trucks will make the trip, in order for a new dynamic array to be declared.
            num_trucks_tripping++;
        }
    }
    Truck *trucks_travelling = new Truck[num_trucks_tripping];//Dynamic array of trucks making the trip.
    int ll = 0;
    for(int i = 0; i < Truck_Count; i++){//Loops through all trucks and copies the ones that will into the new array.
        if(all_trucks[i].trip_getter() == true){
            trucks_travelling[ll] = all_trucks[i];
            ll++;
        }
    }

    ofstream Tripfile;
    Tripfile.open("Trip.txt");//Outputs the trucks' members into a text file
    for(int i = 0; i < num_trucks_tripping; i++){
        for(int m = 0; m < trucks_travelling[i].return_namelength(); m++){
            Tripfile << trucks_travelling[i].return_name()[m];
        }
        Tripfile << trucks_travelling[i].return_fuel() << endl;
        Tripfile << trucks_travelling[i].return_funds() << endl;
        Tripfile << endl;
    }

    Tripfile.close();

    for(int i = 0; i < num_trucks_tripping; i++){
        trucks_travelling[i].Unload();
    }

    delete [] trucks_travelling;//De-allocation of both dynamic arrays.
    trucks_travelling = NULL;
    delete [] all_trucks;
    all_trucks = NULL;

    return 0;
}
