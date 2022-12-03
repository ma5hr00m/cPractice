#include <stdio.h>

/* 按理说，二维数组初始化为0后输出全0；
 * 但实际上最后6位输出的数字不为0
*/
int main() {
	int sheet[5][5] = { 0 };
	
	for (int row = 0; row < 5; row++) {
		for (int column = 0; column < 5; column++) {
			printf("sheet[%d][%d]: %d\n", column, row,sheet[row][column]);
		}
	}	
}