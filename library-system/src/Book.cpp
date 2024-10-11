// src/Book.cpp
#include "Book.h"

// Constructor
Book::Book(const std::string& t, const std::string& a, const std::string& i)
    : title(t), author(a), ISBN(i), available(true) {}

// Implement borrow method
void Book::borrow() {
    if (available) {
        available = false;
        std::cout << "Sách '" << title << "' đã được mượn." << std::endl;
    } else {
        std::cout << "Sách '" << title << "' không có sẵn để mượn." << std::endl;
    }
}

// Implement returnItem method
void Book::returnItem() {
    available = true;
    std::cout << "Sách '" << title << "' đã được trả lại." << std::endl;
}

// Implement isAvailable method
bool Book::isAvailable() const {
    return available;
}

// Getter methods
std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

std::string Book::getISBN() const {
    return ISBN;
}
