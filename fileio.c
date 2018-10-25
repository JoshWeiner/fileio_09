#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> // for open
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main() {

  printf("TESTING OPEN AND CLOSE \n");
  int descriptor = open("test.txt", O_RDONLY | O_CREAT, 644);
  printf("Descriptor: %d\n", descriptor);

  descriptor = close(descriptor);
  printf("Closing: %d\n", descriptor);

  printf("TESTING READING AND WRITING \n");
  descriptor = open("test.txt", O_WRONLY, 644);
  descriptor = write(descriptor, "hello, world", strlen("hello, world"));
  printf("Written? : %d", descriptor);

}
