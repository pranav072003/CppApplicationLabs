#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void POINTS(int x,int y,int X,int Y);

void main()
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
	int r;
	cout<<"Welcome! Enter radius of circle to be made:-\n";
	cin>>r;
	int X=getmaxx()/2;
	int Y=getmaxy()/2;
	int xA=0;
	int yA=r;
	POINTS(xA,yA,X,Y);
	int d=3-2*r;
	while(xA<=yA)
	{
		if(d<=0)
		{
			d=d+4*xA+6;
		}
		else
		{
			d=d+4*(xA-yA)+10;
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