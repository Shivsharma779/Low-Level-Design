#include <iostream>
#include "CMobileObserver.h"
#include "CProductObservable.h"
#include "CCricketObservable.h"
void CMobileObserver::update(IObservable * o)
{
    if(dynamic_cast<CProductObservable *>(o))
        std::cout << "Sending Mobile notification product is now in stock \n";
    if(dynamic_cast<CCricketObservable *>(o))
        std::cout << "Sending Mobile notification match has now started \n";
}
