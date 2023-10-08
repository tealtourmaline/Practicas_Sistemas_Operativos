#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
	int pid, pid1, pid2, i;
    int acumulado = 0;
	pid = fork();

	if (pid == 0) {
		for(i=0; i<=5; i++){
            acumulado += i;
            printf("hijo[1] --> pid = %d y ppid = %d, acumulado = %d\n", getpid(), getppid(), acumulado);
        }
        printf("\n");
	}

	else {

        wait(NULL);
		pid1 = fork();

		if (pid1 == 0) {
			for(i=0; i<=5; i++){
                acumulado += i;
                printf("hijo[2] --> pid = %d y ppid = %d, acumulado = %d\n", getpid(), getppid(), acumulado);
            }
            printf("\n");
		}

		else {

            wait(NULL);
			pid2 = fork();

			if (pid2 == 0) {
				for(i=0; i<=5; i++){
                    acumulado += i;
                    printf("hijo[3] --> pid = %d y ppid = %d, acumulado = %d\n", getpid(), getppid(), acumulado);
                }
                printf("\n");
			}

			else {

                wait(NULL);
                for(i=0; i<=5; i++){
                    acumulado += i;
                    printf("padre --> pid = %d, acumulado = %d\n", getpid(), acumulado);
                }
                printf("\n");
			}
		}
	}

	return 0;
}
