/*
include<stdio.h>
int main()
{
	printf("%d\n", sizeof(bool));
	printf("%d\n", sizeof(char));
	printf("%d\n", sizeof(short));
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof(long));
	printf("%d\n", sizeof(long long));
	printf("%d\n", sizeof(float));
	printf("%d\n", sizeof(double));
	printf("%d\n", sizeof(long double));
	return 0;
}
*/
//#include<iostream>
//using namespace std;
//int main()
//{
//	unsigned char d = 128;
//	cout << d + 1 << endl;
//	if ((d + 1) < 1){
//		cout << "大于" << endl;
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char * str = "asfbjklabnf";
//	printf("%d\n", sizeof("asfbjklabnf"));
//	printf("%d\n", strlen(str));
//	printf("he\"llo");
//	return 0;
//}
//
//
//
//
//#include<iostream>
//using namespace std;
//struct MyUnion
//{
//	char s;
//	int t;
//	int str[5];
//};
//int main()
//{
//	//char name[6] = "jack";
//	//char * str = name;
//	//while (true)
//	//{
//	//	cout << str << endl;
//	//	str++;
//	//}
//	cout << sizeof(MyUnion) << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int k = 0;
//	for (i = 0, k = 0; k = 0; i++, k++){
//		k++;cout << i;
//	}
//	int arr1[10] = { 1, 2, 3 };
//	int arr2[] = { 1, 2, 3, 4 };
//	int arr3[5] = { 1, 2, 3, 4, 5 };
//	char arr4[3] = { 'a', 98, 'c' };
//	char arr5[] = { 'a', 'b', 'c' };
//	char arr6[] = "abcdef";
//	return 0;
//}


//
//#include<stdio.h>
//int main()
//{
//	int num = 1;
//	int count = 0;
//	//while (num)
//	//{
//	//	if (num % 2 == 1)
//	//		count++;
//	//	num /= 2;
//	//}
//	while (num)
//	{
//		count++;
//		num &= (num - 1);
//	}
//	printf("%d\n", count);
//
//	return 0;
//}


//#include <stdio.h>
//void test1(int arr[])
//{
//	printf("%d\n", sizeof(arr));//(2)
//}
//void test2(char ch[])
//{
//	printf("%d\n", sizeof(ch));//(4)
//}
//int main()
//{
//	int arr[10] = { 0 };
//	char ch[10] = { 0 };
//	printf("%d\n", sizeof(arr));//(1)
//	printf("%d\n", sizeof(ch));//(3)
//	test1(arr);
//	test2(ch);
//	return 0;
//}
//
//#include <stdio.h>
////演示实例
//int main()
//{
//	int n = 10;
//	char *pc = (char*)&n;
//	int *pi = &n;
//	printf("%p\n", &n);
//	printf("%p\n", pc);
//	printf("%p\n", pc + 1);
//	printf("%p\n", pi);
//	printf("%p\n", pi + 1);
//	return 0;
//}


#include <stdio.h>
int main()
{
	int i = 0;
	int arr[10] = { 0 };
	for (i = 0; i <= 12; i++)
	{
		arr[i] = 0;
		printf("hehe\n");
	}
	return 0;
}