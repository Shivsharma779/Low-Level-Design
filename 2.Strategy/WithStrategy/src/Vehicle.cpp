#include "Vehicle.h"

Vehicle::Vehicle(std::unique_ptr<DriveStrategy> d) : driveStrategy(std::move(d)) {}

void Vehicle::Drive() {
    driveStrategy->Drive();
}