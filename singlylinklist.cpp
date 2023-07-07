#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next;
};

struct node* createLinkedList(int a[], int size) {
    struct node* head = NULL;
    struct node* tail = NULL;
    for (int i = 0; i < size; i++) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = a[i];
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}



void print_linklist(struct node *head){
    struct node *ptr = head;
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}
/*
Author : Tarek Rahman 
United International University
*/

//Insert Node At End
struct node* add_element_in_linklist(struct node *head,int data){
    struct node *pointer =head;
    while(pointer->next != NULL){
        pointer=pointer->next ;
    }
    struct node *NEW_pointer =(struct node*)malloc(sizeof(struct node));
    pointer->next=NEW_pointer;
    NEW_pointer->data=data;
    NEW_pointer->next=NULL;
}


//Insert Node At First
struct node* add_element_in_the_linklist_in_first(struct node *head,int data){
    struct node *new_pointer=(struct node*)malloc(sizeof(struct node));
    new_pointer->data =data;
    new_pointer->next = head;
    struct node *news=new_pointer;
    return news;
}


// Insert a Node in a Linked List (Middle)
struct node* Insert_Node_middle(struct node* head, int data, int pos) {
    struct node* pointer = head;
    int counter = 0;
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    while (pointer != NULL ) {
        counter++;
        if (counter == pos ) {
            newNode->next = pointer->next;
            pointer->next = newNode;
        }
        pointer = pointer->next;
    }
    if (counter < pos - 1) {
        cout << "Invalid position!" <<endl;
        free(newNode);  // Free the allocated memory
    }
    return head;
}


// searching in link-list
bool searching(struct node *head,int data){
    struct node *new_pointer =head;
    while(new_pointer!=NULL){
        if(new_pointer->data ==data){
            cout<<"Element Found"<<endl;
            return true;
        }
        new_pointer=new_pointer->next;
    }
    cout<<"Element Not Found"<<endl;
    return false;
}


//Single Linked List (Deleting the First Node)
struct node* DeleteFirstNode(struct node* head) {
    if (head == NULL) {
        printf("The linked list is already empty.\n");
        return NULL;
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
    return head;
}


 //Delete a middle Node from a Linked List
struct node* Delete(struct node* head, int data) {
    struct node* dummyhead = (struct node*)malloc(sizeof(struct node));
    dummyhead->next = head;
    struct node* current = dummyhead;

    while (current->next != NULL) {
        if (current->next->data == data) {
            // delet main logic
            current->next = current->next->next;
        }
        current = current->next;
    }
    return dummyhead->next;
}


//Single Linked List (Deleting the Last Node)
struct node* DeleteLastNode(struct node* head) {
    if (head == NULL) {
        printf("The linked list is already empty.\n");
        return NULL;
    }

    if (head->next == NULL) {
        // If there is only one node in the list
        free(head);
        return NULL;
    }

    struct node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
    return head;
}



int main(){
    int a[]={10,20,30,40,50};
    struct node *head = createLinkedList(a,5);
    // head= head = (struct node*)malloc(sizeof(struct node));
    // // Insertaion 
    // head->data = 10;
    // head->next=NULL;
    // add_element_in_linklist(head,20);
    // add_element_in_linklist(head,30);
    // add_element_in_linklist(head,40);
    // add_element_in_linklist(head,50);
    // print_linklist(head);    // 10 20 30 40 50 
    print_linklist(head);
    // All element in first
    head = add_element_in_the_linklist_in_first(head,1);
    print_linklist(head); // 1  10 20 30 40 50

    //searching element
    searching(head,1); //found 
    print_linklist(head); // 1  10 20 30 40 50
    
    // add element in middle
    head=Insert_Node_middle(head,500,3);   
    print_linklist(head);  // 1  10 500 20 30 40 50

    // delet middle number
    head =Delete(head,40);
    print_linklist(head);  // 1  10 500 20 30  50

    //DeleteFirstNode
    head= DeleteFirstNode(head);
    print_linklist(head);   //  10 500 20 30 40 50

    //DeleteLastNode
    head = DeleteLastNode(head);
    print_linklist(head); // 1  10 500 20 30 40 
}