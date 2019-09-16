//#include<iostream>
//using namespace std;
//
//char *m[11] = { "零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖", "拾" };
//
//
//void printfQBS(int num)
//{
//	int qian, bai, shi, ge;
//	qian = num / 1000;
//	num -= qian * 1000;
//	bai = num / 100;
//	num -= bai * 100;
//	shi = num / 10;
//	num -= shi * 10;
//	ge = num;
//
//	if (qian != 0)
//		cout << m[qian] << "仟";
//	if (bai != 0)
//		cout << m[bai] << "佰";
//	if (qian != 0 && bai != 0)
//		cout << m[bai];
//	if (shi != 0){
//		if (shi != 1)
//			cout << m[shi] << "拾";
//		else
//			cout << "拾";
//	}
//	if (bai != 0 && shi == 0)
//		cout << m[shi];
//	if (ge != 0)
//		cout << m[ge];
//
//}
//int main()
//{
//	double money;
//	cin >> money;
//	money += 0.00001;
//	cout << "人民币";
//	int num;
//	//1.计算亿
//	num = money / 100000000;
//	money -= num * 100000000;
//	if (num != 0){
//		printfQBS(num);
//		cout << "亿";
//	}
//	//2.计算万
//	num = money / 10000;
//	money -= num * 10000;
//	if (num != 0){
//		printfQBS(num);
//		cout << "万";
//	}
//	//3.计算元
//	num = int(money);
//	money -= num;
//	if (num != 0){
//		printfQBS(num);
//		cout << "元";
//	}
//	//4.计算角分
//	money = money * 100;
//	int jiao = money / 10;
//	int fen = money - jiao * 10;
//	if (jiao != 0)
//		cout << m[jiao] << "角";
//	if (fen != 0)
//		cout << m[fen] << "分";
//	cout << endl;
//	return 0;
//}


#include<iostream>
#include<string>
#include<fstream>
#include<cstring	>
#include<algorithm>
#include<sstream>
using namespace std;
string table[11] = { "零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖" };
string table2[6] = { "拾", "佰", "仟", "万", "亿" };
int flag = 1;

string change(string s)
{
	int i, index = 0;
	string result = "";
	char ss[4] = "";
	for (i = 0; i < s.size()&&s[i]=='0'; ++i);
	for (; i < s.size(); ++i)
		ss[index++] = s[i];
	ss[index] = '\0';
	int length = strlen(ss);
	int record = 0;
	for (i = length - 1; i >= 0; i--)
	{
		if (ss[i] == '0')
			record++;
		else
		{
			break;
		}
	}
	if (record > 0)
		flag = 0;
	int k = 4 - length;
	if (length == 2){
		if (ss[0] == '1' && ss[1] == '0')
			return "拾";
		if (ss[0] == '1' && ss[1] != '0')
			return "拾" + table[ss[1] - '0'];
		if (ss[0] != '1'&&ss[1] == '0')
			return table[ss[0] - '0'] + "拾";
		if (ss[0] != '1' && ss[1] != '0')
			return table[ss[0] - '0'] + "拾" + table[ss[1] - '0'];
	}

	for (i = 0; i < length - record; i++, k++)
	{
		if (ss[i] != '0')
			result += table[ss[i] - '0'] + table2[k];
		else if (i != 0 && ss[i] != ss[i - 1])
			result += "零";
	}
	return result;
}

int main()
{
	string data = "";
	string s1 = "", s2 = "";
	while (cin>>data)
	{
		int pos = data.find('.');
		if (pos != string::npos){
			s1 = data.substr(0, pos);
			s2 = data.substr(pos + 1);
		}
		else
		{
			s1 = data;
		}
		cout << "人民币";
		if (s1.length() > 8)
		{
			string temp1 = s1.substr(0, s1.length() - 8);
			s1 = s1.substr(s1.length() - 8, s1.length());
			string result1 = change(temp1);
			if (result1.length() != 0)
				cout << result1 << "亿";
		}

		if (s1.length() > 4)
		{
			string temp2 = s1.substr(0, s1.length() - 4);
			s1 = s1.substr(s1.length() - 4, s1.length());
			string result2 = change(temp2);
			if (result2.length() != 0)
				cout << result2 << "万";
		}

		if (s1.length() > 0)
		{
			string result3 = change(s1);
			if (result3.length()!=0)
				cout << result3 << "元";
		}
		if (s2.length() == 0 || (s2[0] == '0' && s2[1] == '0'))
			cout << "整" << endl;
		else{
			if (s2[0] == '0' && s2[1] != '0'){
				cout << table[s2[1] - '0'] << "分" << endl;
			}
			if (s2[0] != '0' && s2[1] == '0')
				cout << table[s2[0] - '0'] << "角" << endl;
			if (s2[0] != '0' && s2[1] != '0')
				cout << table[s2[0] - '0'] << "角"  << table[s2[1] - '0'] << "分" <<endl;
		}

	}
	return 0;
}






//int main()
//{
//
//	string s, temp = "", res = "元";
//	int jiao = 0, fen = 0;
//	cin >> s;
//	int count = 0;
//	bool flag = false;
//	for (int i = 0; i < s.size(); ++i){
//		if (s[i] != '.' && !flag){
//			temp += s[i];
//		}
//		else{
//			flag = true;
//			if (count == 1){
//				jiao = s[i] - '0';
//			}
//			else if (count == 2){
//				fen = s[i] - '0';
//			}
//			count++;
//		}
//	}
//
//	if (s[s.size() - 1] != '0')
//		res = s1[s[s.size() - 1] - '0'] + res;
//
//	int count1 = 0;
//	for (int i = s.size() - 2; i >= 0; i--){
//		if (s[i] - '0' != 0){
//
//			if (count1 == 8)
//				res = s2[4] + res;
//			else
//				res = s2[count1 % 4] + res;
//
//			if (s[i] - '0' != 1 || count1 % 4 != 0)
//				res = s1[(s[i] - '0')] + res;
//		}
//		count1++;
//		count1 %= 9;
//	}
//
//	cout << "人民币" << res;
//	if (!jiao && !fen)
//		cout << "整" << endl;
//	else{
//		if (jiao){
//			cout << s1[jiao] << "角";
//		}
//		if (fen){
//			cout << s1[fen] << "分";
//		}
//		cout << endl;
//	}
//	return 0;
//}


