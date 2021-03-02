

extern void PrintList_Class(SelectedOption, ClassCount);
extern void PrintList_Student(SelectedOption, ClassCount);
extern void PrintList_Student_Bar(int SelectedOption, int StudentCount, struct HEADS *studnetLineHead);

void gotoxy(short x, short y) {
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

extern void MessageBar(char message[40]){

	gotoxy(0, 8);
	printf("������������");
	printf("\n");

	printf("��Ϣ����\n\n%s", message);


}

extern void MainMenu_Display(int SelectedOption){
	

	printf("�����˵���");
	printf("\n");

	if( SelectedOption == 1){
		printf("|����<");
	}
	else{
		printf("����");
	}
	printf("\n");

	if( SelectedOption == 2){
		printf("|ע��<");
	}
	else{
		printf("ע��");
	}
	printf("\n");

	if( SelectedOption == 3){
		printf("|�˳�<");
	}
	else{
		printf("�˳�");
	}
	printf("\n");

}

extern void LoginUI_Display(int SelectedOption, int dataInputState, int StrNum){
	int x = StrNum + 8;
	int i;
	
	printf("��������桿");
	printf("\n");
	

	if( SelectedOption == 1){
		printf("> �˻���");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
		printf("\n");
	}
	else{
		printf("�˻���");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
		printf("\n");
	}

	if( SelectedOption == 2){
		printf("|����<");
	}
	else{
		printf("����");
	}
	printf("\n");

	if( SelectedOption == 3){
		printf("|����<");
	}
	else{
		printf("����");
	}
	printf("\n");

	if( SelectedOption == 1){
		gotoxy( 0, 1);
		printf("> �˻���");
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
		printf("�˻���");
		gotoxy( 6, 1);
		printf("%s",temp_accountName);
		printf("\n");
	}
}

extern void RegisterUI_Display(int SelectedOption, int dataInputState, int StrNum){
	int x = StrNum + 20;
	int i;
	printf("��ע����桿");
	printf("\n");

	if( SelectedOption == 1){
		printf("> �����½��˻����ƣ�");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
		printf("\n");
	}
	else{
		printf("�����½��˻����ƣ�");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
		printf("\n");
	}

	if( SelectedOption == 2){
		printf("|���<");
	}
	else{
		printf("���");
	}
	printf("\n");

	if( SelectedOption == 3){
		printf("|����<");
	}
	else{
		printf("����");
	}
	printf("\n");

	if( SelectedOption == 1){
		gotoxy( 0, 1);
		printf("> �����½��˻����ƣ�");
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
		printf("�����½��˻����ƣ�");
		gotoxy( 18, 1);
		printf("%s", reg_accountName);
		printf("\n");
	}

}

extern void AccountUI_Display(int SelectedOption, char *AccountName){
	

	printf("���˻����桿");
	printf("\n");

	printf("���ã�%s��",AccountName);
	printf("\n");

	if( SelectedOption == 1){
		printf("|�鿴�༶<");
	}
	else{
		printf("�鿴�༶");
	}
	printf("\n");

	if( SelectedOption == 2){
		printf("|�½��༶<");
	}
	else{
		printf("�½��༶");
	}
	printf("\n");

	if( SelectedOption == 3){
		printf("|ע��<");
	}
	else{
		printf("ע��");
	}
	printf("\n");

}

extern void NewClass_Display(int SelectedOption, int dataInputState, int StrNum){
	int x = StrNum + 20;
	int i;
	printf("��ע����桿");
	printf("\n");

	if( SelectedOption == 1){
		printf("> �����½��༶���ƣ�");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
		printf("\n");
	}
	else{
		printf("�����½��༶���ƣ�");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
		printf("\n");
	}

	if( SelectedOption == 2){
		printf("|���<");
	}
	else{
		printf("���");
	}
	printf("\n");

	if( SelectedOption == 3){
		printf("|����<");
	}
	else{
		printf("����");
	}
	printf("\n");

	if( SelectedOption == 1){
		gotoxy( 0, 1);
		printf("> �����½��༶���ƣ�");
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
		printf("�����½��༶���ƣ�");
		gotoxy( 18, 1);
		printf("%s", inputTemp);
		printf("\n");
	}

}

extern void ViewClassList_Display(int SelectedOption, int ClassCount, struct LIST *classLineHead){



	printf("���鿴�༶��");
	printf("\n");

	printf("������������������������");

	PrintList_Class(SelectedOption, ClassCount, classLineHead);	

	printf("������������������������");
	printf("\n");

	if( SelectedOption == ClassCount + 1){
		printf("|����<");
	}
	else{
		printf("����");
	}
	printf("\n");
}

extern void ViewClassA_Display(int SelectedOption, int StudentCount, struct LIST *studentLineHead, char className[NameNumMax]){

	SelectedOption = SelectedOption + StudentCount;


	printf("���༶��%s��", className);
	printf("\n");

	printf("������������������������");

	PrintList_Student(SelectedOption, StudentCount, studentLineHead);

	printf("������������������������");
	printf("\n");

	if( SelectedOption == StudentCount + 1){
		printf("|�༭<");
	}
	else{
		printf("�༭");
	}
	printf("\n");
	
	if( SelectedOption == StudentCount + 2){
		printf("|����<");
	}
	else{
		printf("����");
	}
	printf("\n");
}

extern void ViewClassB_Display(int SelectedOption, int StudentCount, struct HEADS *studentLineHead, char className[NameNumMax]){
	


	printf("���༶��%s��", className);
	printf("\n");

	printf("������������������������");

	PrintList_Student_Bar(SelectedOption, StudentCount, studentLineHead);

	printf("������������������������");
	printf("\n");

	if( SelectedOption == StudentCount + 1){
		printf("|���ͬѧ<");
	}
	else{
		printf("���ͬѧ");
	}
	printf("\n");
	
	if( SelectedOption == StudentCount + 2){
		printf("|����<");
	}
	else{
		printf("����");
	}
	printf("\n");
}

extern void ViewClassC_Display(int SelectedOption, int StudentCount, struct LIST *studentLineHead){
	
	int i;
	SelectedOption = SelectedOption + StudentCount;


	printf("���༶��xxx��");
	printf("\n");

	printf("������������������������");

	PrintList_Student(SelectedOption, StudentCount, studentLineHead);

	printf("������������������������");
	printf("\n");

	if( SelectedOption == StudentCount + 1){
		printf("> ������");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
	}
	else{
		printf("������");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
	}
	printf("\n");
	
	if( SelectedOption == StudentCount + 2){
		printf("> ѧ�ţ�");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
	}
	else{
		printf("ѧ�ţ�");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
	}
	printf("\n");	

	if( SelectedOption == StudentCount + 3){
		printf("> �Ա�");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
	}
	else{
		printf("�Ա�");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
	}
	printf("\n");
	
	if( SelectedOption == StudentCount + 4){
		printf("> סַ��");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
	}
	else{
		printf("סַ��");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
	}
	printf("\n");
	
	if( SelectedOption == StudentCount + 5){
		printf("|���<");
	}
	else{
		printf("���");
	}
	printf("\n");
	
	if( SelectedOption == StudentCount + 6){
		printf("|ȡ��<");
	}
	else{
		printf("ȡ��");
	}
	printf("\n");
}