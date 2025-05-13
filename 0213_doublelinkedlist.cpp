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
bool search(int rollNo, node** previous, node** current)
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
    node* previous, * current;
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
        start= start->next;
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
            node* currentNode = start;
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
			node* currentNode = start;
			while (currentNode->next != NULL)
				currentNode = currentNode->next;

			while (currentNode != NULL)
			{
				cout << currentNode->noMhs << " " << currentNode->name << endl;
				currentNode = currentNode->prev;
			}
		}
	}
    
    int main()
    {
        while (true)
        {
            try
            {
                cout << "\nMenu" << endl;
                cout << "1. Add ad record to the list" << endl;
                cout << "2. Delete a record from the list" << endl;
                cout << "3. view all records in the ascending order of roll numbers" << endl;
                cout << "4. view all records in the descending order of roll numbers" << endl;
                cout << "5. Search for a record in the list" << endl;
                cout << "6. Exit" << endl;
                cout << "\nEnter your choice (1-6):" << endl;
                char ch;
                cin >> ch;
                switch (ch)
                {
                case '1':
                    addNode();
                    break;
                case '2':
                    deleteNode();
                    break;
                case '3':
                    traverse();
                    break;
                case '4':
                    revtraverse();
                    break;
                case '5':
                    searchData();
                    break;
                    case '6':
                return 0;
            default:
                cout << "\nInvalid option" << endl;
                break;
            }
        }
        catch (exception& e)
        {
            cout << "Check for the values entered." << endl;
        }

    }
}