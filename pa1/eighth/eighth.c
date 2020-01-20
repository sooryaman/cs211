#include<stdio.h>
#include<stdlib.h>
struct tree{
  int value;
  struct tree* left;
  struct tree* right;
  int level;
};
struct tree* allocate(){
  struct tree* temp=malloc(sizeof(struct tree));
  temp->left=NULL;
  temp->right=NULL;
  temp->level=0;
  return temp;
}
int insert(struct tree* root, int value);
int search(struct tree* root, int value);
int main(int argc, char** argv){

  FILE* fp=fopen(argv[1],"r");
  if(fp==NULL){
    printf("error\n");
    return 0;
  }
    int leveli;
  int levels;
  char operation;
  int num;
  struct tree* root=allocate();

  while(fscanf(fp,"%c\t%d\n",&operation, &num)!=EOF){
    if(operation=='i'){
      leveli=insert(root, num);
      if(leveli==0){
        printf("duplicate\n");
      }
      else{
        printf("inserted %d\n",leveli);
      }
    }
    else if(operation=='s'){
      levels=search(root,num);
      if(levels==0){
        printf("absent\n");
      }
      else{
        printf("present %d\n",levels);
      }
    }
  }
  fclose(fp);
}

int insert(struct tree* root, int value){
  struct tree* ptr=root;
  struct tree* prev=NULL;
  struct tree* new=allocate();
  int l=1;
  if(root->level==0){
    root->value=value;
    root->level=1;
    return 1;
  }
  new->value=value;
  new->level=0;

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

  new->level=l;
  if(prev->value>new->value){
    prev->left=new;
    return l;
  }
  else{
    prev->right=new;
    return l;
  }
}
int search(struct tree* root, int val){
  struct tree* ptr=root;
  while(ptr!=NULL){
    if(ptr->value==val){
      return ptr->level;
    }
    else if(ptr->value>val){
      ptr=ptr->left;
    }
    else if(ptr->value<val){
      ptr=ptr->right;
    }
  }
  return 0;
}
