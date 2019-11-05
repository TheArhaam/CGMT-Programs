//LAB EXAM - 02
//BRESENHAMS CIRCLE DRAWING ALGORITHM
#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>

void bresenhamcircle(float,float,float);

void main()
{
	float x,y,r;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	cout<<"BRESENHAMS CIRCLE DRAWING ALGORITHM\n";
	//Taking Input
	cout<<"Enter the center coordinates[x y]: ";
	cin>>x>>y;
	cout<<"Enter the radius: ";
	cin>>r;

	//Calling function to draw circle
	bresenhamcircle(x,y,r);

	//closegraph();
	getch();
}

//Function to draw a circle using Bresenhams Algorithm
void bresenhamcircle(float x1,float y1,float r)
{
	float x,y,p;
	x=0;
	y=r;
	p=3-(2*r);
	while(x<=y)
	{
		//Circle is divided into 8 parts
		//We put one pixel in each part
		putpixel(x1+x ,y1+y, LIGHTBLUE);
		putpixel(x1+x ,y1-y, LIGHTBLUE);
		putpixel(x1-x ,y1+y, LIGHTBLUE);
		putpixel(x1-x ,y1-y, LIGHTBLUE);
		putpixel(x1+y ,y1+x, LIGHTBLUE);
		putpixel(x1+y ,y1-x, LIGHTBLUE);
		putpixel(x1-y ,y1+x, LIGHTBLUE);
		putpixel(x1-y ,y1-x, LIGHTBLUE);
		x++;
		if(p<0)
		{
			p=p+4*x+6;
		}
		else
		{
			p=p+4*(x-y)+10;
			y--;
		}
		delay(100);
	}
	return;
}