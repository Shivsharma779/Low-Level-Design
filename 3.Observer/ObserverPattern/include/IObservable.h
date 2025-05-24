// IObservable.h
#pragma once
#include <memory>
#include "IObserver.h"

class IObservable {
public:
    virtual void addObserver(std::shared_ptr<IObserver>) = 0;
    virtual void removeObserver(IObserver*) = 0;
    virtual void notifyObservers() = 0;
    virtual ~IObservable() = default;
};
