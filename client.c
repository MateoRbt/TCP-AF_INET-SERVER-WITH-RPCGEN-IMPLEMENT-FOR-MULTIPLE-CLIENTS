/*Name : Jay Jagtap
3154037
Problem Statement: To implement client-server calculator.
*/

/*
	Client Side
	Please pass ip address and port no as command line arguments in the same sequence.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include<ctype.h>

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[1024];
    if (argc < 3)
    {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
  
  
    int y[256] ;
    int length,an[2] ;
    int max,min;
    int choice,i;
    float ans,a;
    float ay[256];
    
    
  S: bzero(buffer,256);						
    n = read(sockfd,buffer,255);				//Read Server String
    if (n < 0) 
         error("ERROR reading from socket");
    printf("Server - %s",buffer);
    scanf("%d" , &choice);						//Enter choice
    write(sockfd, &choice, sizeof(int));


	bzero(buffer,256);						
    n = read(sockfd,buffer,255);				
    if (n < 0) 
         error("ERROR reading from socket");                //Enter length
    printf("Server - %s\n",buffer);
    scanf("%d" , &length);						
    write(sockfd, &length, sizeof(int));     			
	
	bzero(buffer,256);						
    n = read(sockfd,buffer,255);				
    if (n < 0) 
         error("ERROR reading from socket");		//Enter float
    printf("Server - %s\n",buffer);
    scanf("%f" , &a);						
    write(sockfd, &a, sizeof(float)); 
	
    bzero(buffer,256);						
    n = read(sockfd,buffer,255);				
    if (n < 0) 
         error("ERROR reading from socket");          //Enter numbers of y[]
    printf("Server - %s\n",buffer);
	for (i=0; i<length; i++)
    		scanf("%d" , &y[i]);						
    write(sockfd, &y,256* sizeof(int));     			
	
    	
        		

  if (choice == 4)
  {
		printf("You chose to exit, Thank You so much.");
		exit(0);
  }
		
 else if (choice == 1)
	{
   	 	read(sockfd , &ans , sizeof(float));				
    		printf("Server - The answer is : %.2f\n" , ans);
	}
else if (choice == 2)	
	{
		read(sockfd , &an ,2 * sizeof(int));				
    		printf("Server - max is : %d\n" , an[0]);
		printf("Server - min is : %d\n" , an[1]);
	}	
else if(choice == 3)
	{
		read(sockfd , &ay ,256 * sizeof(float));
		for(i=0; i<length; i++)
			printf("ay[%d]= %.2f \n",i,ay[i]);
	}
	
    if(choice != 4)
    	goto S;
    	
 
     	
       
   
    
    close(sockfd);
    return 0;
}
