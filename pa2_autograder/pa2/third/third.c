#include<stdio.h>
#include<stdlib.h>
double** inverse(double** mat, int r);
double** transpose(double** o, int r, int c);
double** multiply(double** A, double** B, int ra, int ca, int rb, int cb);
void freemat(double** mat, int row, int c);
double** allocate(int row, int col){
  int i;
  double** matrix=malloc(row*sizeof(double*));
  for(i=0;i<row;i++){
    matrix[i]=malloc(col*sizeof(double));
  }
  return matrix;
}
int main(int argc, char** argv){
  FILE* fp=fopen(argv[1],"r");
  int K, N;
  fscanf(fp,"%d\n",&K);
  fscanf(fp,"%d\n",&N);
  FILE* test=fopen(argv[2],"r");
  int ex;
  fscanf(test,"%d\n",&ex);
  //printf("%d %d %d\n",K+1,N,ex);
  double** testfile=allocate(ex,K+1);
  double** X=allocate(N,K+1);
  double** Y=allocate(N,1);
  for(int i=0;i<N;i++){
    for(int j=0;j<1;j++){
        Y[i][j]=0;
      }
    }
  for(int i=0;i<ex;i++){
    for(int j=0;j<K+1;j++){
        testfile[i][j]=1;
      }
    }
  for(int i=0;i<ex;i++){
    for(int j=1;j<K;j++){
      fscanf(test,"%lf,", &testfile[i][j]);
    }
    fscanf(test,"%lf\n",&testfile[i][K]);
  }

  for(int i=0;i<N;i++){
    for(int j=0;j<K+1;j++){
        X[i][j]=1;
      }
    }
  for(int i=0;i<N;i++){
    for(int j=1;j<=K;j++){
        fscanf(fp,"%lf,",&X[i][j]);
      }
        fscanf(fp,"%lf\n",&Y[i][0]);
    }


  double ** W=allocate(K+1,1);
  double** XT=allocate(K+1,N);
  double** result=allocate(ex,1);
  XT=transpose(X,N,K+1);
  double** XXT=allocate(K+1,K+1);
  XXT=multiply(XT,X,K+1,N,N,K+1);
  double** invXXT=allocate(K+1,K+1);
  invXXT=inverse(XXT,K+1);
  double** invXXTXT=allocate(K+1,N);
  invXXTXT=multiply(invXXT,XT,K+1,K+1,K+1,N);
  W=multiply(invXXTXT,Y,K+1,N,N,1);
  result=multiply(testfile,W,ex,K+1,K+1,1);

  for(int i=0;i<ex;i++){
    for(int j=0;j<1;j++){
      printf("%0.0lf ",result[i][j]);
    }
    printf("\n");
  }
  freemat(X,N,K+1);
  freemat(XT,K+1,N);
  freemat(Y,N,1);
  freemat(testfile,ex,K+1);
  freemat(XXT,K+1,K+1);
  freemat(invXXT,K+1,K+1);
  freemat(invXXTXT,K+1,N);
  freemat(W,K+1,1);
  freemat(result,ex,1);
  fclose(fp);
  fclose(test);
}

double** transpose(double** o, int r, int c){
  double** t=allocate(c,r);
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      t[j][i]=o[i][j];
    }
  }
  return t;
}

double** multiply(double** A, double** B, int ra, int ca, int rb, int cb){
  double** res=allocate(ra,cb);
  if(ca!=rb){
    printf("wrong matrix\n");
    return 0;
  }
  double val=0;
  for(int a=0;a<ra;++a){
    for(int b=0;b<cb;++b){
      for(int c=0;c<ca;++c){
      val=val+(A[a][c]*B[c][b]);
      }
        res[a][b]=val;
        //printf("%d \n",val);
        val=0.0;
      }
    }
    return res;
}

double** inverse(double** mat, int r){
  double** res=allocate(r,r);
  double ag[r][r*2];

  for(int i=0;i<r;i++){
    for(int j=0;j<r;j++){
      ag[i][j]=mat[i][j];
    }
  }

  for(int i=0;i<r;i++){
    for(int j=0;j<r;j++){
      if(i==j){
        ag[i][j+r]=1;
      }
      else{
        ag[i][j+r]=0;
      }
    }
  }


  double op=0;

  for(int i=0;i<r;i++){
    for(int j=0;j<r;j++){
      if(i!=j){
        op=ag[j][i]/ag[i][i];
        for(int x=0;x<(r*2);x++){
          ag[j][x]=ag[j][x]-(op*ag[i][x]);
        }
      }
    }
  }
  double t;
  for(int i=0;i<r;i++){
    t=ag[i][i];
    for(int j=0;j<(2*r);j++){
      ag[i][j]=ag[i][j]/t;
    }
  }
  /*for(int i=0;i<r;i++){
    for(int j=0;j<r*2;j++){
      printf("%lf ",ag[i][j]);

    }
    printf("\n");
  }*/
  for(int i=0;i<r;i++){
    for(int j=0;j<r;j++){
      //printf("%lf ",ag[i][j]);
      res[i][j]=ag[i][j+r];
    }
    //printf("\n");
  }
  return res;
}

void freemat(double** mat, int row, int col){
  for(int i=0;i<row;i++){
      double* curr=mat[i];
      free(curr);
  }
}
