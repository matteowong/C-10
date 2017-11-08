#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

static void sighandler(int signo) {

  if (signo==SIGINT) {
    int fd;
    fd = open("foo",O_WRONLY | O_APPEND | O_CREAT,0644);
    char s[]="File closed because SIGINT signal received.\n";
    write(fd,s,sizeof(s));
    printf("Wrote to foo\n");
    close(fd);
    exit(0);

  }
  if (signo==SIGUSR1) {
    printf("Parent process PID: %d\n",getppid());

  }

}

int main() {

  signal(SIGINT,sighandler);
  signal(SIGUSR1,sighandler);

  while(1) {
    printf("signal.c PID: %d\n",getpid());
    sleep(1);

  }
}
