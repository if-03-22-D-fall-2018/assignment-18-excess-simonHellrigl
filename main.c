#include <sys/ioctl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

int GetWidth();
int GetHeight();
int main(int argc, char const *argv[])
{
  FILE* fd = fopen ("filename.txt", "rw");
  fputs("i love C programming so much\n", fd);
  fputs("testcase\n", fd);
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
  fclose(fd);

  return 0;
}

struct winsize getWindowSize()
{
  struct winsize ws;
  if (ioctl(0,TIOCGWINSZ,  &ws) != 0)
  {
    fprintf(stderr, "TIOCGWINSZ:%s\n", strerror(errno));
    exit(-1);
  }
  return ws;
}

int GetWidth()
{
  return getWindowSize().ws_col;
}

int GetHeight()
{
  return getWindowSize().ws_row;

}
