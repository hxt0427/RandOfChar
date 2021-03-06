// Rand of Char.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <stdio.h>  
#include <stdlib.h>
#include <time.h>

int Count(char c[][100], int num[],int n) {
	int count = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < num[i]; j++)
			if (c[i][j] == 'A')
				count++;
	return count;
}

int main()
{
	char cc1[100000][100],cc2[1000000][100];
	int num1[100000],num2[1000000];
	clock_t c1, c2;
	for (int i = 0; i < 100000; i++)
		num1[i] = 0;
	for (int i = 0; i < 1000000; i++)
		num2[i] = 0;
	for(int i = 0 ; i < 100000 ; i ++)
		for (int j = 0 ; j < rand() % 100; j++) {
			if (rand() % 2)
				cc1[i][j] = rand() % 26 + 'a';
			else
				cc1[i][j] = rand() % 26 + 'A';
			num1[i]++;
		}
	for (int i = 0; i < 1000000; i++)
		for (int j = 0; j < rand() % 100; j++) {
			if (rand() % 2)
				cc2[i][j] = rand() % 26 + 'a';
			else
				cc2[i][j] = rand() % 26 + 'A';
			num2[i]++;
		}
	c1 = clock();
	int count = Count(cc1, num1, 100000);
	printf("100,000个字符串中A的个数%d\n", count);
	c2 = clock();
	printf("测量100,000个字符串统计所需时间:%d ms\n", c2 - c1);
	c1 = clock();
	count = Count(cc2, num2, 1000000);
	printf("1,000,000个字符串中A的个数%d\n", count);
	c2 = clock();
	printf("测量1,000,000个字符串统计所需时间:%d ms\n", c2 - c1);
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
