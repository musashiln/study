typedef int Integer;

typedef Integer MyInteger;

typedef char NAME[20]; // 表示NAME是字符数组类型,数组长度为20。然后可用NAME 说明变量,

struct Person{
    int age;
    char *name;
};

typedef struct Person PersonType;

typedef struct Person1{
    int age;
    char *name;
} PersonType1;

typedef struct {
    int age;
    char *name;
} PersonType2;

enum Sex{
    SexMan,
    SexWoman,
    SexOther
};
typedef enum Sex SexType;

typedef enum Sex{
    SexMan,
    SexWoman,
    SexOther
} SexType;

typedef enum{
    SexMan,
    SexWoman,
    SexOther
} SexType;

 // 定义一个结构体并起别名
  typedef struct {
      float x;
      float y;
  } Point;

 // 起别名
 typedef Point *PP;

// 定义一个sum函数，计算a跟b的和
  int sum(int a, int b) {
      int c = a + b;
      printf("%d + %d = %d", a, b, c);
      return c;
 }
 typedef int (*MySum)(int, int);

// 定义一个指向sum函数的指针变量p
 MySum p = sum;
