#include<iostream>
#include<stdlib.h>
using namespace std;

// pa 指向a地址的指针  pa = &a （pa是一个指向地址的指针）
void swap_int(int* pa, int* pb)
{
    printf("swap_int打印a b 地址:a=%p,b=%p\n", pa, pb);
    int* temp = pa;
    pa = pb;
    pb = temp;
    printf("swap_int打印a b 地址:*a=%d,*b=%d\n", *pa, *pb);
}

// 参数  引用方式 会改变传入变量的值
void swap_int_ref(int& ra, int& rb)
{
    printf("swap_int_ref打印pa rb 地址:pa=%p,rb=%p\n", &ra, &rb);
    int temp = ra;
    ra = rb;
    rb = temp;
    printf("swap_int_ref打印pa rb 地址:pa=%d,rb=%d\n", ra, rb);
}
// 这里 p是一个指针 和传参的指针的值一样（是一个地址）
void test(int* p)
{
    if (p != NULL) {
        printf("test p=%p,*p=%d\n", p, *p);
    }
    else {
        cout << "test 指针p为NULL" << endl << endl;
    }
    int a = 2;
    p = &a;
    printf("test p=%p,*p=%d\n", p, *p);
}

void pointers_references(void)
{
    // 指针是  T* 指向T类型地址的变量
    int i1 = 1;
    int* p1 = &i1;
    printf("p1=%p,&i1=%p, *p1=%d\n", p1, &i1, *p1); // p1==&i1   *p1=i
    // 引用 是一个对象的别名
    int i2 = 1;
    int j2 = 2;
    int& ri2 = i2;   // r和i 指向同一个变量
    printf("i r地址相同 : &i=%p,&r=%p\n", &i2, &ri2);
    printf("i r值相等:i=%d,r=%d\n", i2, ri2);
    int x = ri2;    // x=2
    ri2 = 11;        // i=2
    int* p2 = &ri2;    // p指向r

    int* pi2 = &i2;     // 指针ri2是i2的地址
    int* pj2 = &j2;     // 指针rj2是j2的地址
    // 这里替换的只是 ri2 rj2两个指针的值 和swap_int 函数一样
    int* temp = pi2;
    pj2 = pi2;
    pj2 = temp;

    // 参数应用修改数值
    int a = 1, b = 2;
    printf("        打印a b 地址:&a=%p,&b=%p\n", &a, &b); 
    swap_int(&a, &b);       // a b 不受影响
    printf("a=%d,b=%d\n\n",a, b);

    swap_int_ref(a, b);     // a b 的值交换了
    printf("\n        打印a b 地址:&a=%p,&b=%p\n", &a, &b);


    int * p4 = NULL;
    test(p4);
    if (p4 == NULL)
        cout << "指针p4为NULL" << endl << endl;

    int a1 = 1;
    p4 = &a1;
    test(p4);
    if (p4 == NULL)
        cout << "指针p4为NULL" << endl << endl;
    else {
        printf("p4=%p,*p4=%d\n", p4, *p4);  // 没有改变P4的值
    }

    system("pause");
}
