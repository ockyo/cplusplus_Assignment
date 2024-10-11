#ifndef BORROWABLE_H
#define BORROWABLE_H
class Borrowable{
    public:
        virtual void borrow() = 0;
        virtual void returnItem() = 0;
        virtual bool isAvailable() const = 0;
        virtual ~Borrowable () = default;
};
#endif 