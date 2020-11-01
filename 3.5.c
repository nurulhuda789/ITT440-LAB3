#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define waitProcess 20

void sigint_handler(int sig)
{
  printf("This is a special signal handler for SIGINT   \n");
}

int main(void){
	
	int number, flag=0;
        int pipefds[2];
	pipe(pipefds);
        pid_t pid = fork();
    
    if(pid == 0) {
    	
        printf("\nEnter Number : ");
        scanf("%d",&number);
        close(pipefds[0]);
        write(pipefds[1], &number, sizeof(number));
        sleep(waitProcess);
        exit(EXIT_SUCCESS);

    }
    
    if(pid > 0) {
      wait(NULL);
      close(pipefds[1]); 
      read(pipefds[0], &number, sizeof(number));
      close(pipefds[0]);
	  
       for(int i = 2; i <= number/2; i++) {
       if(number%i == 0) {
          flag = 1;
          break;
        }
      }
      if (flag==0)
        printf("%d is a prime number\n\n",number);
      else
        printf("%d is not a prime number\n\n",number);
      
     
    }
    	
     void sigint_handler(int sig);
     if (signal(SIGINT, sigint_handler) == SIG_ERR){
     perror("signal");
     exit(1);
    }
   
   return EXIT_SUCCESS;
}

 
