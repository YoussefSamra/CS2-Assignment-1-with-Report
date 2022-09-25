#include <iostream>
#include <string>
#include <stdlib.h> 
#include <queue>
using namespace std;

class Car
{
private:

    string Car_Brand, Car_Type, Car_Plate;
    int Speed, Year_Model;



public:

    Car() {

        Car_Brand = "";
        Car_Type = "";
        Car_Plate = "";
        Speed = 0;
        Year_Model = 0;
    }

    Car(string x, string f, int y, int z) {

        Car_Brand = x;
        Car_Type = f;
        Speed = y;
        Year_Model = z;

    }
    void set_Speed(int new_speed) {
        Speed = new_speed;
    }
    void set_Year_Model(int new_yearmodel) {
        Year_Model = new_yearmodel;
    }
    void set_Car_Brand(string new_carbrand) {
        Car_Brand = new_carbrand;
    }
    void set_Car_Type(string new_cartype) {
        Car_Type = new_cartype;
    }
    void set_Car_Plate(string new_carplate) {
        Car_Plate = new_carplate;
    }
    void set_cons(string x, int y, int z) {
        Car_Brand = x;
        Speed = y;
        Year_Model = z;
    }
    int get_Speed() {
        return Speed;
    }
    int get_Year_Model() {
        return Year_Model;
    }
    string get_Car_Brand() {
        return Car_Brand;
    }
    string get_Car_Type() {
        return Car_Type;
    }
    string get_Car_Plate() {
        return Car_Plate;
    }
};

class Road
{
private:

    char Road_type;
    int Speed_limit;
    static float countA, countB, countC;


public:

    Road() {

        Road_type = 0;
        Speed_limit = 0;
    }

    Road(char rt, int y) {
        Speed_limit = y;
        Road_type = 0;
        do {
            if (rt == 'A' || rt == 'B' || rt == 'C')
            {
                Road_type = rt; // cout << endl << "value =" << rt; value checker
            }                // Works fine
            else
                cout << "Invalid Entry, Please enter a valid type [A, B, C]"; // inf loop
        } while (rt != 'A' && rt != 'B' && rt != 'C');

    }


    int age(int Year_Model) {
        return (2022 - Year_Model);
    }

    void set_Road_Type(char new_roadtype) {
        do {
            if (new_roadtype == 'A' || new_roadtype == 'B' || new_roadtype == 'C')
                Road_type = new_roadtype;
            else
                cout << "Invalid Entry, Please enter a valid type [A, B, C]";
        } while (new_roadtype != 'A' && new_roadtype != 'B' && new_roadtype != 'C');
    }
    void set_Speed_limit(int new_speedlimit) {
        Speed_limit = new_speedlimit;
    }
    /* void set_countA(int new_countA) {
          countA = new_countA;
      }
      void set_countB(int new_countB) {               [Count does not need a setter as it is set by the allow functtion only]
          countB = new_countB;
      }
      void set_countC(int new_countC) {
          countC = new_countC;
      } */

    bool radar(int car_speed, char Road_type) {
        if (car_speed > Speed_limit)
            return true;                             //Works fine
        else return false;
    }
    float  get_countA() {
        return countA;
    }
    float get_countB() {
        return countB;
    }
    float  get_countC() {
        return countC;
    }
    char get_RoadType() {
        return Road_type;
    }
    int get_speedlimit() {
        return Speed_limit;
    }


    void allow(string Car_type) {

        if (Road_type == 'A')
        {
            if (Car_type == "Private" || Car_type == "Motorcycle") {
                cout << "Allowed"; countA++;
            }
            else   cout << "Not allowed";
        }
        if (Road_type == 'C')
        {
            if (Car_type == "Truck") {
                cout << "Allowed"; countC++;
            }
            else   cout << "Not allowed";
        }
        else if (Road_type == 'B')
        {
            cout << "Allowed"; countB++;
        }





    }
};

float Road::countA = 0;
float Road::countB = 0;
float Road::countC = 0;



void car_queue(Car car_name, queue<Car> queue_name) {

    int x = 1;
    queue_name.push(car_name);
    cout << "Vehicle " << car_name.get_Car_Brand() << " was enqueued || Cars in the queue: " << x << endl;

    x++;

}   // Causes error

void CarMaker(Car car_brand, Road road_name, queue<Car> queue_name, int& count) {
    char roadtype = road_name.get_RoadType();
    cout << "Do you wish to dequeue the Vehicle [Yes or No] " << car_brand.get_Car_Brand() << endl;  string input;
    cin >> input;
    if (input == "Yes")
    {
        queue_name.pop(); cout << "Vehicle " << car_brand.get_Car_Brand() << " was dequeued || cars left in queue: " << count << endl;

        if (road_name.radar(car_brand.get_Speed(), road_name.get_RoadType()) == true) {

            cout << car_brand.get_Car_Brand() << " will be fined for exceding the speed limit" << endl << "Vehicle specs & details: " << endl;
            cout << "Car Brand & Make: " << car_brand.get_Car_Brand() << " " << car_brand.get_Year_Model() << endl << "License Plates:" << car_brand.get_Car_Plate() << endl << "Vehicle Speed: " << car_brand.get_Speed() << endl;

        }
        else cout << "Vehicle is moving under the speed limit" << endl;

        cout << "Vehicle " << car_brand.get_Car_Brand() << " is: "; road_name.allow(car_brand.get_Car_Type()); cout << " on road " << road_name.get_RoadType() << endl;
        cout << "Road A count: " << road_name.get_countA();         cout << endl;
        cout << "Road B count: " << road_name.get_countB();         cout << endl;
        cout << "Road C count: " << road_name.get_countC();         cout << endl;
        cout << "Car Age: " << road_name.age(car_brand.get_Year_Model());  cout << endl;
    }
    else if (input == "No")
    {
        cout << "Thank you" << endl; exit(0);
    }

    char response1;

    cout << "Do you wish to continue? [Y] "; cin >> response1;
    if (response1 != 'Y')
    {
        exit(0);
    }
    else

        system("CLS");  input = ""; count--;

}




int main()
{

    Road Highway('A', 120);
    Road HighwayT('C', 100);
    Road Autobahn('B', 500);

    Car Volvo("Volvo", "Private", 120, 2020);
    Volvo.set_Car_Plate("|||");
    Car BMW("BMW", "Private", 180, 2010);
    BMW.set_Car_Plate("BARON");
    Car Ferrari("Ferrari", "Private", 300, 2022);
    Ferrari.set_Car_Plate("|");
    Car Toyota("Toyota", "Private", 100, 2020);
    Toyota.set_Car_Plate("JOE");
    Car Koenigsegg("Koenigsegg", "Private", 350, 2022);            // Private Cars
    Koenigsegg.set_Car_Plate("Sweden");
    Car Pagani("Pagani", "Private", 350, 2015);
    Pagani.set_Car_Plate("Horacia");
    Car Porsche("Porsche", "Private", 300, 2018);
    Porsche.set_Car_Plate("911");
    Car Mclaren("Mclaren", "Private", 120, 2005);
    Mclaren.set_Car_Plate("911");
    Car Mercedes("Mercedes", "Private", 100, 2018);
    Mercedes.set_Car_Plate("SLS");
    Car Corvette("Corvette", "Private", 200, 1962);
    Corvette.set_Car_Plate("FALL1n1");


    Car Ducati("Ducati", "Motorcycle", 120, 2020);
    Ducati.set_Car_Plate("ARC");
    Car ARC("ARC", "Motorcycle", 180, 2010);
    ARC.set_Car_Plate("LKDIS");
    Car Yamaha("Yamaha", "Motorcycle", 300, 2022);                //Motorcycles
    Yamaha.set_Car_Plate("IWISO");
    Car Kawasaki("Kawasaki", "Motorcycle", 100, 2020);
    Kawasaki.set_Car_Plate("LSOWL");
    Car Harley_Davidson("Harley_Davidson", "Motorcycle", 350, 2022);
    Harley_Davidson.set_Car_Plate("SJDID");


    Car Iveco("Iveco", "Truck", 350, 2015);
    Iveco.set_Car_Plate("ISIDS");
    Car Scania("Scania", "Truck", 300, 2018);
    Scania.set_Car_Plate("SXINR");
    Car Man("Man", "Truck", 182, 2005);              //Trucks
    Man.set_Car_Plate("FNEKD");
    Car DAF("DAF", "Truck", 100, 2018);
    DAF.set_Car_Plate("JDICN");
    Car Renault("Renault", "Truck", 200, 1962);
    Renault.set_Car_Plate("EJCEN");




    char response;
    cout << "Do you with to start? [Y] ";
    cin >> response;
    if (response != 'Y')
    {
        exit(0);
    }
    else



        system("CLS");

    queue<Car> Cars;

    //    Cars.push(Volvo); cout << "Vehicle " << Volvo.get_Car_Brand() << " was enqueued || Cars in the queue: " << "1" << endl;
    //    Cars.push(BMW); cout << "Vehicle " << BMW.get_Car_Brand() << " was enqueued || Cars in the queue: " << "2" << endl;
    Cars.push(Ferrari); cout << "Vehicle " << Ferrari.get_Car_Brand() << " was enqueued || Cars in the queue: " << "1" << endl;
    //    Cars.push(Toyota); cout << "Vehicle " << Toyota.get_Car_Brand() << " was enqueued || Cars in the queue: " << "4" << endl;
    Cars.push(Koenigsegg); cout << "Vehicle " << Koenigsegg.get_Car_Brand() << " was enqueued || Cars in the queue: " << "2" << endl;
    Cars.push(Pagani); cout << "Vehicle " << Pagani.get_Car_Brand() << " was enqueued || Cars in the queue: " << "3" << endl;
    Cars.push(Porsche); cout << "Vehicle " << Porsche.get_Car_Brand() << " was enqueued || Cars in the queue: " << "4" << endl;
    Cars.push(Mclaren); cout << "Vehicle " << Mclaren.get_Car_Brand() << " was enqueued || Cars in the queue: " << "5" << endl;
    //    Cars.push(Mercedes); cout << "Vehicle " << Mercedes.get_Car_Brand() << " was enqueued || Cars in the queue: " << "9" << endl;
    //    Cars.push(Corvette); cout << "Vehicle " << Corvette.get_Car_Brand() << " was enqueued || Cars in the queue: " << "10" << endl;
    Cars.push(Ducati); cout << "Vehicle " << Ducati.get_Car_Brand() << " was enqueued || Cars in the queue: " << "6" << endl;
    Cars.push(ARC); cout << "Vehicle " << ARC.get_Car_Brand() << " was enqueued || Cars in the queue: " << "7" << endl;
    //    Cars.push(Yamaha); cout << "Vehicle " << Yamaha.get_Car_Brand() << " was enqueued || Cars in the queue: " << "13" << endl;
    Cars.push(Kawasaki); cout << "Vehicle " << Kawasaki.get_Car_Brand() << " was enqueued || Cars in the queue: " << "8" << endl;
    //    Cars.push(Harley_Davidson); cout << "Vehicle " << Harley_Davidson.get_Car_Brand() << " was enqueued || Cars in the queue: " << "15" << endl;
    Cars.push(Iveco); cout << "Vehicle " << Iveco.get_Car_Brand() << " was enqueued || Cars in the queue: " << "9" << endl;
    Cars.push(Scania); cout << "Vehicle " << Scania.get_Car_Brand() << " was enqueued || Cars in the queue: " << "10" << endl;
    //    Cars.push(Man); cout << "Vehicle " << Man.get_Car_Brand() << " was enqueued || Cars in the queue: " << "18" << endl;
    //    Cars.push(DAF); cout << "Vehicle " << DAF.get_Car_Brand() << " was enqueued || Cars in the queue: " << "19" << endl;
    //    Cars.push(Renault); cout << "Vehicle " << Renault.get_Car_Brand() << " was enqueued || Cars in the queue: " << "20" << endl;



    char response1;
    cout << endl << endl << "Do you with to start the dequeue process? [Y] ";
    cin >> response1;
    if (response1 != 'Y')
    {
        exit(0);
    }
    else


        system("CLS");
    int Count = 9;


    CarMaker(Ferrari, Highway, Cars, Count);
    CarMaker(Koenigsegg, Autobahn, Cars, Count);
    CarMaker(Pagani, Autobahn, Cars, Count);
    CarMaker(Porsche, HighwayT, Cars, Count);
    CarMaker(Mclaren, Highway, Cars, Count);

    CarMaker(Ducati, Highway, Cars, Count);
    CarMaker(ARC, HighwayT, Cars, Count);
    CarMaker(Kawasaki, Autobahn, Cars, Count);

    CarMaker(Iveco, Autobahn, Cars, Count);
    CarMaker(Scania, HighwayT, Cars, Count);
    /*
    *
      CarMaker(Volvo, Highway, Cars, Count);
      CarMaker(BMW, Highway, Cars, Count);
      CarMaker(Toyota, Highway, Cars, Count);
      CarMaker(Mercedes, Highway, Cars, Count);
      CarMaker(Corvette, Highway, Cars, Count);
      CarMaker(Yamaha, Highway, Cars, Count);
      CarMaker(Harley_Davidson, Highway, Cars, Count);


      CarMaker(Man, HighwayT, Cars, Count);
      CarMaker(DAF, HighwayT, Cars, Count);                     Extra
      CarMaker(Renault, HighwayT, Cars, Count);
    */


    //////////////////////////////////////////////////////////////////

    float carno;
    float roadA;
    float roadB;
    float roadC;



    if (Highway.get_countA() > HighwayT.get_countC())
    {
        if (Highway.get_countA() > Autobahn.get_countB())
            carno = Highway.get_countA();
        else carno = Autobahn.get_countB();

    }
    else carno = HighwayT.get_countA();

    roadA = ((Highway.get_countA() / carno) * 100);
    roadC = ((HighwayT.get_countC() / carno) * 100);
    roadB = ((Autobahn.get_countB() / carno) * 100);

    cout << "Efficiency Test: " << endl;
    cout << "Road A: " << roadA << "% with count: " << Highway.get_countA() << endl << "Road B: " << roadB << "% with count: " << Autobahn.get_countB() << endl << "Road C: " << roadC << "% with count: " << HighwayT.get_countC();









    return 0;
}


