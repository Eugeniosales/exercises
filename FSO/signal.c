#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

int aciona = 0;

void trataSinal(int s) {

    if(s == SIGTERM) {
        printf("Recebi 15\n");
        if(aciona == 2) {
            printf("Senha acionada\n");
            aciona++;
        } else aciona = 0;
    }

    else if(s == SIGINT) {
        printf("Recebi 2\n");
        aciona = 1;
    }

    else if(s == SIGUSR1) {
        printf("Recebi 10\n");
        if(aciona == 3) {
            printf("Tchau\n");
            exit(0);
        } else aciona = 0;
    }

    else if(s == SIGUSR2) {
        printf("Recebi 12\n");
        if(aciona == 1) aciona++;
        else aciona = 0;
    }
}

int main(void)
{
    signal(SIGTERM, trataSinal);
    signal(SIGUSR1, trataSinal);
    signal(SIGUSR2, trataSinal);
    signal(SIGINT, trataSinal);
    
    while(1)
        pause();

    return 0;
}
