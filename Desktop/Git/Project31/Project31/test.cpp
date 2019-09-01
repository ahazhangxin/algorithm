#include <iostream>
#include <vector>
#include <map>
using namespace std;

pair<int, string> fun(const string& str) {
	int len = str.length();
	if (len == 0){
		return make_pair(0, string(""));
	}
	map<string, int> M;
	pair<int, string> ret = make_pair(1, str.substr(0, 1));
	for (int i = 0; i < len; ++i) {
		for (int j = 1; j < len - i + 1; ++j) {
			string substr = str.substr(i, j);
			if (M.find(substr) == M.end()) {
				M[substr] = 1;

			}
			else {
				M[substr] += 1;
				if (M[substr] > ret.first) {
					ret = make_pair(M[substr], substr);

				}
				else if (M[substr] == ret.first && substr.length() > ret.second.length()) {
					ret = make_pair(M[substr], substr);

				}
			}
		}
	}
	return ret;
};
int main()
{
	string str = "asfasfa";
	//cin >> str;
	pair<int, string> rs = fun(str);
	cout << rs.first << endl;
	return 0;
}


/*#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

pair<int, string> fun(const string& str) {
	int len = str.length();
	if (len == 0){
		return make_pair(0, string(""));
	}
	unordered_map<string, int> map(len*len);
	pair<int, string> ret = make_pair(1, str.substr(0, 1));
	for (int i = 0; i < len; ++i) {
		for (int j = 1; j < len - i + 1; ++j) {
			string substr = str.substr(i, j);
			if (map.find(substr) == map.end()) {
				map[substr] = 1;
			}
			else {
				map[substr] += 1;
				if (map[substr] > ret.first) {
					ret = make_pair(map[substr], substr);
				}
				else if (map[substr] == ret.first && substr.length() > ret.second.length()) {
					ret = make_pair(map[substr], substr);
				}
            }
		}
	}
	return ret;
};
int main()
{
	string str = "";
	cin >> str;
	pair<int, string> rs = fun(str);
	cout << rs.first << endl;
	return 0;
	}*/