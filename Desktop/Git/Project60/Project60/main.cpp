//#include<stdio.h>
//int main()
//{
//	union MyUnion
//	{
//		int i;
//		char c;
//	}un;
//	un.i = 1;
//	printf("%d\n", un.c);
//	return 0;
//}

#include <stdio.h>
int check_sys()
{
	int i = 1;
	return (*(char *)&i);
}
int main()
{
	int ret = check_sys();
	if (ret == 1)
	{
		printf("Ð¡¶Ë\n");
	}
	else
	{
		printf("´ó¶Ë\n");
	}
	return 0;
}