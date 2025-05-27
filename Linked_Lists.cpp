#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    int val;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList():head(NULL){}

    Node *getHead()
    {
        return head;
    }

    void printLL()
    {
        Node *curr = head;
        while (curr)
        {
            cout<<"|";
            cout << curr->val << "|->";
            curr = curr->next;
        }
        cout << "null\n";
    }

    void push_back(int newVal)
    {
        Node *curr = head;
        Node *newNode = new Node;
        newNode->val = newVal;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            return;
        }

        while (curr->next)
        {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    void push_front(int newVal){
        Node* newNode = new Node;
        newNode->val = newVal;
        newNode->next = head;

        head = newNode;
    }

    void deleteNode(int delVal){
        if(head == NULL) return;

        Node* curr  = head;
        if(head->val == delVal){
            if(head->next == NULL){
                curr = head;
                head = NULL;
                delete curr;
                return;
            }

            head = head->next;
            delete curr;
        }
    }

    void deleteAllNodes(){
        if(head == NULL)
         return;
        
        Node* curr = head;
        while(curr){
            Node* t = curr;
            curr = curr->next;
            delete t;
        }

        delete curr;
        head = NULL;
    }
};

int main()
{
    LinkedList ll;
    ll.push_back(1);
    ll.push_front(2);
    ll.printLL();
    ll.deleteNode(2);
    ll.printLL();
    ll.deleteAllNodes();
    ll.printLL();
}
