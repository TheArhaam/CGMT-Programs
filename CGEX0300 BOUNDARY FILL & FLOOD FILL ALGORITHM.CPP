//LAB EXAM - 03
//BOUNDARY FILL & FLOOD FILL ALGORITHM
#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>

void boundaryfill(int,int,int,int);
void floodfill(int,int,int,int);

void main()
{
	int edges,arr[20],choice,x,y,i;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	cout<<"FILL ALGORTHMS\n";
	//Taking input
	cout<<"Enter the number of edges: ";
	cin>>edges;
	for(i=0;i<edges*2;i=i+2)
	{
		cout<<"Enter point coordinates [x y]: ";
		cin>>arr[i]>>arr[i+1];
	}
	arr[i]=arr[0];
	arr[i+1]=arr[1];

	//MENU
	cout<<"1)Boundary fill\n";
	cout<<"2)Flood fill\n";
	cout<<"Enter your choice [1/2]: ";
	cin>>choice;

	//Drawing the polygon
	cleardevice();
	setcolor(WHITE);
	drawpoly(edges+1,arr);

	switch(choice)
	{
		case 1:	boundaryfill(arr[0]+1,arr[1]+1,BLUE,WHITE);
			break;
		case 2: floodfill(arr[0]+1,arr[1]+1,BLUE,BLACK);
			break;
		default:cout<<"Invalid input.";
			break;
	}
	getch();
}

//function for boundary fill
void boundaryfill(int x,int y,int fill,int boundary)
{
	int current;
	current = getpixel(x,y);
	if( (current!=fill) && (current!=boundary) )
	{
		putpixel(x,y,fill);
		boundaryfill(x+1,y,fill,boundary);
		boundaryfill(x-1,y,fill,boundary);
		boundaryfill(x,y+1,fill,boundary);
		boundaryfill(x,y-1,fill,boundary);
	}
	return;
}

//function for flood fill
void floodfill(int x,int y,int fill,int old)
{
	int current;
	current = getpixel(x,y);
	if(current == old)
	{
		putpixel(x,y,fill);
		floodfill(x+1,y,fill,old);
		floodfill(x-1,y,fill,old);
		floodfill(x,y+1,fill,old);
		floodfill(x,y-1,fill,old);
	}
	return;
}
