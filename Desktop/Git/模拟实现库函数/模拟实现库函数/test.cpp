#include"main.h"

/*
模拟实现strlen，借助count计数器
*/
int my_strlen(const char * str) {
	int count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return count;
}

/*不借助计数器实现*/

int my_strlen1(const char * str)
{
	if (*str == '\0')
		return 0;
	return 1 + my_strlen1(str + 1);
}

/*
指针-指针的方式
*/
int my_strlen2(const char* str)
{
	const char * temp = str;
	while (*temp != '\0')
	{
		temp++;
	}
	return temp - str;
}

/*
模拟实现strcpy
*/

char* my_strcpy(char *dest, const char*src)
{
	char* res = dest;
	if (res == nullptr)
		return nullptr;
	while (*dest++ = *src++)
	{
		;
	}
	return res;
}


/*
模拟实现strcat
*/

char* my_strcat(char *dest, const char*src)
{
	char* ret = dest;
	while (*dest)
	{
		dest++;
	}
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

/*
模拟实现strstr
*/

char *my_strstr(const char* str1, const char* str2)
{
	assert(str1);
	assert(str2);
	char *cp = (char*)str1;
	const char *substr = (char *)str2;
	char *s1 = NULL;
	if (*str2 == '\0')
		return NULL;
	while (*cp)
	{
		s1 = cp;
		substr = str2;
		while (*s1 && *substr && (*s1 == *substr))
		{
			s1++;
			substr++;
		}
		if (*substr == '\0')
			return cp;
		cp++;
	}
}


/*
模拟实现strcmp
*/

int my_strcmp(const char * src, const char * dst) {
	int ret = 0;
	assert(src != NULL);
	assert(dst != NULL);
	while (!(ret = *(unsigned char *)src - *(unsigned char *)dst) && *dst)
		++src, ++dst;
	if (ret < 0)
		ret = -1;
	else if (ret > 0)
		ret = 1;
	return(ret);
}




int main()
{
	char * str = "abcdefg";
	char * str1 = "";
	char * str2 = "abcdefg";
	cout << my_strlen(str) << endl;
	cout << my_strlen1(str) << endl;
	cout << my_strlen2(str) << endl;
	cout << my_strcpy(str1, str2) << endl;
	return 0;
}