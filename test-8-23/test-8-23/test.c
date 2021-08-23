#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int f(int x)
//{
//	return ((x > 2) ? x * f(x - 1) : 3);
//}
//int main()
//{
//	int i;
//	i = f(f(2));
//	printf("%d\n", i);//9
//	return 0;
//}

//int fun(int a)
//{
//	a ^= (1 << 5) - 1;
//	return a;
//}
//int main()
//{
//	int ret = fun(21);
//	printf("%d\n", ret);
//	return 0;
//}
//21^(1 << 5) - 1
//00000000 00000000 00000000 00010101 - 21 原反补相同
//00000000 00000000 00000000 00011111
//00000000 00000000 00000000 00001010 -10

//#define N 3+1
//#define Y(n) ((N + 1) * n)
//int main()
//{
//	int z = 2 * (N + Y(5 + 1));
//	printf("%d\n", z);//60
//	return 0;
//}
//2 * ( 3 + 1 + ((3 + 1 + 1) * 5 + 1))
//2*(4+25+1)
//2*30 = 60

//求一个数N成为斐波那契数的最小步数
//#include<math.h>
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	int f1 = 0;
//	int f2 = 1;
//	int f3 = 0;
//	while (1)
//	{
//		if (n == f2)
//		{
//			printf("%d\n", 0);
//			break;
//		}
//		else if (n < f2)
//		{
//			if (abs(f1 - n) < abs(f2 - n))
//				printf("%d\n", abs(f1 - n));
//			else
//				printf("%d\n", abs(f2 - n));
//
//			break;	
//		}
//
//
//		f3 = f1 + f2;//斐波那契数列的非递归实现方式
//		f1 = f2;
//		f2 = f3;
//	}
//	return 0;
//}
#include<string.h>
//请实现一个函数，将字符串中出现的每一个空格替换成"%20"
void ReplaceSpace(char* str, int length)
{
	//1、遍历原字符串求出空格的个数
	int spcount = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == ' ')
			spcount++;
	}

	//2、求出替换后字符串的新长度和最后的位置
	int newlength = length + spcount * 2;
	int pos = newlength - 1;

	//替换
	for (int i = length - 1; i >= 0; i--)
	{
		if (str[i] == ' ')
		{
			str[pos--] = '0';
			str[pos--] = '2';
			str[pos--] = '%';
		}
		else
		{
			str[pos] = str[i];
			pos--;
		}
	}
}
int main()
{
	char arr[30] = "we are happy.";
	int length = strlen(arr);
	ReplaceSpace(arr, length);
	printf("%s\n", arr);
	return 0;
}
