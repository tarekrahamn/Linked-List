#include<bits/stdc++.h>
using namespace std;
// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void print_linklist(struct Node *head){
    struct Node *ptr = head;
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}


//Insert Node At End
struct Node* add_element_in_linklist(struct Node *head,int data){
    struct Node *pointer =head;
    while(pointer->next != NULL){
        pointer=pointer->next ;
    }
    struct Node *NEW_pointer =(struct Node*)malloc(sizeof(struct Node));
    NEW_pointer->prev=NULL;
    NEW_pointer->data=data;
    NEW_pointer->next=NULL;
    pointer->next=NEW_pointer;
    NEW_pointer->prev=pointer;
    return head;
    
}

//Function to insert a node at the beginning of the list
struct Node* insertAtBeginning(struct Node* head, int data) {
   struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
   newNode->prev=NULL;
   newNode->data=data;
   newNode->next=NULL;
   newNode->next=head;
   head->prev=newNode;
   head=newNode;
   return head;
}

// Function to insert a node at the middle of the Doubly Linked List
struct Node* Insert_Node_middle(struct Node* head, int data, int pos) {
    struct Node* pointer = head;
    int counter = 0;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    while (pointer != NULL) {
        counter++;
        if (counter == pos) {
            newNode->next = pointer->next;
            newNode->prev = pointer->prev;
            pointer->next = newNode;
        }
        pointer = pointer->next;
    }

    if (counter < pos - 1) {
        printf("Invalid position!\n");
        free(newNode);
    }

    return head;
}


// searching in link-list
bool searching(struct Node *head,int data){
    struct Node *new_pointer =head;
    while(new_pointer!=NULL){
        if(new_pointer->data ==data){
            cout<<"The Element " << new_pointer->data << " is Found " <<endl;
            return true;
        }
        new_pointer=new_pointer->next;
    }
    cout<<"Element Not Found"<<endl;
    return false;
}

//Doubly Linked List (Deleting the First Node)
struct Node* DeleteFirstNode(struct Node* head) {
    if (head == NULL) {
        printf("The linked list is already empty.\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    if(head!=NULL){
        head->prev=NULL;
    }
    free(temp);
    return head;
}

//Doubly Linked List (Deleting the Middle Node)
struct Node* Delete(struct Node* head, int data) {
    struct Node* dummyhead = (struct Node*)malloc(sizeof(struct Node));
    dummyhead->next = head;
    struct Node* current = dummyhead;

    while (current->next != NULL) {
        if (current->next->data == data) {
            // delet main logic
            current->prev=current->prev->prev;
            current->next = current->next->next;
        }
        current = current->next;
    }
    return dummyhead->next;
}


//Doubly Linked List (Deleting the Last Node)
struct Node* DeleteLastNode(struct Node* head) {
    if (head == NULL) {
        printf("The linked list is already empty.\n");
        return NULL;
    }
    if (head->next == NULL) {
        // If there is only one node in the list
        free(head);
        return NULL;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->prev->next = NULL;
    return head;
}
int main() {
    struct Node* head = NULL;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->prev=NULL;
    head->data=1;
    head->next=NULL;
    head=add_element_in_linklist(head,10);
    head=add_element_in_linklist(head,20);
    head=add_element_in_linklist(head,30);
    head=add_element_in_linklist(head,40);
    head=add_element_in_linklist(head,50);
    head=add_element_in_linklist(head,60);
    head=add_element_in_linklist(head,70);
    cout << "Add element in last "<< endl ;
    print_linklist(head);
    cout << endl;

    cout << "Add element in First "<< endl ;
    head=insertAtBeginning(head,0);
    print_linklist(head);
    cout << endl;

    cout << "Add element in MIDDle "<< endl ;
    head=Insert_Node_middle(head,400,3);
    print_linklist(head);
    cout << endl;

    cout << "SEARCHING ELEMENT "<< endl ; 
    searching(head,400); 
    print_linklist(head);
    cout << endl;

    cout<< "Deleting the First Node"<< endl;
    head=DeleteFirstNode(head);
    print_linklist(head);
    cout << endl;

    cout<< "Deleting the Middle Node" << endl;
    head=Delete(head,400);
    print_linklist(head);
    cout << endl;

    cout<< "Deleting the Laast Node"<< endl;
    head=DeleteLastNode(head);
    print_linklist(head);
    cout << endl;

    return 0;
}
