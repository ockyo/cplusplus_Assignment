// src/DVD.cpp
#include "DVD.h"

// Constructor
DVD::DVD(const std::string& t, const std::string& d, int dur)
    : title(t), director(d), duration(dur), available(true) {}

// Implement borrow method
void DVD::borrow() {
    if (available) {
        available = false;
        std::cout << "DVD '" << title << "' đã được mượn." << std::endl;
    } else {
        std::cout << "DVD '" << title << "' không có sẵn để mượn." << std::endl;
    }
}

// Implement returnItem method
void DVD::returnItem() {
    available = true;
    std::cout << "DVD '" << title << "' đã được trả lại." << std::endl;
}

// Implement isAvailable method
bool DVD::isAvailable() const {
    return available;
}

// Getter methods
std::string DVD::getTitle() const {
    return title;
}

std::string DVD::getDirector() const {
    return director;
}

int DVD::getDuration() const {
    return duration;
}
