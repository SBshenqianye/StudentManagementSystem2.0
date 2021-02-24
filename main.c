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
	//�£�224 80
	//
	//�ϣ�224 72
	//



	MainMenu();


	return 0;
}
//==========


//==========
//�������main.c

static void NewClass(char *accountName){

	int SelectedOption = 1, PressedKey, PressedKey_temp = 0;

	while(1){
	
		if( SelectedOption == 1 && PressedKey_temp == 13){			//ָ��ָ������༶����ʱ���س�
			MessageBar("��δ������          ");
			Sleep(1000);
			AccountUI();
			break;
		}
		if( SelectedOption == 2 && PressedKey_temp == 13){			//ָ��ָ�����ʱ���س�
			MessageBar("��δ������          ");
			Sleep(1000);
			AccountUI();
			break;
		}
		if( SelectedOption == 3 && PressedKey_temp == 13){			//ָ��ָ�򷵻�ʱ���س�
			AccountUI();
			break;
		}
		system("cls");

		NewClass_Display(SelectedOption);
		MessageBar("\0");

		PressedKey_temp = _getch();
		if( PressedKey_temp == 224 ){	//���ؼ���ֵ�ĺ������ڷ�����ļ���ֵ�᷵������
			PressedKey = _getch();
			SelectedOption = getFlagWithPressedKey_III( SelectedOption, PressedKey);
		}
	}
}


static void AccountUI(){

	int SelectedOption = 1, PressedKey, PressedKey_temp = 0;

	while(1){
	
		if( SelectedOption == 1 && PressedKey_temp == 13){			//ָ��ָ��鿴�༶ʱ���س�
			MessageBar("��δ������          ");
			Sleep(1000);
			AccountUI( accountName);
			break;
		}
		if( SelectedOption == 2 && PressedKey_temp == 13){			//ָ��ָ���½��༶ʱ���س�
			MessageBar("��δ������          ");
			Sleep(1000);
			AccountUI( accountName);
			break;
		}
		if( SelectedOption == 3 && PressedKey_temp == 13){			//ָ��ָ��ע��ʱ���س�
			printf("ע���ɹ���\n");
			Sleep(1000);
			MainMenu();
			break;
		}
		system("cls");

		AccountUI_Display(SelectedOption, "aother");
		MessageBar("\0");

		PressedKey_temp = _getch();
		if( PressedKey_temp == 224 ){	//���ؼ���ֵ�ĺ������ڷ�����ļ���ֵ�᷵������
			PressedKey = _getch();
			SelectedOption = getFlagWithPressedKey_III( SelectedOption, PressedKey);
		}
	}
}


static int LoginUI(int dataInputState){

	int SelectedOption = 1, PressedKey, PressedKey_temp = 0;
	int IDCode = 1;

	while(1){

		if( SelectedOption == 1 && PressedKey_temp == 13){			//ָ��ָ�������˺�ʱ���س�
			if( dataInputState == -1){
				dataInputState = 0;
			}
			else if( dataInputState == 0){
				dataInputState = -1;
			}
			//LoginUI( dataInputState);
		}
		if( SelectedOption == 2 && PressedKey_temp == 13){			//ָ��ָ�����ʱ���س�
			if( IDCode == 1){
				AccountUI( accountName);
				break;
			}
			else if( IDCode == 2){
				MessageBar("�޴��˺š�          ");
			}
			else if( IDCode == 3){
				MessageBar("�������˺š�          ");
			}
			Sleep(1000);
			StrNum_Name = 0;
			LoginUI(-1);
			break;
		}
		if( SelectedOption == 3 && PressedKey_temp == 13){			//ָ��ָ�򷵻�ʱ���س�
			MainMenu();
			break;
		}
		system("cls");

		LoginUI_Display(SelectedOption, dataInputState, StrNum_Name, temp_accountName);
		MessageBar("\0");

		if( dataInputState == -1){						//������״̬
			PressedKey_temp = _getch();
			if( PressedKey_temp == 224 ){			//���ؼ���ֵ�ĺ������ڷ�����ļ���ֵ�᷵������
				PressedKey = _getch();
				SelectedOption = getFlagWithPressedKey_III( SelectedOption, PressedKey);
			}
		}
		else if( dataInputState == 0){					//����״̬
			PressedKey_temp = _getch();

			if( PressedKey_temp == 13){						//����ǻس��������Թ��˴�ѭ��
				continue;
			}
			if( PressedKey_temp != 224 && PressedKey_temp != 8){//���Ƿ�����˸���������ַ�
				PressedKey = PressedKey_temp;
				if(StrNum_Name < NameNumMax){
					temp_accountName[StrNum_Name] = PressedKey;
					StrNum_Name++;
					temp_accountName[StrNum_Name] = '\0';
				}
				else{
					MessageBar("���ֻ������16λ�ַ���          ");
					Sleep(1000);
				}
			}
			else if( PressedKey_temp == 8){
				if(StrNum_Name > 0){
					temp_accountName[StrNum_Name - 1] = '\0';
					StrNum_Name--;
				}
				else{
					MessageBar("�������˻����ơ�          ");
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

		if( SelectedOption == 1 && PressedKey_temp == 13){			//ָ��ָ�����ʱ���س�
			LoginUI(-1);
			break;
		}
		if( SelectedOption == 2 && PressedKey_temp == 13){			//ָ��ָ��ע��ʱ���س�
			MessageBar("��δ������          ");
			Sleep(1000);
			MainMenu();
			break;
		}
		if( SelectedOption == 3 && PressedKey_temp == 13){			//ָ��ָ�򷵻�ʱ���س�
			break;
		}

		system("cls");

		MainMenu_Display(SelectedOption);
		MessageBar("��ӭʹ�øó���");
		
		PressedKey_temp = _getch();
		if( PressedKey_temp == 224 ){		//���ؼ���ֵ�ĺ������ڷ�����ļ���ֵ�᷵������
			PressedKey = _getch();
			SelectedOption = getFlagWithPressedKey_III( SelectedOption, PressedKey);
		}
	}
	system("cls");
	printf("��лʹ�ã�\n");
}
//==========
