// IObserver.h
#pragma once

class IObservable;

class IObserver {
public:
    virtual void update(IObservable*) = 0;
    virtual ~IObserver() = default;
};
