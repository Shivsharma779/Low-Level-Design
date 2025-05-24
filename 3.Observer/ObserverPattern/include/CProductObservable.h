#pragma once
#include <vector>
#include "IObservable.h"
#include "IObserver.h"


class CProductObservable : public IObservable {
private:
    std::vector<std::shared_ptr<IObserver>> observers;
    int stock;
public:
    CProductObservable();
    void addObserver(std::shared_ptr<IObserver>) override;
    void removeObserver(IObserver*) override;
    void notifyObservers() override;
    void setStock(int);
    ~CProductObservable() override = default;
};