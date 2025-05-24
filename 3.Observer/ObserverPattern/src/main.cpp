#include "CEmailObserver.h"
#include "CMobileObserver.h"
#include "CProductObservable.h"
#include "CCricketObservable.h"

int main() {
    CProductObservable p;
    CCricketObservable cricket;
    // CObservable intObservable;
    // CObservable<bool> boolObservable;

    auto emailObserver = std::make_shared<CEmailObserver>();
    auto mobileObserver = std::make_shared<CMobileObserver>();

    IObserver * emailObserverPtr = emailObserver.get();
    IObserver * mobileObserverPtr = mobileObserver.get();
    p.addObserver(emailObserver);
    cricket.addObserver(mobileObserver);

    p.addObserver(emailObserver);
    cricket.addObserver(mobileObserver);

    p.setStock(10);
    p.setStock(0);
    p.setStock(100);


    cricket.setMatchStarted(true);
    cricket.setMatchStarted(false);
    cricket.setMatchStarted(true);

    p.removeObserver(emailObserverPtr);
    cricket.removeObserver(mobileObserverPtr);

    return 0;
}