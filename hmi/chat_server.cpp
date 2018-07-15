#include <sys/types.h>
#include <sys/socket.h>
#include "chat_server.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

My_Server::My_Server()
{
;
}

My_Server::~My_Server()
{
	if(sock > 0)
		close(sock);
}

bool My_Server::ServerInit()
{
	printf("ServerInit\n");
	sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock < 0)
	{
		perror("socket:");
		return false;
	}

	int opt =1;
   	setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));

	struct sockaddr_in tcp_server;
	tcp_server.sin_family = AF_INET;
	tcp_server.sin_addr.s_addr = INADDR_ANY;
	tcp_server.sin_port = htons(TCP_PORT);

	if(bind(sock,(struct sockaddr*)&tcp_server,sizeof(struct sockaddr)) == -1)
	{
		perror("bind:");
		return false;
	}

	if(listen(sock,1) == -1)
	{
		perror("listen:");
		return false;
	}

	
}

void My_Server::WaitForData()
{
	//RecvData *recvPt = (RecvData*)arg;
	int read_sock = -1;
	struct sockaddr_in client;
	socklen_t client_len;
	int read_bytes = 0;
	RecvData recv_st;
	printf("waitfordata\n");
	while(1)
	{
		if(read_sock = accept(sock,(struct sockaddr*)&client,&client_len) == -1)
		{
			perror("accept:");
			continue;
		}
		printf("test1\n");
		read_bytes = recv(read_sock,recv_st.buf,MAX_READ_LEN-1,0);
		//recv_st.buf[read_bytes] = 0;
		printf("read_bytes = %d\n");//printf("recv:%s\n",recv_st.buf);
		printf("%02x %02x\n",recv_st.buf[0],recv_st.buf[1]);
	}
}



