//��ֹͷ�ļ��ظ�����
#pragma once

//����C++������
#ifdef __CPLUSPLUS
	extern "C" {
#endif // __CPLUSPLUS


	//����������

	//�������ļ�
	int readCfgFile(char* fileName, char* pKey, char* pValue, int* pLen);

	//д���޸������ļ�
	int writeCfgFile(char* fileName, char* pKey, char* pValue, int len);

#ifdef __CPLUSPLUS
	}
#endif // __CPLUSPLUS
