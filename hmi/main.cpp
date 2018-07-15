#include "chat_server.h"
#include <stdio.h>
#include <pthread.h>


int main(int argc, char *argv[] )
{
	printf("hi\n");
	My_Server m_server;
	m_server.ServerInit();
	m_server.WaitForData();
	//RecvData recv_data;
	
	/*pthread_t server_thread;
	if(pthread_create(&server_thread,NULL,m_server.WaitForData,&recv_data) != 0)
	{
		perror("create server thread:");
	}*/
	
	printf("end\n");
}

		
