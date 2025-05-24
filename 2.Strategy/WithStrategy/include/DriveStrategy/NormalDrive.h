#pragma once
#include "DriveStrategy.h"
class NormalDrive: public DriveStrategy{
public:
    void Drive() override;
    ~NormalDrive() override = default;
};