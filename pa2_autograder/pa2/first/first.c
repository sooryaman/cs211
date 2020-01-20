#include<stdio.h>
#include<stdlib.h>
char puzz[16][16];
char val[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int allowed(int r, int c, int num);
int solve();
int check();
int main(int argc, char** argv){
  FILE* fp=fopen(argv[1],"r");
  for(int i=0;i<16;i++){
    for (int j=0;j<16;j++){
      fscanf(fp,"%c\t",&puzz[i][j]);
  }
}
int flag=0;
int r;
int c;

for(r=0;r<16;r++){
  for (c=0;c<16;c++){
    if(puzz[r][c]=='-'){
      flag=1;
      break;
    }
}
if(flag==1){
  break;
}
}
if(r==16 && c==16){
  printf("no-solution\n");
  return 0;
}
int sol=solve();
int chk=check();
if(sol==1 && chk==1){
  for(int i=0;i<16;i++){
    for (int j=0;j<16;j++){
      printf("%c\t",puzz[i][j]);
    }
    printf("\n");
}
}
else{
  printf("no-solution\n");
}
return 0;
}

int solve(){
  int r, c;
  int flag=0;
  for(r=0;r<16;r++){
    for(c=0;c<16;c++){
      if(puzz[r][c]=='-'){
        flag=1;
        break;
      }
    }
    if(flag==1){
      break;
    }
    }
    if(r==16 && c==16){
      return 1;
  }
  for(int k=0;k<16;k++){
    if(allowed(r,c,k)){
      puzz[r][c]=val[k];
      if(solve()==1){
        return 1;
      }
      puzz[r][c]='-';
    }
  }
  return 0;
}

int allowed(int r, int c, int num){
  int fb=0;
  int fr=0;
  int fc=0;
  int br=r-r%4;
  int bc=c-c%4;
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      if(puzz[i+br][j+bc]==val[num]){
        fb=1;
      }
    }
  }

for(int k=0;k<16;k++){
  if(puzz[k][c]==val[num]){
    fc=1;
  }
}
for(int k=0;k<16;k++){
  if(puzz[r][k]==val[num]){
    fr=1;
  }
}
return (!fb && !fr && !fc && puzz[r][c]=='-');
}
int check(){
  int sumr;
  int sumc;
  int flag=0;
  for(int i=0;i<16;i++){
      sumr=0;
      for(int k=0;k<16;k++){
        sumr=sumr+puzz[i][k];
      }
      //printf("%d\n",sumr);
      if(sumr!=930){
      flag=1;
    }
  }


for(int i=0;i<16;i++){
    sumc=0;
    for(int k=0;k<16;k++){
      sumc=sumc+puzz[k][i];
    }
    //printf("%d\n",sumc);
    if(sumc!=930){
    flag=1;
    }
  }



int sqr;
int s1;
int s2;
int s3;
int s4;
for(int x=0;x<4;x++){
  sqr=(x)*4;
  s1=0;
  s2=0;
  s3=0;
  s4=0;
  for(int y=sqr;y<(x+1)*4;y++){
    for(int z=0;z<4;z++){
      s1=s1+puzz[y][z];
    }
    for(int q=4;q<8;q++){
      s2=s2+puzz[y][q];
    }
    for(int w=8;w<12;w++){
      s3=s3+puzz[y][w];
    }
    for(int e=12;e<16;e++){
      s4=s4+puzz[y][e];
    }
  }
  if(s1!=930 || s2!=930|| s3!=930 || s4!=930){
    flag=1;
  }
  //printf("%d\t%d\t%d\t%d\n",s1,s2,s3,s4);

}
return !flag;
}
