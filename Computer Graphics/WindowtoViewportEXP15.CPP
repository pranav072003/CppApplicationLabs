#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>

int max(int a,int b,int c)
{
       return (a>b)?((a>c)?a:c):((b>c)?b:c);
}

int min(int a,int b,int c)
{
	return (a<b)?((a<c)?a:c):((b<c)?b:c);
}

int ROUND(float num)
{
	if(num<=0) return (int)(num-0.5);
	else return (int)(num+0.5);
}

int main()
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
	int a,b,c,d,e,f;
	cout<<"Enter the coordinates:-\n";
	cin>>a>>b>>c>>d>>e>>f;  //coordinates of object to be drawn
	int x=getmaxx()/2;
	int y=getmaxy()/2;
	line(x+a,y-b,x+c,y-d);
	line(x+c,y-d,x+e,y-f);
	line(x+a,y-b,x+e,y-f);

	int p,q,r,s;            //p=xvmin,q=xvmax,r=yvmin,s=yvmax
	cout<<"Enter the viewport coordinates:-\n";
	cin>>p>>q>>r>>s;
	if(r<s || p>q)
	{
		cout<<"ERROR\n";
		exit(1);
	}

	int xwmin=min(a,c,e);
	int xwmax=max(a,c,e);
	int ywmin=max(b,d,f);
	int ywmax=min(b,d,f);

	float sx=(float)(q-p)/(xwmax-xwmin);
	float sy=(float)(s-r)/(ywmax-ywmin);

	float u,v,g,h,i,j;
	u=(a-xwmin)*sx + p;
	v=(b-ywmin)*sy + r;
	g=(c-xwmin)*sx + p;
	h=(d-ywmin)*sy + r;
	i=(e-xwmin)*sx + p;
	j=(f-ywmin)*sy + r;

	cout<<"Viewport shown in green colour\n";
	setcolor(GREEN);
	line(x+ROUND(u),y-ROUND(v),x+ROUND(g),y-ROUND(h));
	line(x+ROUND(g),y-ROUND(h),x+ROUND(i),y-ROUND(j));
	line(x+ROUND(u),y-ROUND(v),x+ROUND(i),y-ROUND(j));

	getch();
	closegraph();

	return 0;
}