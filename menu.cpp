#include "menu.h"

Menu::Menu()
{
}

void Menu::readFileData(){

    ifstream file;
    std::string fileName;
    std::vector<Student> students;
    Student temp;

    std::cout << "Enter file name: ";
    std::cin >> fileName;

    file.open(fileName.c_str());

    if(file.is_open()){

    while(temp.readFromFile(file)){
        students.push_back(temp);
    }

    }
    else{
        cout << "Error. File does not exist!\n";
        return;
    }

    for(auto i : students){
        tree->Insert(i);
    }
    cout << "OVER" << endl;
}

void Menu::writeFileData(){

    ofstream file;
    std::string fileName;

    std::cout << "Enter file name: ";
    std::cin >> fileName;

    file.open(fileName);

    tree->PrintFile(file);
    file << "***";
    file.close();
    //tree->PrintTree(file,tree->m_root);
}

void Menu::search(){

    int id;
    std::cout << "Enter student id: ";
    std::cin >> id;

    Student temp;
    temp.m_id = id;

    if(tree->Lookup(temp)){
        cout << "Student Found: \n";
        cout << temp << endl;
    }
    else{
        cout << "Student Not Found.\n";
    }

}

void Menu::add(){

    std::string name;
    std::string major;
    int age;
    int test[3];
    int id;

    std::cout << "Name: ";
    std::cin >> name;
    std::cout << "Major: ";
    std::cin >> major;
    std::cout << "Age: ";
    std::cin >> age;

    std::cout << "Test #1: ";
    std::cin >> test[0];

    std::cout << "Test #2: ";
    std::cin >> test[1];
    std::cout << "Test #3: ";
    std::cin >> test[2];

    std::cout << "ID: ";
    std::cin >> id;

    Student insert(name,age,major,test,id);

    tree->Insert(insert);

}

void Menu::remove(){

    int id;

    std::cout << "Enter ID of student: ";
    std::cin >> id;

    if(tree->Delete(id)){
        cout << "Student deleted.\n";
    }


}

void Menu::display(){

    //tree->Print();
    cout << *tree << endl;
}
