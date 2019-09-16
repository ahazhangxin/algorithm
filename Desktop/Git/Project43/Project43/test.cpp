//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//// 表示整数部分的标志
//const int INT_ONLY = 1;
//// 表示小数部分的标志
//const int SMALL_ONLY = 2;
//
//
//
//
//bool checkNum(string s) {
//	// atof(s.c_str()) 方法的功能是将字符串 s 转换成一个双精度数值并返回结果
//	double d = atof(s.c_str());
//	// 只有当用户输入一个大于0的数时，才会返回true
//	if (d > 0) {
//		return true;
//	}
//	return false;
//}
//
//
//string roundString(string s) {
//
//	double d = atof(s.c_str());
//
//	int dec, sign;
//
//	s = fcvt(d, 2, &dec, &sign);
//
//	if (s.length() > 15) {
//		cout << "输入数据过大！（整数部分最多13位！）" << endl;
//		return "";
//	}
//	return s;
//}
//
//
//
//string formatChinese(int flag, string s) {
//	int sLength = s.length();
//	// 货币大写形式
//	string bigLetter[] = { "零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖" };
//	// 货币单位
//	string unit[] = { "元", "拾", "佰", "仟", "万",
//		// 拾万位到仟万位
//		"拾", "佰", "仟",
//		// 亿位到万亿位
//		"亿", "拾", "佰", "仟", "万" };
//	string small[] = { "分", "角" };
//	// 用来存放转换后的新字符串
//	string newS = "";
//	// 逐位替换为中文大写形式
//	for (int i = 0; i < sLength; i++) {
//		if (flag == INT_ONLY) {
//			// 转换整数部分为中文大写形式（带单位）
//			newS = newS + bigLetter[s.at(i) - 48] + unit[sLength - i - 1];
//		}
//		else if (flag == SMALL_ONLY) {
//			// 转换小数部分（带单位）
//			newS = newS + bigLetter[s.at(i) - 48] + small[sLength - i - 1];
//		}
//	}
//	return newS;
//}
//
//
//
//string splitNum(string s) {
//	// 如果传入的是空串则继续返回空串
//	if ("" == s) {
//		return "";
//	}
//	// 截取输入数字的整数部分
//	string intOnly = s.substr(0, s.size() - 2);
//	string intPart = formatChinese(1, intOnly);
//
//	// 截取这个数的小数部分
//	string smallOnly = s.substr(s.size() - 2, s.size());
//	string smallPart = formatChinese(2, smallOnly);
//
//	// 把转换好了的整数部分和小数部分重新拼凑一个新的字符串
//	string newS = intPart + smallPart;
//
//	return newS;
//}
//
//
//
//string replaceAll(string src, string regex, string replacement) {
//	int length = regex.length();
//	while (src.find(regex) < src.length()) {
//		// 替换 src 字符串中从第一个匹配 regex 的字符串索引开始的 length 个字符为 replacement 字符串		
//		src.replace(src.find(regex), length, replacement);
//	}
//	return src;
//}
//
//
//
//string cleanZero(string s) {
//	if ("" == s) {
//		return "";
//	}
//	string regex1[] = { "零仟", "零佰", "零拾" };
//	string regex2[] = { "零亿", "零万", "零元" };
//	string regex3[] = { "亿", "万", "元" };
//	string regex4[] = { "零角", "零分" };
//
//	for (int i = 0; i < 3; i++) {
//		s = replaceAll(s, regex1[i], "零");
//	}
//
//	for (int i = 0; i < 3; i++) {
//
//		s = replaceAll(s, "零零零", "零");
//		s = replaceAll(s, "零零", "零");
//		s = replaceAll(s, regex2[i], regex3[i]);
//	}
//	for (int i = 0; i < 2; i++) {
//		s = replaceAll(s, regex4[i], "");
//	}
//	s = replaceAll(s, "亿万", "亿");
//	return s;
//}
//
//int main() {
//	string s;
//	cin >> s;
//	vector<string> res;
//	string temp;
//	for (int i = 0; i < s.size(); ++i)
//	{
//		if (((s[i] - '0') >= 0) && ((s[i] - '0') <= 0) || s[i] == '.'){
//			temp += s[i];
//			continue;
//		}
//		if (s[i] == '\"'){
//			if (checkNum(temp)) {
//				temp = roundString(temp);
//				temp = splitNum(temp);
//				temp = cleanZero(temp);
//				res.push_back(temp);
//				temp.clear();
//			}
//		}
//	}
//	cout << "人民币";
//	for (int i = 0; i < res.size(); ++i){
//		cout << res[i];
//	}
//	return 0;
//}
