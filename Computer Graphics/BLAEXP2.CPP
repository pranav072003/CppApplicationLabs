#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main()
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
	int xA,xB,yA,yB;
	cout<<"Welcome.Please enter x and y coordinates:-\n";
	cin>>xA>>yA>>xB>>yB;
	int x=getmaxx()/2;
	int y=getmaxy()/2;
	int x1=xA+x;
	int x2=xB+x;
	int y1=y-yA;
	int y2=y-yB;
	int delx=x1-x2;
	int dely=y1-y2;
	int p=2*dely - delx;
	putpixel(x,y,1);
	putpixel(x1,y1,1);
	while(x1<=x2)
	{
		x1++;
		if(p<=0)
		{
			p=p+2*dely;
		}
		else
		{
			p=p+2*(dely-delx);
			y1--;
		}
		putpixel(x1,y1,1);
	}

	getch();
	closegraph();
}