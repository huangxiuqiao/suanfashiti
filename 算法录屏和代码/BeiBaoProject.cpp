// �õݹ��㷨���ά������������ 


#include "stdafx.h"
#include<iostream>
#include <stdio.h>
#include <stdlib.h>


int array[64][6];//��ѡ��Ʒ���м���
int value[] = { 100, 600, 1200, 2400, 500, 2000 };//����6����Ʒ�ļ۸�
//������ƷԼ������
int require[10][6] = { { 8,12,13,64,22,41 },//��Ʒ��1������ 
                      { 8, 12, 13, 75 ,22 ,41 },//��Ʒ��2������ 
                      { 3, 6, 4, 18 ,6, 4 } ,//��Ʒ��13������ 
                      { 5, 10, 8, 32, 6, 12 },//��Ʒ��4������ 
                      { 5, 13, 8, 42, 6 ,20 },//��Ʒ��5������ 
                      { 5, 13, 8, 48, 6, 20 },//��Ʒ��6������ 
                      { 0, 0, 0,0, 8,0 },//��Ʒ��7������ 
                      { 3, 0, 4,0, 8,0 },//��Ʒ��8������ 
                      { 3, 2, 4,0, 8,4 },//��Ʒ��9������ 
                      { 3, 2, 4,8, 8,4 } };//��Ʒ��10������ 
int YueShu[] = { 80, 96 ,20, 36 ,44 ,48 ,10 ,18, 22, 24 };//����Լ������

int x[] = { 0,0,0,0,0,0 };//�������Ž�����
int result[10] = { 0,0,0,0,0,0,0,0,0,0 };//�����м����
int outArry[6] = { 0,0,0,0,0,0 };//�����м��������
int MaxValue = 0;//��߼۸����Ž�
int max(int a, int b);//�����������ֵ
int* IntToBiary(int num);//��ʼ�� 
void createArray();//������Ʒ���м���
void ClearArray(void);//��ջ���

int main()
{
	createArray();
	for (int i = 0; i < 64;i++)
	{
		int sumValue = 0;//�����ܼ۸� 
		ClearArray();
		int n = 0;
		for (int j = 0; j < 10;j++)
		{
			for (int k = 0; k < 6;k++)
			{
				if (array[i][k] == 1)
				{
					result[j] += require[j][k];
				}
				else if (array[i][j] == 0)
				{
					result[j] += 0;
				}
			}
		}
		if (result[0] < YueShu[0] &&
			result[1] < YueShu[1] &&
			result[2] < YueShu[2] &&
			result[3] < YueShu[3] &&
			result[4] < YueShu[4] &&
			result[5] < YueShu[5] &&
			result[6] < YueShu[6] &&
			result[7] < YueShu[7] &&
			result[8] < YueShu[8] &&
			result[9] < YueShu[9]
			)
		{
			for (int k = 0;k < 6;k++)
			{
				if (array[i][k] == 1)
				{
					sumValue += value[k];
					outArry[k] = 1;
				}
				else
				{
					outArry[k] = 0;
				}
			}
		}
		else
		{
			sumValue = 0;
		}
		if (MaxValue < sumValue)
		{
			MaxValue = sumValue;
			x[0] = outArry[0];
			x[1] = outArry[1];
			x[2] = outArry[2];
			x[3] = outArry[3];
			x[4] = outArry[4];
			x[5] = outArry[5];
		}
	}
	printf("��Ʒ�ļ۸�Ϊ��\n");
	for (int i = 0;i < 6;i++)
	{
		printf("  %d\n",value[i]);
	}

	printf("���Ž�Ϊ��%d %d %d %d %d %d \n", x[0], x[1], x[2], x[3], x[4], x[5]);
	MaxValue = 0;

	printf("���Ž�ļ۸�ֱ�Ϊ��\n");
	for (int i = 0;i < 6;i++)
	{
		if (x[i] == 1)
		{
			printf("  %d  ", value[i]);
			MaxValue += value[i];
		}
	}
	printf("���Ž���Ϊ��%d \n", MaxValue);
	system("pause");
	return 0;
}

int* IntToBiary(int num)
{
	int b[16];
	char* arrory = "";
	int n = 0;
	for (int n = 0; num; num >>= 1, n++)
	{
		b[n] = num & 1;
	}
	return b;
}

void createArray()
{
	int b = 0;
	memset(array, 0, sizeof(array));
	for (int i = 0;i < 64;i++)
	{
		for (int j = 5, k = 0; j >= 0, k < 6;j--, k++)
		{
			int* arr = IntToBiary(i);
			array[i][j] = arr[k];
		}
	}

	for (int i = 0;i < 64;i++)
	{
		for (int j = 0; j < 6;j++)
		{
			if (array[i][j] != 1)
			{
				array[i][j] = 0;
			}
		}
	}
}



int max(int a, int b)
{

	if (a>b)

		return a;
	else

		return b;
}

void ClearArray(void)
{
	result[0] = 0;
	result[1] = 0;
	result[2] = 0;
	result[3] = 0;
	result[4] = 0;
	result[5] = 0;
	result[6] = 0;
	result[7] = 0;
	result[8] = 0;
	result[9] = 0;
	result[10] = 0;

	outArry[0] = 0;
	outArry[1] = 0;
	outArry[2] = 0;
	outArry[3] = 0;
	outArry[4] = 0;
	outArry[5] = 0;
}
