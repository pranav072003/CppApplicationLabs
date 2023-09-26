#include <iostream>
#include <math.h>
#include <cstdlib>
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
    cout<<"Please enter number:-";
    cin>>data;
    cout<<"Enter power of variable:-";
    cin>>expo;
    head->data=data;
    head->expo=expo;
    int option;
    cout<<"Want to continue(0/1):-";
    cin>>option;
    if(option==1)
    {
        head->next=(node*)malloc(sizeof(node));
        create(head->next);
    }
    else
    head->next=NULL;
}

void display(node* head)
{
    cout<<"Entered equation is\n";
    cout<<"(";
    while(head->next!=NULL)
    {
        cout<<head->data<<"x"<<head->expo<<")"<<"+(";
        head=head->next;
    }
    cout<<head->data<<"x"<<head->expo<<")"<<"=0\n";
}

float BISECTION(node* head,float a,float b,float epsilon)
{
    node* ptr;
    ptr=head;
    node* list;
    list=ptr;
    node* temp;
    temp=ptr;
    float valueA=0.0,valueB=0.0,valueC=0.0;
    while(ptr!=NULL)
    {
        valueA += (ptr->data)* pow(a,ptr->expo);
        ptr=ptr->next;
    }
    while(list!=NULL)
    {
        valueB += (list->data)* pow(b,list->expo);
        list=list->next;
    }
    if(valueA*valueB>0)
    {
        cout<<"No solution between given interval\n";
        return 0.0;
    }
    else if(valueA*valueB<0)
    {
        float c=(a+b)/2;
        cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<valueA<<"\t"<<valueB<<"\n";
        while(temp!=NULL)
        {
            valueC += (temp->data)* pow(c,temp->expo);
            temp=temp->next;
        }
        if(abs(valueC)<epsilon)
        {
            return c;
        }
        else{
        if(valueC*valueA<0)
        {
            BISECTION(head,a,c,epsilon);
        }
        else 
        {
            BISECTION(head,c,b,epsilon);
        }}
    }
    else
    {
        float c=(a+b)/2;
        cout<<a<<b<<c<<valueA<<valueB;
        return c;
    }
}

int main()
{
    node* head;
    head=(node*)malloc(sizeof(node));
    create(head);
    display(head);
    int a,b;
    float epsilon;
    cout<<"Enter range of interval in which solution has to be found:-";
    cin>>a>>b;
    cout<<"Enter tolerance value:-";
    cin>>epsilon;
    int solve;
    cout<<"\n"<<"a\t\tb\t\tc\t\tf(a)\t\tf(b)"<<"\n";
    float root = BISECTION(head,(float)a,(float)b,epsilon);
    cout<<"Root of equation in the given interval is "<<root<<"\n";
    return 0;
}
