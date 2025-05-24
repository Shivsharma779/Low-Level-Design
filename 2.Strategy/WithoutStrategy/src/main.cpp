#include <iostream>
#include <memory>
#include "Vehicle.h"
#include "SportsCar.h"
#include "PassengerCar.h"
int main()
{
    std::unique_ptr<Vehicle> v1= std::make_unique<SportsCar>();
    std::unique_ptr<Vehicle> v2= std::make_unique<PassengerCar>();
    // Vehicle * v1 = new SportsCar();

    v1->Drive();
    v2->Drive();
    return 0;
}