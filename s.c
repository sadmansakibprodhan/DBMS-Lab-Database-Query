#include<cstdio>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct node{
    int val;
    node *next;
    node *prev;
};

node *base = NULL;
node *top_item = NULL;

void push(int val)
{
    if(base==NULL) //If the list is empty
    {
        base=new node;
        base->val=val;
        base->next=NULL;
        base->prev=NULL;
        top_item = base;

    }
    else
    {
        node *temp = top_item;
        top_item->next = new node;
        top_item = top_item->next;
        top_item->val = val;
        top_item->next = NULL;
        top_item->prev = temp;
    }
     //printf("inserting %d", val);
}

void peek()
{
    int c = 0;
    printf("Peeked Value: ");
    if ( base == NULL ) { printf("\n");return ;}
    node *current_node=base;
    printf("%d\n ", current_node->val);
}

/*void print_reverse()
{

    printf("Stack: ");
    if ( top_item == NULL ) { printf("\n");return ;}
    node *current_node=top_item;
    printf("%d ", current_node->val);
    while(current_node->prev!=NULL){
          current_node = current_node->prev;
          printf("%d ", current_node->val);
    }
    printf("\n");
}*/

void print()
{

    printf("Queue: ");
    if ( base == NULL ) { printf("\n");return ;}
    node *current_node=base;
    printf("%d ", current_node->val);
    while(current_node->next!=NULL){
          current_node = current_node->next;
          printf("%d ", current_node->val);
    }
    printf("\n");
}

int pop()
{
   if ( top_item == NULL ) return NULL;
    int val = top_item->val;
    node *temp = top_item;
    if ( top_item->next == NULL ){
        top_item = NULL;
        base = NULL;
    }
    else {
    top_item = top_item->next;
    top_item->prev = NULL;
    }
    delete(temp);
    return val;
}

int top()
{
   // if ( top_item == NULL ) return NULL;
    return top_item->val;
}

int is_emp()
{
    if ( top_item == NULL ) return 1;
    else return 0;
}




int main()
{
    string s;
    int data;
    while ( 1 ) {
        cin >> s;
        if ( s == "enqueue" ) {
            cin >> data;
            push(data);
            print();
        }
        else if ( s == "dequeue" ) {
            pop();
            print();
        }
        else if ( s == "peek" ) {
            peek();
            print();
        }
        else {
            return 0;
        }
        //else if ( s == "peek" )
        /*if( is_emp()){
            printf("empty\n");
        }
        else{
            printf("not empty\n");
        }
        if*/
    }
    return 0;
}

