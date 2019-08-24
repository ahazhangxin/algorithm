//#include <stdio.h> 
//int main()
//{
//	int sum, pad, pAd;
//	sum = pad = 5;
//	pAd = ++sum, pAd++, ++pad;
//	printf("%d\n", pad);
//}

//int main()
//{
//		int m = 12, n = 34;
//		printf("%d%d", m++, ++n);
//		printf("%d%d\n", n++, ++m);
//		return 0;
//}

#include<iostream>
#include<string>
using namespace std;

class Demo {
public:
	Demo() :count(0) {}
	~Demo() {}

	void say(const std::string&msg) {
		fprintf(stderr, "%s\n", msg.c_str());
	}
private:
	int count;
};

int main(int argc, char **argv) {
	Demo* v = NULL;
	v->say("hello world");
}