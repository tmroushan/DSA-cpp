
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void create(Node*& Head, int data, int n) {
    for(int i = 1; i <= n; i++) {
        Node* newnode = new Node();

        cout << "Enter data: ";
        cin >> data;

        newnode->data = data;
        newnode->next = NULL;
        newnode->prev = NULL;

        if(Head == NULL) {
            Head = newnode;
        }
        else {
            Node* temp = Head;

            while(temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newnode;
            newnode->prev = temp;
        }
    }
}

void display(Node* Head) {
    Node* temp = Head;

    while(temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}
void insertAtBeg(Node*& Head,int data){
    Node* newnode= new Node();
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=Head;
    if(Head!=NULL){
        Head->prev=newnode;
    }
    Head= newnode;
}
void inserAtEnd(Node*& Head,int data){
    Node* newnode=new Node();
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(Head==NULL){
        
            Head=newnode;
        return;
    }
    Node* temp=Head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
}
void insertAtSpecific(Node*& Head,int data,int pos){
   if(pos<1){
    cout<<"Invalid postion";
    return;
   }
   if(pos==1){
    insertAtBeg(Head,data);
    return;
   }
   Node* temp= Head;
   for(int i =1;i<pos-1 && temp!=NULL;i++){
    temp=temp->next;
   }
   if(temp==NULL){
    cout<<"invalid position";
    return;
   }
   Node* newnode=new Node();
   newnode->data=data;
   newnode->next=temp->next;
   newnode->prev=temp;

   if(temp->next!=NULL){
    temp->next->prev=newnode;
   }
   temp->next=newnode;
}
void delFromBeg(Node*& Head){
    if(Head==NULL){
        cout<<"List is empty";
        return;
    }
    Node* temp= Head;
    Head=Head->next;
    if(Head!=NULL){
        Head->prev  =NULL;
    }
    delete temp;
}
void delFromEnd(Node*& Head){
    if(Head==NULL){
        cout<<"List is empty";
        return;
    }
    if(Head->next==NULL){
        delete Head;
        Head=NULL;
        return;
    }
    Node* temp= Head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    delete temp;
    
}
void delAtSpecPos(Node*& Head,int pos){
    if(Head==NULL){
        cout<<"List is empty";
        return;
    }
    if(pos<1){
        cout<<"Invalid postion";
        return;
    }
    if(pos==1){
        delFromBeg(Head);
        return;
    }
    Node* temp=Head;
    for(int i =1;i<pos && temp!=NULL;i++){
        temp=temp->next;
    }
    if(temp==NULL){
        cout<<"Invalid postion";
        return;
    }
    if(temp->prev!=NULL){
        temp->prev->next=temp->next;
    }
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }
    delete temp;
}

int main() {
    Node* Head = NULL;
    int data, n,pos;

    cout << "Enter number of nodes: ";
    cin >> n;

    create(Head, data, n);
    display(Head);
    cout<<"after insertion at beginning:";
    insertAtBeg(Head,9);
    display(Head);
    cout<<"After insertion at end:";
    inserAtEnd(Head,100);
    display(Head);
    cout<<"Enter postion to insert node:";
    cin>>pos;
    cout<<"After insertion at postion "<<pos<<":";
    insertAtSpecific(Head,50,pos);
    display(Head);
    cout<<"AFTER DELETION from Beg:";
    delFromBeg(Head);
    display(Head);
    cout<<"After Deletion from End:";
    delFromEnd(Head);
    display(Head);
    cout<<"Enter postion to delete Node:";
    cin>>pos;
    cout<<"After Deletion at pos "<<pos<<":";
    delAtSpecPos(Head,pos);
    display(Head);
    return 0;
}
