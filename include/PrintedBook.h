#ifndef PRINTED_BOOK_H
#define PRINTED_BOOK_H

#include "Book.h"

// A physical copy — has a shelf location, and only one person can hold it.
class PrintedBook : public Book {
private:
    std::string shelfLocation;

public:
    PrintedBook(std::string title, std::string author, std::string isbn,
                std::string shelfLocation)
        : Book(std::move(title), std::move(author), std::move(isbn)),
          shelfLocation(std::move(shelfLocation)) {}

    const std::string& getShelfLocation() const { return shelfLocation; }

    std::string typeName() const override { return "Printed"; }

    void display() const override {
        Book::display();
        std::cout << " | Shelf: " << shelfLocation << "\n";
    }
};

#endif // PRINTED_BOOK_H
