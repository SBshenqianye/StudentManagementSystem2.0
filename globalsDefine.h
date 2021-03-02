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

struct LIST{
	int ordinal;
	char name[NameNumMax];
	struct LIST *next;
};

struct STUDENT{
	int ordinal;
	char name[NameNumMax];
	char ID[NameNumMax];
	char sex[NameNumMax];
	char addres[NameNumMax];
	char PhoneNum[NameNumMax];
};

struct HEADS{
	int ordinal;
	char name[NameNumMax];
	struct STUDENT student;
	struct HEADS *next;
};