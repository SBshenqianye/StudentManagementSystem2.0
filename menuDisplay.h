

extern void PrintList_Class(SelectedOption, ClassCount);
extern void PrintList_Student(SelectedOption, ClassCount);
extern void PrintList_Student_Bar(int SelectedOption, int StudentCount, struct HEADS *studnetLineHead);
extern void PrintList_Student_New(int SelectedOption, int StudentCount, struct HEADS *studnetLineHead);

void gotoxy(short x, short y) {
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

extern void MessageBar(char message[40]){

	gotoxy(0, 16);
	printf("——————");
	printf("\n");

	printf("消息栏：\n\n%s", message);


}

extern void MainMenu_Display(int SelectedOption){
	

	printf("【主菜单】");
	printf("\n");

	if( SelectedOption == 1){
		printf("|登入<");
	}
	else{
		printf("登入");
	}
	printf("\n");

	if( SelectedOption == 2){
		printf("|注册<");
	}
	else{
		printf("注册");
	}
	printf("\n");

	if( SelectedOption == 3){
		printf("|退出<");
	}
	else{
		printf("退出");
	}
	printf("\n");

}

extern void LoginUI_Display(int SelectedOption, int dataInputState, int StrNum){
	int x = StrNum + 8;
	int i;
	
	printf("【登入界面】");
	printf("\n");
	

	if( SelectedOption == 1){
		printf("> 账户：");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
		printf("\n");
	}
	else{
		printf("账户：");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
		printf("\n");
	}

	if( SelectedOption == 2){
		printf("|登入<");
	}
	else{
		printf("登入");
	}
	printf("\n");

	if( SelectedOption == 3){
		printf("|返回<");
	}
	else{
		printf("返回");
	}
	printf("\n");

	if( SelectedOption == 1){
		gotoxy( 0, 1);
		printf("> 账户：");
		gotoxy( 8, 1);
		printf("%s",temp_accountName);
		if( dataInputState == 0){
			gotoxy( (short)x, 1);
			printf("<");
		}
		printf("\n");
	}
	else if( SelectedOption != 1){
		gotoxy( 0, 1);
		printf("账户：");
		gotoxy( 6, 1);
		printf("%s",temp_accountName);
		printf("\n");
	}
}

extern void RegisterUI_Display(int SelectedOption, int dataInputState, int StrNum){
	int x = StrNum + 20;
	int i;
	printf("【注册界面】");
	printf("\n");

	if( SelectedOption == 1){
		printf("> 输入新建账户名称：");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
		printf("\n");
	}
	else{
		printf("输入新建账户名称：");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
		printf("\n");
	}

	if( SelectedOption == 2){
		printf("|完成<");
	}
	else{
		printf("完成");
	}
	printf("\n");

	if( SelectedOption == 3){
		printf("|返回<");
	}
	else{
		printf("返回");
	}
	printf("\n");

	if( SelectedOption == 1){
		gotoxy( 0, 1);
		printf("> 输入新建账户名称：");
		gotoxy( 20, 1);
		printf("%s", reg_accountName);
		if( dataInputState == 0){
			gotoxy( (short)x, 1);
			printf("<");
		}
		printf("\n");
	}
	else if( SelectedOption != 1){
		gotoxy( 0, 1);
		printf("输入新建账户名称：");
		gotoxy( 18, 1);
		printf("%s", reg_accountName);
		printf("\n");
	}

}

extern void AccountUI_Display(int SelectedOption, char *AccountName){
	

	printf("【账户界面】");
	printf("\n");

	printf("您好！%s！",AccountName);
	printf("\n");

	if( SelectedOption == 1){
		printf("|查看班级<");
	}
	else{
		printf("查看班级");
	}
	printf("\n");

	if( SelectedOption == 2){
		printf("|新建班级<");
	}
	else{
		printf("新建班级");
	}
	printf("\n");

	if( SelectedOption == 3){
		printf("|注销<");
	}
	else{
		printf("注销");
	}
	printf("\n");

}

extern void NewClass_Display(int SelectedOption, int dataInputState, int StrNum){
	int x = StrNum + 20;
	int i;
	printf("【注册界面】");
	printf("\n");

	if( SelectedOption == 1){
		printf("> 输入新建班级名称：");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
		printf("\n");
	}
	else{
		printf("输入新建班级名称：");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
		printf("\n");
	}

	if( SelectedOption == 2){
		printf("|完成<");
	}
	else{
		printf("完成");
	}
	printf("\n");

	if( SelectedOption == 3){
		printf("|返回<");
	}
	else{
		printf("返回");
	}
	printf("\n");

	if( SelectedOption == 1){
		gotoxy( 0, 1);
		printf("> 输入新建班级名称：");
		gotoxy( 20, 1);
		printf("%s", inputTemp);
		if( dataInputState == 0){
			gotoxy( (short)x, 1);
			printf("<");
		}
		printf("\n");
	}
	else if( SelectedOption != 1){
		gotoxy( 0, 1);
		printf("输入新建班级名称：");
		gotoxy( 18, 1);
		printf("%s", inputTemp);
		printf("\n");
	}

}

extern void ViewClassList_Display(int SelectedOption, int ClassCount, struct LIST *classLineHead){



	printf("【查看班级】");
	printf("\n");

	printf("————————————");

	PrintList_Class(SelectedOption, ClassCount, classLineHead);	

	printf("————————————");
	printf("\n");

	if( SelectedOption == ClassCount + 1){
		printf("|返回<");
	}
	else{
		printf("返回");
	}
	printf("\n");
}

extern void ViewClassA_Display(int SelectedOption, int StudentCount, struct LIST *studentLineHead, char className[NameNumMax]){

	SelectedOption = SelectedOption + StudentCount;


	printf("【班级：%s】", className);
	printf("\n");

	printf("————————————");
	if( StudentCount == 0){
		printf("\n\t暂无学生\n");
	}
	else{
		PrintList_Student(SelectedOption, StudentCount, studentLineHead);
	}
	

	printf("————————————");
	printf("\n");

	if( SelectedOption == StudentCount + 1){
		printf("|编辑<");
	}
	else{
		printf("编辑");
	}
	printf("\n");
	
	if( SelectedOption == StudentCount + 2){
		printf("|返回<");
	}
	else{
		printf("返回");
	}
	printf("\n");
	gotoxy(0, (short)(6 + StudentCount));
}

extern void ViewClassB_Display(int SelectedOption, int StudentCount, struct HEADS *studentLineHead, char className[NameNumMax]){
	


	printf("【班级：%s】", className);
	printf("\n");

	printf("————————————");

	PrintList_Student_Bar(SelectedOption, StudentCount, studentLineHead);

	printf("————————————");
	printf("\n");

	if( SelectedOption == StudentCount + 1){
		printf("|添加同学<");
	}
	else{
		printf("添加同学");
	}
	printf("\n");
	
	if( SelectedOption == StudentCount + 2){
		printf("|返回<");
	}
	else{
		printf("返回");
	}
	printf("\n");
}

extern void ViewClassC_Display(int SelectedOption, int StudentCount, struct HEADS *studentLineHead, char className[NameNumMax], int dataInputState, int StrNum[5]){
	int x[5];					//选择的选项			学生数目				导入学生链表打印信息		导入班级名字			是否在输入数据		字符长度
	int i;

	for( i = 0; i <5; i++){
		x[i] = StrNum[i] + 20;
	}

	printf("【班级：%s】", className);
	printf("\n");

	printf("————————————");

	PrintList_Student_New(SelectedOption, StudentCount, studentLineHead);

	printf("————————————");
	printf("\n");

	if( SelectedOption == 1){
		printf("> 姓名：");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
	}
	else{
		printf("姓名：");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
	}
	printf("\n");
	
	if( SelectedOption == 2){
		printf("> 学号：");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
	}
	else{
		printf("学号：");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
	}
	printf("\n");	

	if( SelectedOption == 3){
		printf("> 性别：");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
	}
	else{
		printf("性别：");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
	}
	printf("\n");
	
	if( SelectedOption == 4){
		printf("> 住址：");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
	}
	else{
		printf("住址：");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
	}
	printf("\n");
	
	if( SelectedOption == 5){
		printf("> 电话：");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
	}
	else{
		printf("电话：");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
	}
	printf("\n");
	
	if( SelectedOption == 6){
		printf("|完成<");
	}
	else{
		printf("完成");
	}
	printf("\n");
	
	if( SelectedOption == 7){
		printf("|取消<");
	}
	else{
		printf("取消");
	}
	printf("\n");
//======================================
	if( SelectedOption == 1){
		gotoxy( 0, (short)(4 + StudentCount) );
		printf("> 姓名：");
		gotoxy( 8, (short)(4 + StudentCount) );
		printf("%s", inputTempAdd[0]);
		if( dataInputState == 0){
			gotoxy( (short)x, 1);
			printf("<");
		}
		printf("\n");
	}
	else if( SelectedOption != 1){
		gotoxy( 0, (short)(4 + StudentCount));
		printf("姓名：");
		gotoxy( 6, (short)(4 + StudentCount));
		printf("%s", inputTempAdd[0]);
		printf("\n");
	}

	if( SelectedOption == 2){
		gotoxy( 0, (short)(5 + StudentCount));
		printf("> 学号：");
		gotoxy( 8, (short)(5 + StudentCount));
		printf("%s", inputTempAdd[1]);
		if( dataInputState == 0){
			gotoxy( (short)x, 1);
			printf("<");
		}
		printf("\n");
	}
	else if( SelectedOption != 2){
		gotoxy( 0, (short)(5 + StudentCount));
		printf("学号：");
		gotoxy( 6, (short)(5 + StudentCount));
		printf("%s", inputTempAdd[1]);
		printf("\n");
	}

	if( SelectedOption == 3){
		gotoxy( 0, (short)(6 + StudentCount));
		printf("> 性别：");
		gotoxy( 8, (short)(6 + StudentCount));
		printf("%s", inputTempAdd[2]);
		if( dataInputState == 0){
			gotoxy( (short)x, 1);
			printf("<");
		}
		printf("\n");
	}
	else if( SelectedOption != 3){
		gotoxy( 0, (short)(6 + StudentCount));
		printf("性别：");
		gotoxy( 6, (short)(6 + StudentCount));
		printf("%s", inputTempAdd[2]);
		printf("\n");
	}

	if( SelectedOption == 4){
		gotoxy( 0, (short)(7 + StudentCount));
		printf("> 住址：");
		gotoxy( 8, (short)(7 + StudentCount));
		printf("%s", inputTempAdd[3]);
		if( dataInputState == 0){
			gotoxy( (short)x, 1);
			printf("<");
		}
		printf("\n");
	}
	else if( SelectedOption != 4){
		gotoxy( 0, (short)(7 + StudentCount));
		printf("住址：");
		gotoxy( 6, (short)(7 + StudentCount));
		printf("%s", inputTempAdd[3]);
		printf("\n");
	}

	if( SelectedOption == 5){
		gotoxy( 0, (short)(8 + StudentCount));
		printf("> 电话：");
		gotoxy( 8, (short)(8 + StudentCount));
		printf("%s", inputTempAdd[4]);
		if( dataInputState == 0){
			gotoxy( (short)x, 1);
			printf("<");
		}
		printf("\n");
	}
	else if( SelectedOption != 5){
		gotoxy( 0, (short)(8 + StudentCount));
		printf("电话：");
		gotoxy( 6, (short)(8 + StudentCount));
		printf("%s", inputTempAdd[4]);
		printf("\n");
	}
}

extern void ViewClassD_Display(int SelectedOption, int StudentCount, struct HEADS *studentLineHead, char className[NameNumMax], int dataInputState, int StrNum[5]){
	int x[5];					//选择的选项			学生数目				导入学生链表打印信息		导入班级名字			是否在输入数据		字符长度
	int i;

	for( i = 0; i <5; i++){
		x[i] = StrNum[i] + 20;
	}

	printf("【班级：%s】", className);
	printf("\n");

	printf("————————————");
	if( StudentCount == 0){
		printf("\n\t暂无学生\n");
	}
	else{
		PrintList_Student_Bar(SelectedOption, StudentCount, studentLineHead);
	}
	printf("————————————");
	printf("\n");

	if( SelectedOption == 1 + StudentCount){
		printf("> 姓名：");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
	}
	else{
		printf("姓名：");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
	}
	printf("\n");
	
	if( SelectedOption == 2 + StudentCount){
		printf("> 学号：");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
	}
	else{
		printf("学号：");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
	}
	printf("\n");	

	if( SelectedOption == 3 + StudentCount){
		printf("> 性别：");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
	}
	else{
		printf("性别：");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
	}
	printf("\n");
	
	if( SelectedOption == 4 + StudentCount){
		printf("> 住址：");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
	}
	else{
		printf("住址：");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
	}
	printf("\n");
	
	if( SelectedOption == 5 + StudentCount){
		printf("> 电话：");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
	}
	else{
		printf("电话：");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
	}
	printf("\n");
	
	if( SelectedOption == 6 + StudentCount){
		printf("|添加同学<");
	}
	else{
		printf("添加同学");
	}
	printf("\n");
	
	if( SelectedOption == 7 + StudentCount){
		printf("|返回<");
	}
	else{
		printf("返回");
	}
	printf("\n");
//======================================
	if( SelectedOption == 1 + StudentCount){
		gotoxy( 0, (short)(4 + StudentCount) );
		printf("> 姓名：");
		gotoxy( 8, (short)(4 + StudentCount) );
		printf("%s", inputTempAdd[0]);
		if( dataInputState == 0){
			gotoxy( (short)x, 1);
			printf("<");
		}
		printf("\n");
	}
	else if( SelectedOption != 1 + StudentCount){
		gotoxy( 0, (short)(4 + StudentCount));
		printf("姓名：");
		gotoxy( 6, (short)(4 + StudentCount));
		printf("%s", inputTempAdd[0]);
		printf("\n");
	}

	if( SelectedOption == 2 + StudentCount){
		gotoxy( 0, (short)(5 + StudentCount));
		printf("> 学号：");
		gotoxy( 8, (short)(5 + StudentCount));
		printf("%s", inputTempAdd[1]);
		if( dataInputState == 0){
			gotoxy( (short)x, 1);
			printf("<");
		}
		printf("\n");
	}
	else if( SelectedOption != 2 + StudentCount){
		gotoxy( 0, (short)(5 + StudentCount));
		printf("学号：");
		gotoxy( 6, (short)(5 + StudentCount));
		printf("%s", inputTempAdd[1]);
		printf("\n");
	}

	if( SelectedOption == 3 + StudentCount){
		gotoxy( 0, (short)(6 + StudentCount));
		printf("> 性别：");
		gotoxy( 8, (short)(6 + StudentCount));
		printf("%s", inputTempAdd[2]);
		if( dataInputState == 0){
			gotoxy( (short)x, 1);
			printf("<");
		}
		printf("\n");
	}
	else if( SelectedOption != 3 + StudentCount){
		gotoxy( 0, (short)(6 + StudentCount));
		printf("性别：");
		gotoxy( 6, (short)(6 + StudentCount));
		printf("%s", inputTempAdd[2]);
		printf("\n");
	}

	if( SelectedOption == 4 + StudentCount){
		gotoxy( 0, (short)(7 + StudentCount));
		printf("> 住址：");
		gotoxy( 8, (short)(7 + StudentCount));
		printf("%s", inputTempAdd[3]);
		if( dataInputState == 0){
			gotoxy( (short)x, 1);
			printf("<");
		}
		printf("\n");
	}
	else if( SelectedOption != 4 + StudentCount){
		gotoxy( 0, (short)(7 + StudentCount));
		printf("住址：");
		gotoxy( 6, (short)(7 + StudentCount));
		printf("%s", inputTempAdd[3]);
		printf("\n");
	}

	if( SelectedOption == 5 + StudentCount){
		gotoxy( 0, (short)(8 + StudentCount));
		printf("> 电话：");
		gotoxy( 8, (short)(8 + StudentCount));
		printf("%s", inputTempAdd[4]);
		if( dataInputState == 0){
			gotoxy( (short)x, 1);
			printf("<");
		}
		printf("\n");
	}
	else if( SelectedOption != 5 + StudentCount){
		gotoxy( 0, (short)(8 + StudentCount));
		printf("电话：");
		gotoxy( 6, (short)(8 + StudentCount));
		printf("%s", inputTempAdd[4]);
		printf("\n");
	}
	gotoxy(0, (short)(11 + StudentCount));
}