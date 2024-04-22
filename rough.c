#include <stdio.h>
#include <unistd.h>   //fork
#include <sys/wait.h> //wait

int main()
{
    int id = fork();

    if (id == -1)
    {
        printf("fork failed ");
        return 2;
    }
    else if (id == 0)
    {
        // child
        // char *args[] = {'cp', 'src.txt', 'dst.txt', NULL};
        char *args[] = {'bin/ls', NULL};

        execvp(args[0], args);
    }
    else
    {
        // parent
        printf("pid of parent : %d", getpid());
        printf("id : %d", id);
    }

    return 0;
}

// fork()->child,parent
// child -> exec()
//  -1,0,>0
// fail,child,parent

// exec

// execvp
