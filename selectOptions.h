extern int getFlagWithPressedKey_III(int SelectedOption, int PressedKey){
	int returned_SO = SelectedOption;
	////�趨flag�ƶ���ʽ	pos: 1
	if( SelectedOption == 1 && PressedKey == 72 ){
		returned_SO = 3;
	}
	else if( SelectedOption == 1 && PressedKey == 80 ){
		returned_SO = SelectedOption + 1;
	}
	////�趨flag�ƶ���ʽ	pos: 2
	if( SelectedOption == 2 && PressedKey == 72 ){			
		returned_SO = SelectedOption - 1;
	}
	else if( SelectedOption == 2 && PressedKey == 80 ){
		returned_SO = SelectedOption + 1;
	}
	////�趨flag�ƶ���ʽ	pos: 3
	if( SelectedOption == 3 && PressedKey == 72 ){			
		returned_SO = SelectedOption - 1;
	}
	else if( SelectedOption == 3 && PressedKey == 80 ){
		returned_SO = 1;
	}
	return returned_SO;
}

extern int getFlagWithPressedKey_LUI(int SelectedOption, int PressedKey){
	int returned_SO = 0;
	////�趨flag�ƶ���ʽ	pos: 1
	if( SelectedOption == 1 && PressedKey == 72 ){
		returned_SO = 3;
	}
	else if( SelectedOption == 1 && PressedKey == 80 ){
		returned_SO = SelectedOption + 1;
	}
	////�趨flag�ƶ���ʽ	pos: 2
	if( SelectedOption == 2 && PressedKey == 72 ){			
		returned_SO = SelectedOption - 1;
	}
	else if( SelectedOption == 2 && PressedKey == 80 ){
		returned_SO = SelectedOption + 1;
	}
	////�趨flag�ƶ���ʽ	pos: 3
	if( SelectedOption == 3 && PressedKey == 72 ){			
		returned_SO = SelectedOption - 1;
	}
	else if( SelectedOption == 3 && PressedKey == 80 ){
		returned_SO = 1;
	}
	return returned_SO;
}