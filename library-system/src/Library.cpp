// src/Library.cpp
#include "Library.h"
#include "Book.h"
#include "DVD.h"
#include <algorithm>
#include <iostream>

// Thêm mục vào thư viện
void Library::addItem(std::unique_ptr<Borrowable> item) {
    items.push_back(std::move(item));
}

// Mượn mục theo tiêu đề
void Library::borrowItem(const std::string& title) {
    auto it = std::find_if(items.begin(), items.end(),
        [&title](const std::unique_ptr<Borrowable>& item) {
            // Kiểm tra nếu là Book
            if (auto book = dynamic_cast<Book*>(item.get())) {
                return book->getTitle() == title;
            }
            // Kiểm tra nếu là DVD
            if (auto dvd = dynamic_cast<DVD*>(item.get())) {
                return dvd->getTitle() == title;
            }
            return false;
        });

    if (it != items.end()) {
        (*it)->borrow();
    } else {
        std::cout << "Không tìm thấy mục '" << title << "' trong thư viện." << std::endl;
    }
}

// Trả mục theo tiêu đề
void Library::returnItem(const std::string& title) {
    auto it = std::find_if(items.begin(), items.end(),
        [&title](const std::unique_ptr<Borrowable>& item) {
            // Kiểm tra nếu là Book
            if (auto book = dynamic_cast<Book*>(item.get())) {
                return book->getTitle() == title;
            }
            // Kiểm tra nếu là DVD
            if (auto dvd = dynamic_cast<DVD*>(item.get())) {
                return dvd->getTitle() == title;
            }
            return false;
        });

    if (it != items.end()) {
        (*it)->returnItem();
    } else {
        std::cout << "Không tìm thấy mục '" << title << "' trong thư viện." << std::endl;
    }
}

// Hiển thị các mục có sẵn để mượn
void Library::displayAvailableItems() const {
    std::cout << "Danh sách các mục có sẵn để mượn:" << std::endl;
    for (const auto& item : items) {
        if (item->isAvailable()) {
            // Kiểm tra loại đối tượng để hiển thị thông tin phù hợp
            if (auto book = dynamic_cast<Book*>(item.get())) {
                std::cout << "Sách: " << book->getTitle()
                          << " của " << book->getAuthor()
                          << " (ISBN: " << book->getISBN() << ")" << std::endl;
            } else if (auto dvd = dynamic_cast<DVD*>(item.get())) {
                std::cout << "DVD: " << dvd->getTitle()
                          << " của " << dvd->getDirector()
                          << " (Thời lượng: " << dvd->getDuration() << " phút)" << std::endl;
            }
        }
    }
}
