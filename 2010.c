#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>

void func8() {//求 sum(n!+3) n=1 to 10
	double s = 0, t = 1, sum = 0;
	int n;
	for (n = 1;n <= 10;n++)
	{
		t = t * n;
		s = s + t;
		sum = s + 3;
	}
	printf("1!+3+2!+3...+10!+3=%f\n", s);
}

void func8_repair() {//求 sum(n!+3) n=1 to 10
	int t = 1, sum = 0;
	int n;
	for (n = 1;n <= 10;n++)
	{
		t = t * n;
		sum += t + 3;
	}
	printf("1!+3+2!+3...+10!+3=%d\n", sum);
}

//13. 输入 10 个整型整数，用起泡法对这 10 个数排序，并该由小到大顺序在屏幕上输出。
void func13()//这tm根本不是冒泡排序算法
{
	int a[10];
	int i, j, t;
	printf("input 10 number:\n");
	for (i = 0;i < 10;i++)
		scanf("%d", &a[i]);
	for (i = 0;i < 10;i++)
		for (j = i;j < 9;j++)
			if (a[i] > a[j + 1]) {
				t = a[i];
				a[i] = a[j + 1];
				a[j + 1] = t;
			};
	for (i = 0;i < 10;i++)
		printf("%5d ", a[i]);
	printf("\n");
}

void func13_repair()
{
	int a[10];
	int i, j, t;
	printf("input 10 number:\n");
	for (i = 0;i < 10;i++)
		scanf("%d", &a[i]);
	for (i = 9;i > 0;i--)
		for (j = 0;j < i;j++)
			if (a[j] > a[j + 1]) {
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			};
	for (i = 0;i < 10;i++)
		printf("%5d ", a[i]);
	printf("\n");
}


//14. 将一个二维数组 a 的行和列的元素互换（即行列互换），存到另一个二维数组 b 中。
void func14()//这题代码没错
{
	int a[4][5], b[5][4];
	int i, j;
	for (i = 0;i < 4;i++)
		for (j = 0;j < 5;j++)
			scanf("%d", &a[i][j]);
	for (i = 0;i < 5;i++)
		for (j = 0;j < 4;j++)
			b[i][j] = a[j][i];
	printf("该数组的新序列为：\n");
	for (i = 0;i < 5;i++)
	{
		for (j = 0;j < 4;j++)
			printf("%5d", b[i][j]);
		printf("\n");
	}
}

void func14_repair()//这题代码没错，只是为了学习二重指针的用法
{
	int n, m;
	int **a, **b;
	int i, j;
	printf("请输入矩阵 行数 列数 及数据\n");
	scanf("%d%d", &n, &m);

	a = (int**)malloc(sizeof(int*)*n);
	for (i = 0;i < n;i++)
		a[i] = (int*)malloc(sizeof(int)*m);

	b = (int**)malloc(sizeof(int*)*m);
	for (i = 0;i < m;i++)
		b[i] = (int*)malloc(sizeof(int)*n);

	for (i = 0;i < n;i++)
		for (j = 0;j < m;j++)
			scanf("%d", &a[i][j]);
	for (i = 0;i < m;i++)
		for (j = 0;j < n;j++)
			b[i][j] = a[j][i];
	printf("该数组的新序列为：\n");
	for (i = 0;i < m;i++)
	{
		for (j = 0;j < n;j++)
			printf("%5d", b[i][j]);
		printf("\n");
	}

	for (int i = 0;i < n;i++) {
		free(a[i]);
		a[i] = NULL;
	}
	free(a);
	a = NULL;

	for (int i = 0;i < m;i++) {
		free(b[i]);
		b[i] = NULL;
	}
	free(b);
	b = NULL;
}

//17. 有 3 个字符串，要求找出其中最大者。

void func17()//无语
{
	char str1[80], str2[80], str3[80], longest[80];
	gets(str1);
	printf("\n");
	gets(str2);
	printf("\n");
	gets(str3);
	strcpy(longest, str1);
	if (strcmp(str1, str2) < 0)
		strcpy(longest, str1);
	if (strcmp(str2, str3) < 0)
		strcpy(longest, str1);
	printf("the longest is %s", longest);
}

void func17_repair()
{
	char str1[80], str2[80], str3[80], largest[80];
	gets(str1);
	gets(str2);
	gets(str3);
	strcpy(largest, str1);
	if (strcmp(largest, str2) < 0)
		strcpy(largest, str2);
	if (strcmp(largest, str3) < 0)
		strcpy(largest, str3);
	printf("the largest is %s", largest);
}

////{定义题} 函数嵌套： 在一个函数中 调用 另一个函数


//25. 用指针实现输入 3 个整数并按从小到大的顺序输出。
//----------
void func25()//指针是对的，输入有点小麻烦。{这题代码没错,且值得学习，指针的操作都忘光了}
{
	void exchange(int * p1, int * p2, int * p3);
	int n1, n2, n3;
	int * p1, *p2, *p3;
	printf("input three integer n1,n2,n3:");
	scanf("%d,%d,%d", &n1, &n2, &n3);
	p1 = &n1; p2 = &n2;p3 = &n3;
	exchange(p1, p2, p3);
	printf("Now,the order is:%d,%d,%d", n1, n2, n3);
}
void exchange(int * p1, int * p2, int * p3)
{
	void swap(int * p1, int * p2);
	if (*p1 > * p2)
		swap(p1, p2);
	if (*p1 > * p3)
		swap(p1, p3);
	if (*p2 > * p3)
		swap(p2, p3);
}
void swap(int * p1, int * p2)
{
	int p;
	p = *p1;*p1 = *p2;*p2 = p;
}
//-------------


//29.这是把冒泡排序和选择排序记混了吧


//39. 找出一个2维数组中的鞍点，即该位置上的元素在该行上最大、在该列上最小。
void func39()//for玩疯了吧，完全不知道它在搞啥...
{
	int a[4][5];
	int i, j, k, m;
	for (i = 0;i < 4;i++)
		for (j = 0;j < 5;j++)
			scanf("%d", &a[i][j]);
	for (i = 0;i < 4;i++)
		for (j = 0;j < 5;j++)
			for (m = 0;m < 4;m++)
				if (a[i][j] < a[m][j])
					for (k = 0;k < 5;k++)
						if (a[i][j] > a[i][k])
							for (k = 0;k < 5;k++)
								if (a[i][j] > a[i][k]) 
									continue;
	printf("i=%d,j=%d", i, j);
}

void func39_repair()
{
	int a[4][5], finded = 0;
	int i, j, k;
	for (i = 0;i < 4;i++)
		for (j = 0;j < 5;j++)
			scanf("%d", &a[i][j]);
	for (i = 0;i < 4;i++) {
		k = 0;
		for (j = 1;j < 5;j++) {
			if (a[i][j] > a[i][k])
				k = j;//找出i行最大值
		}
		finded = 1;
		for (j = 0;j < 4;j++) {//判断其是否为该列最小
			if (a[j][k] < a[i][k])
				finded = 0;
		}
		if (finded) {
			j = k;
			break;
		}
	}
	if (finded)
		printf("i=%d,j=%d\n", i, j);
	else
		puts("no andian finded");
}


int main() {
	func39_repair();
	return 0;
}
