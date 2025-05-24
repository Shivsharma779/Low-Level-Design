#pragma once
#include "IObserver.h"
#include <iostream>

class CMobileObserver : public IObserver {
public:
    void update(IObservable *) override;
    ~CMobileObserver() = default;
};

