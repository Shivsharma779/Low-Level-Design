#pragma once
#include "DriveStrategy.h"
class SportsDrive: public DriveStrategy{
public:
    void Drive() override;
    ~SportsDrive() override = default;
};