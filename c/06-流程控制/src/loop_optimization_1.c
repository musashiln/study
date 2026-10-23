#include <stdio.h>

int main() {
    int row, sum, col;
    int a[101][6];
    for (row=0; row<100; row++) {
    // 低效率：长循环在最外层
        for ( col=0; col<5; col++ ) {
            sum = sum + a[row][col];
        }
    }

    for (col=0; col<5; col++ ) {
        // 高效率：长循环在最内层
        for (row=0; row<100; row++) {
            sum = sum + a[row][col];
        }
    }


}