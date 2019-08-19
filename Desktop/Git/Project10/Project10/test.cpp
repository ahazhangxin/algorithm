//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int i = 1;
//	cout << "i = " << i << endl;
//	(char)i;
//	cout << "t = " << i << endl;
//	return 0;
//}



// 创建 socket 文件描述符 (TCP/UDP, 客户端 + 服务器)
int socket(int domain, int type, int protocol);
// 绑定端口号 (TCP/UDP, 服务器)      
int bind(int socket, const struct sockaddr *address,
	socklen_t address_len);
// 开始监听socket (TCP, 服务器)
int listen(int socket, int backlog);
// 接收请求 (TCP, 服务器)
int accept(int socket, struct sockaddr* address,
	socklen_t* address_len);
// 建立连接 (TCP, 客户端)
int connect(int sockfd, const struct sockaddr *addr,
	socklen_t addrlen);