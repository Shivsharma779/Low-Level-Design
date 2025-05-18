# Single Responsibility Principle (SRP)

This directory demonstrates the Single Responsibility Principle (SRP) from SOLID principles.

## Incorrect Example

In `Incorrect.cpp`, the `Invoice` class is responsible for:

- Calculating the total invoice price
- Printing the invoice
- Adding the invoice to the database

This violates SRP because changes in printing or database logic require changes to the `Invoice` class.

## Correct Example

In `Correct.cpp`, responsibilities are separated:

- `Invoice` handles only invoice data and calculation.
- `InvoicePrinter` handles printing.
- `InvoiceDAO` handles database operations.

This adheres to SRP, making the code easier to maintain and extend.
