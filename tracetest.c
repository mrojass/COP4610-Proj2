#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysinfo.h>
#include <signal.h>
#include <errno.h>


//  fork()
//  exec()
//  wait()
//  getTime()
//  getpid()
//  getcwd()

int main(int argc, const char *argv[])
{
    unsigned time;
    struct sysinfo info;
    struct stat fileStat;
    char buf[36];
    size_t nbytes = sizeof(buf);

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

    //Path from getcwd
    //if(chroot(PATH) != 0)
    //    printf("chroot error: %s\n", strerror(errno));
    
    if(sysinfo(&info) != 0)
        printf("sysinfo error: %s\n", strerror(errno));

    int childpid = fork();

    if (childpid == 0)
    {
        exec("/bin/sleep", "10");

    } else {
        int childFinished;

        childFinished = waitpid(0, 0, (int *) NULL);
    }

    close(fd);

    _exit(1);

    return 0;
}

