#include <iostream>
#include <string>
#include <memory>

// we have to add another functionality to add to file 
// in the class InvoiceDAO
// void addToFile(){
//     std::cout << "Added invoice to db." << std::endl;
// }
// also another function function to add to backup db
// void addToBackupDB(){
//     std::cout << "Added invoice to db." << std::endl;
// }


// This class has already been developed tested and live in produciton
// we shouldn't make any changes in the file
// to fix this problem may be we can create and interface that provides saving options
// and use that interface to implement the classes

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

//inv
class InvoiceSaver{
    public:
        virtual void SaveInvoice() const = 0;
        virtual ~InvoiceSaver() = default;
};

// now this file is close for modication or
// concrete implementation is closed 
// if we want to do another implemenetaiton of Invoice Saver
// we will EXTEND it and create another class 
// which allows us to follow the open for extension and close for modification principle
class InvoiceDBSaver: public InvoiceSaver{
    private:
        const Invoice& in;
    public:
        InvoiceDBSaver() = delete;
        InvoiceDBSaver(const Invoice& in): in(in) {};
        void SaveInvoice() const override{
            std::cout << "Added invoice to db." << std::endl;
        }

};

class InvoiceFileSave: public InvoiceSaver{
    private:
        const Invoice& in;
    public:
        InvoiceFileSave() = delete;
        explicit InvoiceFileSave(const Invoice& in): in(in) {};
        void SaveInvoice() const override{
            std::cout << "Added invoice to file." << std::endl;
        }

};


class InvoiceBackupDBSaver: public InvoiceSaver{
    private:
        const Invoice& in;
    public:
        explicit InvoiceBackupDBSaver(const Invoice& in): in(in) {};
        void SaveInvoice() const override{
            std::cout << "Added invoice to backup db." << std::endl;
        }
};

int main(){
    Marker m;
    m.price = 10;
    m.name = "coffee";

    Invoice in(m,2);
    InvoicePrinter printer(in);
    printer.printInvoice();

    std::unique_ptr<InvoiceSaver> dbSaver = std::make_unique<InvoiceDBSaver>(in);
    dbSaver->SaveInvoice();

    std::unique_ptr<InvoiceSaver> fileSaver = std::make_unique<InvoiceFileSave>(in);
    fileSaver->SaveInvoice();

    std::unique_ptr<InvoiceSaver> backupSaver = std::make_unique<InvoiceBackupDBSaver>(in);
    backupSaver->SaveInvoice(); 


    return 0;
}
