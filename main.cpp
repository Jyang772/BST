#include <iostream>

#include "menu.h"
#include "student.h"
#include "tree.h"

using namespace std;

ostream& operator<<(ostream&, const TreeNode&);


int main()
{

    ifstream file;
    file.open("students.dat");
    int test[3] = {100,100,100};
    Tree tree;
    Student student("Mr. Mead",18,"Computer Science",test,1337);
    Student student2("Saxton Hale",18,"Computer Science",test,1000);
    Student student3("Banana",18,"Computer Science",test,2000);
    Student student4("ZZZZ",18,"Computer Science",test,1337);
    Student student5("RRR",18,"Computer Science",test,1337);
    Student student6("Alpha",19,"Computer Science",test,1337);

    tree.Insert(student);
    tree.Insert(student2);
    tree.Insert(student3);


    tree.Delete(1337);


    cout << tree << endl;

//    Menu menu(&tree);
//    bool done = false;
//    int choice;

//    while(!done){

//        cout << "[1] Read File Data\n";
//        cout << "[2] Write to File\n";
//        cout << "[3] Search for student\n";
//        cout << "[4] Add student\n";
//        cout << "[5] Remove student\n";
//        cout << "[6] Display data\n";

//        cout << "Select an option: ";
//        cin >> choice;

//        switch(choice){

//        case 1:
//            menu.readFileData();
//            break;
//        case 2:
//            menu.writeFileData();
//            break;
//        case 3:
//            menu.search();
//            break;
//        case 4:
//            menu.add();
//            break;
//        case 5:
//            menu.remove();
//            break;
//        case 6:
//            menu.display();
//            break;
//        default:
//            break;

//        }



//    }






    cout << "Hello World!" << endl;
    return 0;
}

