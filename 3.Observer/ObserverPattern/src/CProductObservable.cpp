#include "CProductObservable.h"
#include <iostream>
CProductObservable::CProductObservable(): stock(0){}

void CProductObservable::addObserver(std::shared_ptr<IObserver> o) 
{
    observers.push_back(o);
}

void CProductObservable::removeObserver(IObserver * o) 
{
    auto it = std::find_if(observers.begin(), observers.end(), 
    [&](const std::shared_ptr<IObserver> &a)
        {
            return a.get() == o;
        }
    );
    if(it != observers.end())
        observers.erase(it);
    
    if (it != observers.end()) {
        std::cout << "Removed observer of type: " << typeid(**it).name() << std::endl;
    }
}

void CProductObservable::notifyObservers() 
{
    for(auto &observer: observers)
        observer->update(this);
}

void CProductObservable::setStock(int newStock) 
{
    if(stock == 0)
        notifyObservers();
    
    stock =  newStock;
}