/*********************
	sheet操作函数文件
**********************/

# include <stdio.h>
# include <stdlib.h>
# include <time.h>




/***************************************************************
	Name: 	  sheetPrint()
	Function: 传入一个5x5的二维数组，以类表格的形式输出该数组的所有元素
	Effect:   测试
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
	Function: 传入一个5x5的二维数组
	Effect:   将数组初始化为随机值
**********************************************************/

void sheetClear ( int form[5][5] ) {
	for (int row = 0; row < 5; row++) {
		for (int column = 0; column < 5; column++) {
			form[row][column] = 0;
		}
	}
}




/**************************************************************
	Name:     sheetInitialize()
	Function: 传入一个5x5二维数组，为数组中每个元素赋予随机值 ( 1~20 )
	Effect:   将数组初始化为随机值
***************************************************************/

void sheetInitialize ( int form[5][5] ) {
	srand( ( unsigned ) time ( NULL ) );
	for (int row = 0; row < 5; row++) {
		for (int column = 0; column < 5; column++) {
			form[row][column] = rand() % 20+1;
		}
	}
}




/*********************************************************************************************************************
	Name:     elementDrop()
	Function: 该函数被 sheetChange() 调用，以实现空位的上位元素向下传递的效果，空位元素所在列的最顶部数字会被赋予一个随机值 ( 1~20 )
	Effect:   某列元素值向下传递
**********************************************************************************************************************/

void elementDrop ( int form_[5][5], int x, int y ) {
	srand( ( unsigned ) time ( NULL ) );

	for ( int row = x; row > 0; row-- ) {
		form_[row][y] = form_[row-1][y];
	}

	form_[0][y] = rand() % 20+1;
}



/******************************************************************************
	Name:     sheetChange()
	Function: 实现sheet内两元素的合并。若两数之和超过100，则返回0；若小于等于合并则返回1
	Effect:   合并两指定元素
*******************************************************************************/

int sheetChange ( int form[5][5], int x1, int y1, int x2, int y2) {
	int selectedVar = form[x1][y1];
	int sumVar = form[x2][y2];
	
	if ( selectedVar == 100 || sumVar == 100 ) {
		return 0;
	} else {
		if ( ( selectedVar + sumVar ) > 100 ) {
			return 0;
		} else {
			form[x2][y2] = selectedVar + sumVar;
			elementDrop( form, x1, y1 );
			return 1;
		}
	}
}




/*
	Name:
	Function: 
*/

int functionName (  ) {
	return 0;
}