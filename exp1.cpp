#include <iostream>
using namespace std;
class Student {
    private:
        int rollno;
        string name;
public:
   //constructor
    Student(int r, string n)
    {
        rollno = r;
        name = n;
        cout << "Student object created" << endl;
    }
    //member function 
    void display()
    {
        cout << "Roll Number: " << rollno << endl;
        cout << "Name: " << name << endl;
    }
    //destructor
    ~Student()
    {
        cout << "Student object destroyed" << endl;
    }
};
int main() {
    Student s1(101, "ARUN");
    s1.display();
    return 0;
}