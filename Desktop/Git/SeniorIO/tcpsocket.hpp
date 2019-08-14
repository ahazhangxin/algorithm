/*=============================================================== 
*   Copyright (C) . All rights reserved.")
*   文件名称： 
*   创 建 者：zhang
*   创建日期：
*   描    述：z封装一个tcpsocket类，向外提供简单的套接字接口 
*       1. 创建套接字
*       2. 为套接字绑定地址信息
*       3. 开始监听
*       4. 向服务端发起连接请求
*       5. 服务端获取新建连接
*       6. 发送数据
*       7. 接收数据
*       8. 关闭套接字
================================================================*/
#ifndef __M_TS_H__
#define __M_TS_H__
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define CHECK_RET(q) if((q)==false){return -1;}

class TcpSocket
{
    private:
        int _sockfd;
    public:
        void SetFd(int fd) {
            _sockfd = fd;
        }
        int GetFd() {
            return _sockfd;
        }
        void SetNonBlock() {
            //int fcntl(int fd, int cmd, ... /* arg */ );
            //fd： 描述符
            //cmd：对描述符要进行的操作
            //      F_SETFL 通过第三个参数来设置描述符属性
            //      F_GETFL 获取描述符的属性并通过返回值返回
            //arg： O_NONBLOCK  文件描述符的非阻塞属性
            int flag = fcntl(_sockfd, F_GETFL, 0);
            fcntl(_sockfd, F_SETFL, flag | O_NONBLOCK);
        }
        bool Socket() {
            _sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            if (_sockfd < 0) {
                std::cerr << "socket error\n";
                return false;
            }
            int opt = 1;
            setsockopt(_sockfd, SOL_SOCKET, SO_REUSEADDR, (void*)&opt,
                    sizeof(int));
            return true;
        }
        int str2int(const std::string &str){
            int num;
            std::stringstream tmp;
            tmp << str;
            tmp >> num;
            return num;
        }
        bool Bind(const std::string &ip, const std::string &port) {
            struct sockaddr_in addr;
            addr.sin_family = AF_INET;
            addr.sin_port = htons(str2int(port));
            addr.sin_addr.s_addr = inet_addr(ip.c_str());
            socklen_t len = sizeof(struct sockaddr_in);
            int ret = bind(_sockfd, (struct sockaddr*)&addr, len);
            if (ret < 0) {
                std::cerr << "bind error\n";
                return false;
            }
            return true;
        }
        bool Listen(const int backlog = 5) {
            //int listen(int sockfd, int backlog);
            //开始监听：通知操作系统，可以开始接收客户端的连接请求了，
            //并且完成三次握手建立连接过程
            //tcp的面向连接，有一个三次握手建立连接过程
            //backlog:客户端最大并发连接数（同一时间最多接收多少个客户端
            //新连接请求）
            int ret = listen(_sockfd, backlog);
            if (ret < 0) {
                std::cerr << "listen error\n";
                return false;
            }
            return true;
        }
        bool Connect(const std::string &srv_ip, 
                const std::string &srv_port) {
            //int connect(int sockfd, sockaddr *addr,socklen_t addrlen)
            //addr: 服务端地址信息
            //addrlen:  地址信息长度
            struct sockaddr_in addr;
            addr.sin_family = AF_INET;
            addr.sin_port = htons(str2int(srv_port));
            addr.sin_addr.s_addr = inet_addr(srv_ip.c_str());
            socklen_t len = sizeof(struct sockaddr_in);
            int ret = connect(_sockfd, (struct sockaddr*)&addr, len);
            if (ret < 0) {
                std::cerr << "connect error\n";
                return false;
            }
            return true;
        }
        bool Accept(TcpSocket &clisock, std::string *ip = NULL, 
                uint16_t *port = NULL) {
            //int accept(int sockfd, sockaddr *addr, socklen_t *addrlen)
            //sockfd:   监听套接字描述符
            //addr：    客户端地址信息
            //addrlen： 地址信息长度
            //返回值：返回新建连接的socket描述符-与客户端进行数据通信
            struct sockaddr_in cliaddr;
            socklen_t len = sizeof(struct sockaddr_in);
            int newfd = accept(_sockfd, (sockaddr*)&cliaddr, &len);
            if (newfd < 0) {
                std::cerr << "accept error\n";
                return false;
            }
            clisock.SetFd(newfd);
            if (ip != NULL) {
                *ip = inet_ntoa(cliaddr.sin_addr);
            }
            if (port != NULL) {
                *port = ntohs(cliaddr.sin_port);
            }
            return true;
        }
        bool Send(std::string &data) {
            //ssize_t send(int sockfd, void *buf, size_t len, int flags)
            //sockfd: 套接字描述符（服务端是新建连接的socket描述符）
            //buf： 要发送的数据
            //len： 要发送的数据长度
            //flags：   0-默认阻塞发送
            //返回值： 成功-返回实际发送的数据长度；失败-返回-1
            int ret = send(_sockfd, &data[0], data.size(), 0);
            if (ret < 0) {
                std::cerr << "send error\n";
                return false;
            }
            return true;
        }
        bool Recv(std::string &buf) {
            //ssize_t recv(int sockfd, void *buf, size_t len, int flags)
            //flags:
            //  0-默认阻塞接收
            //  MSG_PEEK：从缓冲区取数据，但是数据并不从缓冲区移除
            //返回值：>0:实际接收的数据长度 ==0：连接断开   <0:错误
            buf.clear();
            while(1) {
                char tmp[5];
                int ret = recv(_sockfd, tmp, 5, 0);
                if (ret < 0) {
                    //std::cerr << "recv error\n";
                    if (errno == EAGAIN) {
                        std::cerr << "No data to read\n";
                        return true;
                    }
                    perror("recv error");
                    return false;
                }else if (ret == 0) {
                    std::cerr << "connect shutdown\n";
                    return false;
                }
                tmp[ret] = '\0';
                buf += tmp;
            }
            return true;
        }
        bool Close() {
            close(_sockfd);
        }
};
#endif
