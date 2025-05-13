#include <iostream>
using namespace std;
// membuat struktur untuk object double linkedlist
struct node
{
    // deklarasi noMhs dan name untuk menampung data
    int noMhs;
    string name;
    node *next;
    node *prev;
};
 node *start = NULL;
