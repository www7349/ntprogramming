#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include<errno.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#define Buffer_Len 256

int main(int argc,char* argv[]){
	int s;
	int a;
	int n;
	int maxLen;	
	char* servName;
	int servPort;
	char* string;
	int len;
	char buffer[Buffer_Len+1];
	char* ptr=buffer;
	struct sockaddr_in serverAddr;
	if(argc!=4){
		printf("%d %s %s %s \n",argc,argv[1],argv[2],argv[3]);
		printf("Error:three arguments are needed!");
		exit(1);
	}
	servName=argv[1];
	servPort=atoi(argv[2]);
	string=argv[3];
	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family=AF_INET;
	inet_pton(AF_INET,servName,&serverAddr.sin_addr);
	serverAddr.sin_port=htons(servPort);
	


	if((s=socket(PF_INET,SOCK_STREAM,0))<0){
	perror("Error:socket creation failed!");
	exit(1);
	}
	if(connect(s,(struct sockaddr*)&serverAddr,sizeof(serverAddr))<0){
	perror("Error:connection failed!");
	exit(1);
	}
	

	send(s,string,strlen(string),0);
	char Buffer[Buffer_Len];
	while((n=recv(s,ptr,maxLen,0))>0){
	ptr+=n;
	maxLen-=n;
	len+=n;
	Buffer[n]='\0';
	}

	//char Buffer[Buffer_Len];
	//int m=read(s, buffer, Buffer_Len);
	printf("%d bytes read\n", n);

	//Buffer[n]='\0';
	//printf("Echoed string received:");
	fputs(Buffer,stdout);
	fflush(stdout);

	close(s);
	exit(0);
	
}
