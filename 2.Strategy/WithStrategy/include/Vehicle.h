#pragma once
#include <memory>
#include "DriveStrategy.h"
class Vehicle{
private:
    std::unique_ptr<DriveStrategy> driveStrategy;
public:
    explicit Vehicle(std::unique_ptr<DriveStrategy> d);
    void Drive();
};