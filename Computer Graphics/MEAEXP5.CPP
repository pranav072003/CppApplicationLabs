#include <stdio.h>
#include <math.h>
#include <iostream.h>
#include <conio.h>
#include <graphics.h>

void POINTS(int x,int y,int X,int Y);

float decisionparameter(float x,float y,float a,float b)
{
	float param;
	param=pow(b*(x+0.5),2)+pow(a*(y-1),2)-pow(a*b,2);
	return param;
}

void main()
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
	int a,b;
	cout<<"Welcome! Please enter the lengths of semi major and semi minor axes:-\n";
	cin>>a>>b;
	int X=getmaxx()/2;
	int Y=getmaxy()/2;
	int x=0;
	int y=b;
	POINTS(x,y,X,Y);
	float dx=2*pow(b,2)*x;
	float dy=2*pow(a,2)*y;
	float b1=(float)b;
	float a1=(float)a;
	float d1=pow(b1,2)+(0.25*pow(a1,2))-(pow(a1,2)*b1);
	float d2;
	while(dx<dy)
	{
		dx=dx+(2*pow(b1,2));
		if(d1<=0.0)
		{
			d1=d1+dx+(pow(b1,2));
		}
		else
		{
			dy=dy-(2*pow(a1,2));
			d1=d1+dx-dy+(pow(b1,2));
			y--;
		}
		x++;
		POINTS(x,y,X,Y);
	}
	//d2=decisionparameter((float)x,(float)y,a1,b1);
	POINTS(x,y,X,Y);
	while(y>0)
	{
	       //	POINTS(x,y,X,Y);
		dy=dy-(2*pow(a1,2));
		if(d2<=0.0)
		{
			dx=dx+(2*pow(b1,2));
			d2=d2+dx-dy+(pow(a1,2));
			x++;
		}
		else
		{
			d2=d2-dy+(pow(a1,2));
		}
		y--;
		POINTS(x,y,X,Y);
	}
	getch();
	closegraph();
}

void POINTS(int x,int y,int X,int Y)
{
	putpixel(X+x,Y-y,1);
	putpixel(X-x,Y-y,1);
	putpixel(X-x,Y+y,1);
	putpixel(X+x,Y+y,1);
}