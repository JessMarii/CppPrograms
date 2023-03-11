#include <iostream>
#include <cstdlib>

using namespace std;

class LinkedList
{

public:
    LinkedList()
    {
        head = NULL;
    }


    void add(double x)  // added a value to the linked list 
    {
        head = createNode(x, head);  // create a new node and with value x sets head to the new node
    }

    bool isMember(double x)  // searched the list and return True if the item is in list. 
    {
        ListNode* lN = head;
        while (lN != NULL)     // search through the list until null 
        {
            if (lN->num == x)
            {
                return true;   // Item found  return true
            }
            lN = lN->PTRnext;  // Next item increment pointer
        }
        return false;         // Item not found return False    
    }

   

    void print()                  // print the linked list 
    {
        if (head == NULL)        // empty list print Empty List  and return
        {
            cout << "Empty list!" << endl;
            return;
        }
        ListNode* listptr = head;  //sets the pointer to the head of the list
        while (listptr != NULL)
        {
            cout << listptr->num << " ";
            listptr = listptr->PTRnext;  // Next item increment pointer
        }
        cout << endl;
    }



private:
    struct ListNode
    {
        double num;            // value stored in ListNode
        ListNode* PTRnext;     // pointer to next element
    };

    ListNode* createNode(double x, ListNode* next)  // creates an new node of value x at the head of the list
    {
        ListNode* newN = new ListNode;  // creates the new node 
        newN->num = x;                  // added value x to the node
        newN->PTRnext = next;           // set next pointer to the next item in the list
        return newN;                    // returns the new pointer to the head of the list. 
    }
    ListNode* head;
};

int main()
{
    LinkedList list;
    list.print();
    double element = 0;
    while (element != -1)   // added numbers to the linked list until -1 entered
    {
        cout << "Enter numbers into list (Enter -1 to stop):";
        cin >> element;
        if (element != -1)
        {
            list.add(element);  // added the number to the linked list 
        }
    }
    cout << "Printed List:\n";
    list.print();               // prints the linked liste
    double check = 0;
    while (check != -1)    //  check if a specific value is in the linked list
    {
        cout << "Enter number to check if it is in the list (Enter -1 to stop):";
        cin >> check;
        if (check != -1)
        {
            if (list.isMember(check)) {   // check to see if the value in the linked list
                cout << "List contains " << check << endl;
            }
            else {
                cout << "List does not contain " << check << endl;
            }
        }
    }

}