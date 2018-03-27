#include "types.h"
#include "stat.h"
#include "user.h"
#include "syscall.h"





char buf[512];

int
test(int fd)
{
  int n;
  while((n = read(fd, buf, sizeof(buf))) > 0)
    write(1, buf, n);

    write(1, strcpy(buf, "booo"), sizeof(buf));
    write(1, strcpy(buf, "booo"), sizeof(buf));
    write(1, strcpy(buf, "booo"), sizeof(buf));

    read(fd, buf, sizeof(buf));
  if(n < 0){
    printf(1, "cat: read error\n");
    exit();
  }

  return 5;
}

int
main(int argc, char *argv[])
{


  int fd, i;

  if(argc <= 1){
    test(0);
    exit();
  }

  for(i = 1; i < argc; i++){
    if((fd = open(argv[i], 0)) < 0){
      printf(1, "cat: cannot open %s\n", argv[i]);
      exit();
    }
    test(fd);
    close(fd);
    int writeCount = getCallCount(SYS_write);
    int readCount = getCallCount(SYS_read);
    int errorCount = getCallCount(-99);
    int errorCount2 = getCallCount(43);

    printf(1, "Write System Calls: %d\n", writeCount);
    printf(1, "Read System Calls: %d\n", readCount);
    printf(1, "Error1 System Calls: %d\n", errorCount);
    printf(1, "Error2 System Calls: %d\n", errorCount2);






  }
  exit();
}
