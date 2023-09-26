#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <graphics.h>

int ROUND(float p)
{
	if(p<=0)
	{
		return (int)(p-0.5);
	}
	else
	{
		return (int)(p+0.5);
	}
       //	return (int)(p+0.5);
}

int abs(int p)
{
	if(p<0) return -p;
	else return p;
}

void main()
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
	int x=getmaxx()/2;
	int y=getmaxy()/2;
	int xA,xB,yA,yB;
	cout<<"Welcome.Enter the x and y coordinates:-\n";
	cin>>xA>>yA>>xB>>yB;
	int x1=xA+x;
	int y1=y-yA;
	int x2=xB+x;
	int y2=y-yB;
	int delx=x2-x1;
	int dely=y2-y1;
	int steps;
	if(delx>=dely)
	{
		steps=delx;
	}
	else
	{
		steps=dely;
	}
	float xin=(float)delx/(float)steps;
	float yin=(float)dely/(float)steps;
	putpixel(x1,y1,1);
	float c1=(float)x1;
	float c2=(float)y1;
	for(int i=1;i<=steps;i++)
	{
		c1+=xin;
		c2+=yin;
		if(i%3==0) continue;
		putpixel(ROUND(c1),ROUND(c2),1);
	}
	int a=0,b=0;
	int x3=x-a;
	int y3=y-b;
	putpixel(x3,y3,1);

	getch();
	closegraph();
}