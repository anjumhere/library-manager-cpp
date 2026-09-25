#ifndef BOOK_H
#define BOOH_H
#include <string>

using std::string;

class Book {
protected:
  string title;
  string author;
  string isbn;
  bool isIssued;

public:
  Book(const string &title, const string &author, const string &isbn);

  virtual ~Book() = default;

  // getters

  string getTitle() const;
  string getAuthor() const;
  string getIsbn() const;
  bool getIsIssued() const;

  // behaviour comon to all books;
  void issue();
  void returnBook();
  virtual void displayInfo() const = 0;
  virtual std::string getType() const = 0;
};

#endif
