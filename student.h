#ifndef STUDENT_H
#define STUDENT_H

#include <iterator>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Student
{
    friend ostream& operator << (ostream& os, Student& other);

public:
    Student();
    Student(string name, int age, string major, int tests[], int id);

    bool operator < (Student& other) const;
    bool operator < (int) const;
    bool operator > (Student& other) const;
    bool operator > (int) const;
    bool operator == (int) const;
    bool readFromFile(ifstream& is);

    void writeToFile(ofstream& os);
    void writeToScreen();
    int getID(){ return m_id; }

    //EXTRA
    void setID(int id){
        this->m_id = id;
    }
    string getMajor(){
        return m_major;
    }

    ostream& writeTree(ostream& os, int length);
    double getAverage();


//private:
    string m_name;
    int m_age;
    string m_major;
    int m_test[3];
    int m_id;
};

#endif // STUDENT_H
