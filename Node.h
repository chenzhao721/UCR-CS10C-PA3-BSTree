#ifndef __NODE__
#define __NODE__
#include <string>

using namespace std;
class Node
{
    public:
    string data;
    int count;

    Node *left;
    Node *right;

    Node():count(1),left(0),right(0){};
    Node(const string &datastring){data = datastring; count=1;left=nullptr;right=nullptr;}

};



#endif