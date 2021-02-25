
#include "globalsDefine.h"

//==========
char temp_accountName[NameNumMax] = "author";		//������� �˻�ID��ʾ
char reg_accountName[NameNumMax];		//ע����� �˻�ID��ʾ
char accountName[NameNumMax] = "author";			//����ɹ����ID��ʾ
int StrNum_Name = 0;					//
int StrNum_NewName = 0;					//


//==========
#include ".\menuDisplay.h"
#include ".\selectOptions.h"
//==========






//==========
void LogToAcc();
void ReToLog();
void MainMenu();
void AccountUI();
void addClass(struct CLASS **pclassLineHead, int classNum);
//==========

void InitializeState(){
	FILE *testingFile;
	int InitializeState;
	if( ( testingFile = fopen( ".\\data\\users.txt", "r") ) == NULL ){
		if( _access( ".\\data", 0) == -1){
			InitializeState = mkdir(".\\data");
			if( InitializeState == -1){
				printf("��ʼ��ʧ�ܣ����˳�����\n");
				exit( 0);
			}
		}

		testingFile = fopen( ".\\data\\users.txt", "w");
		fputs( "���û��б�", testingFile);
		fclose( testingFile);
	}
}



//==========
int main(){
	InitializeState();
	MainMenu();
	return 0;
}
//==========


//==========
//�������main.c


void ViewClassList(){

	int SelectedOption = 10, PressedKey, PressedKey_temp = 0;

	int ClassCount = 0;
	char pathname[NameNumMax + 30] = ".\\data\\", strTemp[NameNumMax];
	FILE *fp;
	struct CLASS *classLineHead = NULL;		//�������ͷ��ʼ��Ϊ��

	strcat( pathname, accountName);			
	strcat( pathname, "\\classlist.txt");
	if( (fp = fopen(pathname, "r")) == NULL){			//��ָ��·���ļ�
		MessageBar("���ļ�ʧ�ܣ������ļ��Ķ�Ȩ��          ");
		Sleep(1000);
		system("pause");
		return;
	}
	while( !feof(fp)){								//����classlist.txt�а༶����
		fgets( strTemp, NameNumMax, fp);
		ClassCount += 1;
	}
	fclose( fp);
	ClassCount--;						//���⡰�༶�б�������༶������˼�һ

	while(1){
	
		if( SelectedOption == ClassCount + 1 && PressedKey_temp == 13){			//ָ��ָ�򷵻�ʱ���س�
			AccountUI();
			break;
		}

		addClass(&classLineHead, ClassCount);
		
		system("cls");
		ViewClassList_Display(SelectedOption, ClassCount, classLineHead);

		fflush(stdin);
		PressedKey_temp = _getch();
		if( PressedKey_temp == 224 ){	//���ؼ���ֵ�ĺ������ڷ�����ļ���ֵ�᷵�����Σ��������ж��Ƿ�Ϊ�����
			PressedKey = _getch();
			SelectedOption = getFlagWithPressedKey_ALL( SelectedOption, PressedKey, ClassCount + 1);
		}
	}
}


void addClass(struct CLASS **pclassLineHead, int classNum){		//β�ӷ�
	struct CLASS *newClass;
	FILE *classListFile;
	char className[NameNumMax], pathname[NameNumMax + 30] = ".\\data\\";
	int i = 0;
	
	strcat( pathname, accountName);
	strcat( pathname, "\\classlist.txt");
	if( (classListFile = fopen( pathname, "r")) == NULL){
		MessageBar("���ļ�ʧ��");
	}

	while( !feof(classListFile)){
		newClass = (struct CLASS *)malloc(sizeof(struct CLASS));
		if( newClass == NULL){						//�����ַ������һ���ṹ��
			MessageBar("�ڴ����ʧ��");
			exit(1);
		}

		fgets( className, NameNumMax, classListFile);
		for( i = 0; i < 20; i++){
			if( className[i] == '\n'){						//ɾȥ'\n'
				className[i] = '\0';
			}
		}
		strcpy(newClass->name, className);				//����Ϣ���뵽�ṹ��
		newClass->ordinal = i;
		i++;


		if( *pclassLineHead == NULL){
			*pclassLineHead = newClass;				//��ͷΪ�վͰѱ�ͷֱ��ָ���½ṹ��
		}
		else{
			newClass->next = *pclassLineHead;		//��ͷ���������½ṹ��ָ���ͷ
			*pclassLineHead = newClass;				//Ȼ��ѱ�ͷָ���½ṹ��
		}
	}
	fclose( classListFile);
}




void NewClass(){

	int SelectedOption = 1, PressedKey, PressedKey_temp = 0;

	while(1){
	
		if( SelectedOption == 1 && PressedKey_temp == 13){			//ָ��ָ������༶����ʱ���س�
			MessageBar("��δ������          ");
			Sleep(500);
			AccountUI();
			break;
		}
		if( SelectedOption == 2 && PressedKey_temp == 13){			//ָ��ָ�����ʱ���س�
			MessageBar("��δ������          ");
			Sleep(500);
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
			SelectedOption = getFlagWithPressedKey_ALL( SelectedOption, PressedKey, 3);
		}
	}
}


void AccountUI(){

	int SelectedOption = 1, PressedKey, PressedKey_temp = 0;

	while(1){
	
		if( SelectedOption == 1 && PressedKey_temp == 13){			//ָ��ָ��鿴�༶ʱ���س�
			
			ViewClassList();
		}
		if( SelectedOption == 2 && PressedKey_temp == 13){			//ָ��ָ���½��༶ʱ���س�
			MessageBar("��δ������          ");
			Sleep(500);
			AccountUI( accountName);
			break;
		}
		if( SelectedOption == 3 && PressedKey_temp == 13){			//ָ��ָ��ע��ʱ���س�
			printf("ע���ɹ���\n");
			Sleep(500);
			MainMenu();
			break;
		}
		system("cls");


		AccountUI_Display(SelectedOption, accountName);
		MessageBar("\0");

		PressedKey_temp = _getch();
		if( PressedKey_temp == 224 ){	//���ؼ���ֵ�ĺ������ڷ�����ļ���ֵ�᷵������
			PressedKey = _getch();
			SelectedOption = getFlagWithPressedKey_ALL( SelectedOption, PressedKey, 3);
		}
	}
}


int LoginUI(int dataInputState){								//�������

	int SelectedOption = 1, PressedKey, PressedKey_temp = 0;


	while(1){

		if( SelectedOption == 1 && PressedKey_temp == 13){			//ָ��ָ�������˺�ʱ���س�
			if( dataInputState == -1){
				dataInputState = 0;
			}
			else if( dataInputState == 0){
				dataInputState = -1;
			}
		}
		if( SelectedOption == 2 && PressedKey_temp == 13){			//ָ��ָ�����ʱ���س�
			
			LogToAcc();
		}
		if( SelectedOption == 3 && PressedKey_temp == 13){			//ָ��ָ�򷵻�ʱ���س�
			MainMenu();
			break;
		}
		system("cls");

		LoginUI_Display(SelectedOption, dataInputState, StrNum_Name);
		MessageBar("\0");

		if( dataInputState == -1){						//������״̬
			PressedKey_temp = _getch();
			if( PressedKey_temp == 224 ){			//���ؼ���ֵ�ĺ������ڷ�����ļ���ֵ�᷵������
				PressedKey = _getch();
				SelectedOption = getFlagWithPressedKey_ALL( SelectedOption, PressedKey, 3);
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


int RegisterUI(int dataInputState){							//ע�����

	int SelectedOption = 1, PressedKey, PressedKey_temp = 0;

	while(1){

		if( SelectedOption == 1 && PressedKey_temp == 13){			//ָ��ָ�������˺�ʱ���س�
			if( dataInputState == -1){
				dataInputState = 0;
			}
			else if( dataInputState == 0){
				dataInputState = -1;
			}

		}
		if( SelectedOption == 2 && PressedKey_temp == 13){			//ָ��ָ�����ʱ���س�
			ReToLog();
		}
		if( SelectedOption == 3 && PressedKey_temp == 13){			//ָ��ָ�򷵻�ʱ���س�
			MainMenu();
			break;
		}
		system("cls");

		RegisterUI_Display(SelectedOption, dataInputState, StrNum_NewName);
		MessageBar("\0");

		if( dataInputState == -1){						//������״̬
			PressedKey_temp = _getch();
			if( PressedKey_temp == 224 ){			//���ؼ���ֵ�ĺ������ڷ�����ļ���ֵ�᷵������
				PressedKey = _getch();
				SelectedOption = getFlagWithPressedKey_ALL( SelectedOption, PressedKey, 3);
			}
		}
		else if( dataInputState == 0){					//����״̬
			PressedKey_temp = _getch();

			if( PressedKey_temp == 13){						//����ǻس��������Թ��˴�ѭ��
				continue;
			}
			if( PressedKey_temp != 224 && PressedKey_temp != 8){//���Ƿ�����˸���������ַ�
				PressedKey = PressedKey_temp;
				if(StrNum_NewName < NameNumMax){
					reg_accountName[StrNum_NewName] = PressedKey;
					StrNum_NewName++;
					reg_accountName[StrNum_NewName] = '\0';
				}
				else{
					MessageBar("���ֻ������16λ�ַ���          ");
					Sleep(1000);
				}
			}
			else if( PressedKey_temp == 8){
				if(StrNum_NewName > 0){
					reg_accountName[StrNum_NewName - 1] = '\0';
					StrNum_NewName--;
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


void MainMenu(void){

	int SelectedOption = 1, PressedKey, PressedKey_temp = 0;

	while(1){

		if( SelectedOption == 1 && PressedKey_temp == 13){			//ָ��ָ�����ʱ���س�
			LoginUI(-1);
			break;
		}
		if( SelectedOption == 2 && PressedKey_temp == 13){			//ָ��ָ��ע��ʱ���س�
			RegisterUI(-1);
			break;
		}
		if( SelectedOption == 3 && PressedKey_temp == 13){			//ָ��ָ�򷵻�ʱ���س�
			system("cls");
			printf("��лʹ�ã�\n");
			exit(0);

		}

		system("cls");

		MainMenu_Display(SelectedOption);
		MessageBar("��ӭʹ�øó���");
		
		PressedKey_temp = _getch();
		if( PressedKey_temp == 224 ){		//���ؼ���ֵ�ĺ������ڷ�����ļ���ֵ�᷵������
			PressedKey = _getch();
			SelectedOption = getFlagWithPressedKey_ALL( SelectedOption, PressedKey, 3);
		}
	}
}
//==========
void LogToAcc(){
	FILE *fp;
	char ReadFromFile[ NameNumMax + 2];
	int IDCode = 2;			//1��ʾ���ڸ��û���2��ʾ������

	if( (fp = fopen(".\\data\\users.txt", "r") ) == NULL ){			//����ȡȨ��
		MessageBar("�޷����ļ��У������ļ���ȡȨ�ޡ�          ");
		return;
	}
	
	while( !feof(fp)){								//����user.txt���Ƿ���ڸ��û���
		int CompareResult, i;
		fgets( ReadFromFile, NameNumMax + 2, fp);		//+2����ΪҪ���һ��\n��һ��\0
		for( i = 0; i < 20; i++){
			if( ReadFromFile[i] == '\n'){						//ɾȥ'\n'
				ReadFromFile[i] = '\0';
			}
		}
		if( (CompareResult = strcmp( ReadFromFile, temp_accountName)) == 0){ //�ַ�����ͬ
			IDCode = 1;				//��Ϊ�����û�
			strcpy( accountName, temp_accountName);
			break;
		}
	}
	fclose( fp);

		//================================
	if( IDCode == 1){
		MessageBar("����ɹ���          ");
		Sleep(400);
		StrNum_Name = 0;
		AccountUI();
	}
	else if( IDCode == 2){
		MessageBar("�޴��˺š�          ");
		Sleep(1000);
		StrNum_Name = 0;
		LoginUI(-1);
	}
}

void ReToLog(){
	FILE *fp, *setFile;
	int IDCode = 1, CompareResult;
	char ReadFromFile[ NameNumMax + 2];
	int LineNum = 0;
	if( (fp = fopen(".\\data\\users.txt", "r") ) == NULL ){
		MessageBar("�޷����ļ��У������ļ���ȡȨ�ޡ�          ");
		return;
	}
	
	while( !feof(fp)){								//����user.txt���Ƿ��Ѿ����ڸ��û���
		int i;
		fgets( ReadFromFile, NameNumMax + 2, fp);		//+2����ΪҪ���һ��\n��һ��\0
		for( i = 0; i < 20; i++){
			if( ReadFromFile[i] == '\n'){						//ɾȥ'\n'
				ReadFromFile[i] = '\0';
			}
		}
		LineNum += 1;
		if( (CompareResult = strcmp( ReadFromFile, reg_accountName)) == 0){ //�ַ�����ͬ
			IDCode = 2;
			break;
		}
	}


	if( (CompareResult = strcmp( "", reg_accountName)) == 0){
		IDCode = 3;								//IDCodeΪ 3��ζ�Ų�����ע���������
	}

	fclose( fp);

	if( (fp = fopen(".\\data\\users.txt", "a") ) == NULL ){
		MessageBar("�޷����ļ��У������ļ�д��Ȩ�ޡ�          ");
		return;
	}

	if( IDCode == 1){
		int FileCreateState = 0;
		char pathname[NameNumMax + 30] = ".\\data\\";

		if( LineNum > 0){						//	ԭ�������ֲŴ�ӡ���з�
			fputs( "\n", fp);
		}
		fputs( reg_accountName, fp);
		fclose( fp);
		strcat( pathname, reg_accountName);
		if( _access( pathname, 0) == -1 ){				//�����û��ļ��У����ڴ����û�����Ϣ
			if( (FileCreateState = mkdir( pathname)) == -1 ){
				MessageBar("�����û��ļ���ʧ�ܣ������ļ�д��Ȩ��          ");
				return;
			}
		}
		
		strcat( pathname, "\\classlist.txt");
		if( (setFile = fopen( pathname, "w")) == NULL){
			MessageBar("�����ļ�ʧ�ܣ������ļ�д��Ȩ��          ");
			return;
		}											//�����༶�б��ļ������ڴ����û��İ༶�б�
		fputs( "�༶�б�", setFile);
		fclose(setFile);
		
		StrNum_NewName = 0;
		MessageBar("ע��ɹ���          ");
		Sleep(500);
		LoginUI(-1);
	}
	else if( IDCode == 2){
		fclose( fp);
		StrNum_NewName = 0;
		MessageBar("�Ѵ��ڴ��˺š�          ");
		Sleep(600);
		LoginUI(-1);
	}
	else if( IDCode == 3){
		fclose( fp);
		StrNum_NewName = 0;
		MessageBar("������ע��Ƿ��˺š�          ");
		Sleep(700);
		LoginUI(-1);
	}
}

void PrintList_Class(int SelectedOption, int ClassCount, struct CLASS *classLineHead){
	
	int i;
	printf("\n");
	for( i = 0; i < ClassCount; i++){
		if( SelectedOption == i + 1){
			printf("%s\t\t\t\t|�鿴<", classLineHead->name);
		}
		else{
			printf("%s\t\t\t\t�鿴", classLineHead->name);
		}
		printf("\n");
		classLineHead = classLineHead->next;
	}
}
