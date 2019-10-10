#include<stdio.h>        
#include <arpa/inet.h>
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#define PORT 8088
#define SockAdd struct sockaddr //unsigned short sa_family,char sa_data[14];
#define MAX 100
//using namespace std;


void func(int tmpSock){
	char msg[MAX];
	int i;
	for(;;){
		bzero(msg,sizeof(msg));
		read(tmpSock,msg,sizeof(msg));
		i=0;
		
		printf("\n From Client --------->>>> %s ",msg);
		

		bzero(msg,sizeof(msg));
		puts("\n Enter Message\n");
		i=0;
		while((msg[i++]=getchar())!='\n');
		
		if(msg=="Exit"){
			
			printf("Server Exits");
			break;
		}
	
		write(tmpSock,msg,sizeof(msg));
		

	}


}

int main(){
	
	int mainSock, confd,len;
	struct sockaddr_in servInfo, TempServInfo; //sin_family,sin_port,struct in_addr sin_addr, sin_zero[8];

	mainSock= socket(AF_INET,SOCK_STREAM,0);
	
	if(mainSock==-1){
		
		printf("SOCKET Creation failed");
		puts("Hellooooooooooooo");
		exit(0);	
	}else{
		//printf("")
		//printf("Socket Created \n");
		puts("\n Socket Created \n");
	}

	
	bzero(&servInfo, sizeof(servInfo)); // assign zeros to servInfo

	servInfo.sin_family=AF_INET;
	servInfo.sin_addr.s_addr = htons(INADDR_ANY); //INADDR_ANY== localhost IP
	//servInfo.sin_addr.s_addr = inet_addr("127.0.0.1");
	servInfo.sin_port = htons(PORT);
	
	printf("Server Info Assigned \n");
	//bind mainSocket abd servInfo
	
	

	if(bind(mainSock, (SockAdd*)&servInfo, sizeof(servInfo))!=0){
		
		printf("Bind Failed \n ");
	}else{
		
		//printf("Bind Success \n");
		puts("Bind Success  \n");
	}
	
	
	
	printf("\n Before Listen \n");
	if(listen(mainSock,5)!=0){
		
		//printf("\n Listen Faifled \n");
		puts("\n Listen Failed  \n");
	}else{
		
		//printf("\n Listen Success \n");
		puts("\n Listen Success  \n");
	}

	len=sizeof(TempServInfo);

	
	
	printf("\n Len----->> %d \n",len);
	
	
	confd = accept(mainSock, (SockAdd*)&TempServInfo, &len);
	
	puts ("\n After confd \n");
	//connfd = accept(sockfd, (SA*)&cli, &len); 
	
	puts("\n Before connf \n");
	if(confd<0){
		
		printf("\n Accept Failed \n");
		puts("\n Accept Failed Hellooooooooooooo \n");
	}else{
		
		printf("\n Accept Success \n");
		puts("Accept Failed Hellooooooooooooo \n");
	}

	func(confd);
		
	close(confd);
	
	
	
return 0;
}
