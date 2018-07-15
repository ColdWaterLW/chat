#ifndef	__CHAT_SER_H__
#define __CHAT_SER_H__

#define	TCP_PORT	7000
#define MAX_READ_LEN	1024

typedef struct _RecvData{
	char buf[MAX_READ_LEN];
	int len;
}RecvData;

class My_Server
{
public : 
	My_Server();
	~My_Server();
	
	bool ServerInit();
	
	void WaitForData();

	int sock;

};


#endif	//__CHAT_SER_H__

