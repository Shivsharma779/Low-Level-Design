#include <memory>
#include "SportsCar.h"
#include "SportsDrive.h"

SportsCar::SportsCar() : Vehicle(std::make_unique<SportsDrive>()) {}