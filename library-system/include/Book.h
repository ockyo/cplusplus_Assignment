#ifndef BOOK_H
#define BOOK_H

#include "Borrowable.h"
#include <string>
#include <iostream>

class Book : public Borrowable {
private:
    std::string title;
    std::string author;
    std::string ISBN;
    bool available;
public:
    Book(const std::string& t, const std::string& a, const std::string& i);
    
    void borrow() override;
    void returnItem() override;
    bool isAvailable() const override;

    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getISBN() const;
};

#endif // BOOK_H