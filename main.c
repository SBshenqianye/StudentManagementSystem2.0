#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#include <conio.h>

#include ".\menuDisplay.h"
#include ".\selectOptions.h"
//==========
#define YESbreak 1
#define NObreak 0

//==========

//==========

static void MainMenu(void);
static void AccountUI();
//==========




//==========
char temp_accountName[NameNumMax];
char accountName[NameNumMax];
int StrNum_Name = 0;
int main(){
	//下：224 80
	//
	//上：224 72
	//



	MainMenu();


	return 0;
}
//==========


//==========
//打算放在main.c

static void NewClass(char *accountName){

	int SelectedOption = 1, PressedKey, PressedKey_temp = 0;

	while(1){
	
		if( SelectedOption == 1 && PressedKey_temp == 13){			//指标指向输入班级名称时按回车
			MessageBar("暂未开发。          ");
			Sleep(1000);
			AccountUI();
			break;
		}
		if( SelectedOption == 2 && PressedKey_temp == 13){			//指标指向完成时按回车
			MessageBar("暂未开发。          ");
			Sleep(1000);
			AccountUI();
			break;
		}
		if( SelectedOption == 3 && PressedKey_temp == 13){			//指标指向返回时按回车
			AccountUI();
			break;
		}
		system("cls");

		NewClass_Display(SelectedOption);
		MessageBar("\0");

		PressedKey_temp = _getch();
		if( PressedKey_temp == 224 ){	//返回键盘值的函数对于方向键的键盘值会返回两次
			PressedKey = _getch();
			SelectedOption = getFlagWithPressedKey_III( SelectedOption, PressedKey);
		}
	}
}


static void AccountUI(){

	int SelectedOption = 1, PressedKey, PressedKey_temp = 0;

	while(1){
	
		if( SelectedOption == 1 && PressedKey_temp == 13){			//指标指向查看班级时按回车
			MessageBar("暂未开发。          ");
			Sleep(1000);
			AccountUI( accountName);
			break;
		}
		if( SelectedOption == 2 && PressedKey_temp == 13){			//指标指向新建班级时按回车
			MessageBar("暂未开发。          ");
			Sleep(1000);
			AccountUI( accountName);
			break;
		}
		if( SelectedOption == 3 && PressedKey_temp == 13){			//指标指向注销时按回车
			printf("注销成功！\n");
			Sleep(1000);
			MainMenu();
			break;
		}
		system("cls");

		AccountUI_Display(SelectedOption, "aother");
		MessageBar("\0");

		PressedKey_temp = _getch();
		if( PressedKey_temp == 224 ){	//返回键盘值的函数对于方向键的键盘值会返回两次
			PressedKey = _getch();
			SelectedOption = getFlagWithPressedKey_III( SelectedOption, PressedKey);
		}
	}
}


static int LoginUI(int dataInputState){

	int SelectedOption = 1, PressedKey, PressedKey_temp = 0;
	int IDCode = 1;

	while(1){

		if( SelectedOption == 1 && PressedKey_temp == 13){			//指标指向输入账号时按回车
			if( dataInputState == -1){
				dataInputState = 0;
			}
			else if( dataInputState == 0){
				dataInputState = -1;
			}
			//LoginUI( dataInputState);
		}
		if( SelectedOption == 2 && PressedKey_temp == 13){			//指标指向登入时按回车
			if( IDCode == 1){
				AccountUI( accountName);
				break;
			}
			else if( IDCode == 2){
				MessageBar("无此账号。          ");
			}
			else if( IDCode == 3){
				MessageBar("请输入账号。          ");
			}
			Sleep(1000);
			StrNum_Name = 0;
			LoginUI(-1);
			break;
		}
		if( SelectedOption == 3 && PressedKey_temp == 13){			//指标指向返回时按回车
			MainMenu();
			break;
		}
		system("cls");

		LoginUI_Display(SelectedOption, dataInputState, StrNum_Name, temp_accountName);
		MessageBar("\0");

		if( dataInputState == -1){						//非输入状态
			PressedKey_temp = _getch();
			if( PressedKey_temp == 224 ){			//返回键盘值的函数对于方向键的键盘值会返回两次
				PressedKey = _getch();
				SelectedOption = getFlagWithPressedKey_III( SelectedOption, PressedKey);
			}
		}
		else if( dataInputState == 0){					//输入状态
			PressedKey_temp = _getch();

			if( PressedKey_temp == 13){						//如果是回车键，就略过此次循环
				continue;
			}
			if( PressedKey_temp != 224 && PressedKey_temp != 8){//不是方向键退格键就输入字符
				PressedKey = PressedKey_temp;
				if(StrNum_Name < NameNumMax){
					temp_accountName[StrNum_Name] = PressedKey;
					StrNum_Name++;
					temp_accountName[StrNum_Name] = '\0';
				}
				else{
					MessageBar("最多只能输入16位字符。          ");
					Sleep(1000);
				}
			}
			else if( PressedKey_temp == 8){
				if(StrNum_Name > 0){
					temp_accountName[StrNum_Name - 1] = '\0';
					StrNum_Name--;
				}
				else{
					MessageBar("请输入账户名称。          ");
					Sleep(1000);
				}
			}
			else{
				PressedKey_temp = _getch();
			}
		}
	}
	return dataInputState;
}


static void MainMenu(void){

	int SelectedOption = 1, PressedKey, PressedKey_temp = 0;

	while(1){

		if( SelectedOption == 1 && PressedKey_temp == 13){			//指标指向登入时按回车
			LoginUI(-1);
			break;
		}
		if( SelectedOption == 2 && PressedKey_temp == 13){			//指标指向注册时按回车
			MessageBar("暂未开发。          ");
			Sleep(1000);
			MainMenu();
			break;
		}
		if( SelectedOption == 3 && PressedKey_temp == 13){			//指标指向返回时按回车
			break;
		}

		system("cls");

		MainMenu_Display(SelectedOption);
		MessageBar("欢迎使用该程序！");
		
		PressedKey_temp = _getch();
		if( PressedKey_temp == 224 ){		//返回键盘值的函数对于方向键的键盘值会返回两次
			PressedKey = _getch();
			SelectedOption = getFlagWithPressedKey_III( SelectedOption, PressedKey);
		}
	}
	system("cls");
	printf("感谢使用！\n");
}
//==========
