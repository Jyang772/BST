#ifndef TREE_H
#define TREE_H

#include "student.h"

#include <iomanip>
#include <vector>
#include <cmath>
#include <deque>
#include <sstream>
#include <string>
#include <cmath>

struct TreeNode{
    Student m_student;

    TreeNode* m_left;
    TreeNode* m_right;
    TreeNode(const Student& student, TreeNode* left = NULL, TreeNode* right = NULL){
        m_student = student;
        m_left = left;
        m_right = right;
    }
};


class Tree
{
    friend ostream& operator<<(ostream& os, Tree& tree);

public:
    Tree();
    Tree(const Tree& tree2);
    ~Tree(){
        Clear(m_root);
    }

    bool Insert(const Student &student);



    bool IsEmpty() const;
    int Size() const;
    bool Delete(int id);
    bool Lookup(Student &student) const;
    void Print() const;

    Tree& operator=(const Tree& tree2);
    void PrintFile(ofstream& of);
    int getHeight();

    //EXTRA
    //void PrintTree(ostream& os, TreeNode* pTree);

    double getMaxAvg();
    void getMaxAvg(double &max, TreeNode *pTree);
    void getPeopleWithAvg(int average, std::vector<Student>&);
    void getPeopleWithAvg(int average, std::vector<Student>&, TreeNode*);
    void getPeopleWithMajor(string major, std::vector<Student>&);
    void getPeopleWithMajor(string major, std::vector<Student>&, TreeNode*);
    void getPeopleWithMaxAvg(std::vector<Student>&);
    void getPeopleWithMaxAvg(double &max, std::vector<Student>&, TreeNode*);
    void printLevels();

    void PrintTree2(TreeNode* pTree,int level, int indentSpace, ostream&);
    void printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<TreeNode*>& nodesQueue, ostream& out);
    void printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, int currentLevel, const deque<TreeNode*>& nodesQueue, ostream& out);
    void printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<TreeNode*>& nodesQueue, ostream& out);


private:
    TreeNode* m_root;

    bool Insert(const Student &student, TreeNode*& pTree);
    int Size(TreeNode* pTree) const;

    void Print(ostream& os, TreeNode* pTree) const;
    void PrintFile(ofstream &of, TreeNode* pTree) const;

    void Lookup(Student &student, TreeNode* pTree, bool &found) const;

    bool Delete(int id, TreeNode*& pTree);
    void DeleteNode(TreeNode*& pTree);
    void GetPredecessor(TreeNode* pTree, Student&);

    void Print(TreeNode* pTree) const;

    void Clear(TreeNode* pTree);
    void Copy(const Tree& list2);
    void Copy(TreeNode*& pThis, TreeNode* pTree2);



    //EXTRA
    int getHeight(TreeNode *pTree);
    int height;

};




#endif // TREE_H
