#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

// Base class for all book types in the catalog.
class Book {
protected:
    std::string title;
    std::string author;
    std::string isbn;
    bool issued;

public:
    Book(std::string title, std::string author, std::string isbn)
        : title(std::move(title)), author(std::move(author)),
          isbn(std::move(isbn)), issued(false) {}

    virtual ~Book() = default;

    // Accessors
    const std::string& getTitle() const { return title; }
    const std::string& getAuthor() const { return author; }
    const std::string& getIsbn() const { return isbn; }
    bool isIssued() const { return issued; }

    // Issue/return tracking
    virtual bool issue() {
        if (issued) return false;
        issued = true;
        return true;
    }

    virtual bool returnBook() {
        if (!issued) return false;
        issued = false;
        return true;
    }

    // Every derived type must describe itself (used by display/search later)
    virtual std::string typeName() const = 0;

    // Polymorphic display; derived classes extend this
    virtual void display() const {
        std::cout << "[" << typeName() << "] "
                  << title << " by " << author
                  << " (ISBN: " << isbn << ") - "
                  << (issued ? "Issued" : "Available");
    }
};

#endif // BOOK_H
