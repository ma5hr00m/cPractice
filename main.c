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
    sheetChange ( sheet, 3, 0, 3, 1);
    sheetPrint ( sheet );

    return 0;
}