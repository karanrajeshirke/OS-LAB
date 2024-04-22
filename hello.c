#include<stdio.h>
#include<unistd.h>
int main()

{


	printf("inside the hello file which was called by exec ,the process id is :  %d \n",getpid());
	
	return 0;
}
