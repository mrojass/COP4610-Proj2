#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
//  open()
//  read()
//  write()
//  close()
//  fork()
//  exec()
//  wait()
//  getTime()
//  getpid()
//  getcwd()
//
//  changeMod()
//  makedir()
//  removeDir()
//  rename()
//  exit()
//  sysInfo()
//  kill()
//  sethostname()
//  sleep()
//  chroot()
//

int main(int argc, const char *argv[])
{
    int fd = open("text.txt", O_WRONLY | O_RDONLY | O_CREAT | O_APPEND);
    return 0;
}
