#include "Student.hpp"

void Print(ostream& out, Student stu[], int numelement)
{
    for(int i=0; i<numelement; i++)
    {
        stu[i].Print(out);
    }
}
void Student::Print(ostream& out)
{
    out << id << "\t" << name << "\t" << gpa << endl;
}
void Student::InitValue(int _id, string _name, float _gpa)
{
    id = _id;
    //strcpy_s(name, sizeof(name), _name);
    name = _name;
    gpa = _gpa;
}
void Student::getValue(int& _id, string _name, float& _gpa)
{
    _id = id;
    //strcpy_s(_name, sizeof(name), name);
    name = _name;
    _gpa = gpa;
}
string Student::getName()
{
    return name;
}
void Student::operator = (Student stu)
{
    id = stu.id;
    //strcpy_s(name, sizeof(name), stu.name);
    name = stu.name;
    gpa = stu.gpa;
}

void PrintByPointer(ostream& out, Student* values[], int numValues)
{
    for(int i=0; i<numValues; i++)
    {
        (*values[i]).Print(out);
    }
}

string Student::Key()
{
    return name;
}

bool Student::operator==(const Student& other) const
{
    return (this->name == other.name);
}

bool Student::operator!=(const Student& other) const
{
    return (this->name != other.name);
}

Student Student::EmptyKey()
{
    Student empty;
    empty.InitValue(0, "", 0.0);
    return empty;
}
