#include <iostream>
#include "CEmailObserver.h"
#include "CProductObservable.h"
#include "CCricketObservable.h"
void CEmailObserver::update(IObservable * o)
{
    if(dynamic_cast<CProductObservable *>(o))
        std::cout << "Sending Email product is now in stock \n";
    if(dynamic_cast<CCricketObservable *>(o))
        std::cout << "Sending Email match has now started \n";
}