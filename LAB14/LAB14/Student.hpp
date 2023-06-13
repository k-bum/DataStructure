#ifndef Student_hpp
#define Student_hpp

#include <iostream>
#include <string>

using namespace std;

class Student
{
public :
    void Print(ostream& out);
    //void InitValue(int _id, char* _name, float _gpa);
    //void getValue(int& _id, char* _name, float& _gpa);
    void InitValue(int _id, string _name, float _gpa);
    void getValue(int& _id, string _name, float& _gpa);
    //char* getName();
    string getName();
    void operator = (Student stu);
    string Key();
    bool operator == (const Student& other) const;
    bool operator != (const Student& other) const;
    Student EmptyKey();
    
private :
    int id;
    //char name[30];
    string name;
    float gpa;
};

void Swap(Student& item1, Student& item2);
void Swap(Student*& item1, Student*& item2);
void Print(ostream& out, Student stu[], int numelement);
void PrintByPointer(ostream& out, Student* values[], int numValues);

#endif /* Student_hpp */
