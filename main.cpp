#include <iostream>

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
    Student student2("Saxton Hale",18,"Computer Science",test,1337);
    Student student3("Banana",18,"Computer Science",test,1337);
    Student student4("ZZZZ",18,"Computer Science",test,1337);
    Student student5("RRR",18,"Computer Science",test,1337);
    Student student6("Alpha",19,"Computer Science",test,1337);



    tree.Insert(student);
    tree.Insert(student2);
    tree.Insert(student3);
    //tree.Insert(student4);
    //tree.Insert(student5);
    //tree.Insert(student6);

//    Student students[4];
//    students[0].readFromFile(file);
//    students[1].readFromFile(file);
//    students[2].readFromFile(file);
//    students[3].readFromFile(file);

//    tree.Insert(students[0]);
//    tree.Insert(students[1]);
//    tree.Insert(students[2]);
    //tree.Insert(students[2]);




    cout << tree.getHeight() << endl;
    //cout << tree << endl;
    cout << tree << endl;
    //tree.PrintTree();




    cout << "Hello World!" << endl;
    return 0;
}

