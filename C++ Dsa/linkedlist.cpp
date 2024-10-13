#include <iostream>
using namespace std;

class node {
    public:
        int data;
        node* next; // Fixed: changed 'node next' to 'node* next' node is a pointer 
        node(int value){
            data = value;
            next = NULL;
        }
};

//  array[4] = { 1, 5, 6, 8 };

class LinkedList {
    private:
        node *head;
    public:
    void addFirstNode(int data){
        node* newNode =  new node(data);
        head->next = newNode;
    }
    void addNodeToEnd (int data){
        node* newNode = new node(data);
        if(head->next == NULL){
            head->next = newNode;
        }
        else{
            node *temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            };
            temp->next = newNode;
        }
    };

    void addNodeToStart(int data){
        node* newNode = new node(data);
        newNode->next = head->next;
        head->next = newNode;
    }

    void deleteNodeStart(){
        if(head->next == NULL){
            cout<<"List is empty. Cannot delete."<<endl;
            return;
        }
        node *temp = head->next;
        head->next = temp->next;
        delete temp;
    }
    void deleteNodeEnd(){
        if(head->next == NULL){
            cout<<"List is empty. Cannot delete."<<endl;
            return;
        }
        node *temp = head;
        while(temp->next->next!= NULL){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    void deleteNodeAtIndex(int index){
        if(head->next == NULL){
            cout<<"List is empty. Cannot delete."<<endl;
            return;
        }
        if(index == 0){
            deleteNodeStart();
            return;
        }
        node *temp = head;
        for(int i=0; i<index-1; i++){
            if(temp->next == NULL){
                cout<<"Index out of range. Cannot delete."<<endl;
                return;
            }
            temp = temp->next;
        }
        node *delNode = temp->next;
        temp->next = delNode->next;
        delete delNode; 

    }

    void printList(){
        node *temp = head->next;
        while(temp!= NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    void sortTheList(){
        node* temp = head->next;
        while(temp!= NULL){
            node* minNode = temp;
            node* minNodePrev = head;
            for(node* current = temp->next; current!= NULL; current = current->next){
                if(current->data < minNode->data){
                    minNode = current;
                    minNodePrev = temp;
                }
            }
            int tempData = minNode->data;
            minNode->data = temp->data;
            temp->data = tempData;
            temp = minNodePrev->next;
        }
    }
};

int main()
{
    LinkedList list;
    list.addFirstNode(10);
    list.addNodeToEnd(20);
    list.addNodeToStart(5);
    list.addNodeToEnd(15);
    list.addNodeToEnd(30);
    list.addNodeToEnd(35);
    list.printList();
    // list.sortTheList();
    list.printList();
    return 0;
}