#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <arpa/innet.h>
#include <sys/wait.h>

int main(void){
	int ls;
	int s;
	char buffer[256];
	char* ptr=buffer;
	int len=0;
	int maxLen=sizeof(buffer);
	int n=0;
	int waitSize=16;
	struct sockaddr_in servAddr;
	struct sockaddr_in clntAddr;
	int clntAddrLen;

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family=AF_INET;
	servAddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servAddr.sin_port = htos(SERV_PORT);
	if(ls=socket(PF_INET,SOCK_STREAM, 0)<0){
	perror("Error:Listen socket failed!");
	exit(1);
	}
	for( : : ){
	if(s=accept(ls,&clntAddr,&clntAddrLen)<0){
	perror("Error: accepting failed!");
	exit(1);
	}
	while((n=recv(s,ptr,maxLen,0))>0){
	ptr+=n;
	maxLen-=n;
	len+=n;
	}
	send(s,buffer,len,0);
	close(s);
	}
}
