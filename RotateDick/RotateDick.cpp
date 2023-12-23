// RotateDick.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#define _CRT_SECURE_NO_WARNINGS 1
#include "rotate.h"
#include "decrypt.h"
#include <mmsystem.h>
#include <stdlib.h>
#include <time.h>
#pragma comment(lib,"winmm.lib")
//#pragma comment(linker, "/section:.data,RWE") 
J8 isJ, is8;
IMAGE bkgrd,dickbit;
MOUSEMSG mMSG;
Dick d[6];
int head;
void game_start();
void chooseDicks();
void start();

void rd(int n) {
	//BeginBatchDraw();
	    IMAGE dick1, dick1bit;
		int temp;
		temp = head == 4 ? n: head;
		
		RotateImage(&dick1, & d[temp].head, d[n].deg * PI,false);
		RotateImage(&dick1bit, &dickbit, d[n].deg * PI, true);
		//cleardevice();		
		putimage(d[n].DickX, d[n].DickY, &dick1bit, SRCPAINT);
		putimage(d[n].DickX, d[n].DickY, &dick1, SRCAND);
		
		d[n].deg += 0.02;
		//Sleep(1);
		if (d[n].deg >= 2)
		{
			d[n].isDick = false;
			d[n].deg = 0;
			d[n].finishnum++;
		}
		if (d[n].finishnum == 5)
		{
			int tem = rand() % 10;
			
		}
		//EndBatchDraw();
} 
void game_start()
{
	putimage(0, 0, &bkgrd);
	/*
	mciSendString(L"close j", NULL, 0, NULL);
	mciSendString(L"open dick\\water.mp3 alias j", NULL, 0, NULL);
	mciSendString(L"play j repeat", NULL, 0, NULL);
	*/
	while (1)
	{
		BeginBatchDraw();
		putimage(0, 0, &bkgrd);
		mMSG = GetMouseMsg();

		settextstyle(50, 25, L"楷体");
		outtextxy(800,450,L"Exit");
		if (mMSG.x > 800 && mMSG.x< 900 && mMSG.y>450 && mMSG.y < 500 && mMSG.uMsg == WM_LBUTTONDOWN)
		{
			del();
			
			exit(0);
		}
		for (int i = 0; i < 6; i++)
		{
			if (mMSG.x > d[i].DickX && mMSG.x< d[i].DickX + 74 && mMSG.y>d[i].DickY && mMSG.y < d[i].DickY + 74 && mMSG.uMsg == WM_LBUTTONDOWN)
			{
				d[i].isDick = true;
				
			}
		}

		for (int i = 0; i < 4; i++)

		{

			if (d[i].isDick)
			{
				rd(i);
			}
			else
			{
				int temp;
				temp = head == 4 ? i : head;
				putimage(d[i].DickX, d[i].DickY, &d[temp].head);
			}


		}
		EndBatchDraw();
		Sleep(1);

	}
}
void chooseDicks()
{
	setbkcolor(RGB(150, 150, 255));
	cleardevice();
	settextstyle(60, 25, L"楷体");
	outtextxy(80, 100, _T("Choose a type  of Dick you like"));
	for (int i = 0; i < 4; i++)

	{		
			putimage(d[i].DickX, 300, &d[i].head);
	}

	while (1) 
	{
		mMSG = GetMouseMsg();
		for (int i = 0; i < 6; i++)
		{
			if (mMSG.x > d[i].DickX && mMSG.x < d[i].DickX + 74 && mMSG.y>300 && mMSG.y < 300 + 74 && mMSG.uMsg == WM_LBUTTONDOWN)
			{
				
				head = i;
				
				game_start();
			}
		}
	}




}
void start()
{
	setbkcolor(RGB(150, 150, 255));
	cleardevice();
	settextstyle(100, 50, L"楷体");
	outtextxy(190, 100, _T("ROTATE DICKS"));
	settextstyle(30, 15, L"楷体");
	outtextxy(500, 200, _T("2.0.2 made by shousake"));

	setlinestyle(0, 5);
	settextstyle(30, 10, L"楷体");
	line(300, 350, 300, 400);
	line(600, 350, 600, 400);
	line(300, 350, 600, 350);
	line(300, 400, 600, 400);
	outtextxy(330, 360, _T("Rotate single-typed Dicks"));
	line(300, 450, 300, 500);
	line(600, 450, 600, 500);
	line(300, 450, 600, 450);
	line(300, 500, 600, 500);
	outtextxy(330, 460, _T("Rotate variety-typed Dicks"));

	while (1)
	{
		mMSG = GetMouseMsg();
		if (mMSG.x > 300 && mMSG.x < 600 && mMSG.y>450 && mMSG.y < 500 && mMSG.uMsg == WM_LBUTTONDOWN)
		{
			head = 4;
			game_start();
		}
		if (mMSG.x > 300 && mMSG.x < 600 && mMSG.y>350 && mMSG.y < 400 && mMSG.uMsg == WM_LBUTTONDOWN)
		{
			chooseDicks();
		}
	}
}
int main()
{
	
		
	
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 4; i++)
	{
		d[i].deg = 0;
	}
	d[0].DickX = 100;
	d[0].DickY = 100;
	d[1].DickX = 300;
	d[1].DickY = 100;
	d[2].DickX = 500;
	d[2].DickY = 100;
	d[3].DickX = 700;
	d[3].DickY = 100;
	//mciSendString(L"open dick\\water.mp3 alias a", NULL, 0, NULL);
	decrypt();
	loadimage(&d[0].head,L"dick\\ddick\\dickhead.BMP",74,74);
	loadimage(&d[1].head, L"dick\\ddick\\dickhead1.BMP", 74, 74);
	loadimage(&d[2].head, L"dick\\ddick\\dickhead2.BMP", 74, 74);
	loadimage(&d[3].head, L"dick\\ddick\\dickhead3.BMP", 74, 74);
	//loadimage(&dickbit, L"dick\\dickbit.BMP", 74, 74);
	dickbit.Resize(74,74);
	
	DWORD* dst = GetImageBuffer(&dickbit);
	for (int i = 0; i < 74 * 74; i++)
	{
		dst[i] = 0xffffffff;
	}
	
	loadimage(&bkgrd, L"dick\\ddick\\bk.BMP");
	del();
	//BeginBatchDraw();
    //:begin
	
	initgraph(970, 545);

	cleardevice();
	putimage(0,0,&dickbit);
     start();
	 del();
    //EndBatchDraw();
	

}

