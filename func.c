/*********************
	sheet操作函数文件
**********************/

# include <stdio.h>
# include <stdlib.h>
# include <time.h>




/***************************************************************
	Name: 	  sheetPrint()
	Function: 传入一个5x5的二维数组，以类表格的形式输出该数组的所有元素
****************************************************************/

void sheetPrint ( int form[5][5] ) {
	for (int row = 0; row < 5; row++) {
		for (int column = 0; column < 5; column++) {
            if ( !( form[row][column] / 10 ) ) {
                printf( " %d  ", form[row][column] );
            } else {
                printf( "%d  ", form[row][column] );
            }
		}
        printf("\n");
	}	
    printf("------------------\n");
}




/*********************************************************
	Name:     sheetClear()
	Function: 传入一个5x5的二维数组，将该数组所有元素值初始化为0
**********************************************************/

void sheetClear ( int form[5][5] ) {
	for (int row = 0; row < 5; row++) {
		for (int column = 0; column < 5; column++) {
			form[row][column] = 0;
		}
	}

	return 0;
}




/**************************************************************
	Name:     sheetInitialize()
	Function: 传入一个5x5二维数组，为每个元素依次赋予随机值 ( 1~20 )
***************************************************************/

void sheetInitialize ( int form[5][5] ) {
	srand( ( unsigned ) time ( NULL ) );
	for (int row = 0; row < 5; row++) {
		for (int column = 0; column < 5; column++) {
			form[row][column] = rand() % 20+1;
		}
	}

	return 0;
}




/*********************************************************************************************************************
	Name:     elementDrop()
	Function: 该函数被 sheetChange() 调用，以实现空位的上位元素向下传递的效果，空位元素所在列的最顶部数字会被赋予一个随机值 ( 1~20 )
	Tips:     感谢rippleQAQ师傅对该函数做出的贡献！
**********************************************************************************************************************/

void elementDrop ( int form_[5][5], int x, int y ) {
	srand( ( unsigned ) time ( NULL ) );

	for ( int row = x; row > 0; row-- ) {
		form_[row][y] = form_[row-1][y];
	}

	form_[0][y] = rand() % 20+1;
}



/*
	Name:     
	Function: 
*/

int sheetChange ( int form[5][5], int x1, int y1, int x2, int y2) {
	int selectedVar = form[x1][y1];
	int sumVar = form[x2][y2];
	
	if ( ( selectedVar + sumVar ) > 100 ) {
		return 0;
	} else {
		sumVar += selectedVar + sumVar;
		elementDrop( form, x1, y1 );
		return 1;
	}
}