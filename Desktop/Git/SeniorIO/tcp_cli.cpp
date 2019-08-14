/*=============================================================== 
*   Copyright (C) . All rights reserved.")
*   文件名称： 
*   创 建 者：zhang
*   创建日期：
*   描    述：tcp客户端通信流程
*       1. 创建套接字
*       2. 为套接字绑定地址信息(不推荐用户主动绑定)
*       3. 向服务端发起连接请求
*       4. 发送数据
*       5. 接收数据
*       6. 关闭套接字 
================================================================*/
#include <stdio.h>
#include <signal.h>
#include "tcpsocket.hpp"
void sigcb(int signo)
{
    printf("recv a signo SIGPIPE --- conect shutdown\n");
}
int main(int argc, char *argv[])
{
    if (argc != 3) {
        std::cerr << "./tcp_cli ip port\n";
        return -1;
    }
    signal(SIGPIPE, sigcb);
    TcpSocket sock;
    /*1. 创建套接字*/
    CHECK_RET(sock.Socket());
    /*2. 为套接字绑定地址信息(不推荐用户主动绑定)*/
    /*3. 向服务端发起连接请求*/
    CHECK_RET(sock.Connect(argv[1], argv[2]));
    while(1) {
        /*4. 发送数据*/
        std::string buf;
        std::cout << "client say: ";
        fflush(stdout);
        std::cin >> buf;
        sock.Send(buf);
        /*5. 接收数据*/
        /*
        buf.clear();
        sock.Recv(buf);
        std::cout << "server say: " << buf << std::endl;
        */
    }
    /*6. 关闭套接字 */
    sock.Close();
    return 0;
}
