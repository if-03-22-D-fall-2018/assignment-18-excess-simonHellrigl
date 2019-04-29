#include <sys/ioctl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char const *argv[])
{
  FILE* fd = fopen ("filename.txt", "r");
  int len = 0;
  while (!feof(fd))
  {
    char next = fgetc(fd);
    if (next == '\n')
    {
      len++;
    }
    printf("%c", next);
  }
  return 0;
}
