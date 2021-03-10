

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
	if( StudentCount == 0){
		printf("\n\t����ѧ��\n");
	}
	else{
		PrintList_Student(SelectedOption, StudentCount, studentLineHead);
	}
	

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
	gotoxy(0, (short)(6 + StudentCount));
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

extern void ViewClassC_Display(int SelectedOption, int StudentCount, struct HEADS *studentLineHead, char className[NameNumMax], int dataInputState, int StrNum[5]){
	int x[5];					//ѡ���ѡ��			ѧ����Ŀ				����ѧ�������ӡ��Ϣ		����༶����			�Ƿ�����������		�ַ�����
	int i;

	for( i = 0; i <5; i++){
		x[i] = StrNum[i] + 20;
	}

	printf("���༶��%s��", className);
	printf("\n");

	printf("������������������������");

	PrintList_Student_New(SelectedOption, StudentCount, studentLineHead);

	printf("������������������������");
	printf("\n");

	if( SelectedOption == 1){
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
	
	if( SelectedOption == 2){
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

	if( SelectedOption == 3){
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
	
	if( SelectedOption == 4){
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
	
	if( SelectedOption == 5){
		printf("> �绰��");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
	}
	else{
		printf("�绰��");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
	}
	printf("\n");
	
	if( SelectedOption == 6){
		printf("|���<");
	}
	else{
		printf("���");
	}
	printf("\n");
	
	if( SelectedOption == 7){
		printf("|ȡ��<");
	}
	else{
		printf("ȡ��");
	}
	printf("\n");
//======================================
	if( SelectedOption == 1){
		gotoxy( 0, (short)(4 + StudentCount) );
		printf("> ������");
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
		printf("������");
		gotoxy( 6, (short)(4 + StudentCount));
		printf("%s", inputTempAdd[0]);
		printf("\n");
	}

	if( SelectedOption == 2){
		gotoxy( 0, (short)(5 + StudentCount));
		printf("> ѧ�ţ�");
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
		printf("ѧ�ţ�");
		gotoxy( 6, (short)(5 + StudentCount));
		printf("%s", inputTempAdd[1]);
		printf("\n");
	}

	if( SelectedOption == 3){
		gotoxy( 0, (short)(6 + StudentCount));
		printf("> �Ա�");
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
		printf("�Ա�");
		gotoxy( 6, (short)(6 + StudentCount));
		printf("%s", inputTempAdd[2]);
		printf("\n");
	}

	if( SelectedOption == 4){
		gotoxy( 0, (short)(7 + StudentCount));
		printf("> סַ��");
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
		printf("סַ��");
		gotoxy( 6, (short)(7 + StudentCount));
		printf("%s", inputTempAdd[3]);
		printf("\n");
	}

	if( SelectedOption == 5){
		gotoxy( 0, (short)(8 + StudentCount));
		printf("> �绰��");
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
		printf("�绰��");
		gotoxy( 6, (short)(8 + StudentCount));
		printf("%s", inputTempAdd[4]);
		printf("\n");
	}
}

extern void ViewClassD_Display(int SelectedOption, int StudentCount, struct HEADS *studentLineHead, char className[NameNumMax], int dataInputState, int StrNum[5]){
	int x[5];					//ѡ���ѡ��			ѧ����Ŀ				����ѧ�������ӡ��Ϣ		����༶����			�Ƿ�����������		�ַ�����
	int i;

	for( i = 0; i <5; i++){
		x[i] = StrNum[i] + 20;
	}

	printf("���༶��%s��", className);
	printf("\n");

	printf("������������������������");
	if( StudentCount == 0){
		printf("\n\t����ѧ��\n");
	}
	else{
		PrintList_Student_Bar(SelectedOption, StudentCount, studentLineHead);
	}
	printf("������������������������");
	printf("\n");

	if( SelectedOption == 1 + StudentCount){
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
	
	if( SelectedOption == 2 + StudentCount){
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

	if( SelectedOption == 3 + StudentCount){
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
	
	if( SelectedOption == 4 + StudentCount){
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
	
	if( SelectedOption == 5 + StudentCount){
		printf("> �绰��");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
	}
	else{
		printf("�绰��");
		for(i = 0; i < NameNumMax; i++){
			printf("_");
		}
	}
	printf("\n");
	
	if( SelectedOption == 6 + StudentCount){
		printf("|���ͬѧ<");
	}
	else{
		printf("���ͬѧ");
	}
	printf("\n");
	
	if( SelectedOption == 7 + StudentCount){
		printf("|����<");
	}
	else{
		printf("����");
	}
	printf("\n");
//======================================
	if( SelectedOption == 1 + StudentCount){
		gotoxy( 0, (short)(4 + StudentCount) );
		printf("> ������");
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
		printf("������");
		gotoxy( 6, (short)(4 + StudentCount));
		printf("%s", inputTempAdd[0]);
		printf("\n");
	}

	if( SelectedOption == 2 + StudentCount){
		gotoxy( 0, (short)(5 + StudentCount));
		printf("> ѧ�ţ�");
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
		printf("ѧ�ţ�");
		gotoxy( 6, (short)(5 + StudentCount));
		printf("%s", inputTempAdd[1]);
		printf("\n");
	}

	if( SelectedOption == 3 + StudentCount){
		gotoxy( 0, (short)(6 + StudentCount));
		printf("> �Ա�");
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
		printf("�Ա�");
		gotoxy( 6, (short)(6 + StudentCount));
		printf("%s", inputTempAdd[2]);
		printf("\n");
	}

	if( SelectedOption == 4 + StudentCount){
		gotoxy( 0, (short)(7 + StudentCount));
		printf("> סַ��");
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
		printf("סַ��");
		gotoxy( 6, (short)(7 + StudentCount));
		printf("%s", inputTempAdd[3]);
		printf("\n");
	}

	if( SelectedOption == 5 + StudentCount){
		gotoxy( 0, (short)(8 + StudentCount));
		printf("> �绰��");
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
		printf("�绰��");
		gotoxy( 6, (short)(8 + StudentCount));
		printf("%s", inputTempAdd[4]);
		printf("\n");
	}
	gotoxy(0, (short)(11 + StudentCount));
}