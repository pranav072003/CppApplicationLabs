#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

typedef struct node //implement polynomial node
{
    int coefficient;
    int powx;
    int powy;
    struct node* next;
}node;

typedef struct Best //implement Best node
{
    float x;
    float y;
    float valb;
}Best;

typedef struct Good //implement Good node
{
    float x;
    float y;
    float valg;
}Good;

typedef struct Worst //implement Worst node
{
    float x;
    float y;
    float valw;
}Worst;

typedef struct Reflection //implement Reflection node
{
    float x;
    float y;
    float valr;
}Reflection;

typedef struct Mid //implement Mid node
{
    float x;
    float y;
    float valm;
}Mid;

typedef struct S //implement S node
{
    float x;
    float y;
    float vals;
}S;

typedef struct Expansion //implement Expansion node
{
    float x;
    float y;
    float vale;
}Expansion;

typedef struct Contraction //implement Contraction node
{
    float x;
    float y;
    float valc;
}Contraction;

typedef struct gradient //implement del of function
{
    float valx;
    float valy;
}gradient;

void create_node(node* head)  //initialise the equation/polynomial to be minimised
{
    int val,x1,y1;
    cout<<"Enter coefficient:-"; //coefficient of polynomial
    cin>>val;
    head->coefficient=val;
    cout<<"Enter power for variable x:-"; //enter power of x
    cin>>x1;
    head->powx=x1;
    cout<<"Enter power for variable y:-"; //enter power of y
    cin>>y1;
    head->powy=y1;
    int option;
    cout<<"Want to proceed further:-"; //proceed further or not 1 for yes else no
    cin>>option;
    if(option==1)
    {
        head->next=(node*)malloc(sizeof(node));
        create_node(head->next);
    }
    else  //stop creating further
    head->next=NULL;
}

void display(node* head) //print polynomial
{
    cout<<"Polynomial is:-\n";
    cout<<"(";
    while(head->next!=NULL)
    {
        cout<<"("<<head->coefficient<<")"<<"x^"<<head->powx<<"y^"<<head->powy<<"+";
        head=head->next;
    }
    cout<<"("<<head->coefficient<<")"<<"x^"<<head->powx<<"y^"<<head->powy<<")"<<endl;
}

gradient* derivative(node* head,float x,float y) //computes derivative of polynomial
{
    float funcdervalx=0.0,funcdervaly=0.0;
    node* list;
    node* ptr;
    ptr=head;
    list=head;
    while(ptr!=NULL)
    {
        if(ptr->powx==1)
        funcdervalx=funcdervalx+((ptr->coefficient)*pow(y,ptr->powy));
        else if(ptr->powx>1)
        funcdervalx=funcdervalx+((ptr->coefficient)*(ptr->powx)*pow(x,ptr->powx-1)*pow(y,ptr->powy));
        ptr=ptr->next;
    }
    while(list!=NULL)
    {
        if(list->powy==1)
        funcdervaly=funcdervaly+((list->coefficient)*pow(x,list->powx));
        else if(list->powy>1)
        funcdervaly=funcdervaly+((list->coefficient)*(list->powy)*pow(x,list->powx)*pow(y,list->powy-1));
        list=list->next;
    }
    gradient* del;
    del=(gradient*)malloc(sizeof(gradient));
    del->valx=funcdervalx;
    del->valy=funcdervaly;
    return del;
}

void swap(float* a,float* b)
{
    float t;
    t=*a;
    *a=*b;
    *b=t;
}

void SelectionSort(float array[],int size)
{
    for(int i=0;i<size;i++)
    {
        int minidx=i;
        float minimum=array[i];
        for(int j=i+1;j<size;j++)
        {
            if(array[j]<=array[minidx])
            {
                minidx=j;    
            }
        }
        swap(&array[minidx],&array[i]);
    }
}

typedef struct vertex
{
    Best* b;
    Good* g;
    Worst* w;
}vertex;

int main()
{
    node* head;
    head=(node*)malloc(sizeof(node));
    create_node(head);
    display(head);
    float x1,y1,x2,y2,x3,y3;
    cout<<"Enter three vertices of simplex:-\n"; //inputs simplex vertices
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    Best *b; Good* g; Worst *w; Expansion* e; Contraction* c1; Contraction* c2; Reflection* ref; Mid* m; vertex* v; S* sp;
    b=(Best*)malloc(sizeof(Best));
    g=(Good*)malloc(sizeof(Good));
    w=(Worst*)malloc(sizeof(Worst));
    e=(Expansion*)malloc(sizeof(Expansion));
    c1=(Contraction*)malloc(sizeof(Contraction));
    c2=(Contraction*)malloc(sizeof(Contraction));
    ref=(Reflection*)malloc(sizeof(Reflection));
    m=(Mid*)malloc(sizeof(Mid));
    v=(vertex*)malloc(sizeof(vertex));
    sp=(S*)malloc(sizeof(S));
    gradient* del;
    float epsilon=0.0001;
    b->x=x1; b->y=y1;    //initialising by default
    g->x=x2; g->y=y2;
    w->x=x3; w->y=y3;
    v->b=b;
    v->g=g;
    v->w=w;
    del=(gradient*)malloc(sizeof(gradient));
    del->valx=55.6;
    del->valy=57.3;
    while(abs(del->valx)>epsilon && abs(del->valy)>epsilon)
    {
        node* list; node* temp; node* ptr; //polynomial node pointers
        list=head; temp=head; ptr=head;
        v->b->valb=0.0; v->g->valg=0.0; v->w->valw=0.0;  //reset values back to zero
        
        while(list!=NULL)
        {
            v->b->valb+=(list->coefficient)*pow(v->b->x,list->powx)*pow(v->b->y,list->powy);
            list=list->next;
        }
        
        while(temp!=NULL)
        {
            v->g->valg+=(temp->coefficient)*pow(v->g->x,temp->powx)*pow(v->g->y,temp->powy);
            temp=temp->next;
        }
        
        while(ptr!=NULL)
        {
            v->w->valw+=(ptr->coefficient)*pow(v->w->x,ptr->powx)*pow(v->w->y,ptr->powy);
            ptr=ptr->next;
        }
        
        float array[3];
        array[0]=v->b->valb; array[1]=v->g->valg; array[2]=v->w->valw; //initialising array containing function values
        
        //sort function for function value array
        SelectionSort(array,3);
        
        float p=v->b->x,q=v->b->y,r=v->g->x,s=v->g->y,t=v->w->x,u=v->w->y; //store in auxiliary variables
        
        //shuffle function for adjusting best,worst and good values
        for(int i=0;i<3;i++)
        {
            if(array[i]==v->b->valb)
            {
                if(i==1)
                {
                    v->g->x=p;
                    v->g->y=q;
                }
                else
                {
                    v->w->x=p;
                    v->w->y=q;
                }
            }
            else if(array[i]==v->g->valg)
            {
                if(i==0) //good is best
                {
                    v->b->x=r;
                    v->b->y=s;
                }
                else if(i==2)
                {
                    v->w->x=r;
                    v->w->y=s;
                }
            }
            else
            {
                if(i==0) //worst is best
                {
                    v->b->x=t;
                    v->b->y=u;
                }
                else if(i==1)
                {
                    v->g->x=t;
                    v->g->y=u;
                }
            }
        }
        
        v->b->valb=array[0];
        v->g->valg=array[1];
        v->w->valw=array[2];
        
        del=derivative(head,v->b->x,v->b->y); //call for best value
        
        m->x=(v->b->x + v->g->x)/2;
        m->y=(v->b->y + v->g->y)/2;
        m->valm=0.0;
        
        ref->x=2*m->x-v->w->x;
        ref->y=2*m->y-v->w->y;
        ref->valr=0.0;
        
        node* pol;
        pol=head;
        node* pt;         //initialising and declaration of spare node pointers to compute function values at required points
        pt=head;
        node* deg;
        deg=head;
        node* nt;
        nt=head;
        
        while(pol!=NULL)
        {
            ref->valr+=(pol->coefficient)*pow(ref->x,pol->powx)*pow(ref->y,pol->powy);
            pol=pol->next;
        }
        
        if(ref->valr<v->g->valg)              //case I
        {
            if(v->b->valb<ref->valr)
            {
                v->w->x=ref->x;
                v->w->y=ref->y;
                continue;
            }
            else
            {
                e->x=2*ref->x-m->x;
                e->y=2*ref->y-m->y;
                e->vale=0.0;
                
                while(pt!=NULL)
                {
                    e->vale+=(pt->coefficient)*pow(e->x,pt->powx)*pow(e->y,pt->powy);
                    pt=pt->next;
                }
                
                if(e->vale<v->b->valb)
                {
                    v->w->x=e->x;
                    v->w->y=e->y;
                    continue;
                }
                
                else
                {
                    v->w->x=ref->x;
                    v->w->y=ref->y;
                    continue;
                }
            }
        }
        
        else   //case II
        {
            //TODO: write case II
            if(ref->valr<v->w->valw)
            {
                v->w->x=ref->x;
                v->w->y=ref->y;
                continue;
            }
            
            c1->x=(v->w->x + m->x)/2;
            c1->y=(v->w->y + m->y)/2;
            c1->valc=0.0;
            
            while(deg!=NULL)
            {
                c1->valc+=(deg->coefficient)*pow(c1->x,deg->powx)*pow(c1->y,deg->powy);
                deg=deg->next;    
            }
            
            c2->x=(ref->x + m->x)/2;
            c2->y=(ref->y + m->y)/2;
            c2->valc=0.0;
            
            while(nt!=NULL)
            {
                c2->valc+=(nt->coefficient)*pow(c2->x,nt->powx)*pow(c2->y,nt->powy);
                nt=nt->next;    
            }
            
            if(c1->valc<v->w->valw || c2->valc<v->w->valw)
            {
                if(c1->valc<c2->valc)
                {
                    v->w->x=c1->x;
                    v->w->y=c1->y;
                    continue;
                }
                
                else
                {
                    v->w->x=c2->x;
                    v->w->y=c2->y;
                    continue;
                }
            }
            
            else
            {
                sp->x=(v->b->x + v->w->x)/2;
                sp->y=(v->b->y + v->w->y)/2;
                sp->vals=0.0;
                
                v->w->x=sp->x;
                v->w->y=sp->y;
                
                v->g->x=m->x;
                v->g->y=m->y;
                
                continue;
            }
        }
    }
    
    cout<<v->b->x<<"\t"<<v->b->y;
    
    return 0;
}
