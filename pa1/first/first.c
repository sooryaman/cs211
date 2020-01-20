#include<stdio.h>
#include<stdlib.h>
int trunk(int a);
int isPrime(int b);
int main(int argc, char **argv){
  int i;
  int result;
  int entries;
  FILE* fp= fopen(argv[1],"r");
  fscanf(fp,"%d \n",&entries);
  for(i=0;i<entries;i++){
      int inp; 
    fscanf(fp,"%d\n",&inp);
    result= trunk(inp);
    if(result==0){
       printf("no\n");
  }
  else if(result==1){
    printf("yes\n");
  }
}
  fclose(fp);
  return 0;
}
int trunk(int a){
  int x=0;
  int temp=0;
  while(a/10!=0){
    temp=isPrime(a);
    if(temp==0){
      return 0;
    }
    a=a/10;
  }
     x=isPrime(a);
  if(x==0){
    return 0;
  }
  return 1;
}
int isPrime(int b){
  int z=0;
  for(z=2;z<b;z++){
    if(b%z==0){
      return 0;
    }
   
  }
  return 1;
}




