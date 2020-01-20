#include<stdio.h>
#include<stdlib.h>
int ** allocate(int row, int col){
  int i;
  int** matrix=malloc(row*sizeof(int*));
  for(i=0;i<row;i++){
    matrix[i]=malloc(col*sizeof(int));
  }
  return matrix;
}



int main(int argc, char ** argv){
  FILE* fp=fopen(argv[1],"r");
  if(fp==NULL){
    return 0;
  }
  int m1r;
  int m1c;
  fscanf(fp,"%d\t%d\n",&m1r, &m1c);
  int** m1=allocate(m1r,m1c);
  //int ** m1[100][100];
  int j;
  int i;
  for(i=0;i<m1r;i++){
    for(j=0;j<m1c-1;j++){
      fscanf(fp,"%d\t", &m1[i][j]);
    }
    fscanf(fp,"%d\n",&m1[i][m1c-1]);
  }

  int m2r;
  int m2c;
  fscanf(fp,"%d\t%d\n",&m2r,&m2c);
  if(m1c!=m2r){
    printf("bad-matrices");
    return 0;
  }
  int** m2=allocate(m2r,m2c);
  //int ** m2[100][100];
  int x;
  int y;
  for(x=0;x<m2r;x++){
    for(y=0;y<m2c-1;y++){
      fscanf(fp,"%d\t", &m2[x][y]);
    }
    fscanf(fp,"%d\n",&m2[x][m2c-1]);
  }
  int** result=allocate(m1r,m2c);
  //int ** result[100][100];
  int a;
  int b;
  int c;
  int val=0;
  for(a=0;a<m1r;++a){
    for(b=0;b<m2c;++b){
      for(c=0;c<m1c;++c){
      val=val+(m1[a][c]*m2[c][b]);

      }
        //printf("%d " , val);
        result[a][b]=val;
        val=0;
      }
    }
    for(x=0;x<m1r;x++){
      for(y=0;y<m2c-1;y++){
        printf("%d\t",result[x][y]);
      }
      printf("%d\n",result[x][m2c-1]);
    }
}
