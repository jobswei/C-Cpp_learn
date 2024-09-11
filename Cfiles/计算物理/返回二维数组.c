#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define  N 5
 
double** Link(double a, double b, double c, double d)
{
	double** T = NULL;
	T = (double**)malloc(sizeof(double*)*N);
	if (NULL == T)
		return NULL;
	// 定义一个二维数组，为了给要返回的T 初始化，要不然后面直接赋值会出错
	double B[N][N] = { 0 };
	for (int i = 0; i < N; i++)
	{
		T[i] = (double*)malloc(sizeof(double) * N);
		if (NULL == T[i])
			return NULL;
		for (int j = 0; j < N; j++)
		{
			T[i][j] = 0;
		}
	}
        // 给二维数组赋值
	T[0][0] = a;
	T[0][1] = b; 
	T[0][2] = c;
	T[0][3] = d;
	T[1][0] = a;
	T[1][1] = b;
	T[1][2] = c;
	T[1][3] = d;
	T[2][0] = a;
	T[2][1] = b;
	T[2][2] = c;
	T[2][3] = d;
	T[3][0] = a;
	T[3][1] = b;
	T[3][2] = c;
	T[3][3] = d;
        // 返回二维数组
	return T;
}
 
int main()
{
        // 下面的T1 T2两种写法都可以 T2的写法要进行判空
	double** T1 = NULL;    
	double** T2 = (double**)malloc(sizeof(double*)*N);
        // 判空
	if (NULL == T2)
		return 0;
	T2 = Link(0, 0.2, 0.2, 0);
	T1 = Link(0, 0.2, 0.2, 0);
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%0.1f\t", T2[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}