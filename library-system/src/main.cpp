// src/main.cpp
#include "Library.h"
#include "Book.h"
#include "DVD.h"
#include <memory>

int main() {
    Library library;

    // Thêm sách vào thư viện
    library.addItem(std::make_unique<Book>("1984", "George Orwell", "123-456-789"));
    library.addItem(std::make_unique<Book>("To Kill a Mockingbird", "Harper Lee", "987-654-321"));

    // Thêm DVD vào thư viện
    library.addItem(std::make_unique<DVD>("Inception", "Christopher Nolan", 148));
    library.addItem(std::make_unique<DVD>("The Matrix", "The Wachowskis", 136));

    // Hiển thị các mục có sẵn
    library.displayAvailableItems();

    // Mượn một sách và một DVD
    library.borrowItem("1984");
    library.borrowItem("Inception");

    // Hiển thị lại các mục có sẵn
    library.displayAvailableItems();

    // Trả lại một mục
    library.returnItem("1984");

    // Hiển thị lại các mục có sẵn
    library.displayAvailableItems();

    return 0;
}
