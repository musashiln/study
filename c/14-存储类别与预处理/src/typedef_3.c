typedef char *String1; // 给char *起了个别名String1
#define String2 char * // 定义了宏String2
int main(int argc, const char * argv[]) {
        /*
        只有str1、str2、str3才是指向char类型的指针变量
        由于String1就是char *，所以上面的两行代码等于:
        char *str1;
        char *str2;
        */
      String1 str1, str2;
        /*
        宏定义只是简单替换, 所以相当于
        char *str3, str4;
        *号只对最近的一个有效, 所以相当于
        char *str3;
        char str4;
        */
      String2 str3, str4;
      return 0;
}
