typedef int(A)[10];	//A: 数组类型
A a;	//int a[10];	数组类型变量,普通变量
A* pa;	//数组类型定义数组指针变量

typedef int(*P)[10];	//数组指针类型
P p;	//数组指针变量

int(*ptr)[10];	//数组指针变量