// include/Library.h
#ifndef LIBRARY_H
#define LIBRARY_H

#include "Borrowable.h"
#include <vector>
#include <memory>
#include <string>

class Library {
private:
    std::vector<std::unique_ptr<Borrowable>> items;
public:
    void addItem(std::unique_ptr<Borrowable> item);
    void borrowItem(const std::string& title);
    void returnItem(const std::string& title);
    void displayAvailableItems() const;
};

#endif // LIBRARY_H
