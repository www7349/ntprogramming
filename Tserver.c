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
#include <arpa/inet.h>
#include <sys/wait.h>
#define SERV_PORT 5000
#define Buffer_Len 256

int main(int argc,char *argv[] ){
	int ls;
	int s;
	char buffer[Buffer_Len];
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
	servAddr.sin_port = htons(SERV_PORT);
	
	ls=socket(PF_INET,SOCK_STREAM, 0);
	if(ls<0){
	perror("Error:Listen socket failed!");
	exit(1);
	}
	bind(ls,(struct sockaddr *)&servAddr,sizeof(servAddr));
	if(bind<0){
	perror("Error:binding failed!");
	exit(1);
	}

	if(listen(ls,waitSize)<0){
	perror("Error: listening failed!");
	exit(1);
	}
	for(;;){	
	if(s=accept(ls,(struct sockaddr*)&clntAddr,&clntAddrLen)<0){
	perror("Error: accepting failed!");
	exit(1);
	}

	char Buffer[Buffer_Len]={0};
	while((n=recv(s,ptr,maxLen,0))>0){
	ptr+=n;
	maxLen-=n;
	len+=n;
	}

	sprintf(Buffer, "Hello\n");
	send(s, Buffer, strlen(Buffer),0);

	//printf("%s",ptr);
	//send(s,buffer,len,0);
	close(s);
	}
}
