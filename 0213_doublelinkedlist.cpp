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
void addNode()
{
    node *newnode = new node();
    cout << "\nEnter the roll number of the student :";
    cin >> newnode->noMhs;
    cout << "\nEnter the name of the student :";
    cin >> newnode->name;

    // insert the new code in the list
    // kondisi jika star == null atau noMhs node baru <= no Mhs start
    if (start == NULL || newnode->noMhs <= start->noMhs)
    {
        // step 2 insert  the new node at the beginning
        // kondisi jika star tidak kosong dan noMhs node baru sama dengan noMhs
        if (start != NULL && newnode->noMhs == start->noMhs)
        {
            cout << "\033[31mdumplicate roll number not allowed\033[0m" << endl;
            return;
        }
        newnode->next = start;
        if (start != NULL)
        {
            start->prev = newnode;
            newnode->prev = NULL;
            start = newnode;
        }
        else
        {
            node *current = start;
            node *previous = NULL;
            while (current != NULL && current->noMhs < newnode->noMhs)
            {
                previous = current;
                current = current->next;
            }
            newnode->next = current;
            newnode->prev = previous;

            if (current != NULL)
            {
                current->prev = newnode;
            }
            else
            {
                start = newnode;
            }
        }
    }
}
bool search(int rollNo, node **previous, node **current)
{
    *previous = NULL;
    *current = start;
    while (*current != NULL && (*current)->noMhs != rollNo)
    {
        *previous = *current;
        *current = (*current)->next;
    }
    return (*current != NULL);
}
void deleteNode()
{
    node *previous, *current;
    int rollNo;

    cout << "\nEnter the roll number of the student whose record is to be deleted: ";
    cin >> rollNo;

    if (start == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    current = start;
    previous = NULL;
    while (current != NULL && current->noMhs != rollNo)
    {
        previous = current;
        current = current->next;
    }
    if (current == NULL)
    {
        cout << "\033[31mThe record with roll number " << rollNo << " not found\033[0m" << endl;
        return;
    }
    if (current == start)
    {
        start = start->next;
        if (start != NULL)
        {
            start->prev = NULL;
        }
    }
    else
    {
        previous->next = current->next;
        if (current->next != NULL)
        {
            current->next->prev = previous;
        }
    }

    delete current;
    cout << "\x1b[32mRecord with roll number " << rollNo << " deleted\x1b[0m" << endl;
}
bool listEmpty()
{
    return (start == NULL);
}
void traverse()
{
    if (listEmpty())
        cout << "\nList is empty" << endl;
    else
    {
        cout << "\nRecords in ascending order of roll number are: " << endl;
        node *currentNode = start;
        while (currentNode != NULL)
        {
            cout << currentNode->noMhs << " " << currentNode->name << endl;
            currentNode = currentNode->next;
        }
    }
}
void revtraverse()
{
    if (listEmpty())
        cout << "\nList is emty" << endl;
    else
    {
        cout << "\nRecords in descending order pf roll number are:" << endl;
        node *currentNode = start;
        while (currentNode->next != NULL)
            currentNode = currentNode->next;

        while (currentNode != NULL)
        {
            cout << currentNode->noMhs << " " << currentNode->name << endl;
            currentNode = currentNode->prev;
        }
    }
}
// prosedure untuk mencari data dan menampilkan data yang dicari jika ada
void searchData()
{
    if (listEmpty() == true)
    {
        cout << "\nList is empty" << endl;
    }
    node *prev, *curr;
    prev = curr = NULL;
    cout << "\nEnter the roll number of the student whose record you want to search: ";
    int num;
    cin >> num;
    if (search(num, &prev, &curr) == false)
        cout << "\nRecord not found" << endl;
    else
    {
        cout << "\nRecord found" << endl;
        cout << "\nRoll number: " << curr->noMhs << endl;
        cout << "\nName: " << curr->name << endl;
    }
}
