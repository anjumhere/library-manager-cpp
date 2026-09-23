#include <vector>
#include <memory>
#include <iostream>

#include "../include/Book.h"
#include "../include/PrintedBook.h"
#include "../include/EBook.h"

int main() {
    // In-memory catalog: STL vector of polymorphic Book pointers.
    // (Persistence + search + menu are later roadmap items — not here yet.)
    std::vector<std::unique_ptr<Book>> catalog;

    catalog.push_back(std::make_unique<PrintedBook>(
        "The Pragmatic Programmer", "Andrew Hunt", "978-0135957059", "A3-12"));

    catalog.push_back(std::make_unique<EBook>(
        "Effective Modern C++", "Scott Meyers", "978-1491903995", 4.2, 3));

    std::cout << "=== Library Catalog ===\n";
    for (const auto& book : catalog) {
        book->display();
    }

    std::cout << "\n=== Issuing a copy of each ===\n";
    for (auto& book : catalog) {
        bool ok = book->issue();
        std::cout << book->getTitle() << ": "
                  << (ok ? "issued successfully" : "could not be issued") << "\n";
    }

    std::cout << "\n=== Catalog after issuing ===\n";
    for (const auto& book : catalog) {
        book->display();
    }

    return 0;
}
