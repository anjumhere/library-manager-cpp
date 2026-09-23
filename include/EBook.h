#ifndef EBOOK_H
#define EBOOK_H

#include "Book.h"

// A digital copy — has a file size, and can support multiple concurrent
// "issues" up to a license limit instead of a strict single-holder rule.
class EBook : public Book {
private:
    double fileSizeMB;
    int licenseCount;   // total concurrent licenses available
    int activeIssues;   // how many are currently checked out

public:
    EBook(std::string title, std::string author, std::string isbn,
          double fileSizeMB, int licenseCount)
        : Book(std::move(title), std::move(author), std::move(isbn)),
          fileSizeMB(fileSizeMB), licenseCount(licenseCount), activeIssues(0) {}

    double getFileSizeMB() const { return fileSizeMB; }
    int getLicenseCount() const { return licenseCount; }

    // Override: EBooks allow multiple simultaneous issues up to licenseCount
    bool issue() override {
        if (activeIssues >= licenseCount) return false;
        activeIssues++;
        issued = (activeIssues > 0);
        return true;
    }

    bool returnBook() override {
        if (activeIssues <= 0) return false;
        activeIssues--;
        issued = (activeIssues > 0);
        return true;
    }

    std::string typeName() const override { return "EBook"; }

    void display() const override {
        Book::display();
        std::cout << " | Size: " << fileSizeMB << "MB | Licenses: "
                  << activeIssues << "/" << licenseCount << "\n";
    }
};

#endif // EBOOK_H
