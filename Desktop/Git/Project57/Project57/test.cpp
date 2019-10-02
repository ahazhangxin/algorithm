//#include<iostream>
//#include<map>
//#include<algorithm>
//#include<string>
//#include<unordered_set>
//#include<vector>
//using namespace std;
//bool cmp1(const pair<string,int>&a, const pair<string,int>& b)
//{
//	return a.second > b.second;
//}
//int main()
//{
//	string s;
//	unordered_set<string> us;
//	map<string, int> mp;
//	getline(cin, s);
//	for (int j = 0; j < s.size(); ++j)
//	{
//		string temp1 = "";
//		string temp2 = "";
//		bool sign = true;
//		while ( j < s.size() && s[j] != ' ')
//		{
//			temp1 += s[j];
//			if (s[j] == '-'){
//				sign = false;
//			}
//			else if(!sign){
//				temp2 += s[j];
//			}
//			++j;
//		}
//			
//		if ( us.end() == us.find(temp1))
//		{		
//			us.insert(temp1);
//			mp[temp2]++;
//		}
//
//	}
//	vector<pair<string, int>> v;
//	for (auto e : mp)
//	{
//		v.push_back(pair<string, int>(e.first, e.second));
//	}
//	sort(v.begin(), v.end(), cmp1);
//	for (int i = 0; i < 3; ++i)
//	{
//		cout << v[i].first << " " << v[i].second << endl;
//	}
//	return 0;
//}

//
//#include<iostream>
//#include<algorithm>
//#include<string>
//#include<vector>
//using namespace std;
//int main()
//{
//	vector<int> v{ 1, 4, 3, 2 };
//	string s = "1423";
//	string res(s.begin() + 1,s.end());
//	next_permutation(res.begin(), res.end());
//	cout << s << endl;
//	return 0;
//}


//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//int lengthOfLongestSubstring(string s) {
//	int m[256] = { 0 };//字符有256个
//	int left = 0;//查找的左边界
//	int mlen = 0;//结果
//	for (int i = 0; i<s.length(); i++)
//	{
//		if (m[s[i]] == 0 || m[s[i]]<left)
//		{
//			mlen = max(mlen, i - left + 1);
//		}
//		else
//		{
//			left = m[s[i]];
//		}
//		m[s[i]] = i + 1;
//	}
//	return mlen;
//}
//
//
//int main()
//{
//	string s;
//	cin >> s;
//	cout << lengthOfLongestSubstring(s) << endl;
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	vector<int> v = { 8, 9, 1, 2, 3, 4, 5, 6, 7 };
//	int t = 1;
//	int left = 0;
//	int right = v.size() - 1;
//	int mid;
//	while (left <= right)
//	{
//		mid = (left + right) / 2;
//		if (v[left] > t || v[mid] < t)
//		{
//			right = mid - 1;
//		}
//		else if (v[mid] > t || v[right] < t)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			cout << mid << endl;
//			return 0;
//		}
//	}
//	cout << -1 << endl;
//	return 0;
//}


//class Solution {
//public:
//	std::unordered_map<char, std::string> m;
//
//	void InitMap() {
//		m['2'] = "abc";
//		m['3'] = "def";
//		m['4'] = "ghi";
//		m['5'] = "jkl";
//		m['6'] = "mno";
//		m['7'] = "pqrs";
//		m['8'] = "tuv";
//		m['9'] = "wxyz";
//	}
//	void Helper(const std::string &digits, string &phone_number, std::vector<std::string> &result) {
//		if (phone_number.size() == digits.size()) {
//			result.push_back(phone_number);
//		}
//		else {
//			for (char c : m[digits[phone_number.size()]]) {
//				phone_number.push_back(c);
//				Helper(digits, phone_number, result);
//				phone_number.pop_back();
//			}
//		}
//	}
//
//	vector<string> letterCombinations(string digits) {
//		if (digits.empty()) return{};
//		InitMap();
//		std::string phone_number;
//		std::vector<std::string> result;
//		Helper(digits, phone_number, result);
//		return result;
//	}
//
//};