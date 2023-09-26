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

void derivative(node* head,node* ptr)
{
    while(head->next!=NULL)
    {
        if(head->expo==0)
        {
            ptr->expo=0;
            ptr->data=0;
            head=head->next;
            ptr->next=(node*)malloc(sizeof(node));
            ptr=ptr->next;
            continue;
        }
        ptr->data=head->data*head->expo;
        ptr->expo=head->expo-1;
        head=head->next;
        ptr->next=(node*)malloc(sizeof(node));
        ptr=ptr->next;
    }
    if(head->expo==0)
    {
            ptr->expo=0;
            ptr->data=0;
            ptr->next=NULL;
            return;
    }
    ptr->data=head->data*head->expo;
    ptr->expo=head->expo-1;
    ptr->next=NULL;
}

void Newton_Raphson(node* head,node* list,float a,float epsilon)
{
    node* ptr;
    ptr=head;
    node* temp;
    temp=list;
    float funcval=0.0,funcderval=0.0;
    while(head!=NULL)
    {
        funcval=funcval+head->data*pow(a,head->expo);
        head=head->next;
    }
    while(list!=NULL)
    {
        funcderval=funcderval+list->data*pow(a,list->expo);
        list=list->next;
    }
    if(abs(funcval)<epsilon)
    {
        cout<<"\nSolution is "<<a<<"\n";
        return;
    }
    float c;
    c=a-(funcval/funcderval);
    Newton_Raphson(ptr,temp,c,epsilon);
}


int main()
{
    node* head;
    head=(node*)malloc(sizeof(node));
    create(head);
    cout<<"Entered equation is-\n";
    display(head);
    node* list;
    list=(node*)malloc(sizeof(node));
    derivative(head,list);
    cout<<"Derivative of equation is-\n";
    display(list);
    float a,epsilon;
    cout<<"Enter initial guess and tolerance limit for root of equation:-\n";
    cin>>a>>epsilon;
    Newton_Raphson(head,list,a,epsilon);

    return 0;
}
