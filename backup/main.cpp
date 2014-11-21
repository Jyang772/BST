#include <iostream>

#include "menu.h"
#include "student.h"
#include "tree.h"

#define _AFXDLL
#include <afxwin.h>
#define new DEBUG_NEW

using namespace std;

ostream& operator<<(ostream&, const TreeNode&);


int main()
{
    int *pt = new int;

    ifstream file;
    file.open("students.dat");


    Tree tree;

	int test[3] = {100,90,100};
    int test2[3] = {80,90,100};
    int test3[3] = {90,90,90};
    Student student("Mr. Mead",18,"Computer Science",test,1337);
    Student student2("Saxton Hale",18,"Mathematics",test2,1000);
    Student student3("Banana",18,"Computer Science",test3,2000);
    Student student4("ZZZZ",18,"Computer Science",test,10);

    Student student5("RRR",18,"Computer Science",test,1337);
    Student student6("Alpha",19,"Computer Science",test,1337);

    tree.Insert(student);
    tree.Insert(student2);
    tree.Insert(student3);
    tree.Insert(student4);

	Tree tree2;
	tree2 = tree;
	cout << tree2 << endl;

    //std::vector<Student> students;
    //tree.getPeopleWithAvg(90,students);
    //tree.getPeopleWithMajor("Computer Science",students);
    //tree.getPeopleWithMaxAvg(students);
    //cout << tree.getHeight() << endl;
    //tree.printLevels();

//    for(auto i : students)
//        i.writeToScreen();

    //    Student temp;
    //    temp.m_id = 1337;

    //    cout << tree.Lookup(temp);
    //    cout << temp << endl;
    //    tree.Delete(1337);
    //    tree.Print();


  //  Menu menu(&tree);
  //  bool done = false;
  //  int choice;

  //  while(!done){

  //      cout << "[1] Read File Data\n";
  //      cout << "[2] Write to File\n";
  //      cout << "[3] Search for student by ID\n";
  //      cout << "[4] Add student\n";
  //      cout << "[5] Remove student\n";
  //      cout << "[6] Display data\n";
  //      cout << "[7] Get Max Average\n";
		//cout << "[8] Exit Program\n";

  //      cout << "Select an option: ";
  //      cin >> choice;

  //      switch(choice){

  //      case 1:
  //          menu.readFileData();
  //          break;
  //      case 2:
  //          menu.writeFileData();
  //          break;
  //      case 3:
  //          menu.search();
  //          break;
  //      case 4:
  //          menu.add();
  //          break;
  //      case 5:
  //          menu.remove();
  //          break;
  //      case 6:
  //          menu.display();
  //          break;
  //      case 7:
  //          menu.getMaxAvg();
  //          break;
		//case 8:
		//	done = true;
  //      default:
  //          break;

  //      }



  //  }



    return 0;
}


	//int test[3] = {100,90,100};
    //int test2[3] = {80,90,100};
    //int test3[3] = {90,90,90};
    //Student student("Mr. Mead",18,"Computer Science",test,1337);
    //Student student2("Saxton Hale",18,"Mathematics",test2,1000);
    //Student student3("Banana",18,"Computer Science",test3,2000);
    //Student student4("ZZZZ",18,"Computer Science",test,10);

    //Student student5("RRR",18,"Computer Science",test,1337);
    //Student student6("Alpha",19,"Computer Science",test,1337);

    //tree.Insert(student);
    //tree.Insert(student2);
    //tree.Insert(student3);
    //tree.Insert(student4);

    //std::vector<Student> students;
    //tree.getPeopleWithAvg(90,students);
    //tree.getPeopleWithMajor("Computer Science",students);
    //tree.getPeopleWithMaxAvg(students);
    //cout << tree.getHeight() << endl;
    //tree.printLevels();

//    for(auto i : students)
//        i.writeToScreen();

    //    Student temp;
    //    temp.m_id = 1337;

    //    cout << tree.Lookup(temp);
    //    cout << temp << endl;
    //    tree.Delete(1337);
    //    tree.Print();
