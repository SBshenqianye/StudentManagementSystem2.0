#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <direct.h>
#include <io.h>

#include <conio.h>


//==========
#define YESbreak 1
#define NObreak 0
#define NameNumMax 16
//==========

struct CLASS{
	int ordinal;
	char name[NameNumMax];
	struct CLASS *next;
};

struct STUDENT{
	int ordinal;
	char name[NameNumMax];
	long int ID;
	int sex[NameNumMax];
	char addres[NameNumMax];
	long int PhoneNum;
	struct *next;
};
