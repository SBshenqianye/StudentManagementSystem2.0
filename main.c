
#include "globalsDefine.h"

//==========
char temp_accountName[NameNumMax] = "author";		//登入界面 账户ID显示
char reg_accountName[NameNumMax];		//注册界面 账户ID显示
char accountName[NameNumMax] = "author";			//登入成功后的ID显示
char inputTemp[NameNumMax];					//输入框临时字符，建议用完就清除
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
				printf("初始化失败，请退出程序。\n");
				exit( 0);
			}
		}

		testingFile = fopen( ".\\data\\users.txt", "w");
		fputs( "【用户列表】", testingFile);
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
//打算放在main.c



void ViewClassB( char className[NameNumMax]){

	int SelectedOption = 1, PressedKey, PressedKey_temp = 0;

	int StudentCount = 0;
	char pathname[NameNumMax + 30] = ".\\data\\", strTemp[NameNumMax];
	FILE *fp;
	struct HEADS *Leader = NULL;		//把链表表头初始化为空
//=================================================
	strcat( pathname, accountName);
	strcat( pathname, "\\");
	strcat( pathname, className);
	strcat( pathname, "\\students.txt");			//.\data\#username\#calssname\students.txt
	if( (fp = fopen(pathname, "r")) == NULL){			//打开指定路径文件
		MessageBar("打开文件失败，请检查文件阅读权限          ");
		Sleep(1000);
		system("pause");
		return;
	}
	while( !feof(fp)){								//检索students.txt中学生个数
		fgets( strTemp, NameNumMax, fp);
		StudentCount += 1;
	}
	fclose( fp);
	StudentCount--;						//标题“学生列表”被记入学生数，因此减一

//===========================================
	while(1){
	
		if( SelectedOption == StudentCount + 1 && PressedKey_temp == 13){			//指标指向添加同学时按回车
			MessageBar("暂时未开发				");
			system("pause");
			break;
		}
		if( SelectedOption == StudentCount + 2 && PressedKey_temp == 13){			//指标指向返回时按回车
			ViewClassList();
			break;
		}

		getStudent(&Leader, StudentCount, className);	//students里储存了学生数量+1的数据，并且那条非学生在第一排

/*
		printf("order: %d, name: %s, add: %s\n", Leader->student.ordinal, Leader->student.name, Leader->student.addres);
		printf("sex: %s, ID: %s, num: %s, \n", Leader->student.sex, Leader->student.ID, Leader->student.PhoneNum);
		while( Leader->next != NULL){
			Leader = Leader->next;
			printf("order: %d, name: %s, add: %s\n", Leader->student.ordinal, Leader->student.name, Leader->student.addres);
			printf("sex: %s, ID: %s, num: %s, \n", Leader->student.sex, Leader->student.ID, Leader->student.PhoneNum);
		}//测试储存是否正常
		system("pause");
		*/

		inFlagKeyToOperation2( SelectedOption, PressedKey, Leader);
		
		system("cls");
		ViewClassB_Display(SelectedOption, StudentCount, Leader, className);

		fflush(stdin);
		PressedKey_temp = _getch();
		if( PressedKey_temp == 224 ){	//返回键盘值的函数对于方向键的键盘值会返回两次，所以先判断是否为方向键
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
	struct LIST *studentLineHead = NULL;		//把链表表头初始化为空

	strcat( pathname, accountName);
	strcat( pathname, "\\");
	strcat( pathname, className);
	strcat( pathname, "\\students.txt");			//.\data\#username\#calssname\students.txt
	if( (fp = fopen(pathname, "r")) == NULL){			//打开指定路径文件
		MessageBar("打开文件失败，请检查文件阅读权限          ");
		Sleep(1000);
		system("pause");
		return;
	}
	while( !feof(fp)){								//检索students.txt中学生个数
		fgets( strTemp, NameNumMax, fp);
		StudentCount += 1;
	}
	fclose( fp);
	StudentCount--;						//标题“学生列表”被记入学生数，因此减一

	while(1){
	
		if( SelectedOption == 1 && PressedKey_temp == 13){			//指标指向编辑时按回车
			ViewClassB( className);
			break;
		}
		if( SelectedOption == 2 && PressedKey_temp == 13){			//指标指向返回时按回车
			ViewClassList();
			break;
		}

		listStudent(&studentLineHead, StudentCount + 1, className);	//students里储存了学生数量+1的数据，并且那条非学生在第一排
		
		system("cls");
		ViewClassA_Display(SelectedOption, StudentCount, studentLineHead, className);

		fflush(stdin);
		PressedKey_temp = _getch();
		if( PressedKey_temp == 224 ){	//返回键盘值的函数对于方向键的键盘值会返回两次，所以先判断是否为方向键
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
	struct LIST *classLineHead = NULL;		//把链表表头初始化为空

	strcat( pathname, accountName);			
	strcat( pathname, "\\classlist.txt");
	if( (fp = fopen(pathname, "r")) == NULL){			//打开指定路径文件
		MessageBar("打开文件失败，请检查文件阅读权限          ");
		Sleep(1000);
		system("pause");
		return;
	}
	while( !feof(fp)){								//检索classlist.txt中班级个数
		fgets( strTemp, NameNumMax, fp);
		ClassCount += 1;
	}
	fclose( fp);
	ClassCount--;						//标题“班级列表”被记入班级数，因此减一

	while(1){
	
		if( SelectedOption == ClassCount + 1 && PressedKey_temp == 13){			//指标指向返回时按回车
			AccountUI();
			break;
		}

		listClass(&classLineHead, ClassCount + 1);	//classlist里储存了班级数量+1的数据，并且那条非班级在第一排

		inFlagKeyToOperation( SelectedOption, PressedKey_temp, classLineHead);
		
		system("cls");
		ViewClassList_Display(SelectedOption, ClassCount, classLineHead);

		fflush(stdin);
		PressedKey_temp = _getch();
		if( PressedKey_temp == 224 ){	//返回键盘值的函数对于方向键的键盘值会返回两次，所以先判断是否为方向键
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
	}		//循环之后会依据SO得到一个序数，此时结构体的名字就等于ViewClassList_display里相应序数的名字
	
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
	}		//循环之后会依据SO得到一个序数，此时结构体的名字就等于ViewClassList_display里相应序数的名字
	
	strcpy( className, ergodicClass->name);
	if( PressedKey_temp == 13){
		ViewClassA( className);
	}
	return;
}

void listClass(struct LIST **pclassLineHead, int classNum){		//尾接法
	struct LIST *newClass;
	static struct LIST *tailClass;
	FILE *classListFile;
	char className[NameNumMax], pathname[NameNumMax + 30] = ".\\data\\";
	int i = 0, tempOrdinal=0;
	
	strcat( pathname, accountName);
	strcat( pathname, "\\classlist.txt");			//.\data\#username\classlist.txt
	if( (classListFile = fopen( pathname, "r")) == NULL){
		MessageBar("打开文件失败");
	}

	while( !feof(classListFile)){
		newClass = (struct LIST *)malloc(sizeof(struct LIST));
		if( newClass == NULL){						//分配地址，储存一个结构体
			MessageBar("内存分配失败");
			exit(1);
		}

		fgets( className, NameNumMax, classListFile);
		for( i = 0; i < NameNumMax + 1; i++){
			if( className[i] == '\n'){						//删去'\n'
				className[i] = '\0';
			}
		}
		strcpy(newClass->name, className);				//把信息输入到结构体
		newClass->ordinal = tempOrdinal;					//为各结构体编写序号
		tempOrdinal++;

		
		if( *pclassLineHead == NULL){
			*pclassLineHead = newClass;				//表头为空就把表头直接指向新结构体
			newClass->next = NULL;
		}
		else{
			tailClass->next = newClass;		//表头不空则上一结构体指向该结构体
			newClass->next = NULL;
		}
		tailClass = newClass;
	}
	fclose( classListFile);
}


void listStudent(struct LIST **pstudentLineHead, int studentNum, char className[NameNumMax]){		//尾接法
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
		MessageBar("打开文件失败");
	}
	
	while( !feof(studentListFile)){
		newStudent = (struct LIST *)malloc(sizeof(struct LIST));
		if( newStudent == NULL){						//分配地址，储存一个结构体
			MessageBar("内存分配失败");
			exit(1);
		}

		fgets( studentName, NameNumMax, studentListFile);
		for( i = 0; i < NameNumMax + 1; i++){
			if( studentName[i] == '\n'){						//删去'\n'
				studentName[i] = '\0';
			}
		}
		
		if( (studentInfo = fopen( pathname, "r")) == NULL){
			if( (studentInfo = fopen( pathname, "w")) == NULL){
				MessageBar("初始化学生文件失败			");
			}
		}
		fclose( studentInfo);
		strcpy(newStudent->name, studentName);				//把信息输入到结构体
		newStudent->ordinal = tempOrdinal;					//为各结构体编写序号
		tempOrdinal++;

		
		if( *pstudentLineHead == NULL){
			*pstudentLineHead = newStudent;				//表头为空就把表头直接指向新结构体
			newStudent->next = NULL;
		}
		else{
			tailStudent->next = newStudent;		//表头不空则上一结构体指向该结构体
			newStudent->next = NULL;
		}
		tailStudent = newStudent;
	}
	fclose( studentListFile);
}


void listStudentHead(struct HEADS **pstudentLineHead, int studentNum, char className[NameNumMax]){		//尾接法
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
		MessageBar("打开文件失败");
	}
	fgets( studentName, NameNumMax, studentListFile);
	while( !feof(studentListFile)){
		newStudent = (struct HEADS *)malloc(sizeof(struct HEADS));
		if( newStudent == NULL){						//分配地址，储存一个结构体
			MessageBar("内存分配失败");
			exit(1);
		}

		fgets( studentName, NameNumMax, studentListFile);
		for( i = 0; i < NameNumMax + 1; i++){
			if( studentName[i] == '\n'){						//删去'\n'
				studentName[i] = '\0';
			}
		}

		strcpy( pathname, ".\\data\\");								//重置pathname
		strcat( pathname, accountName);
		strcat( pathname, "\\");
		strcat( pathname, className);
		strcat( pathname, "\\");
		strcat( pathname, studentName);		
		strcat( pathname, ".txt");			//.\data\#username\#classname\#studentname.txt

		if( (studentInfo = fopen( pathname, "r")) == NULL){				//此处初始化学生文件目的是为列表中的学生创建信息文件
			if( (studentInfo = fopen( pathname, "w")) == NULL){
				MessageBar("初始化学生文件失败			");
			}
		}


		strcpy(newStudent->name, studentName);				//把信息输入到结构体
		newStudent->ordinal = tempOrdinal;					//为各结构体编写序号
		tempOrdinal++;

		
		if( *pstudentLineHead == NULL){
			*pstudentLineHead = newStudent;				//表头为空就把表头直接指向新结构体
			newStudent->next = NULL;
		}
		else{
			tailStudent->next = newStudent;		//表头不空则上一结构体指向该结构体
			newStudent->next = NULL;
		}
		tailStudent = newStudent;
	}
	fclose( studentListFile);
}


void getStudent(struct HEADS **pLeader, int studentNum, char className[NameNumMax]){		//尾接法

	struct HEADS *tempPLeader;
	FILE *studentInfo;
	char pathname[NameNumMax + 30] = ".\\data\\", studentName[NameNumMax];
	char pathnameTemp[NameNumMax + 30], tempStr[NameNumMax + 30];
	int i = 0, j = 0, k = 0, tempOrdinal=0;
	
	strcat( pathname, accountName);
	strcat( pathname, "\\");
	strcat( pathname, className);			//.\data\#username\#classname

	listStudentHead(pLeader, studentNum, className);
												//把students.txt里的学生列出来，得到姓名、序号和指针
												//之后就可以用头指针调用


	/*
	tempPLeader = *(pLeader);
	printf("name: %s, next: %d, ordinal: %d, toHead: %d\n", (*pLeader)->name, (*pLeader)->next, (*pLeader)->ordinal );
	while( (*pLeader)->next != NULL){
		*(pLeader) = (*pLeader)->next;
		printf("name: %s, next: %d, ordinal: %d, toHead: %d\n", (*pLeader)->name, (*pLeader)->next, (*pLeader)->ordinal );
						//检查HEADS pLeader中存的数据是否正常
	}						//#########################
	//*///
	tempPLeader = *(pLeader);			//暂存一下，到时候这个指针数据还会用
	strcpy( pathnameTemp, pathname);				//↓
	for( j = 0; j < studentNum; j++){				//↓		//此处循环用于确保每个学生得以记录
		*(pLeader) = tempPLeader;				//这就用上了
		for( k = 0; k < j && (*pLeader)->next != NULL; k++){	//此处循环用于确保第k个学生得到记录
			(*pLeader) = (*pLeader)->next;
		}		//循环之后会依据 j（学生数目）得到一个序数，
				//此时结构体的名字就等于ViewClassList_display里相应序数的名字
//		printf("序数为：%d \n该文件为：%s \n", k, (*pLeader)->name );				//###################3333
//		system("pause");				//###################3333
		strcpy( studentName, (*pLeader)->name);
		strcat( pathname, "\\");
		strcat( pathname, studentName);
		strcat( pathname, ".txt");					//.\data\#username\#classname\#studentname.txt

		if( (studentInfo = fopen( pathname, "r")) == NULL){
			MessageBar("打开文件失败");
			exit(1);
		}


		fgets( tempStr, NameNumMax + 30, studentInfo);

		for( i = 0; i < NameNumMax + 30; i++){
			if( tempStr[i] == '\n'){						//删去'\n'
				tempStr[i] = '\0';
			}
		}
		strcpy( (*pLeader)->student.name, tempStr);					//存入姓名
//		printf("姓名 %s\n", (*pLeader)->student.name);			//######################
//		system("pause");						//######################
		fgets( tempStr, NameNumMax + 30, studentInfo);
		for( i = 0; i < NameNumMax + 30; i++){
			if( tempStr[i] == '\n'){						//删去'\n'
				tempStr[i] = '\0';
			}
		}
		strcpy( (*pLeader)->student.ID, tempStr);					//存入学号
//		printf("ID %s\n", (*pLeader)->student.ID);			//######################
//		system("pause");						//######################
		fgets( tempStr, NameNumMax + 30, studentInfo);
		for( i = 0; i < NameNumMax + 30; i++){
			if( tempStr[i] == '\n'){						//删去'\n'
				tempStr[i] = '\0';
			}
		}
		strcpy( (*pLeader)->student.sex, tempStr);					//存入性别
//		printf("性别 %s\n", student->sex);			//######################
//		system("pause");						//######################
		fgets( tempStr, NameNumMax + 30, studentInfo);
		for( i = 0; i < NameNumMax + 30; i++){
			if( tempStr[i] == '\n'){						//删去'\n'
				tempStr[i] = '\0';
			}
		}
		strcpy( (*pLeader)->student.addres, tempStr);					//存入地址
	//	printf("地址 %s\n", student->addres);			//######################
//		system("pause");						//######################
		fgets( tempStr, NameNumMax + 30, studentInfo);
		for( i = 0; i < NameNumMax + 30; i++){
			if( tempStr[i] == '\n'){						//删去'\n'
				tempStr[i] = '\0';
			}
		}
		strcpy( (*pLeader)->student.PhoneNum, tempStr);					//存入电话号
//		printf("电话 %s\n", student->PhoneNum);			//######################
//		system("pause");						//######################
		strcpy( pathname, pathnameTemp);
		
	}
	*(pLeader) = tempPLeader;
}


int NewClass(int dataInputState){

	int SelectedOption = 1, PressedKey, PressedKey_temp = 0;

	while(1){

		if( SelectedOption == 1 && PressedKey_temp == 13){			//指标指向输入账号时按回车
			if( dataInputState == -1){
				dataInputState = 0;
			}
			else if( dataInputState == 0){
				dataInputState = -1;
			}

		}
		if( SelectedOption == 2 && PressedKey_temp == 13){			//指标指向完成时按回车
			NewcToAcc();
		}
		if( SelectedOption == 3 && PressedKey_temp == 13){			//指标指向返回时按回车
			AccountUI();
			break;
		}
		system("cls");

		NewClass_Display(SelectedOption, dataInputState, StrNum_InputTemp);
		MessageBar("\0");

		if( dataInputState == -1){						//非输入状态
			PressedKey_temp = _getch();
			if( PressedKey_temp == 224 ){			//返回键盘值的函数对于方向键的键盘值会返回两次
				PressedKey = _getch();
				SelectedOption = getFlagWithPressedKey_ALL( SelectedOption, PressedKey, 3);
			}
		}
		else if( dataInputState == 0){					//输入状态
			PressedKey_temp = _getch();

			if( PressedKey_temp == 13){						//如果是回车键，就略过此次循环
				continue;
			}
			if( PressedKey_temp != 224 && PressedKey_temp != 8){//不是方向键退格键就输入字符
				PressedKey = PressedKey_temp;
				if(StrNum_InputTemp < NameNumMax){
					inputTemp[StrNum_InputTemp] = PressedKey;
					StrNum_InputTemp++;
					inputTemp[StrNum_InputTemp] = '\0';
				}
				else{
					MessageBar("最多只能输入16位字符。          ");
					Sleep(1000);
				}
			}
			else if( PressedKey_temp == 8){
				if(StrNum_InputTemp > 0){
					inputTemp[StrNum_InputTemp - 1] = '\0';
					StrNum_InputTemp--;
				}
				else{
					MessageBar("请输入班级名称。          ");
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
	
		if( SelectedOption == 1 && PressedKey_temp == 13){			//指标指向查看班级时按回车
			
			ViewClassList();
		}
		if( SelectedOption == 2 && PressedKey_temp == 13){			//指标指向新建班级时按回车

			NewClass(-1);
		}
		if( SelectedOption == 3 && PressedKey_temp == 13){			//指标指向注销时按回车
			printf("注销成功！\n");
			Sleep(500);
			MainMenu();
			break;
		}
		system("cls");


		AccountUI_Display(SelectedOption, accountName);
		MessageBar("\0");

		PressedKey_temp = _getch();
		if( PressedKey_temp == 224 ){	//返回键盘值的函数对于方向键的键盘值会返回两次
			PressedKey = _getch();
			SelectedOption = getFlagWithPressedKey_ALL( SelectedOption, PressedKey, 3);
		}
	}
}


int LoginUI(int dataInputState){								//登入界面

	int SelectedOption = 1, PressedKey, PressedKey_temp = 0;


	while(1){

		if( SelectedOption == 1 && PressedKey_temp == 13){			//指标指向输入账号时按回车
			if( dataInputState == -1){
				dataInputState = 0;
			}
			else if( dataInputState == 0){
				dataInputState = -1;
			}
		}
		if( SelectedOption == 2 && PressedKey_temp == 13){			//指标指向登入时按回车
			
			LogToAcc();
		}
		if( SelectedOption == 3 && PressedKey_temp == 13){			//指标指向返回时按回车
			MainMenu();
			break;
		}
		system("cls");

		LoginUI_Display(SelectedOption, dataInputState, StrNum_Name);
		MessageBar("\0");

		if( dataInputState == -1){						//非输入状态
			PressedKey_temp = _getch();
			if( PressedKey_temp == 224 ){			//返回键盘值的函数对于方向键的键盘值会返回两次
				PressedKey = _getch();
				SelectedOption = getFlagWithPressedKey_ALL( SelectedOption, PressedKey, 3);
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


int RegisterUI(int dataInputState){							//注册界面

	int SelectedOption = 1, PressedKey, PressedKey_temp = 0;

	while(1){

		if( SelectedOption == 1 && PressedKey_temp == 13){			//指标指向输入账号时按回车
			if( dataInputState == -1){
				dataInputState = 0;
			}
			else if( dataInputState == 0){
				dataInputState = -1;
			}

		}
		if( SelectedOption == 2 && PressedKey_temp == 13){			//指标指向完成时按回车
			ReToLog();
		}
		if( SelectedOption == 3 && PressedKey_temp == 13){			//指标指向返回时按回车
			MainMenu();
			break;
		}
		system("cls");

		RegisterUI_Display(SelectedOption, dataInputState, StrNum_NewName);
		MessageBar("\0");

		if( dataInputState == -1){						//非输入状态
			PressedKey_temp = _getch();
			if( PressedKey_temp == 224 ){			//返回键盘值的函数对于方向键的键盘值会返回两次
				PressedKey = _getch();
				SelectedOption = getFlagWithPressedKey_ALL( SelectedOption, PressedKey, 3);
			}
		}
		else if( dataInputState == 0){					//输入状态
			PressedKey_temp = _getch();

			if( PressedKey_temp == 13){						//如果是回车键，就略过此次循环
				continue;
			}
			if( PressedKey_temp != 224 && PressedKey_temp != 8){//不是方向键退格键就输入字符
				PressedKey = PressedKey_temp;
				if(StrNum_NewName < NameNumMax){
					reg_accountName[StrNum_NewName] = PressedKey;
					StrNum_NewName++;
					reg_accountName[StrNum_NewName] = '\0';
				}
				else{
					MessageBar("最多只能输入16位字符。          ");
					Sleep(1000);
				}
			}
			else if( PressedKey_temp == 8){
				if(StrNum_NewName > 0){
					reg_accountName[StrNum_NewName - 1] = '\0';
					StrNum_NewName--;
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


void MainMenu(void){

	int SelectedOption = 1, PressedKey, PressedKey_temp = 0;

	while(1){

		if( SelectedOption == 1 && PressedKey_temp == 13){			//指标指向登入时按回车
			LoginUI(-1);
			break;
		}
		if( SelectedOption == 2 && PressedKey_temp == 13){			//指标指向注册时按回车
			RegisterUI(-1);
			break;
		}
		if( SelectedOption == 3 && PressedKey_temp == 13){			//指标指向返回时按回车
			system("cls");
			printf("感谢使用！\n");
			exit(0);

		}

		system("cls");

		MainMenu_Display(SelectedOption);
		MessageBar("欢迎使用该程序！");
		
		PressedKey_temp = _getch();
		if( PressedKey_temp == 224 ){		//返回键盘值的函数对于方向键的键盘值会返回两次
			PressedKey = _getch();
			SelectedOption = getFlagWithPressedKey_ALL( SelectedOption, PressedKey, 3);
		}
	}
}
//==========
void LogToAcc(){
	FILE *fp;
	char ReadFromFile[ NameNumMax + 2];
	int IDCode = 2;			//1表示存在该用户，2表示不存在

	if( (fp = fopen(".\\data\\users.txt", "r") ) == NULL ){			//检查读取权限
		MessageBar("无法打开文件夹，请检查文件读取权限。          ");
		return;
	}
	
	while( !feof(fp)){								//检索user.txt中是否存在该用户名
		int CompareResult, i;
		fgets( ReadFromFile, NameNumMax + 2, fp);		//+2是因为要多读一个\n和一个\0
		for( i = 0; i < NameNumMax + 1; i++){
			if( ReadFromFile[i] == '\n'){						//删去'\n'
				ReadFromFile[i] = '\0';
			}
		}
		if( (CompareResult = strcmp( ReadFromFile, temp_accountName)) == 0){ //字符串相同
			IDCode = 1;				//认为存在用户
			strcpy( accountName, temp_accountName);
			break;
		}
	}
	fclose( fp);

		//================================
	if( IDCode == 1){
		MessageBar("登入成功。          ");
		Sleep(100);
		StrNum_Name = 0;
		AccountUI();
	}
	else if( IDCode == 2){
		MessageBar("无此账号。          ");
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
		MessageBar("无法打开文件夹，请检查文件读取权限。          ");
		return;
	}
	
	while( !feof(fp)){								//检索user.txt中是否已经存在该用户名
		int i;
		fgets( ReadFromFile, NameNumMax + 2, fp);		//+2是因为要多读一个\n和一个\0
		for( i = 0; i < NameNumMax + 1; i++){
			if( ReadFromFile[i] == '\n'){						//删去'\n'
				ReadFromFile[i] = '\0';
			}
		}
		LineNum += 1;
		if( (CompareResult = strcmp( ReadFromFile, reg_accountName)) == 0){ //字符串相同
			IDCode = 2;
			break;
		}
	}


	if( (CompareResult = strcmp( "", reg_accountName)) == 0){
		IDCode = 3;								//IDCode为 3意味着不允许注册此类名字
	}

	fclose( fp);

	if( IDCode == 1){
		int FileCreateState = 0;
		char pathname[NameNumMax + 30] = ".\\data\\";

		if( (fp = fopen(".\\data\\users.txt", "a") ) == NULL ){
			MessageBar("无法打开文件夹，请检查文件写入权限。          ");
			return;
		}

		if( LineNum > 0){						//	原文有文字才打印换行符
			fputs( "\n", fp);
		}
		fputs( reg_accountName, fp);
		fclose( fp);
		strcat( pathname, reg_accountName);
		if( _access( pathname, 0) == -1 ){				//创建用户文件夹，用于储存用户的信息
			if( (FileCreateState = mkdir( pathname)) == -1 ){
				MessageBar("创建用户文件夹失败，请检查文件写入权限          ");
				return;
			}
		}
		
		strcat( pathname, "\\classlist.txt");
		if( (setFile = fopen( pathname, "w")) == NULL){
			MessageBar("创建文件失败，请检查文件写入权限          ");
			return;
		}											//创建班级列表文件，用于储存用户的班级列表
		fputs( "班级列表", setFile);
		fclose(setFile);
		
		StrNum_NewName = 0;
		reg_accountName[StrNum_NewName] = '\0';
		MessageBar("注册成功。          ");
		Sleep(500);
		LoginUI(-1);
	}
	else if( IDCode == 2){
		StrNum_NewName = 0;
		reg_accountName[StrNum_NewName] = '\0';
		MessageBar("已存在此账号。          ");
		Sleep(600);
		LoginUI(-1);
	}
	else if( IDCode == 3){
		StrNum_NewName = 0;
		reg_accountName[StrNum_NewName] = '\0';
		MessageBar("不允许注册非法账号。          ");
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
	if( (fp = fopen(pathname, "r") ) == NULL ){				//检查是否能打开classlist.txt文件
		MessageBar("无法打开文件，请检查文件读取权限。          ");
		return;
	}
	
	while( !feof(fp)){								//检索classlist.txt中是否已经存在该班级名
		int i;
		fgets( ReadFromFile, NameNumMax + 2, fp);		//+2是因为要多读一个\n和一个\0
		for( i = 0; i < NameNumMax + 1; i++){
			if( ReadFromFile[i] == '\n'){						//删去'\n'
				ReadFromFile[i] = '\0';
			}
		}
		LineNum += 1;
		if( (CompareResult = strcmp( ReadFromFile, inputTemp)) == 0){ //字符串相同
			IDCode = 2;			//IDCode为 2意味着已存在该名字
			break;
		}
	}

	if( (CompareResult = strcmp( "", inputTemp)) == 0){
		IDCode = 3;								//IDCode为 3意味着不允许创建此类名字的班级
	}

	fclose( fp);


	if( IDCode == 1){
		int FileCreateState = 0;

		if( (fp = fopen(pathname, "a") ) == NULL ){
			MessageBar("无法打开文件，请检查文件写入权限。          ");
			system("pause");
			return;
		}

		if( LineNum > 0){						//	原文有文字才打印换行符
			fputs( "\n", fp);
		}
		fputs( inputTemp, fp);				//	往classlist.txt写入#classname完毕
		fclose( fp);

		strcpy(pathname, ".\\data\\");			//前面拼接过pathname，故此处初始化
		strcat(pathname, accountName);
		strcat(pathname, "\\");
		strcat(pathname, inputTemp);		//.\data\#username\#classname

		if( _access( pathname, 0) == -1 ){				//创建班级文件夹，用于储存学生的信息
			if( (FileCreateState = mkdir( pathname)) == -1 ){
				MessageBar("创建用户文件夹失败，请检查文件写入权限          ");
				system("pause");
				return;
			}
		}			
		strcat(pathname, "\\students.txt");		//.\data\#username\#classname\students.txt

		if( (setFile = fopen( pathname, "a")) == NULL){
			MessageBar("创建文件失败，请检查文件写入权限          ");
			system("pause");
			return;
		}											//创建学生列表文件，用于储存班级的学生列表

		fputs( "学生列表", setFile);
		fclose(setFile);

		StrNum_InputTemp = 0;
		inputTemp[StrNum_InputTemp] = '\0';
		MessageBar("创建班级成功。          ");
		Sleep(600);
		AccountUI();
	}
	else if( IDCode == 2){
		StrNum_InputTemp = 0;
		inputTemp[StrNum_InputTemp] = '\0';
		MessageBar("已存在此班级。          ");
		Sleep(600);
		NewClass(-1);
	}
	else if( IDCode == 3){
		StrNum_InputTemp = 0;
		inputTemp[StrNum_InputTemp] = '\0';
		MessageBar("不允许注册非法班级名。          ");
		Sleep(700);
		NewClass(-1);
	}
}


void PrintList_Class(int SelectedOption, int ClassCount, struct LIST *classLineHead){
	
	int i;
	printf("\n");
	printf("%s\t\t\t\t\n", classLineHead->name);		//打印标题
	classLineHead = classLineHead->next;
	for( i = 0; i < ClassCount; i++){
		if( SelectedOption == i + 1){
			printf("%d  %s\t\t\t\t|查看<", classLineHead->ordinal, classLineHead->name);
		}
		else{
			printf("%d  %s\t\t\t\t查看", classLineHead->ordinal, classLineHead->name);
		}
		printf("\n");
		classLineHead = classLineHead->next;
	}
}

void PrintList_Student(int SelectedOption, int StudentCount, struct LIST *studnetLineHead){
	
	int i;
	printf("\n");
	printf("%s\t\t\t\t\n", studnetLineHead->name);		//打印标题
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
	printf("\t姓名\t学号\t性别\t地址\t电话号码\n");		//打印标题


	for( i = 0; i < StudentCount ; i++){

		if( SelectedOption == i + 1){
			printf("|删除<   %s\t", studnetLineHead->student.name);
			printf("%s\t%s\t", studnetLineHead->student.ID, studnetLineHead->student.sex);
			printf("%s\t%s", studnetLineHead->student.addres, studnetLineHead->student.PhoneNum);
		}
		else{
			printf("删除   %s\t", studnetLineHead->student.name);
			printf("%s\t%s\t", studnetLineHead->student.ID, studnetLineHead->student.sex);
			printf("%s\t%s", studnetLineHead->student.addres, studnetLineHead->student.PhoneNum);
		}
		printf("\n");
		studnetLineHead = studnetLineHead->next;
	}
}