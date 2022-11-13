#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include "console.h"
#include <conio.h>
#include <fstream> 
#include <time.h>
using namespace std;

void SetWindowSize(SHORT width, SHORT height);
void SetScreenBufferSize(SHORT width, SHORT height);
void ShowScrollbar(BOOL Show);
void ShowCur(bool CursorVisibility);
void DisableSelection();




#define default_ColorCode		7


#define key_Up		1072
#define key_Down	1080
#define key_Left	1075
#define key_Right	1077
#define key_none	-1

//--------------------------------------------------------


//--------------------------------------------------------

int inputKey();

//-------------------------Screen-------------------------
void clrscr();

//screen: goto [x,y]
void gotoXY(int column, int line);

//screen: get [x]
int whereX();

//screen: get [y]
int whereY();

void TextColor(int color);
//end----------------------Screen----------------------end

void SetColor(WORD color);