#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

int main() {

  printf("TESTING OPEN AND CLOSE \n");
  int descriptor = open("test.txt", O_RDONLY | O_CREAT, 0700);
  printf("Descriptor: %d\n", descriptor);
  descriptor = close(descriptor);
  printf("Closing: %d\n", descriptor);

  printf("============================\n");
  printf("TESTING READING AND WRITING \n");

  printf("Opening test.txt \n");
  char * str = "hello, world";
  descriptor = open("test.txt", O_WRONLY, 0700);
  descriptor = write(descriptor, str, strlen(str));
  printf("Written: %s, Descriptor: %d \n", str, descriptor);
  close(descriptor);

  printf("Testing read... \n");
  descriptor = open("test.txt", O_RDONLY, 0700);
  char *b = (char *) calloc(100, sizeof(char));
  printf("%d \n", descriptor);
  // printf("%d \n", read(descriptor, b, 12));
  if(read(descriptor, b, 12) < 0){
   	printf("Error while reading \n");
  }
  else {
    printf("No errors while reading \n");
  }

  printf("Testing read result: ");

  for(int i=0; i<12; i++) {
      printf("%c", b[i]);
  }
  printf("\n");

  printf("...Closing file \n");
  close(descriptor);

}
