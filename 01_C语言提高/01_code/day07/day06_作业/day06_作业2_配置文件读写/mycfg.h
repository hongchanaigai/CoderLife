//防止头文件重复包含
#pragma once

//兼容C++编译器
#ifdef __CPLUSPLUS
	extern "C" {
#endif // __CPLUSPLUS


	//函数的声明

	//读配置文件
	int readCfgFile(char* fileName, char* pKey, char* pValue, int* pLen);

	//写、修改配置文件
	int writeCfgFile(char* fileName, char* pKey, char* pValue, int len);

#ifdef __CPLUSPLUS
	}
#endif // __CPLUSPLUS
