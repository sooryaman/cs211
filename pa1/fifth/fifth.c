#include<stdio.h>
#include<stdlib.h>
int main (int argc, char** argv){
  FILE* fp=fopen(argv[1],"r");
  int row;
  fscanf(fp,"%d\n",&row);
  int column=row;
  int mat[row][column];
  int i, j;
  for(i=0;i<row;i++){
    for(j=0;j<column-1;j++){
      fscanf(fp,"%d\t",&mat[i][j]);
    }
    fscanf(fp,"%d\n",&mat[i][column-1]);
	   }

 int size=(row*2)+2;
 int arr [size];
 int k;
 for(k=0;k<size;k++){
   arr[k]=0;
 }


for(i=0;i<row;i++){
    for(j=0;j<column;j++){
      arr[i]=arr[i]+mat[i][j];
    }
	      }
for(j=0;j<column;j++){
    for(i=0;i<row;i++){
      arr[row+i]=arr[row+i]+mat[i][j];
    }
	      }
   for(i=0;i<row;i++){
     arr[2*row]=arr[2*row]+mat[i][i];
	      }
 for(i=0;i<row;i++){
   arr[(2*row)+1]=arr[(2*row)+1]+mat[row-1-i][i];
	      }
 // int p;
 // for(p=0;p<(row*2)+2;p++){
 // printf("%d\t",arr[p]);
 //}
 int flag=0;
 int l;
 for(l=0;l<size-1;l++){
   if(arr[l]!=arr[l+1]){
     flag++;
   }
 }
 int flag2=0;
 int value=mat[0][0];
 //printf("%d ",mat[0][0]);
 for(int t=0;t<row;t++){
   for(int c=0;c<column;c++){
     //printf("%d ",mat[t][c]);
     if(mat[t][c]!=value){
       flag2++;

       break;
     }
   }
 }
 //printf("%d ",flag2);
 if(flag==0 && flag2!=0){
   printf("magic\n");
 }
 else{
   printf("not-magic\n");
 }
 return 0;
}
