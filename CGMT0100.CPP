//BOUNCING CIRCLE (with Matrix rain at the end)
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>

void main()
{
int gd=DETECT,gm;
int x,y,j,c,i;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
setcolor(1);

//LOOP
for(j=240,c=2,x=0;j<430;j=j+50)
{
	//DOWN & RIGHT
	for(y=j;y<=430;y=y+10,x=x+7)
	{
		delay(20);
		cleardevice();
		fillellipse(x,y,50,50);
	}

	//Color change on bounce
	setfillstyle(1,c);

	//UP & RIGHT
	for(;y>=j+30;y=y-10,x=x+7,c++)
	{
		delay(20);
		cleardevice();
		fillellipse(x,y,50,50);
	}
}

//RAIN
for(i=0;i<640;i=i+random(20))
{
	for(j=0;j<480;j=j+random(15))
	{
		delay(1);
		setcolor(GREEN);
		setfillstyle(1,WHITE);
		setfillstyle(1,LIGHTGREEN);
		setfillstyle(1,GREEN);
		fillellipse(i,j,2,2);
	}
}

getch();
closegraph();
}