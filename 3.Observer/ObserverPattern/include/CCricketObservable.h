#pragma once
#include "IObservable.h"
#include <vector>
class CCricketObservable : public IObservable
{
    bool matchStarted;
    std::vector<std::shared_ptr<IObserver>> observers;

    public:
    void addObserver(std::shared_ptr<IObserver>) override;
    void removeObserver(IObserver *) override;
    void notifyObservers() override;
    void setMatchStarted(bool started);
    ~CCricketObservable() = default;
};