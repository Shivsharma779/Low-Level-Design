#include "PassengerCar.h"
#include "NormalDrive.h"

PassengerCar::PassengerCar() : Vehicle(std::make_unique<NormalDrive>()) {}