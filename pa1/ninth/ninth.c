#include<stdio.h>
#include<stdlib.h>
struct tree{
  int value;
  struct tree* left;
  struct tree* right;

};
struct tree* allocate(){
  struct tree* temp=malloc(sizeof(struct tree));
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}
int insert(int value);
int search(int value);
int delete(struct tree* root, int value);
struct tree* root=NULL;
int main(int argc, char** argv){

  FILE* fp=fopen(argv[1],"r");
  if(fp==NULL){
    printf("error\n");
    return 0;
  }
    int leveli=0;
  int levels;
  char operation;
  int num;

  while(fscanf(fp,"%c\t%d\n",&operation, &num)!=EOF){
    if(operation=='i'){
      leveli=insert(num);
      if(leveli==0){
        printf("duplicate\n");
      }
      else{
        printf("inserted %d\n",leveli);
      }
    }
    else if(operation=='s'){
      levels=search(num);
      if(levels==0){
        printf("absent\n");
      }
      else{
        printf("present %d\n",levels);
      }
    }
    else if(operation=='d'){
      int del=-2;
      del=delete(root, num);
      if(del==0){
        printf("fail\n");
      }
      else{
        printf("success\n");
      }
    }
  }
  fclose(fp);
}

int insert(int value){
  struct tree* ptr=root;
  struct tree* prev=NULL;
  struct tree* new=allocate();
  int l=1;
  if(root==NULL){

    new->value = value;
    new->left = NULL;
    new->right = NULL;
    root = new;
    return 1;
  }
  new->value=value;

  while(ptr!=NULL){
    if(ptr->value==new->value){
      return 0;
    }
    if(ptr->value>new->value){
      prev=ptr;
      ptr=ptr->left;
      l++;
    }
    else{
      prev=ptr;
      ptr=ptr->right;
      l++;
    }
  }


  if(prev->value>new->value){
    prev->left=new;
    return l;
  }
  else{
    prev->right=new;
    return l;
  }
}
int search(int val){
  struct tree* ptr=root;
  int count=1;
  while(ptr!=NULL){
    if(ptr->value==val){
      return count;
    }
    else if(ptr->value>val){
      ptr=ptr->left;
      count++;
    }
    else if(ptr->value<val){
      ptr=ptr->right;
      count++;
    }
  }
  return 0;
}
int delete(struct tree* root, int value){

  struct tree* ptr=root;
  struct tree* prev=NULL;
  if(root==NULL){
    return 0;
  }
  /*int s=search(ptr, value);
  if(s==0){
    return 0;
  }*/
  while(ptr!=NULL){
    //printf("loop is accessed\n");
    if(ptr->value==value){
      break;
    }
    prev=ptr;
    if(ptr->value>value){
      ptr=ptr->left;
    }
    if(ptr->value<value){
      ptr=ptr->right;
    }
  }
  if(ptr==NULL){
    //printf("pointer is null\n");
    return 0;
  }
  struct tree* temp=NULL;
  if(ptr->right!=NULL && ptr->left!=NULL){
    temp=ptr->right;
    while(temp->left !=NULL){
      prev=temp;
      temp=temp->left;
    }

    int tempVal=temp->value;
    //printf("%d\n", tempVal);
    int a=delete(ptr, tempVal);
    ptr->value=temp->value;

    if(a==1){
      return 1;
    }

  }
  struct tree* tmp2=NULL;
if(ptr==root){
  if(ptr->left==NULL){
    root=ptr->right;

  }
  else if(ptr->right==NULL){
    root=ptr->left;
  }
  return 1;
}
//printf("ptr->value\n");
if(ptr->right!=NULL){
  tmp2=ptr->right;
}
else if(ptr->left!=NULL){
  tmp2=ptr->left;
}
if(ptr==prev->left){
  prev->left=tmp2;
}
else{
  prev->right=tmp2;
}
return 1;

}
