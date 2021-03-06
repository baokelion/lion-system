int main(int agrc, char ** argv)
{
	int sockfd, nbytes;
	char buf[128];
	struct sockaddr_in srvaddr;
	//创建网络端点
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd == -1){
		prinf("can't create socket\n");
		exit(1);
	}
	//指定服务器地址（本地socket地址采用默认值）
	bzero(&srvaddr, sizeof(srvaddr));
	srvaddr.sin_family = AF_INET;
	srvaddr.sin_port = htons(PORT);
	if(inet_aton("127.0.0.1", srvaddr.sin_addr.s_addr == -1){//inet_aton字符串ip改成32位的网络程序ip
		prinf("addr convert error\n");
		exit(1);
	}
	//2.连接服务器
	if(connect(sockfd, (struct sockaddr* )&srvaddr, sizeof(struct sockaddr))==-1){
		printf("connect error\n");
		exit(1);
	}
	//3.发送请求
	sprintf(buf,"hello");
	write(sockfd, buf, strlen(buf));
	//4.接收响应
	if((nbytes = read(sockfd, buf, MAXDATASIZE))== -1){
		printf("read error\n");
		exit(1);
	}
	buf[nbytes] = '\0';
	printf("srv respons:%s\n", buf);
	//关闭socket
	close(sockfd);
}