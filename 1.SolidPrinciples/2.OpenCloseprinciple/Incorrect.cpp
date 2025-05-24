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

        int calculateTotal()
        {
            return marker.price*quantity ;
        }

};

class InvoicePrinter{
    private:
        Invoice in;
    public:
        InvoicePrinter() = delete;
        InvoicePrinter(Invoice in): in(in) {};
        void printInvoice(){
            std::cout << "Total: " << in.calculateTotal() << std::endl;
        }
};
        
class InvoiceDAO{
    private:
        Invoice in;
    public:
        InvoiceDAO() = delete;
        InvoiceDAO(Invoice in): in(in) {};
        void addInvoiceToDB(){
            std::cout << "Added invoice to db." << std::endl;
        }

        // we have to add another functionality to add to file
        // void addToFile(){
        //     std::cout << "Added invoice to db." << std::endl;
        // }
        // also another function function to add to backup db
        // void addToBackupDB(){
        //     std::cout << "Added invoice to db." << std::endl;
        // }
};

int main(){
    Marker m;
    m.price = 10;
    m.name = "coffee";

    Invoice in(m,2);
    InvoicePrinter printer(in);
    printer.printInvoice();

    InvoiceDAO dao(in);
    dao.addInvoiceToDB();
}
