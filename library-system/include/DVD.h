// include/DVD.h
#ifndef DVD_H
#define DVD_H

#include "Borrowable.h"
#include <string>
#include <iostream>

class DVD : public Borrowable {
private:
    std::string title;
    std::string director;
    int duration; // thời lượng tính bằng phút
    bool available;
public:
    DVD(const std::string& t, const std::string& d, int dur);
    
    void borrow() override;
    void returnItem() override;
    bool isAvailable() const override;

    std::string getTitle() const;
    std::string getDirector() const;
    int getDuration() const;
};

#endif // DVD_H
