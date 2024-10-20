#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node* next;
};

class LinkedStr 
{
private:
    Node* ptr;

public:
    LinkedStr();
    ~LinkedStr();
    void makeStr(int len);
    void displayStr();
    void removeFirst();
    void removeLast();
    void remove(int k);
};

LinkedStr::LinkedStr()
{
    ptr = NULL;
}

LinkedStr::~LinkedStr()
{
    while (ptr != NULL) 
    {
        Node* temp = ptr;
        ptr = ptr->next;
        delete temp;
    }
}

void LinkedStr::makeStr(int len)
{
    for (int i = 0; i < len; i++) 
    {
        Node* newNode = new Node;
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> newNode->info;
        newNode->next = NULL;

        if (ptr == NULL) 
        {
            ptr = newNode;
        }
        else
        {
            Node* temp = ptr;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void LinkedStr::displayStr()
{
    Node* temp = ptr;
    while (temp != NULL)
    {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}

void LinkedStr::removeFirst()
{
    if (ptr == NULL) return;
    Node* temp = ptr;
    ptr = ptr->next;
    delete temp;
}

void LinkedStr::removeLast()
{
    if (ptr == NULL) return;
    if (ptr->next == NULL) 
    {
        delete ptr;
        ptr = NULL;
        return;
    }
    Node* temp = ptr;
    while (temp->next->next != NULL) 
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void LinkedStr::remove(int pos) 
{
    if (ptr == NULL || pos <= 0) return;
    if (pos == 1) {
        removeFirst();
        return;
    }

    Node* temp = ptr;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) return;

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}

int main() 
{
    LinkedStr list;
    int len;

    cout << "Enter the length of the linked list: ";
    cin >> len;
    list.makeStr(len);

    system("cls");

    cout << "Values in the linked list are: ";
    list.displayStr();

    list.removeFirst();
    list.removeLast();
    cout << "After removing first and last element: ";
    list.displayStr();

    list.remove(5);
    cout << "After removing the 5 element: ";
    list.displayStr();

    return 0;
}
