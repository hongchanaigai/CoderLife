/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-07 16:52
 * Last modified  : 2020-08-07 16:52
 * Filename       : 02_标准文件指针.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>
#include <unistd.h> //close()
#include <sys/types.h> //open()
#include <sys/stat.h> //open()
#include <fcntl.h> //open()

int main()
{
	//printf函数的内部实现,往标准输出设备(1)写内容
	printf("before aaaaaaaaaaaaaaaaaaa\n");
	//fclose(stdout);
	close(1); //1代表是标准输出设备,关闭了,1就是空闲的数字

	int fd = open("02.txt", O_WRONLY, 0777);
	//printf函数的内部实现,往(1)写内容,但是(1)现在和02.txt关联,printf的内容写到02.txt文件
	printf("fd = %d\n", fd);

	printf("after bbbbbbbbbbbbbbbbbbbb\n");
	printf("after cccccccccccccccccccc\n");
	printf("after dddddddddddddddddddd\n");

	return 0;
}

int main01()
{
	printf("before aaaaaaaaaaaaaaaaaaa\n");
	fclose(stdout);

	stdout = fopen("./02.txt", "w");
	if(stdout == NULL)
	{
		printf("fopen ");
		return -1;
	}
	printf("after bbbbbbbbbbbbbbbbbbbb\n");

	return 0;
}

int main00()
{
	printf("aaaaaaaaaaaaaaaaa\n");
	//fclose(stdout); //关闭标准输出文件指针
	printf("bbbbbbbbbbbbbbbbb\n");

	//打印库函数调用失败的原因
	perror("huang");
	fclose(stderr); //关闭标准错误文件指针
	perror("huang2");

	int a;
	printf("please input a: ");
	fclose(stdin); //关闭标准输入文件指针
	scanf("%d", &a);
	printf("a = %d\n", a);

	return 0;
}
