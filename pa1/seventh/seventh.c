#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char ** argv){
  
  char* str;
  int length;
  int x;
  for(x=1;x<argc;x++){
    str=argv[x];
    length=strlen(str);
    printf("%c",str[length-1]);
  }
  printf("\n");
  return 0;
}
