1. ����ָ�����������ָ�������?
	1) //ָ������: ��������,ÿ��Ԫ����һ��ָ������
	2) //����ָ��: ����ָ��,ָ�������ָ�����

2. ��ζ���һ��ָ�� int a[10] ���͵�ָ�����������ָ�룩��ʹ��3�ַ�������
	1) //�ȶ�������,�ٸ������鶨������ָ�����
		int a[10];
		typedef int A[10];
		A* pa;
		pa = &a;
	2) //ֱ�Ӷ�������ָ������
		int a[10];
		int(*pa)[10];
		pa = &a;
	3) //�ȶ�������ָ������,�ٶ�������ָ�����
		int a[10];
		typedef int(*A)[10];
		A pa;
		pa = &a;

3. 
	int a[10];
	int b[5][10];
	int (*p)[10];
	p = &a;	//Ϊ�μ� &
	//aһά����,&��������һά����ĵ�ַ
	p = b;	//Ϊ�β��ü� & 
	//b�Ƕ�ά����,b����ľ���һά����ĵ�ַ
	
4. int a[3][5] = { 0 };
	//a -> a + 0		     
	//a + i				     
	//*(a+i) -> a[i]		 
	//*(a+i)+j -> &a[i][j]   
	//*(*(a+i)+j ) -> a[i][j]
	

5. �����ջ�Ͽ���һ����ά���飬����ڶ��Ͽ���һ����ά���飿
	//ջ��
	int a1[2][3] = { 
		{1, 2, 3}, 
		{4, 5, 6} 
	};
	int a2[2][3] = { 1, 2, 3, 4, 5, 6 };
	int a3[][3] = { 1, 2, 3, 4, 5, 6 };
	
	//����
	int** b;
	b = (int**)malloc(2 * sizeof(int*));
	for(int i = 0; i < 2; ++i)
	{
		*(b + i) = (int*)malloc(3 * sizeof(int));
	}


6. int main(int argc, char *argv[]);
	argc, argv�ֱ����ʲô��
	//argc: �����������
	//argv: ����Ĳ���


7. �ҵ�������ָ���ַ�����λ��
#define NUM(a) (sizeof(a)/sizeof(*a))

char* keywords[] = {
	"while", 
	"case",
	"static",
	"do"
};

int searcheKeyTable(const char* table[], const int size, 
			  const char* key, int *pos);
				  
8. ���ַ��������������

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
