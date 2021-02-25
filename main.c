
#include "globalsDefine.h"

//==========
char temp_accountName[NameNumMax] = "author";		//登入界面 账户ID显示
char reg_accountName[NameNumMax];		//注册界面 账户ID显示
char accountName[NameNumMax] = "author";			//登入成功后的ID显示
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


void ViewClassList(){

	int SelectedOption = 10, PressedKey, PressedKey_temp = 0;

	int ClassCount = 0;
	char pathname[NameNumMax + 30] = ".\\data\\", strTemp[NameNumMax];
	FILE *fp;
	struct CLASS *classLineHead = NULL;		//把链表表头初始化为空

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

		addClass(&classLineHead, ClassCount);
		
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


void addClass(struct CLASS **pclassLineHead, int classNum){		//尾接法
	struct CLASS *newClass;
	FILE *classListFile;
	char className[NameNumMax], pathname[NameNumMax + 30] = ".\\data\\";
	int i = 0;
	
	strcat( pathname, accountName);
	strcat( pathname, "\\classlist.txt");
	if( (classListFile = fopen( pathname, "r")) == NULL){
		MessageBar("打开文件失败");
	}

	while( !feof(classListFile)){
		newClass = (struct CLASS *)malloc(sizeof(struct CLASS));
		if( newClass == NULL){						//分配地址，储存一个结构体
			MessageBar("内存分配失败");
			exit(1);
		}

		fgets( className, NameNumMax, classListFile);
		for( i = 0; i < 20; i++){
			if( className[i] == '\n'){						//删去'\n'
				className[i] = '\0';
			}
		}
		strcpy(newClass->name, className);				//把信息输入到结构体
		newClass->ordinal = i;
		i++;


		if( *pclassLineHead == NULL){
			*pclassLineHead = newClass;				//表头为空就把表头直接指向新结构体
		}
		else{
			newClass->next = *pclassLineHead;		//表头不空则先新结构体指向表头
			*pclassLineHead = newClass;				//然后把表头指向新结构体
		}
	}
	fclose( classListFile);
}




void NewClass(){

	int SelectedOption = 1, PressedKey, PressedKey_temp = 0;

	while(1){
	
		if( SelectedOption == 1 && PressedKey_temp == 13){			//指标指向输入班级名称时按回车
			MessageBar("暂未开发。          ");
			Sleep(500);
			AccountUI();
			break;
		}
		if( SelectedOption == 2 && PressedKey_temp == 13){			//指标指向完成时按回车
			MessageBar("暂未开发。          ");
			Sleep(500);
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
			SelectedOption = getFlagWithPressedKey_ALL( SelectedOption, PressedKey, 3);
		}
	}
}


void AccountUI(){

	int SelectedOption = 1, PressedKey, PressedKey_temp = 0;

	while(1){
	
		if( SelectedOption == 1 && PressedKey_temp == 13){			//指标指向查看班级时按回车
			
			ViewClassList();
		}
		if( SelectedOption == 2 && PressedKey_temp == 13){			//指标指向新建班级时按回车
			MessageBar("暂未开发。          ");
			Sleep(500);
			AccountUI( accountName);
			break;
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
		for( i = 0; i < 20; i++){
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
		Sleep(400);
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
		for( i = 0; i < 20; i++){
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

	if( (fp = fopen(".\\data\\users.txt", "a") ) == NULL ){
		MessageBar("无法打开文件夹，请检查文件写入权限。          ");
		return;
	}

	if( IDCode == 1){
		int FileCreateState = 0;
		char pathname[NameNumMax + 30] = ".\\data\\";

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
		MessageBar("注册成功。          ");
		Sleep(500);
		LoginUI(-1);
	}
	else if( IDCode == 2){
		fclose( fp);
		StrNum_NewName = 0;
		MessageBar("已存在此账号。          ");
		Sleep(600);
		LoginUI(-1);
	}
	else if( IDCode == 3){
		fclose( fp);
		StrNum_NewName = 0;
		MessageBar("不允许注册非法账号。          ");
		Sleep(700);
		LoginUI(-1);
	}
}

void PrintList_Class(int SelectedOption, int ClassCount, struct CLASS *classLineHead){
	
	int i;
	printf("\n");
	for( i = 0; i < ClassCount; i++){
		if( SelectedOption == i + 1){
			printf("%s\t\t\t\t|查看<", classLineHead->name);
		}
		else{
			printf("%s\t\t\t\t查看", classLineHead->name);
		}
		printf("\n");
		classLineHead = classLineHead->next;
	}
}
