#ifndef MENU_H
#define MENU_H

#include "tree.h"

#include <iostream>
#include <fstream>

using namespace std;

class Menu
{
public:
    Menu();
    Menu(Tree* tree){
        this->tree = tree;
    }

    void readFileData();
    void writeFileData();
    void search();
    void searchByName();
    void add();
    void remove();
    void display();

    void getMaxAvg();

private:
    Tree *tree;

};

#endif // MENU_H
