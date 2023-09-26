#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void POINTS(int x,int y,int X,int Y);

void main()
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
	int X=getmaxx()/2;
	int Y=getmaxy()/2;
	int r;
	cout<<"Welcome! Enter the radius of circle to be made:-\n";
	cin>>r;
	int xA=0;
	int yA=r;
	POINTS(xA,yA,X,Y);
	int d=1-r;
	while(xA<=yA)
	{
		if(d<=0)
		{
			d=d+2*xA+3;
		}
		else
		{
			d=d+2*(xA-yA)+5;
			yA--;
		}
		xA++;
		POINTS(xA,yA,X,Y);
	}

	getch();
	closegraph();
}

void POINTS(int x,int y,int X,int Y)
{
	putpixel(X+x,Y-y,1);
	putpixel(X-x,Y-y,1);
	putpixel(X+x,Y+y,1);
	putpixel(X-x,Y+y,1);
	putpixel(X+y,Y-x,1);
	putpixel(X-y,Y-x,1);
	putpixel(X+y,Y+x,1);
	putpixel(X-y,Y+x,1);
}