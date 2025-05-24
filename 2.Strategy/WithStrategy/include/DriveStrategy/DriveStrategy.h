#pragma once
class DriveStrategy{
public:
    virtual void Drive() = 0;
    virtual ~DriveStrategy() = default;
};