#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//判断循环进去多少次
//int main()
//{
//	unsigned char i = 7;
//	int j = 0;
//	for (; i > 0; i++)
//	{
//		++j;
//	}
//	printf("%d\n", j);//173 不要看见unsigned就觉得是死循环
//	return 0;
//}
//7 4 1 254 ... 84*3 2 255 85*3 0

//输入：1abcedf2df<回车>
//int main()
//{
//	char a = 0, ch;
//	while ((ch = getchar()) != '\n')
//	{
//		if (a % 2 != 0 && (ch >= 'a' && ch <= 'z'))
//		{
//			ch = ch - 'a' + 'A';//-97+65 = 32
//		}
//		a++;//1 2 3
//		putchar(ch);//1AbCeDf2dF
//	}
//	return 0;
//}
//大写字母（65）和小写字母（97）之间差32，小写转换成大写-32 大写转换成小写+32

//flag = 15
//0000 1111
//1111 1101
//0000 0010

//int main()
//{
//	int x = 1;
//	do
//	{
//		printf("%2d\n", x++);//1 x==2
//	} while (x--);//2 x==1
//	return 0;
//}

//int main()
//{
//	int a = -3;
//	//10000000 00000000 00000000 00000011 - 原码
//	//11111111 11111111 11111111 11111100 - 反码
//	//11111111 11111111 11111111 11111101 - 补码
//	unsigned int b = 2;
//	//00000000 00000000 00000000 00000010 -补码
//	long c = a + b;
//	//11111111 11111111 11111111 11111101 - 补码
//	//00000000 00000000 00000000 00000010 -补码
//	//11111111 11111111 11111111 11111111 - 补码
//	printf("%ld\n", c);//有符号的long -1
//	return 0;
//}

//拿到字符j
//int main()
//{
//	char* p[] = { "ShangHai", "Beijing", "Honkong" };
//	return 0;
//} 
//*(p[1]+3) p[1]拿到的是B的地址，+3拿到了j的地址，解引用就拿到了j
