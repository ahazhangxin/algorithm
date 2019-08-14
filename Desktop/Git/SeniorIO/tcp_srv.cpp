/*=============================================================== 
 *   Copyright (C) . All rights reserved.")
 *   文件名称： 
 *   创 建 者：zhang
 *   创建日期：
 *   描    述：tcp服务端通信流程
 *       1. 创建套接字
 *       2. 为套接字绑定地址信息
 *       3. 开始监听
 *       4. 获取已完成连接socket
 *       5. 通过获取的新建socket与客户端进行通信-接收数据
 *       6. 发送数据
 *       7. 关闭套接字 
 ================================================================*/
#include <stdio.h>
#include "tcpsocket.hpp"
#include "select.hpp"
#include "epoll.hpp"

int main(int argc, char *argv[])
{
    if (argc != 3) {
        std::cerr << "./tcp_srv ip port\n";
        return -1;
    }
    TcpSocket lst_sock;
    /*1. 创建套接字*/
    CHECK_RET(lst_sock.Socket());
    /*2. 为套接字绑定地址信息*/
    CHECK_RET(lst_sock.Bind(argv[1], argv[2]));
    /*3. 开始监听*/
    CHECK_RET(lst_sock.Listen());

    lst_sock.SetNonBlock();

    //Select s;
    //s.Add(lst_sock);
    Epoll epoll;
    epoll.Init();
    epoll.Add(lst_sock);
    while(1){
        std::vector<TcpSocket> list;
        //bool ret = s.Wait(list);
        bool ret = epoll.Wait(list);
        if (ret == false) {
            continue;
        }
        //list中现在都保存的是就绪的套接字TcpSocket
        //套接字有两种：监听套接字/通信套接字
        //监听套接字就绪：应该获取新连接
        //通信套接字就绪：读取数据
        for (auto sock : list) {
            if (sock.GetFd() == lst_sock.GetFd()) {
                //就绪的描述符若等于监听套接字的描述符，应该accept
                TcpSocket clisock;
                ret = lst_sock.Accept(clisock);
                if (ret == false) {
                    continue;
                }
                std::cout << "A new connection has arrived\n";
                clisock.SetNonBlock();
                epoll.Add(clisock);
            }else {
                std::string buf;
                ret = sock.Recv(buf);
                if (ret == false) {
                    epoll.Del(sock);
                    sock.Close();
                    continue;
                }
                std::cout << "client say: " << buf << std::endl;

                /*
                buf.clear();
                std::cout << "server say: ";
                fflush(stdout);
                std::cin >> buf;
                sock.Send(buf);
                */
            }
        }
    }
    lst_sock.Close();
    return 0;
}

