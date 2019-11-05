//LAB EXAM - 08
//COHEN & SUTHERLAND LINE CLIPPING ALGORITHM
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

//PT type declaration
typedef struct coordinate
{
	int x,y;
	char code[4];
}PT;

//Function declaration
void drawwindow();
void drawline(PT,PT);
int visibility(PT,PT);
PT setcode(PT);
PT resetendpt(PT,PT);

void main()
{
	//Variable declartion
	int gd=DETECT,gm;
	PT p1,p2,p3,p4;
	int v;
	clrscr();
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

	//Taking input
	cout<<"COHEN & SUTHERLAND LINE CLIPPING ALGORITHM\n";
	cout<<"Enter coordinates [x1 y1]: ";
	cin>>p1.x>>p1.y;
	cout<<"Enter coordinates [x2 y2]: ";
	cin>>p2.x>>p2.y;

	//BEFORE CLIPPING
	cleardevice();
	cout<<"BEFORE CLIPPING";
	drawwindow();
	drawline(p1,p2);
	getch();
	cleardevice();

	//CLIPPING
	//Setting TBRL code
	p1=setcode(p1);
	p2=setcode(p2);
	//Checking the visibility of the line
	v=visibility(p1,p2);
	switch(v)
	{
		case 0:	//COMPLETELY VISIBLE LINE
			drawwindow();
			drawline(p1,p2);
			break;
		case 1:	//LINE NOT VISIBLE AT ALL
			drawwindow();
			break;
		case 2:	//PARTIALLY VISIBLE
			p3=resetendpt(p1,p2);
			p4=resetendpt(p2,p1);
			cout<<"AFTER CLIPPING";
			drawwindow();
			drawline(p3,p4);
			break;
		default://INVALID
			cout<<"Invalid input.";
			break;
	}
	getch();
}

//function to draw the window
void drawwindow()
{
	int arr[20]=	{150,100,
			 450,100,
			 450,350,
			 150,350,
			 150,100};
	drawpoly(5,arr);
}

//function to draw the line
void drawline(PT p1,PT p2)
{
	line(p1.x,p1.y,p2.x,p2.y);
}

//function to set the TBRL code
PT setcode(PT p)
{
	//TOP
	if(p.y<100)
	{
		p.code[0]='1';
	}
	else
	{
		p.code[0]='0';
	}
	//BOTTOM
	if(p.y>350)
	{
		p.code[1]='1';
	}
	else
	{
		p.code[1]='0';
	}
	//RIGHT
	if(p.y>450)
	{
		p.code[2]='1';
	}
	else
	{
		p.code[2]='0';
	}
	//LEFT
	if(p.y<150)
	{
		p.code[3]='1';
	}
	else
	{
		p.code[3]='0';
	}
	return p;
}

//function to check the visibility
int visibility(PT p1,PT p2)
{
	int i,flag=0;

	for(i=0;i<4;i++)
	{
		if((p1.code[i]=='1') || (p2.code[i]=='1'))
		{
			flag=1;
		}
	}
	if(flag==0)
	{
		return 0; //LINE IS COMPLETELY VISIBLE
	}
	for(i=0;i<4;i++)
	{
		if((p1.code[i]==p2.code[i]) && (p1.code[i]=='1'))
		{
			flag=0;
		}
	}
	if(flag==0)
	{
		return 1; //LINE IS NOT VISIBLE AT ALL
	}
	else
	{
		return 2; //LINE IS PARTIALLY VISIBLE
	}
}

//function to get the new end point after clipping
PT resetendpt(PT p1,PT p2)
{
	PT temp;
	int x,y,i;
	float m,k;
	m=(float) (p2.y-p1.y)/(p2.x-p1.x);
	//FOR RIGHT & LEFT
	if(p1.code[2]=='1')
	{
		x=450;
	}
	if(p1.code[3]=='1')
	{
		x=150;
	}
	if((p1.code[2]=='1') || (p1.code[3]=='1'))
	{
		k=p1.y+(m*(x-p1.x));
		temp.x=x;
		temp.y=k;
		for(i=0;i<4;i++)
		{
			temp.code[i]=p1.code[i];
		}
		if((temp.code[0]=='0')&&(temp.code[1]=='0'))
		{
			return temp;
		}
	}
	//FOR TOP & BOTTOM
	if(p1.code[0]=='1')
	{
		y=100;
	}
	if(p1.code[1]=='1')
	{
		y=350;
	}
	if((p1.code[0]=='1')||(p1.code[1]=='1'))
	{
		k=p1.x+(m*(y-p1.y));
		temp.x=k;
		temp.y=y;
		for(i=0;i<4;i++)
		{
			temp.code[i]=p1.code[i];
		}
		return temp;
	}
	else
	{
		return p1;
	}
}