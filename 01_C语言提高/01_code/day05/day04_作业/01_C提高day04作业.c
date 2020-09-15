1. 简述指针数组和数组指针的区别?
	1) //指针数组: 它是数组,每个元素是一个指针类型
	2) //数组指针: 它是指针,指向数组的指针变量

2. 如何定义一个指向 int a[10] 类型的指针变量（数组指针）（使用3种方法）？
	1) //先定义数组,再根据数组定义数组指针变量
		int a[10];
		typedef int A[10];
		A* pa;
		pa = &a;
	2) //直接定义数组指针类型
		int a[10];
		int(*pa)[10];
		pa = &a;
	3) //先定义数组指针类型,再定义数组指针变量
		int a[10];
		typedef int(*A)[10];
		A pa;
		pa = &a;

3. 
	int a[10];
	int b[5][10];
	int (*p)[10];
	p = &a;	//为何加 &
	//a一维数组,&才是整个一维数组的地址
	p = b;	//为何不用加 & 
	//b是二维数组,b代表的就是一维数组的地址
	
4. int a[3][5] = { 0 };
	//a -> a + 0		     
	//a + i				     
	//*(a+i) -> a[i]		 
	//*(a+i)+j -> &a[i][j]   
	//*(*(a+i)+j ) -> a[i][j]
	

5. 如何在栈上开辟一个二维数组，如何在堆上开辟一个二维数组？
	//栈上
	int a1[2][3] = { 
		{1, 2, 3}, 
		{4, 5, 6} 
	};
	int a2[2][3] = { 1, 2, 3, 4, 5, 6 };
	int a3[][3] = { 1, 2, 3, 4, 5, 6 };
	
	//堆上
	int** b;
	b = (int**)malloc(2 * sizeof(int*));
	for(int i = 0; i < 2; ++i)
	{
		*(b + i) = (int*)malloc(3 * sizeof(int));
	}


6. int main(int argc, char *argv[]);
	argc, argv分别代表什么？
	//argc: 传入参数个数
	//argv: 传入的参数


7. 找到数组中指定字符串的位置
#define NUM(a) (sizeof(a)/sizeof(*a))

char* keywords[] = {
	"while", 
	"case",
	"static",
	"do"
};

int searcheKeyTable(const char* table[], const int size, 
			  const char* key, int *pos);
				  
8. 将字符串数组进行排序

int sort(char **array1, int num1,
         char (*array2)[30], int num2, 
         char ***myp3 /*out*/, int *num3);

int  main()
{
    int ret = 0; 
    char *p1[] = {"aa", "ccccccc", "bbbbbb"};
    char buf2[10][30] = {"111111", "3333333", "222222"};
    char **p3 = NULL;   
    int len1, len2, len3, i = 0;
                            
    len1 = sizeof(p1)/sizeof(*p1);
    len2 = 3;
                                    
    ret = sort(p1, len1, buf2, len2, &p3, &len3);

    return 0;
}
