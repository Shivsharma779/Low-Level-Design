#pragma once
#include "IObserver.h"
#include "IObservable.h"
#include <iostream>

class CEmailObserver : public IObserver {
public:
    void update(IObservable *) override;
    ~CEmailObserver() override = default;
};
