#include <iostream>
#include <stdlib.h>
#include <math.h>
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

int FindLength(float uncertain,int a,int b)
{
    int val=1/(uncertain);
    int len=0;
    while(b<val)
    {
        int t;
        len++;
        t=b;
        b=a+b;
        a=t;
    }
    return b;
}

void Fibonacciseries(int array[],int num1,int num2,int n,int p)
{
    if(p>n)
    {
        return;
    }
    int temp=num2;
    num2=num1+num2;
    num1=temp;
    array[p]=num2;
    p++;
    Fibonacciseries(array,num1,num2,n,p);
}

void traverse(int array[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<array[i]<<"\t";
    }
}

float minfibbsearch(node* head,int array[],int n,float a,float b)
{
    float diff,x1,x2;
    node* list;
    node* ptr;
    int k=1;
    while(k<=n)
    {
        list=head;
        ptr=head;
        diff=b-a;
        // diff=(float)b-(float)a;
        float c=(float)array[n-k]/(float)array[1+n-k];
        cout<<diff<<"\n";
        x2=a+c*diff;
        x1=a+b-x2;
        float value1=0.0,value2=0.0;
        while(list!=NULL)
        {
            value1 += list->data * pow(x1,list->expo);
            list=list->next;
        }
        while(ptr!=NULL)
        {
            value2 += ptr->data * pow(x2,ptr->expo);
            ptr=ptr->next;
        }
        if(value1>=value2)
        {
            a=x1;
        }
        else
        {
            b=x2;
        }
        k++;
    }
    float sol=(float)(a+b)/2.0;
    return sol;
}

float maxfibbsearch(node* head,int array[],int n,float a,float b)
{
    float diff,x1,x2;
    node* list;
    node* ptr;
    int k=1;
    while(k<=n)
    {
        list=head;
        ptr=head;
        diff=b-a;
        // diff=(float)b-(float)a;
        float c=(float)array[n-k]/(float)array[1+n-k];
        cout<<diff<<"\n";
        x2=a+c*diff;
        x1=a+b-x2;
        float value1=0.0,value2=0.0;
        while(list!=NULL)
        {
            value1 += list->data * pow(x1,list->expo);
            list=list->next;
        }
        while(ptr!=NULL)
        {
            value2 += ptr->data * pow(x2,ptr->expo);
            ptr=ptr->next;
        }
        if(value1>=value2)
        {
            b=x2;
        }
        else
        {
            a=x1;
        }
        k++;
    }
    float sol=(float)(a+b)/2.0;
    return sol;
}

int main()
{
    int a=1,b=1;
    float uncertain;
    cout<<"Enter the interval uncertainity:-";
    cin>>uncertain;
    int iter=FindLength(uncertain,a,b);
    int fibbarr[iter];
    fibbarr[0]=a;
    fibbarr[1]=b;
    int p=2;
    Fibonacciseries(fibbarr,a,b,iter,p);
    // traverse(fibbarr,iter);
    node* head;
    head=(node*)malloc(sizeof(node));
    create(head);
    display(head);
    int a1,b1;
    cout<<"Enter range of interval in which minima/maxima has to be found:-";
    cin>>a1>>b1;
    int option;
    cout<<"Minimise or Maximise function:-";
    cin>>option;
    if(option==1)
    {
    float minima=minfibbsearch(head,fibbarr,iter,(float)a1,(float)b1);
    node* list;
    float minval=0.0;
    list=head;
    while(list!=NULL)
    {
        minval += list->data*pow(minima,list->expo);
        list=list->next;
    }
    cout<<"The minima is "<<minima<<" and minimum value of function is "<<minval<<"\n";
    }
    else if(option==0)
    {
    float maxima=maxfibbsearch(head,fibbarr,iter,(float)a1,(float)b1);
    node* temp;
    float maxval=0.0;
    temp=head;
    while(temp!=NULL)
    {
        maxval += temp->data*pow(maxima,temp->expo);
        temp=temp->next;
    }
    cout<<"The maxima is "<<maxima<<" and maximum value of function is "<<maxval<<"\n";
    }
    else
    {
        cout<<"input has to be 1 or 0.Cant be anything other\n";
    }
    return 0;
}

