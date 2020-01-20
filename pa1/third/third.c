#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int val;
  struct node* next;
}nodes;

typedef struct hasht{
  struct node** bucket;
  int size;
}hashts;

struct hasht* newt(int size);
int insert(struct node* newNode, struct hasht* maint);
int search(struct hasht* maint, int val);
void freet(struct hasht* maint);

int main(int argc, char ** argv){
  FILE* fp=fopen(argv[1],"r");
  if(fp==NULL){
    return 0;
  }
   struct node* temp=NULL;
   struct hasht* maint=newt(1000);

  char operation;
  int value;
  while(fscanf(fp,"%c\t%d",&operation,&value)!=EOF){
      if(operation=='i'){
      temp=NULL;
      struct node* temp2=malloc(sizeof(nodes));
      temp2->val=value;
      temp2->next=temp;
      temp=temp2;
      if(insert(temp , maint)){
	       printf("inserted\n");
      }
      else{
	        printf("duplicate\n");
}


    }
    if(operation=='s'){
      if(search(maint, value)){
       printf("present\n");
      	}
      	else{
      	  printf("absent\n");
      	}
     }

  }

  fclose(fp);
  freet(maint);
  return 0;
  }

  struct hasht* newt(int size){
    struct hasht *maint=malloc(sizeof(struct hasht));
    maint->size=size;
    maint->bucket=malloc(size* sizeof(struct node*));
    int j;
    for(j=0;j<size;j++){
      maint->bucket[j]=NULL;
    }
    return maint;
  }

  int insert(struct node* newNode, struct hasht* maint){
    int value=newNode->val;
    int k;
    if(value<0){
      k=(value*-1)%maint->size;
    }else{
    k=value%maint->size;
  }
    struct node* elem=NULL;
    if(maint->bucket[k]==NULL){
      maint->bucket[k]=newNode;
      return 1;
    }
    if(maint->bucket[k]->val==value){
      return 0;
    }
    elem=maint->bucket[k];
    while(elem->next!=NULL){
      if(elem->next->val==value){
	       return 0;
      }
      elem=elem->next;
    }
    elem->next=newNode;

  return 1;

  }

int search(struct hasht* maint, int s){
  int k;
if(s<0){
   k=((s*-1)%maint->size);
}else{
 k=s%maint->size;
}
 if(maint->bucket[k]==NULL){
   return 0;
 }
 if(maint->bucket[k]->val==s){
   return 1;
 }
 struct node* temp=maint->bucket[k];
 while(temp->next!=NULL){
   if(temp->next->val==s){
     return 1;
   }
   temp=temp->next;
 }
 return 0;
}
void freet(struct hasht* maint){
  int i;
  for(i=0;i<maint->size;i++){
      struct node* temp=maint->bucket[i];
      while(temp!=NULL){
      struct node* temp2= temp;
      temp=temp->next;
      free(temp2);
      }

  }
}
