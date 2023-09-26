#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <graphics.h>
#include <conio.h>

int ROUND(float num)
{
    if(num<=0.0) return (int)(num-0.5);
    else return (int)(num+0.5);
}

void cohenlineclip(int g,int h,int array[],int k,int l,int m,int n,int o,int p,int q,int r) //k-l=clip coordinates,o-r=line coordinates
{
	int y;
	char cd[4];
	char pd[4];
	for(int i=0;i<4;i++)
	{
		cd[i]='0';
		pd[i]='0';
	}
	if(p<n) cd[0]='1';
	else if(r<n) pd[0]='1';
	else if(o>l) cd[1]='1';
	else if(q>l) pd[1]='1';
	else if(o<k) cd[2]='1';
	else if(q<k) pd[2]='1';
	else if(p>m) cd[3]='1';
	else if(r>m) pd[3]='1';
	//int num1=atoi(cd);
	//int num2=atoi(pd);
	for(int e=0;e<4;e++)
		cout<<cd[e];
	cout<<"\t";
	for(int j=0;j<4;j++)
		cout<<pd[j];
	cout<<"\n";
	char st[4];
	int count=0;
	for(int x=0;x<4;x++)
	{
		if(cd[x]=='1' && pd[x]=='1')
		{
			st[x]='1';
			cout<<"No output\n";
			return;
		}
		else
		{
			if(cd[x]=='1' || pd[x]=='1')
			{
				st[x]='1';
				continue;
			}
			st[x]='0';
			count++;
		}
	}
	//int X=getmaxx()/2;
	//int Y=getmaxy()/2;
	setcolor(GREEN);
	if(count==4)
	{
		array[0]=o; array[1]=p; array[2]=q; array[3]=r;
		cout<<"Clipped line accepted and plotted\n";
		return;
	}
	float slope=(float)(p-r)/(q-o);
	int y1, y2, x1, x2;
	y1=p-(slope)*(k-o); //take x=k
	y2=r+(slope)*(q-l);  //take x=l
	x1=ROUND((float)(p-m)/slope + o);       //take y=m
	x2=ROUND(q-(float)(n-r)/slope);      //take y=n
	int ct,pt;
	for(int w=0;w<4;w++)
    {
	if(cd[w]=='0')  ct++;
	if(pd[w]=='0')  pt++;
    }
    if(ct==4 || pt==4)
    {
	if(ct==4 && pt!=4)
	{
	    if(x2<=l)
	    {
		array[0]=o; array[1]=p; array[2]=x2; array[3]=n;
		return;
	    }
	    else if(y2<=n)
	    {
		array[0]=o; array[1]=p; array[2]=l; array[3]=y2;
		return;
	    }
	}
	else if(pt==4 && ct!=4)
	{
	    if(x1>=k)
	    {
		array[0]=x1; array[1]=m; array[2]=q; array[3]=r;
		return;
	    }
	    else if(y1>=m)
	    {
		array[0]=k; array[1]=y1; array[2]=q; array[3]=r;
		return;
	    }
	}
	else
	{
		array[0]=o; array[1]=p; array[2]=q; array[3]=r;
		cout<<"Clipped line accepted and plotted\n";
		return;
	}
    }
    if(x2<=l && x1>=k)  {array[0]=x1; array[1]=m; array[2]=x2; array[3]=n;}
    else if(y2<=n && x1>=k) {array[0]=x1; array[1]=m; array[2]=l; array[3]=y2;}
    else if(y1>=m && y2<=n) {array[0]=k; array[1]=y1; array[2]=l; array[3]=y2;}
    else if(y1>=m && x2<=l) {array[0]=k; array[1]=y1; array[2]=x2; array[3]=n;}
    return;
}

int main()
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
	int a,b,c,d;
	cout<<"Enter the coordinates:-\n";
	cin>>a>>b>>c>>d;
	int x=getmaxx()/2;
	int y=getmaxy()/2;
	//line(x+a,y-b,x+c,y-d);
	int p,q,r,s;  //p=xmin,q=xmax,r=ymin,s=ymax
	cout<<"Enter clip coordinates:-\n";
	cin>>p>>q>>r>>s;
	int xA=x+p,xB=x+q,xC=x+a,xD=x+c;
	int yA=y-r,yB=y-s,yC=y-b,yD=y-d;
	setcolor(WHITE);
	//line(xC,yC,xD,yD);
	line(xA,yA,xA,yB);
	line(xA,yA,xB,yA);
	line(xB,yA,xB,yB);
	line(xA,yB,xB,yB);
	setcolor(GREEN);
	int array[4];
	array[0]=0; array[1]=0; array[2]=0; array[3]=0;
	cohenlineclip(x,y,array,xA,xB,yA,yB,xC,yC,xD,yD);
	setcolor(GREEN);
	cout<<array[0]<<"\t"<<array[1]<<"\t"<<array[2]<<"\t"<<array[3]<<"\n";
	line(array[0],array[1],array[2],array[3]);

	getch();
	closegraph();
	return 0;
}