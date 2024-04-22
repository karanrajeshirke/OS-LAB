#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int justFork()
{
	int id = fork();

	if (id == -1)
	{
		printf("fork failed \n ");
		return 1;
	}

	if (id == 0)
	{

		printf("child process with id  : %d \n", getpid());
	}
	else
	{
		printf("parent process with id  : %d  \n", getpid());
	}

	return 2;
}

int withWait()
{
	int id = fork();

	if (id == -1)
	{
		printf("fork failed \n ");
		return 1;
	}

	if (id == 0)
	{

		printf("child process with id  : %d \n", getpid());

		int x;
		printf("enter a number : ");
		scanf("%d", &x);

		if (x < 0)
			printf("negative \n");
		else
			printf("positive \n ");
	}
	else
	{

		wait(NULL);

		printf("parent process with id  : %d  \n", getpid());

		printf("parent started after the child terminated \n");
		printf("------ \n");
		int x;
		printf("enter a number : ");
		scanf("%d", &x);

		if (x % 2 == 0)
			printf("even \n");
		else
			printf("odd \n ");
	}

	return 2;
}
int execFile()
{
	int id = fork();

	if (id == -1)
	{
		printf("fork failed \n ");
		return 1;
	}

	if (id == 0)
	{

		printf("the process id : %d \n", getpid());
		char *args[] = {"./hello", NULL};

		execvp(args[0], args);
	}
	else
	{
		wait(NULL);
	}

	return 2;
}
int execCp()
{
	int id = fork();

	if (id == -1)
	{
		printf("fork failed \n ");
		return 1;
	}

	if (id == 0)
	{
		printf("the process id : %d \n", getpid());
		char *args[] = {"cp", "one.txt", "two.txt", NULL};
		execvp(args[0], args);
	}
	else
	{
		wait(NULL);
	}

	return 2;
}
int execGrep()
{
	int id = fork();

	if (id == -1)
	{
		printf("fork failed \n ");
		return 1;
	}

	if (id == 0)
	{
		printf("the process id : %d \n", getpid());
		char *args[] = {"grep", "karan", "example.txt", NULL};
		execvp(args[0], args);
	}
	else
	{
		wait(NULL);
	}

	return 2;
}
int execPwd()
{
	int id = fork();

	if (id == -1)
	{
		printf("fork failed \n ");
		return 1;
	}

	if (id == 0)
	{
		printf("the process id : %d \n", getpid());
		char *args[] = {"pwd", NULL};
		execvp(args[0], args);
	}
	else
	{
		wait(NULL);
	}

	return 2;
}
int execLs()
{
	int id = fork();

	if (id == -1)
	{
		printf("fork failed \n ");
		return 1;
	}

	if (id == 0)
	{
		printf("the process id : %d \n", getpid());
		char *args[] = {"ls", NULL};
		execvp(args[0], args);
	}
	else
	{
		wait(NULL);
	}

	return 2;
}
int main()
{
	int x;
	printf("enter 1 to fork   \n : ");
	printf("enter 2 to fork with wait  \n : ");
	printf("enter 3 to exec another file   \n : ");
	printf("enter 4 to exec with  cp command   \n : ");
	printf("enter 5 to exec with grep  command   \n : ");
	printf("enter 6 to exec with ls  command   \n : ");
	printf("enter 7 to exec with pwd  command   \n : ");
	scanf("%d", &x);

	switch (x)
	{

	case 1:
		justFork();
		break;
	case 2:
		withWait();
		break;
	case 3:
		execFile();
		break;
	case 4:
		execCp();
		break;
	case 5:
		execGrep();
		break;
	case 6:
		execLs();
		break;
	case 7:
		execPwd();
		break;
	}

	return 0;
}
