#include <iostream>
#include <string>

class Marker{
    public:
        int price;
        std::string name;
};

class Invoice
{
    private:
        Marker marker;
        int quantity;
    
    public:
        Invoice() = default;
        Invoice(const Marker& m, int q) : marker(m), quantity(q) {}
        void calculateTotal()
        {
            std::cout << "Total: ";
            std::cout << marker.price*quantity << std::endl;
        }

};

int main(){
    Marker m;
    m.price = 10;
    m.name = "coffee";

    Invoice in(m,2);
    in.calculateTotal();
}