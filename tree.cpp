#include "tree.h"




#define MAX(x,y) (x > y) ? x : y

Tree::Tree()
{
    m_root = nullptr;
}

bool Tree::Insert(const Student& student){

    return Insert(student, m_root);
}

bool Tree::IsEmpty() const{
    if(Size() == 0)
        return true;
    return false;
}

int Tree::Size() const{

    return Size(m_root);
}

bool Tree::Lookup(Student &student) const{

    return Lookup(student,m_root);
}

bool Tree::Delete(int id){

    return Delete(id,m_root);
}

void Tree::Print() const{
    Print(m_root);
}

ostream& operator<<(ostream& os, Tree& tree){

    //tree.Print(os,tree.m_root);
    //tree.PrintTree(os,tree.m_root);
    tree.PrintTree2(tree.m_root,8,7,os);
    return os;
}

//EXTRA public functions
int Tree::getHeight(){

    return getHeight(m_root);
}


//Private Helper Functions

int Tree::Size(TreeNode *pTree) const{
    //Precondition: pTree is valid pointer
    //Postcondition: Returns length of tree recursively.

    if(pTree == nullptr){
        return 0;
    }
    else
        return Size(pTree->m_left) + Size(pTree->m_right) + 1;
}

bool Tree::Lookup(Student &student, TreeNode *pTree) const{

    if(pTree == nullptr){
        return false;
    }
    else{
        if(student < pTree->m_student){
            Lookup(student,pTree->m_left);
        }
        else if(student > pTree->m_student){
            Lookup(student,pTree->m_right);
        }
        else
            return true;

    }

    return false;

}

bool Tree::Insert(const Student &student, TreeNode *&pTree){

    //Passing pointer by value vs. by reference.
    //Modifying the calling pointer - by reference.

    //Recursive.

    if(pTree == 0){
        pTree = new TreeNode(student);
    }

    else if(student < pTree->m_student){
        Insert(student,pTree->m_left);
    }
    else
        Insert(student,pTree->m_right);

    return true;
}

bool Tree::Delete(int id, TreeNode *&pTree){

    if(pTree->m_student > id){
        Delete(id,pTree->m_left);
    }
    else if(pTree->m_student < id){
        Delete(id,pTree->m_right);
    }
    else
        DeleteNode(pTree);
}

void Tree::DeleteNode(TreeNode *&pTree){

    Student data;
    TreeNode* temp;

    temp = pTree;

    if(pTree->m_left == nullptr){
        pTree = pTree->m_right;
        delete temp;
    }
    else if(pTree->m_right == nullptr){
        pTree = pTree->m_left;
        delete temp;
    }
    else{
        GetPredecessor(pTree->m_left,data);
        pTree->m_student = data;
        Delete(data.getID(),pTree);
    }
}

void Tree::GetPredecessor(TreeNode *pTree, Student &data){
    while(pTree->m_right != nullptr){
        pTree = pTree->m_right;
    }
    data = pTree->m_student;
}

void Tree::Clear(TreeNode *pTree){

    if(pTree == nullptr)
        return;

    Clear(pTree->m_left);
    Clear(pTree->m_right);

    delete pTree;

}

void Tree::Copy(const Tree &list2){
    Copy(m_root,list2.m_root);

}

void Tree::Copy(TreeNode *&pThis, TreeNode *pTree2){

    if(pThis == nullptr)
        pTree2 == nullptr;

    else
    {
        pTree2 = new TreeNode(pThis->m_student);
        pTree2->m_student = pThis->m_student;
        Copy(pTree2->m_left,pThis->m_left);
        Copy(pTree2->m_right,pThis->m_right);
    }


}


void Tree::Print(TreeNode *pTree) const{


}

void Tree::Print(ostream &os, TreeNode *pTree) const{
    if(pTree != nullptr){

        Print(os,pTree->m_left);
        os << pTree->m_student;
        Print(os,pTree->m_right);

    }

}



//EXTRA

int Tree::getHeight(TreeNode *pTree){

    if(pTree == nullptr){
        return -1;
    }

   return MAX(getHeight(pTree->m_left), getHeight(pTree->m_right)) + 1;



}

void Tree::PrintTree(ostream& os, TreeNode *pTree) {

    if(pTree == m_root)
        height = 2;



//    if(pTree != nullptr){
//        int length = pTree->m_student.m_major.size()*height;
//        pTree->m_student.writeTree(os,length);
//        for(int i=0; i<pTree->m_student.m_name.size()*height; i++)
//            os << "\t";
//        os << "/\n";

//        cout << "Printing level: " << height << endl;
//        PrintTree(os,pTree->m_left);
//        PrintTree(os,pTree->m_right);

//    }

}

void Tree::PrintTree2(TreeNode* pTree, int level, int indentSpace, ostream& out ){

    int h = getHeight(m_root)+2;
    cout << h << endl;
    int nodesInThisLevel = 1;

    int branchLen = 2*((int)pow(2.0,h)-1) - (3-level)*(int)pow(2.0,h-1);
    int nodeSpaceLen = 2 + (level+1)*(int)pow(2.0,h);
    int startLen = branchLen + (3-level) + indentSpace;

    deque<TreeNode*> nodesQueue;
    nodesQueue.push_back(m_root);
    for (int r = 1; r < h; r++) {
      printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
      branchLen = branchLen/2 - 1;
      nodeSpaceLen = nodeSpaceLen/2 + 1;
      startLen = branchLen + (3-level) + indentSpace;
      printNodes(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, r, nodesQueue, out);

      for (int i = 0; i < nodesInThisLevel; i++) {
        TreeNode *currNode = nodesQueue.front();
        nodesQueue.pop_front();
        if (currNode) {
            nodesQueue.push_back(currNode->m_left);
            nodesQueue.push_back(currNode->m_right);
        } else {
          nodesQueue.push_back(NULL);
          nodesQueue.push_back(NULL);
        }
      }
      nodesInThisLevel *= 2;
    }
    printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
    printLeaves(indentSpace, level, nodesInThisLevel, nodesQueue, out);


}


void Tree::printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<TreeNode*>& nodesQueue, ostream& out) {
    deque<TreeNode*>::const_iterator iter = nodesQueue.begin();
    for (int i = 0; i < nodesInThisLevel / 2; i++) {
      out << ((i == 0) ? setw(startLen-1) : setw(nodeSpaceLen-2)) << "" << ((*iter++) ? "/" : " ");
      out << setw(2*branchLen+2) << "" << ((*iter++) ? "\\" : " ");
    }
    out << endl;
}

void Tree::printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, int currentLevel, const deque<TreeNode*>& nodesQueue, ostream& out) {
    deque<TreeNode*>::const_iterator iter = nodesQueue.begin();
    for (int i = 0; i < nodesInThisLevel; i++, iter++) {
      out << ((i == 0) ? setw(startLen) : setw(nodeSpaceLen)) << "" << ((*iter && (*iter)->m_left) ? setfill(' ') : setfill(' '));
      out << setw(branchLen+2) << ((*iter) ? ((*iter)->m_student.m_name) : "");
      out << ((*iter && (*iter)->m_right) ? setfill(' ') : setfill(' ')) << setw(branchLen) << "" << setfill(' ');
    }
    out << endl;
    iter = nodesQueue.begin();
  //
    for (int i = 0; i < nodesInThisLevel; i++, iter++) {
      out << ((i == 0) ? setw(startLen) : setw(nodeSpaceLen-10)) << "" << ((*iter && (*iter)->m_left) ? setfill(' ') : setfill(' '));
      out << setw(branchLen-10) << "" << ((*iter) ? ("major: Computer Science") : "");
      out << ((*iter && (*iter)->m_right) ? setfill(' ') : setfill(' ')) << setw(branchLen) << "" << setfill(' ');
    }
    out << endl;
    iter = nodesQueue.begin();
  //
    for (int i = 0; i < nodesInThisLevel; i++, iter++) {
      out << ((i == 0) ? setw(startLen) : setw(nodeSpaceLen)) << "" << ((*iter && (*iter)->m_left) ? setfill(' ') : setfill(' '));
      out << setw(branchLen+2) << ((*iter) ? ("age: 10") : "");
      out << ((*iter && (*iter)->m_right) ? setfill(' ') : setfill(' ')) << setw(branchLen) << "" << setfill(' ');
    }
    out << endl;
    iter = nodesQueue.begin();
  //

    for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    out << ((i == 0) ? setw(startLen) : setw(nodeSpaceLen-5)) << "" << ((*iter && (*iter)->m_left) ? setfill(' ') : setfill(' '));
    out << setw(branchLen+2+currentLevel) << ((*iter) ? ("tests: 100 100 100") : "");
    out << ((*iter && (*iter)->m_right) ? setfill(' ') : setfill(' ')) << setw(branchLen) << "" << setfill(' ');
    }
    out << endl;
    iter = nodesQueue.begin();
  //
    for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    out << ((i == 0) ? setw(startLen) : setw(nodeSpaceLen)) << "" << ((*iter && (*iter)->m_left) ? setfill('_') : setfill(' '));
    out << setw(branchLen+2) << ((*iter) ? ("id: 1337") : "");
    out << ((*iter && (*iter)->m_right) ? setfill('_') : setfill(' ')) << setw(branchLen) << "" << setfill(' ');
    }

    out << endl;
}


void Tree::printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<TreeNode*>& nodesQueue, ostream& out) {
    deque<TreeNode*>::const_iterator iter = nodesQueue.begin();
    for (int i = 0; i < nodesInThisLevel; i++, iter++) {
      out << ((i == 0) ? setw(indentSpace+2) : setw(2*level+2)) << ((*iter) ? ((*iter)->m_student.m_name) : "");
    }

    out << endl;
    iter = nodesQueue.begin();
    for (int i = 0; i < nodesInThisLevel; i++, iter++) {
      out << ((i == 0) ? setw(indentSpace+2) : setw(2*level+2)) << ((*iter) ? ("major: Computer Science") : "");
    }
    out << endl;
    iter = nodesQueue.begin();
    for (int i = 0; i < nodesInThisLevel; i++, iter++) {
      out << ((i == 0) ? setw(indentSpace+2) : setw(2*level+2)) << ((*iter) ? ("age: 10") : "");
    }
    out << endl;
    iter = nodesQueue.begin();
    for (int i = 0; i < nodesInThisLevel; i++, iter++) {
      out << ((i == 0) ? setw(indentSpace+2) : setw(2*level+2)) << ((*iter) ? ("tests: 100 100 100") : "");
    }
    out << endl;
    iter = nodesQueue.begin();
    for (int i = 0; i < nodesInThisLevel; i++, iter++) {
      out << ((i == 0) ? setw(indentSpace+2) : setw(2*level+2)) << ((*iter) ? ("id: 1337") : "");
    }

  out << endl;
}
