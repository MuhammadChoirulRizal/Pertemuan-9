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
 void addNode(){
    node *newnode = new node();
    cout << "\nEnter the roll number of the student :";
    cin >> newnode->noMhs;
    cout << "\nEnter the name of the student :";
    cin >> newnode -> name;

    // insert the new code in the list
    // kondisi jika star == null atau noMhs node baru <= no Mhs start
 }
