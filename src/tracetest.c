#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>

#include <sys/time.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysinfo.h>
#include <signal.h>
#include <errno.h>

//  getcwd()

int main(int argc, const char *argv[])
{   
    struct timeval tv;
    unsigned time;
    struct sysinfo info;
    struct stat fileStat;
    char buf[36], time_buffer[30];
    size_t nbytes = sizeof(buf);
    char *cwd;

    int fd = open("testfile.txt", O_RDWR | O_CREAT | O_APPEND, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

    if (write(fd, "This will be output to testfile.txt\n", 36) != 36)
        printf("write error: %s\n", strerror(errno));
    
    if(read(fd, buf, nbytes) != 36)
        printf("read error: %s\n", strerror(errno));

    if(fstat(fd, &fileStat ) != 0) 
        printf("stat error: %s\n", strerror(errno));

    if(rename("text.txt", "newtext.txt") != 0)
        printf("rename error: %s\n", strerror(errno));

    if(mkdir("myDir", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) != 0)
        printf("mkdir error: %s\n", strerror(errno));

    if(chmod("myDir", S_IRUSR | S_IRGRP | S_IROTH) != 0)
        printf("chmod error: %s\n", strerror(errno));

    if(rmdir("myDir") != 0)
        printf("rmdir error: %s\n", strerror(errno));

    if((time = sleep(3)) != 0)
        printf("Unslept time: %d", time);

    if(kill( getpid(), SIGCHLD ) != 0)
        printf("kill error: %s\n", strerror(errno));

    if (gettimeofday(&tv, NULL) != 0)
        printf("time error: %s\n", strerror(errno));
    time_t current_time;

    current_time = tv.tv_sec;

    strftime(time_buffer, 30, "%m-%d-%Y %T.", localtime(&current_time));
    printf("%s%ld\n", time_buffer, tv.tv_usec);

    if ((cwd = getcwd(NULL, 64)) == NULL)
         printf("current directory error: %s\n", strerror(errno));


    (void)printf("%s\n", cwd);

    free(cwd);
    
    printf("Current");
    //Path from getcwd
    //if(chroot(PATH) != 0)
    //    printf("chroot error: %s\n", strerror(errno));
    
    if(sysinfo(&info) != 0)
        printf("sysinfo error: %s\n", strerror(errno));

    int childPID = fork();

    if (childPID == 0)
    {
        printf("child PID = %d\n", getpid());

        execl("/bin/sleep", "/bin/sleep", "10", (char *) 0);

    } else {
        int status;

        wait(&status);
        
        printf("parent PID = %d\n", getpid());
    }


    close(fd);

    _exit(1);

    return 0;
}

