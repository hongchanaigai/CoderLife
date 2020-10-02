1. �г�����ṹ������ļ��ַ�����

	//1) �ȶ�������,�ٶ������
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

	//2) �������͵�ͬʱ,�������
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


2. ͬ���ͽṹ������Ƿ�����໥��ֵ�������ʲô���գ�
	//���Ի��ำֵ,���ܻ����ǳ����,�������,��ɳ������
	//�ṹ���໥��ֵ,ֻ�ǰ��ڴ濽��һ��,��ǳ����
	//���,��Ϊ�����ڴ�,���¿���һ��

3. ��ϰ�ṹ���������򡡡� 
	�Ӽ�������3��ѧ������Ϣ��������ѧ�š��ɼ���������һ���ṹ�������У�����ƽ���֣������ɼ�
	�ߵ��������
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

		//�Ӽ�������ѧ����Ϣ
		initStu(s, n); 

		//aveStu(s, 3)��ƽ����
		printf("\nƽ����Ϊ�� %lf\n",  aveStu(s, n) );

		//�������򣬽���
		sortStu(s, n);

		//��ӡѧ����Ϣ
		showStu(s, n);

		return 0;
	}


4. ��д�ṹ��Ƕ��һ��ָ����ʦ�Ͷ���ָ��ѧ���Ĵ���
	
    //�ṹ�����ͣ�ÿ����ʦ������ѧ��
	typedef struct Teacher
	{
		char *tName; //��ʦ
		char **stu;  //����ѧ��
		int age;
	}Teacher;
	
	//��createTeacher�з���ռ�
	int createTeacher(Teacher **p/*out*/, int n1, int n2);
	
	//����Ա��ֵ
	void initTeacher(Teacher *p, int n1, int n2);
	
	//��ӡ�ṹ���Ա��Ϣ
	void printTeacher(Teacher *p, int n1, int n2);
	
	
	//���ݵ�ʦ��������, ����
	void sortTeacher(Teacher *p, int n);
	
	
	//�ͷſռ䣬�ں����ڲ���p��ֵΪNULL
	void freeTeacher(Teacher **p, int n1, int n2);
	
	int main(void)
	{
		int ret = 0;
		int n1 = 3; //��ʦ����
		int n2 = 3; //ѧ��
		Teacher *p = NULL;

		ret = createTeacher(&p, n1, n2);
		if (ret != 0)
		{
			printf("createTeacher err:%d\n", ret);
			return ret;
		}

		initTeacher(p, n1, n2); //����Ա��ֵ

		//��ӡ��Ա������ǰ
		printf("����ǰ��\n");
		printTeacher(p, n1, n2);


		//���ݵ�ʦ��������, ����
		sortTeacher(p, n1);

		//��ӡ��Ա�������
		printf("\n�����\n");
		printTeacher(p, n1, n2);

		//�ͷſռ䣬�ں����ڲ���p��ֵΪNULL
		freeTeacher(&p, n1, n2);
		
		return 0;
	}


5. ��һ�µ�4��createTeacher()���ڴ�����ͼ

6. �������½ṹ����ռ�ռ��С
	typedef struct Stu
	{
		char a[4];
		int b;
		double c;
		short d;
	}Stu;
	
	#pragma pack(1)     //1�ֽڶ���	4+4+8+2 = 18
	#pragma pack(2)     //2�ֽڶ���	4+4+8+2 = 18
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
	
	#pragma pack(4)     //4�ֽڶ���	4+4+8+4 = 20
	/*
	a a a a 
	b b b b
	c c c c
	c c c c
	d d * * 
	*/
	
	#pragma pack(8)     //8�ֽڶ���	4+4+8+8 = 24
	/*
	a a a a b b b b
	c c c c c c c c 
	d d * * * * * *
	*/
	
	#pragma pack(16)    //16�ֽڶ���	4+4+8+8 = 24
	/*
	������������Ϊdouble,ռ8�ֽ�,���Ի�����8�ֽڶ���
	a a a a b b b b
	c c c c c c c c
	d d * * * * * *
	*/


