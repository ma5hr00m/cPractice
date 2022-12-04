/************
    测试文件
*************/

#include <stdio.h>
#include "func.c"

int main() {
    // 定义一个5x5二维数组
    int sheet[5][5];
    printf("------------------\n");

    // 测试 | sheetClear()函数
    sheetClear ( sheet );
    sheetPrint ( sheet );


    // 测试 | sheetInitialize()函数
    sheetInitialize ( sheet );
    sheetPrint ( sheet );


    // 测试 | sheetChange()函数
    while ( 1 ) {

        int a, b, c, d;

        scanf("%d %d %d %d", &a, &b , &c , &d);

        if ( a == 113 || b == 113 || c == 113 || d == 113 ) break;

        printf("------------------\n");

        sheetChange ( sheet, a, b, c, d);
        sheetPrint ( sheet );
        
    }
    

    return 0;
}