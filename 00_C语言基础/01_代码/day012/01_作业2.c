/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-07 15:32
 * Last modified  : 2020-08-07 15:32
 * Filename       : 01_作业2.c
 * Description    : 
 * *******************************************************/
#include <stdio.h> //fflush()
#include <time.h> //time()
#include <unistd.h> //sleep()

typedef struct Time
{//表示时间的数据类型
	int hour;
	int minute;
	int second;
}Time;

int main()
{
	Time m_data;
	
	m_data.hour = 10;
	m_data.minute = 00;
	m_data.second = 00;

	printf("the time is: \n");

	while(1)
	{
		sleep(1); //一秒执行一次
		++m_data.second;
		if(m_data.second >= 60)
		{
			m_data.second = 0;

			++m_data.minute;
			if(m_data.minute >= 60)
			{
				m_data.minute = 0;

				++m_data.hour;
				if(m_data.hour >= 24)
				{
					m_data.hour = 0;
				}
			}
		}
		printf("\r%02d:%02d:%02d", m_data.hour, m_data.minute, m_data.second);
		fflush(stdout); //不用等待缓冲区满,立即输出到屏幕
	}

	return 0;
}
