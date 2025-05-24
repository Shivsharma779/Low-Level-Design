#include "CCricketObservable.h"
#include <algorithm>
#include <memory>

void CCricketObservable::addObserver(std::shared_ptr<IObserver> observer) {
    observers.push_back(observer);
}

void CCricketObservable::removeObserver(IObserver* observer) {
    observers.erase(
        std::remove_if(observers.begin(), observers.end(),
            [observer](const std::shared_ptr<IObserver>& ptr) {
                return ptr.get() == observer;
            }),
        observers.end()
    );

    
}

void CCricketObservable::notifyObservers() {
    for (const auto& observer : observers) {
        observer->update(this);
    }
}

void CCricketObservable::setMatchStarted(bool started) {
    matchStarted = started;
    if(matchStarted)
        notifyObservers();
}