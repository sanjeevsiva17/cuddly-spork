#include <stdio.h>
#include <malloc.h>
struct Directory{
struct Directory *parent, *child[5];
char name;
int n, level;
}*root;
struct Directory* init(struct Directory *ptr, struct Directory *parent,int level){
int i;
struct Directory* node=(struct Directory*)malloc(sizeof(struct Directory));
node->parent=parent;
node->level=level;
printf(" Enter name: ");
scanf(" %s",&node->name);
printf(" Enter number of files: ");
scanf(" %d",&node->n);
ptr=node;
for(i=0; i<ptr->n; i++)
node->child[i]=init(node->child[i],node,node->level+1);
return node;
}
void disp(struct Directory *ptr){
int i;
if(ptr){
printf("\n");
for(i=0;i<ptr->level;i++)
printf("\t");
printf("%c",ptr->name);
if(ptr->n!=0)
printf(" ->");
for(i=0;i<ptr->n;i++){disp(ptr->child[i]);
}
}
}
int main(){
root=init(root,NULL,0);
disp(root);
printf("\n");
return 1;
}
