#include <iostream>
#include <cstdlib>
#include <math.h>
#include <stdlib.h>
using namespace std;

typedef struct node
{
    int data;
    int expo;
    struct node* next;
}node;

void create(node* head)
{
    int data,expo;
    cout<<"Enter coefficient:-";
    cin>>data;
    head->data=data;
    cout<<"Enter power of variable:-";
    cin>>expo;
    head->expo=expo;
    int op;
    cout<<"Want to continue(1 for Y/0 for N):-";
    cin>>op;
    if(op==1)
    {
        head->next=(node*)malloc(sizeof(node));
        create(head->next);
    }
    else
    head->next=NULL;
}

void display(node* head)
{
    cout<<"(";
    while(head->next!=NULL)
    {
        cout<<head->data<<"x"<<head->expo<<")"<<"+(";
        head=head->next;
    }
    cout<<head->data<<"x"<<head->expo<<")"<<"\n";
}

void secant(node* head,float a,float b,float epsilon)
{
    node* ptr;
    node* temp;
    ptr=head;
    temp=head;
    node* list;
    list=head;
    float valueA=0.0,valueB=0.0;
    while(ptr!=NULL)
    {
        valueA=valueA+ptr->data*pow(a,ptr->expo);
        ptr=ptr->next;
    }
    while(temp!=NULL)
    {
        valueB=valueB+temp->data*pow(b,temp->expo);
        temp=temp->next;
    }
    if(abs(valueA)<epsilon || abs(valueB)<epsilon)
    {
        cout<<"Either of "<<a<<" or "<<b<<" is the solution\n";
        return;
    }
    float c=b-(valueB*(b-a)/(valueB-valueA));
    float valueC=0.0;
    while(list!=NULL)
    {
        valueC=valueC+list->data*pow(c,list->expo);
        list=list->next;
    }
    if(abs(valueC)<epsilon)
    {
        cout<<"Solution is "<<c<<"\n";
        return;
    }
    secant(head,b,c,epsilon);
}


int main()
{
    node* head;
    head=(node*)malloc(sizeof(node));
    create(head);
    cout<<"Entered equation is-\n";
    display(head);
    float a,b,epsilon;
    cout<<"Enter initial guesses and tolerance limit for root of equation:-\n";
    cin>>a>>b>>epsilon;
    secant(head,a,b,epsilon);

    return 0;
}
