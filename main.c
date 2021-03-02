
#include "globalsDefine.h"

//==========
char temp_accountName[NameNumMax] = "author";		//������� �˻�ID��ʾ
char reg_accountName[NameNumMax];		//ע����� �˻�ID��ʾ
char accountName[NameNumMax] = "author";			//����ɹ����ID��ʾ
char inputTemp[NameNumMax];					//�������ʱ�ַ���������������
int StrNum_Name = 0;					//
int StrNum_NewName = 0;					//
int StrNum_InputTemp = 0;


//==========
#include ".\menuDisplay.h"
#include ".\selectOptions.h"
//==========






//==========
void LogToAcc();
void ReToLog();
void NewcToAcc();
void MainMenu();
void AccountUI();
void ViewClassList();
void listClass(struct LIST **pclassLineHead, int classNum);
void listStudent(struct LIST **pstudentLineHead, int studentNum, char className[NameNumMax]);
void listStudentHead(struct HEADS **pstudentLineHead, int studentNum, char className[NameNumMax]);
void inFlagKeyToOperation( int SelectedOption, int PressedKey_temp, struct LIST *classLineHead);
void inFlagKeyToOperation2( int SelectedOption, int PressedKey_temp, struct HEADS *ergodicClass);
void getStudent(struct HEADS **pLeader, int studentNum, char className[NameNumMax]);
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



void ViewClassB( char className[NameNumMax]){

	int SelectedOption = 1, PressedKey, PressedKey_temp = 0;

	int StudentCount = 0;
	char pathname[NameNumMax + 30] = ".\\data\\", strTemp[NameNumMax];
	FILE *fp;
	struct HEADS *Leader = NULL;		//�������ͷ��ʼ��Ϊ��
//=================================================
	strcat( pathname, accountName);
	strcat( pathname, "\\");
	strcat( pathname, className);
	strcat( pathname, "\\students.txt");			//.\data\#username\#calssname\students.txt
	if( (fp = fopen(pathname, "r")) == NULL){			//��ָ��·���ļ�
		MessageBar("���ļ�ʧ�ܣ������ļ��Ķ�Ȩ��          ");
		Sleep(1000);
		system("pause");
		return;
	}
	while( !feof(fp)){								//����students.txt��ѧ������
		fgets( strTemp, NameNumMax, fp);
		StudentCount += 1;
	}
	fclose( fp);
	StudentCount--;						//���⡰ѧ���б�������ѧ��������˼�һ

//===========================================
	while(1){
	
		if( SelectedOption == StudentCount + 1 && PressedKey_temp == 13){			//ָ��ָ�����ͬѧʱ���س�
			MessageBar("��ʱδ����				");
			system("pause");
			break;
		}
		if( SelectedOption == StudentCount + 2 && PressedKey_temp == 13){			//ָ��ָ�򷵻�ʱ���س�
			ViewClassList();
			break;
		}

		getStudent(&Leader, StudentCount, className);	//students�ﴢ����ѧ������+1�����ݣ�����������ѧ���ڵ�һ��

/*
		printf("order: %d, name: %s, add: %s\n", Leader->student.ordinal, Leader->student.name, Leader->student.addres);
		printf("sex: %s, ID: %s, num: %s, \n", Leader->student.sex, Leader->student.ID, Leader->student.PhoneNum);
		while( Leader->next != NULL){
			Leader = Leader->next;
			printf("order: %d, name: %s, add: %s\n", Leader->student.ordinal, Leader->student.name, Leader->student.addres);
			printf("sex: %s, ID: %s, num: %s, \n", Leader->student.sex, Leader->student.ID, Leader->student.PhoneNum);
		}//���Դ����Ƿ�����
		system("pause");
		*/

		inFlagKeyToOperation2( SelectedOption, PressedKey, Leader);
		
		system("cls");
		ViewClassB_Display(SelectedOption, StudentCount, Leader, className);

		fflush(stdin);
		PressedKey_temp = _getch();
		if( PressedKey_temp == 224 ){	//���ؼ���ֵ�ĺ������ڷ�����ļ���ֵ�᷵�����Σ��������ж��Ƿ�Ϊ�����
			PressedKey = _getch();
			SelectedOption = getFlagWithPressedKey_ALL( SelectedOption, PressedKey, StudentCount + 2);
		}
	}
}



void ViewClassA( char className[NameNumMax]){

	int SelectedOption = 1, PressedKey, PressedKey_temp = 0;

	int StudentCount = 0;
	char pathname[NameNumMax + 30] = ".\\data\\", strTemp[NameNumMax];
	FILE *fp;
	struct LIST *studentLineHead = NULL;		//�������ͷ��ʼ��Ϊ��

	strcat( pathname, accountName);
	strcat( pathname, "\\");
	strcat( pathname, className);
	strcat( pathname, "\\students.txt");			//.\data\#username\#calssname\students.txt
	if( (fp = fopen(pathname, "r")) == NULL){			//��ָ��·���ļ�
		MessageBar("���ļ�ʧ�ܣ������ļ��Ķ�Ȩ��          ");
		Sleep(1000);
		system("pause");
		return;
	}
	while( !feof(fp)){								//����students.txt��ѧ������
		fgets( strTemp, NameNumMax, fp);
		StudentCount += 1;
	}
	fclose( fp);
	StudentCount--;						//���⡰ѧ���б�������ѧ��������˼�һ

	while(1){
	
		if( SelectedOption == 1 && PressedKey_temp == 13){			//ָ��ָ��༭ʱ���س�
			ViewClassB( className);
			break;
		}
		if( SelectedOption == 2 && PressedKey_temp == 13){			//ָ��ָ�򷵻�ʱ���س�
			ViewClassList();
			break;
		}

		listStudent(&studentLineHead, StudentCount + 1, className);	//students�ﴢ����ѧ������+1�����ݣ�����������ѧ���ڵ�һ��
		
		system("cls");
		ViewClassA_Display(SelectedOption, StudentCount, studentLineHead, className);

		fflush(stdin);
		PressedKey_temp = _getch();
		if( PressedKey_temp == 224 ){	//���ؼ���ֵ�ĺ������ڷ�����ļ���ֵ�᷵�����Σ��������ж��Ƿ�Ϊ�����
			PressedKey = _getch();
			SelectedOption = getFlagWithPressedKey_ALL( SelectedOption, PressedKey, 2);
		}
	}
}

void ViewClassList(){

	int SelectedOption = 1, PressedKey, PressedKey_temp = 0;

	int ClassCount = 0;
	char pathname[NameNumMax + 30] = ".\\data\\", strTemp[NameNumMax];
	FILE *fp;
	struct LIST *classLineHead = NULL;		//�������ͷ��ʼ��Ϊ��

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

		listClass(&classLineHead, ClassCount + 1);	//classlist�ﴢ���˰༶����+1�����ݣ����������ǰ༶�ڵ�һ��

		inFlagKeyToOperation( SelectedOption, PressedKey_temp, classLineHead);
		
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

void inFlagKeyToOperation( int SelectedOption, int PressedKey_temp, struct LIST *ergodicClass){

	char className[NameNumMax];
	int i;
	for( i = 0; i < SelectedOption && ergodicClass->next != NULL; i++){
		ergodicClass = ergodicClass->next;
	}		//ѭ��֮�������SO�õ�һ����������ʱ�ṹ������־͵���ViewClassList_display����Ӧ����������
	
	strcpy( className, ergodicClass->name);
	if( PressedKey_temp == 13){
		ViewClassA( className);
	}
	return;
}

void inFlagKeyToOperation2( int SelectedOption, int PressedKey_temp, struct HEADS *ergodicClass){

	char className[NameNumMax];
	int i;
	for( i = 0; i < SelectedOption && ergodicClass->next != NULL; i++){
		ergodicClass = ergodicClass->next;
	}		//ѭ��֮�������SO�õ�һ����������ʱ�ṹ������־͵���ViewClassList_display����Ӧ����������
	
	strcpy( className, ergodicClass->name);
	if( PressedKey_temp == 13){
		ViewClassA( className);
	}
	return;
}

void listClass(struct LIST **pclassLineHead, int classNum){		//β�ӷ�
	struct LIST *newClass;
	static struct LIST *tailClass;
	FILE *classListFile;
	char className[NameNumMax], pathname[NameNumMax + 30] = ".\\data\\";
	int i = 0, tempOrdinal=0;
	
	strcat( pathname, accountName);
	strcat( pathname, "\\classlist.txt");			//.\data\#username\classlist.txt
	if( (classListFile = fopen( pathname, "r")) == NULL){
		MessageBar("���ļ�ʧ��");
	}

	while( !feof(classListFile)){
		newClass = (struct LIST *)malloc(sizeof(struct LIST));
		if( newClass == NULL){						//�����ַ������һ���ṹ��
			MessageBar("�ڴ����ʧ��");
			exit(1);
		}

		fgets( className, NameNumMax, classListFile);
		for( i = 0; i < NameNumMax + 1; i++){
			if( className[i] == '\n'){						//ɾȥ'\n'
				className[i] = '\0';
			}
		}
		strcpy(newClass->name, className);				//����Ϣ���뵽�ṹ��
		newClass->ordinal = tempOrdinal;					//Ϊ���ṹ���д���
		tempOrdinal++;

		
		if( *pclassLineHead == NULL){
			*pclassLineHead = newClass;				//��ͷΪ�վͰѱ�ͷֱ��ָ���½ṹ��
			newClass->next = NULL;
		}
		else{
			tailClass->next = newClass;		//��ͷ��������һ�ṹ��ָ��ýṹ��
			newClass->next = NULL;
		}
		tailClass = newClass;
	}
	fclose( classListFile);
}


void listStudent(struct LIST **pstudentLineHead, int studentNum, char className[NameNumMax]){		//β�ӷ�
	struct LIST *newStudent;
	static struct LIST *tailStudent;
	FILE *studentListFile, *studentInfo;
	char studentName[NameNumMax], pathname[NameNumMax + 30] = ".\\data\\";
	int i = 0, tempOrdinal=0;
	
	strcat( pathname, accountName);
	strcat( pathname, "\\");
	strcat( pathname, className);
	strcat( pathname, "\\students.txt");			//.\data\#username\#classname\students.txt

	if( (studentListFile = fopen( pathname, "r")) == NULL){
		MessageBar("���ļ�ʧ��");
	}
	
	while( !feof(studentListFile)){
		newStudent = (struct LIST *)malloc(sizeof(struct LIST));
		if( newStudent == NULL){						//�����ַ������һ���ṹ��
			MessageBar("�ڴ����ʧ��");
			exit(1);
		}

		fgets( studentName, NameNumMax, studentListFile);
		for( i = 0; i < NameNumMax + 1; i++){
			if( studentName[i] == '\n'){						//ɾȥ'\n'
				studentName[i] = '\0';
			}
		}
		
		if( (studentInfo = fopen( pathname, "r")) == NULL){
			if( (studentInfo = fopen( pathname, "w")) == NULL){
				MessageBar("��ʼ��ѧ���ļ�ʧ��			");
			}
		}
		fclose( studentInfo);
		strcpy(newStudent->name, studentName);				//����Ϣ���뵽�ṹ��
		newStudent->ordinal = tempOrdinal;					//Ϊ���ṹ���д���
		tempOrdinal++;

		
		if( *pstudentLineHead == NULL){
			*pstudentLineHead = newStudent;				//��ͷΪ�վͰѱ�ͷֱ��ָ���½ṹ��
			newStudent->next = NULL;
		}
		else{
			tailStudent->next = newStudent;		//��ͷ��������һ�ṹ��ָ��ýṹ��
			newStudent->next = NULL;
		}
		tailStudent = newStudent;
	}
	fclose( studentListFile);
}


void listStudentHead(struct HEADS **pstudentLineHead, int studentNum, char className[NameNumMax]){		//β�ӷ�
	struct HEADS *newStudent;
	static struct HEADS *tailStudent;
	FILE *studentListFile, *studentInfo;
	char studentName[NameNumMax], pathname[NameNumMax + 30] = ".\\data\\";
	int i = 0, tempOrdinal=0;
	
	strcat( pathname, accountName);
	strcat( pathname, "\\");
	strcat( pathname, className);
	strcat( pathname, "\\students.txt");			//.\data\#username\#classname\students.txt

	if( (studentListFile = fopen( pathname, "r")) == NULL){
		MessageBar("���ļ�ʧ��");
	}
	fgets( studentName, NameNumMax, studentListFile);
	while( !feof(studentListFile)){
		newStudent = (struct HEADS *)malloc(sizeof(struct HEADS));
		if( newStudent == NULL){						//�����ַ������һ���ṹ��
			MessageBar("�ڴ����ʧ��");
			exit(1);
		}

		fgets( studentName, NameNumMax, studentListFile);
		for( i = 0; i < NameNumMax + 1; i++){
			if( studentName[i] == '\n'){						//ɾȥ'\n'
				studentName[i] = '\0';
			}
		}

		strcpy( pathname, ".\\data\\");								//����pathname
		strcat( pathname, accountName);
		strcat( pathname, "\\");
		strcat( pathname, className);
		strcat( pathname, "\\");
		strcat( pathname, studentName);		
		strcat( pathname, ".txt");			//.\data\#username\#classname\#studentname.txt

		if( (studentInfo = fopen( pathname, "r")) == NULL){				//�˴���ʼ��ѧ���ļ�Ŀ����Ϊ�б��е�ѧ��������Ϣ�ļ�
			if( (studentInfo = fopen( pathname, "w")) == NULL){
				MessageBar("��ʼ��ѧ���ļ�ʧ��			");
			}
		}


		strcpy(newStudent->name, studentName);				//����Ϣ���뵽�ṹ��
		newStudent->ordinal = tempOrdinal;					//Ϊ���ṹ���д���
		tempOrdinal++;

		
		if( *pstudentLineHead == NULL){
			*pstudentLineHead = newStudent;				//��ͷΪ�վͰѱ�ͷֱ��ָ���½ṹ��
			newStudent->next = NULL;
		}
		else{
			tailStudent->next = newStudent;		//��ͷ��������һ�ṹ��ָ��ýṹ��
			newStudent->next = NULL;
		}
		tailStudent = newStudent;
	}
	fclose( studentListFile);
}


void getStudent(struct HEADS **pLeader, int studentNum, char className[NameNumMax]){		//β�ӷ�

	struct HEADS *tempPLeader;
	FILE *studentInfo;
	char pathname[NameNumMax + 30] = ".\\data\\", studentName[NameNumMax];
	char pathnameTemp[NameNumMax + 30], tempStr[NameNumMax + 30];
	int i = 0, j = 0, k = 0, tempOrdinal=0;
	
	strcat( pathname, accountName);
	strcat( pathname, "\\");
	strcat( pathname, className);			//.\data\#username\#classname

	listStudentHead(pLeader, studentNum, className);
												//��students.txt���ѧ���г������õ���������ź�ָ��
												//֮��Ϳ�����ͷָ�����


	/*
	tempPLeader = *(pLeader);
	printf("name: %s, next: %d, ordinal: %d, toHead: %d\n", (*pLeader)->name, (*pLeader)->next, (*pLeader)->ordinal );
	while( (*pLeader)->next != NULL){
		*(pLeader) = (*pLeader)->next;
		printf("name: %s, next: %d, ordinal: %d, toHead: %d\n", (*pLeader)->name, (*pLeader)->next, (*pLeader)->ordinal );
						//���HEADS pLeader�д�������Ƿ�����
	}						//#########################
	//*///
	tempPLeader = *(pLeader);			//�ݴ�һ�£���ʱ�����ָ�����ݻ�����
	strcpy( pathnameTemp, pathname);				//��
	for( j = 0; j < studentNum; j++){				//��		//�˴�ѭ������ȷ��ÿ��ѧ�����Լ�¼
		*(pLeader) = tempPLeader;				//���������
		for( k = 0; k < j && (*pLeader)->next != NULL; k++){	//�˴�ѭ������ȷ����k��ѧ���õ���¼
			(*pLeader) = (*pLeader)->next;
		}		//ѭ��֮������� j��ѧ����Ŀ���õ�һ��������
				//��ʱ�ṹ������־͵���ViewClassList_display����Ӧ����������
//		printf("����Ϊ��%d \n���ļ�Ϊ��%s \n", k, (*pLeader)->name );				//###################3333
//		system("pause");				//###################3333
		strcpy( studentName, (*pLeader)->name);
		strcat( pathname, "\\");
		strcat( pathname, studentName);
		strcat( pathname, ".txt");					//.\data\#username\#classname\#studentname.txt

		if( (studentInfo = fopen( pathname, "r")) == NULL){
			MessageBar("���ļ�ʧ��");
			exit(1);
		}


		fgets( tempStr, NameNumMax + 30, studentInfo);

		for( i = 0; i < NameNumMax + 30; i++){
			if( tempStr[i] == '\n'){						//ɾȥ'\n'
				tempStr[i] = '\0';
			}
		}
		strcpy( (*pLeader)->student.name, tempStr);					//��������
//		printf("���� %s\n", (*pLeader)->student.name);			//######################
//		system("pause");						//######################
		fgets( tempStr, NameNumMax + 30, studentInfo);
		for( i = 0; i < NameNumMax + 30; i++){
			if( tempStr[i] == '\n'){						//ɾȥ'\n'
				tempStr[i] = '\0';
			}
		}
		strcpy( (*pLeader)->student.ID, tempStr);					//����ѧ��
//		printf("ID %s\n", (*pLeader)->student.ID);			//######################
//		system("pause");						//######################
		fgets( tempStr, NameNumMax + 30, studentInfo);
		for( i = 0; i < NameNumMax + 30; i++){
			if( tempStr[i] == '\n'){						//ɾȥ'\n'
				tempStr[i] = '\0';
			}
		}
		strcpy( (*pLeader)->student.sex, tempStr);					//�����Ա�
//		printf("�Ա� %s\n", student->sex);			//######################
//		system("pause");						//######################
		fgets( tempStr, NameNumMax + 30, studentInfo);
		for( i = 0; i < NameNumMax + 30; i++){
			if( tempStr[i] == '\n'){						//ɾȥ'\n'
				tempStr[i] = '\0';
			}
		}
		strcpy( (*pLeader)->student.addres, tempStr);					//�����ַ
	//	printf("��ַ %s\n", student->addres);			//######################
//		system("pause");						//######################
		fgets( tempStr, NameNumMax + 30, studentInfo);
		for( i = 0; i < NameNumMax + 30; i++){
			if( tempStr[i] == '\n'){						//ɾȥ'\n'
				tempStr[i] = '\0';
			}
		}
		strcpy( (*pLeader)->student.PhoneNum, tempStr);					//����绰��
//		printf("�绰 %s\n", student->PhoneNum);			//######################
//		system("pause");						//######################
		strcpy( pathname, pathnameTemp);
		
	}
	*(pLeader) = tempPLeader;
}


int NewClass(int dataInputState){

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
			NewcToAcc();
		}
		if( SelectedOption == 3 && PressedKey_temp == 13){			//ָ��ָ�򷵻�ʱ���س�
			AccountUI();
			break;
		}
		system("cls");

		NewClass_Display(SelectedOption, dataInputState, StrNum_InputTemp);
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
				if(StrNum_InputTemp < NameNumMax){
					inputTemp[StrNum_InputTemp] = PressedKey;
					StrNum_InputTemp++;
					inputTemp[StrNum_InputTemp] = '\0';
				}
				else{
					MessageBar("���ֻ������16λ�ַ���          ");
					Sleep(1000);
				}
			}
			else if( PressedKey_temp == 8){
				if(StrNum_InputTemp > 0){
					inputTemp[StrNum_InputTemp - 1] = '\0';
					StrNum_InputTemp--;
				}
				else{
					MessageBar("������༶���ơ�          ");
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


void AccountUI(){

	int SelectedOption = 1, PressedKey, PressedKey_temp = 0;

	while(1){
	
		if( SelectedOption == 1 && PressedKey_temp == 13){			//ָ��ָ��鿴�༶ʱ���س�
			
			ViewClassList();
		}
		if( SelectedOption == 2 && PressedKey_temp == 13){			//ָ��ָ���½��༶ʱ���س�

			NewClass(-1);
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
		for( i = 0; i < NameNumMax + 1; i++){
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
		Sleep(100);
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
		for( i = 0; i < NameNumMax + 1; i++){
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

	if( IDCode == 1){
		int FileCreateState = 0;
		char pathname[NameNumMax + 30] = ".\\data\\";

		if( (fp = fopen(".\\data\\users.txt", "a") ) == NULL ){
			MessageBar("�޷����ļ��У������ļ�д��Ȩ�ޡ�          ");
			return;
		}

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
		reg_accountName[StrNum_NewName] = '\0';
		MessageBar("ע��ɹ���          ");
		Sleep(500);
		LoginUI(-1);
	}
	else if( IDCode == 2){
		StrNum_NewName = 0;
		reg_accountName[StrNum_NewName] = '\0';
		MessageBar("�Ѵ��ڴ��˺š�          ");
		Sleep(600);
		LoginUI(-1);
	}
	else if( IDCode == 3){
		StrNum_NewName = 0;
		reg_accountName[StrNum_NewName] = '\0';
		MessageBar("������ע��Ƿ��˺š�          ");
		Sleep(700);
		RegisterUI(-1);
	}
}


void NewcToAcc(){
	FILE *fp, *setFile;
	int IDCode = 1, CompareResult;
	char ReadFromFile[ NameNumMax + 2], pathname[NameNumMax + 30] = ".\\data\\";
	int LineNum = 0;

	strcat( pathname, accountName);
	strcat( pathname, "\\classlist.txt");			//.\data\#username\classlist.txt
	if( (fp = fopen(pathname, "r") ) == NULL ){				//����Ƿ��ܴ�classlist.txt�ļ�
		MessageBar("�޷����ļ��������ļ���ȡȨ�ޡ�          ");
		return;
	}
	
	while( !feof(fp)){								//����classlist.txt���Ƿ��Ѿ����ڸð༶��
		int i;
		fgets( ReadFromFile, NameNumMax + 2, fp);		//+2����ΪҪ���һ��\n��һ��\0
		for( i = 0; i < NameNumMax + 1; i++){
			if( ReadFromFile[i] == '\n'){						//ɾȥ'\n'
				ReadFromFile[i] = '\0';
			}
		}
		LineNum += 1;
		if( (CompareResult = strcmp( ReadFromFile, inputTemp)) == 0){ //�ַ�����ͬ
			IDCode = 2;			//IDCodeΪ 2��ζ���Ѵ��ڸ�����
			break;
		}
	}

	if( (CompareResult = strcmp( "", inputTemp)) == 0){
		IDCode = 3;								//IDCodeΪ 3��ζ�Ų��������������ֵİ༶
	}

	fclose( fp);


	if( IDCode == 1){
		int FileCreateState = 0;

		if( (fp = fopen(pathname, "a") ) == NULL ){
			MessageBar("�޷����ļ��������ļ�д��Ȩ�ޡ�          ");
			system("pause");
			return;
		}

		if( LineNum > 0){						//	ԭ�������ֲŴ�ӡ���з�
			fputs( "\n", fp);
		}
		fputs( inputTemp, fp);				//	��classlist.txtд��#classname���
		fclose( fp);

		strcpy(pathname, ".\\data\\");			//ǰ��ƴ�ӹ�pathname���ʴ˴���ʼ��
		strcat(pathname, accountName);
		strcat(pathname, "\\");
		strcat(pathname, inputTemp);		//.\data\#username\#classname

		if( _access( pathname, 0) == -1 ){				//�����༶�ļ��У����ڴ���ѧ������Ϣ
			if( (FileCreateState = mkdir( pathname)) == -1 ){
				MessageBar("�����û��ļ���ʧ�ܣ������ļ�д��Ȩ��          ");
				system("pause");
				return;
			}
		}			
		strcat(pathname, "\\students.txt");		//.\data\#username\#classname\students.txt

		if( (setFile = fopen( pathname, "a")) == NULL){
			MessageBar("�����ļ�ʧ�ܣ������ļ�д��Ȩ��          ");
			system("pause");
			return;
		}											//����ѧ���б��ļ������ڴ���༶��ѧ���б�

		fputs( "ѧ���б�", setFile);
		fclose(setFile);

		StrNum_InputTemp = 0;
		inputTemp[StrNum_InputTemp] = '\0';
		MessageBar("�����༶�ɹ���          ");
		Sleep(600);
		AccountUI();
	}
	else if( IDCode == 2){
		StrNum_InputTemp = 0;
		inputTemp[StrNum_InputTemp] = '\0';
		MessageBar("�Ѵ��ڴ˰༶��          ");
		Sleep(600);
		NewClass(-1);
	}
	else if( IDCode == 3){
		StrNum_InputTemp = 0;
		inputTemp[StrNum_InputTemp] = '\0';
		MessageBar("������ע��Ƿ��༶����          ");
		Sleep(700);
		NewClass(-1);
	}
}


void PrintList_Class(int SelectedOption, int ClassCount, struct LIST *classLineHead){
	
	int i;
	printf("\n");
	printf("%s\t\t\t\t\n", classLineHead->name);		//��ӡ����
	classLineHead = classLineHead->next;
	for( i = 0; i < ClassCount; i++){
		if( SelectedOption == i + 1){
			printf("%d  %s\t\t\t\t|�鿴<", classLineHead->ordinal, classLineHead->name);
		}
		else{
			printf("%d  %s\t\t\t\t�鿴", classLineHead->ordinal, classLineHead->name);
		}
		printf("\n");
		classLineHead = classLineHead->next;
	}
}

void PrintList_Student(int SelectedOption, int StudentCount, struct LIST *studnetLineHead){
	
	int i;
	printf("\n");
	printf("%s\t\t\t\t\n", studnetLineHead->name);		//��ӡ����
	studnetLineHead = studnetLineHead->next;
	for( i = 0; i < StudentCount; i++){
		printf("%d  %s\t\t\t\t", studnetLineHead->ordinal, studnetLineHead->name);
		printf("\n");
		studnetLineHead = studnetLineHead->next;
	}
}

void PrintList_Student_Bar(int SelectedOption, int StudentCount, struct HEADS *studnetLineHead){
	
	int i;
	printf("\n");
	printf("\t����\tѧ��\t�Ա�\t��ַ\t�绰����\n");		//��ӡ����


	for( i = 0; i < StudentCount ; i++){

		if( SelectedOption == i + 1){
			printf("|ɾ��<   %s\t", studnetLineHead->student.name);
			printf("%s\t%s\t", studnetLineHead->student.ID, studnetLineHead->student.sex);
			printf("%s\t%s", studnetLineHead->student.addres, studnetLineHead->student.PhoneNum);
		}
		else{
			printf("ɾ��   %s\t", studnetLineHead->student.name);
			printf("%s\t%s\t", studnetLineHead->student.ID, studnetLineHead->student.sex);
			printf("%s\t%s", studnetLineHead->student.addres, studnetLineHead->student.PhoneNum);
		}
		printf("\n");
		studnetLineHead = studnetLineHead->next;
	}
}