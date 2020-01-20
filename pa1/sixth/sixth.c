#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int isVow(char z);
int main(int argc, char **argv){
  char* word;
  char result[100];
  int x;int len;int y;
  for(x=1;x<argc;x++){
    word=argv[x];
    len=strlen(word);
    if(isVow(word[0])){
      printf("%syay ",word);
      } 
    else{
      for(y=0;y<len;y++){
       if(isVow(word[y])){
         strcpy(result, word+y);
	 strncpy(result + strlen(word)-y ,word, y);
	 strcpy(result + strlen(word), "ay");
         break;
       }
      }
    
    printf("%s " , result);
    }
  }
    printf("\n");
  
   
	     
      return 0;
}
  
int isVow(char z){
  if (z=='a' ||z=='e' ||z=='i' ||z=='o' ||z=='u' ||z=='A' ||z=='E' ||z=='I' ||z=='O' ||z=='U'){
    return 1;
  }
  return 0;
}

  
 
	 
	
	




        


