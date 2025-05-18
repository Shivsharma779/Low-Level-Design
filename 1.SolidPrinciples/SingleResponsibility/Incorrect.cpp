#include <iostream>
#include <string>

// find and change the code to implement single responsibility principle


class Marker{
    public:
        int price;
        std::string name;
};

// invoice has a marker
class Invoice
{
    private:
        Marker marker;
        int quantity;
    
    public:
        Invoice() = default;
        Invoice(const Marker& m, int q) : marker(m), quantity(q) {}

        //functional for calculation of total invoice price
        int calculateTotal()
        {
            return marker.price*quantity ;
        }

        // function for printing the invoice
        void printInvoice(){
            std::cout << "Total: " << calculateTotal() << std::endl;
        }

        //function to add the invoice to db
        void addInvoiceToDB(){
            std::cout << "Added invoice to db." << std::endl;
        }

};

//stub code 
int main(){
    Marker m;
    m.price = 10;
    m.name = "coffee";

    Invoice in(m,2);
    in.printInvoice();
}