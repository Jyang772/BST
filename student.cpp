#include "student.h"

Student::Student()
{
}

Student::Student(string name, int age, string major, int tests[], int id){

    m_name = name;
    m_age = age;
    m_major = major;

   // std::copy(std::begin(tests),std::end(tests),std::begin(m_test));
    std::copy(tests,tests+3,m_test);
    m_id = id;

}

bool Student::operator <(Student& other) const{

//    if(m_name.compare(other.m_name) < 0)
//        return true;
    if(this->m_id < other.m_id)
        return true;

    return false;

}

bool Student::operator <(int id) const{
    if(id > this->m_id)
        return true;
    return false;
}

bool Student::operator >(Student& other) const{

//    if(m_name.compare(other.m_name) > 0)
//        return true;

    if(this->m_id > other.m_id)
        return true;

    return false;
}

bool Student::operator >(int id) const{
    if(id < this->m_id )
        return true;
    return false;
}

ostream& operator <<(ostream& os, Student& other) {


    os << other.m_name << endl;
    os << other.m_major << endl;
    os << other.m_age << endl;
    os << other.m_test[0] << " ";
    os << other.m_test[1] << " ";
    os << other.m_test[2] << endl;
    os << other.m_id << endl;

//    os << other.m_name << ", ";
//    os << other.m_major << ", ";
//    os << other.m_age << ", ";
//    os << other.m_test[0] << ", ";
//    os << other.m_test[1] << ", ";
//    os << other.m_test[2] << ", ";
//    os << other.m_id << endl;

    return os;
}

bool Student::readFromFile(ifstream &is){



    string sentinel = "***";

    getline(is,m_name);

    if(m_name == sentinel){
        return false;
    }

    getline(is, m_major);
    is >> m_age;
    is >> m_test[0];
    is >> m_test[1];
    is >> m_test[2];
    is >> m_id;
    is.ignore();

    return true;

}

void Student::writeToFile(ofstream &os){

    os << this->m_name;
    os << this->m_major;
    os << this->m_age;
    os << this->m_test[0];
    os << this->m_test[1];
    os << this->m_test[2];
    os << this->m_id;
}

void Student::writeToScreen(){
    //Using \n for efficiency. Don't have to flush the output stream every time with std::endl


    std::cout << this->m_name << "\n";
    std::cout << this->m_major << "\n";
    std::cout << this->m_age << "\n";
    std::cout << this->m_test[0] << "\n";
    std::cout << this->m_test[1] << "\n";
    std::cout << this->m_test[2] << "\n";
    std::cout << this->m_id << std::endl;
}

ostream& Student::writeTree(ostream& os, int length){


    for(int i=0; i<length; i++)
        os << " ";
      os << this->m_name << std::endl;

    for(int i=0; i<length; i++)
          os << " ";
    os << this->m_major << std::endl;


    for(int i=0; i<length; i++)
        os << " ";
    os << this->m_age << std::endl;


    for(int i=0; i<length; i++)
        os << " ";

    os << this->m_test[0] << std::endl;

    for(int i=0; i<length; i++)
        os << " ";
    os << this->m_test[1] << std::endl;

    for(int i=0; i<length; i++)
        os << " ";

    os << this->m_test[2] << std::endl;

    for(int i=0; i<length; i++)
        os << " ";
    os << this->m_id << std::endl;

    //Get Max length from all strings.

    //Maybe use array for keeping track of each line at each level.

    return os;

}

double Student::getAverage(){

    return (double(m_test[0] + m_test[1] + m_test[2]) / 3);
}
