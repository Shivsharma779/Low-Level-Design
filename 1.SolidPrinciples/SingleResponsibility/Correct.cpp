#include <iostream>
#include <string>

class Marker{
    public:
        int price;
        std::string name;
};

// the problem with invoice class is that it has multiple responsibilities
// 1. calculating total of invoice 
// 2. printing the invoice
// 3. adding the invoice to database

// as the class has multiple resposibilites any of the task if changes 
// we have to update the class

// we can solve this problem by diving the class responsibilities 
// to multiple classes
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

};

class InvoicePrinter{
    private:
        Invoice in;
    public:
        InvoicePrinter() = delete;
        InvoicePrinter(Invoice in): in(in) {};
        // function for printing the invoice
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
    // in.printInvoice(); this has moved to invoicePrinter
    InvoicePrinter printer(in);
    printer.printInvoice();

    InvoiceDAO dao(in);
    dao.addInvoiceToDB();
}