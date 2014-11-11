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
    void add();
    void remove();
    void display();

private:
    Tree *tree;

};

#endif // MENU_H
