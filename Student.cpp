#include <iostream>
using namespace std;
class Student
{
private:
    string name;
    int age;
    float gpa;

public:
    Student(string name, int age, float gpa) : name(name), age(age), gpa(gpa) {}
    string getName() const { return name; }
    int getAge() const { return age; }
    float getGPA() const { return gpa; }

    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setGPA(float g) { gpa = g; }
    void displayInfo() const
    {
        cout << "Ten: " << name << endl;
        cout << "Tuoi: " << age << endl;
        cout << "GPA: " << gpa << endl;
    }
};

int main()
{
    Student s1("Nguyen Van A", 20, 3.5);
    cout << "Thong tin sinh vien:" << endl;
    s1.displayInfo();
    s1.setGPA(3.8);

    cout << "Thong tin sinh vien:" << endl;
    s1.displayInfo();
    return 0;
}