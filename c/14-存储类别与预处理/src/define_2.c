#define R  3.0
#define PI 3.14
#define L  2*PI*R
#define S  PI*R*R

int main ()
 {
    printf("%f", PI);
    return 0;
}
#undef PI
void test()
{
    // printf("%f", PI); // 不能使用
}
