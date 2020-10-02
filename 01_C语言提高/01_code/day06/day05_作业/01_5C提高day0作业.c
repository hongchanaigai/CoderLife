1. 列出定义结构体变量的几种方法。

	//1) 先定义类型,再定义变量
	struct MyStruct1
	{
		int a1;
		int b1;
	};

	struct MyStruct1 ms1;

	typedef struct MyStruct2
	{
		int a2;
		int b2;
	}MyStruct2;

	MyStruct2 ms2;

	//2) 定义类型的同时,定义变量
	struct MyStruct3
	{
		int a3;
		int b3;
	}ms3;

	struct
	{
		int a4;
		int b4;
	}ms4;


2. 同类型结构体变量是否可以相互赋值？会存在什么风险？
	//可以互相赋值,可能会出现浅拷贝,深拷贝问题,造成程序崩溃
	//结构体相互赋值,只是把内存拷贝一份,是浅拷贝
	//深拷贝,人为增加内存,重新拷贝一份

3. 练习结构体数组排序　　 
	从键盘输入3个学生的信息（姓名、学号、成绩），存入一个结构体数组中，计算平均分，并按成绩
	高低排序并输出
	typedef struct Stu
	{
		char name[50];
		int id;
		double score;
	}Stu;
	
	int main(void)
	{
		Stu s[3];
		int n = 3;

		//从键盘输入学生信息
		initStu(s, n); 

		//aveStu(s, 3)：平均分
		printf("\n平均分为： %lf\n",  aveStu(s, n) );

		//分数排序，降序
		sortStu(s, n);

		//打印学生信息
		showStu(s, n);

		return 0;
	}


4. 重写结构体嵌套一级指针老师和二级指针学生的代码
	
    //结构体类型，每个导师有三个学生
	typedef struct Teacher
	{
		char *tName; //导师
		char **stu;  //三个学生
		int age;
	}Teacher;
	
	//在createTeacher中分配空间
	int createTeacher(Teacher **p/*out*/, int n1, int n2);
	
	//给成员赋值
	void initTeacher(Teacher *p, int n1, int n2);
	
	//打印结构体成员信息
	void printTeacher(Teacher *p, int n1, int n2);
	
	
	//根据导师名字排序, 降序
	void sortTeacher(Teacher *p, int n);
	
	
	//释放空间，在函数内部把p赋值为NULL
	void freeTeacher(Teacher **p, int n1, int n2);
	
	int main(void)
	{
		int ret = 0;
		int n1 = 3; //导师个数
		int n2 = 3; //学生
		Teacher *p = NULL;

		ret = createTeacher(&p, n1, n2);
		if (ret != 0)
		{
			printf("createTeacher err:%d\n", ret);
			return ret;
		}

		initTeacher(p, n1, n2); //给成员赋值

		//打印成员，排序前
		printf("排序前：\n");
		printTeacher(p, n1, n2);


		//根据导师名字排序, 降序
		sortTeacher(p, n1);

		//打印成员，排序后
		printf("\n排序后：\n");
		printTeacher(p, n1, n2);

		//释放空间，在函数内部把p赋值为NULL
		freeTeacher(&p, n1, n2);
		
		return 0;
	}


5. 画一下第4题createTeacher()的内存四区图

6. 分析以下结构体所占空间大小
	typedef struct Stu
	{
		char a[4];
		int b;
		double c;
		short d;
	}Stu;
	
	#pragma pack(1)     //1字节对齐	4+4+8+2 = 18
	#pragma pack(2)     //2字节对齐	4+4+8+2 = 18
	/*
	a a
	a a
	b b
	b b
	c c
	c c
	c c 
	c c
	d d
	*/
	
	#pragma pack(4)     //4字节对齐	4+4+8+4 = 20
	/*
	a a a a 
	b b b b
	c c c c
	c c c c
	d d * * 
	*/
	
	#pragma pack(8)     //8字节对齐	4+4+8+8 = 24
	/*
	a a a a b b b b
	c c c c c c c c 
	d d * * * * * *
	*/
	
	#pragma pack(16)    //16字节对齐	4+4+8+8 = 24
	/*
	最大的数据类型为double,占8字节,所以还是以8字节对齐
	a a a a b b b b
	c c c c c c c c
	d d * * * * * *
	*/


