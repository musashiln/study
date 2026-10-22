#include <stdio.h>
int main(){
    // ()优先级高, 先计算()里面的内容
    // 10==10为真, 所以result = !(1);
    // !代表真变假, 假变真,所以结果是假0
    int result = !(10 == 10);
    printf("result = %i\n", result); // 0
}
