#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

struct symbolInfo{
    char name[20];
    char type[20];
    struct symbolInfo *next;
}*p[MAX];

typedef struct symbolInfo node;

int getHashKey(char a[]){
    int i,index,sum=0;
    for(i=0;a[i]!='\0';i++){
            sum=sum+a[i];
    }
    index=sum%MAX;
    return index;
}

void insert(char a[],char b[],int index){
    node *temp=new node();
    strcpy(temp->name,a);
    strcpy(temp->type,b);
    temp->next=p[index]->next;
    p[index]->next=temp;
    printf("INSERTED!\n");
}

bool search(char a[]){
    int index=getHashKey(a);
    node *temp=p[index];
    while(temp!=NULL && strcmp(temp->next->name,a)!=0){
            temp=temp->next;
    }
    if(temp==NULL)
            return false;
    else
            return true;
}

void remove(char a[])
{
    int result =0;
    int i,index=getHashKey(a);
    for(i=0;a[i]!='\0';i++){
         node *temp=p[index];
         while(temp->next!=NULL && strcmp(temp->next->name,a)!=0){
            temp=temp->next;
         }
         if(temp==NULL){
            printf("Nothing to Delete!!\n");
         }
         else{
            node* del=temp->next;
            temp->next=del->next;
            free(del);
            printf("Deleted!\n");
         }
       }

}

void show()
{
    int i;
    for(i=0;i<MAX;i++){
            node *temp=p[i]->next;
            printf("%d - ",i);
            while(temp!=NULL){
                printf("%s -> %s\t",temp->name,temp->type);
                temp=temp->next;
            }
            printf("\n");
    }
}

void update(char a[],char b[])
{
    int index=getHashKey(a);
    node *temp=p[index];
    while(temp!=NULL && strcmp(temp->name,a)!=0){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Nothing to Update!\n");
    }
    else{
        strcpy(temp->type,b);
        printf("Updated!\n");
    }
}

int main()
{
    int choice;
    for(int i=0;i<MAX;i++){
        p[i]=new node();
        p[i]->next=NULL;
    }

    while(1){
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Show\n5. Update\n6. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        if(choice==1){
            char x[50],name[50],type[50];
            int i,j,index;
            printf("Enter input : ");
            fflush(stdin);
            gets(x);
            for(i=0;x[i]!=',';i++){
                name[i]=x[i];
            }
            int k=0;
            for(j=i+1;x[j]!='\0';j++){
                type[k]=x[j];
                k++;
            }
            name[i]='\0';
            type[k]='\0';
            index=getHashKey(name);
            insert(name,type,index);
        }

        else if(choice==2){
            char x[50];
            printf("Enter name to search : ");
            fflush(stdin);
            gets(x);
            bool result=search(x);
            if(result==true){
                printf("Value exist");
            }
            else if(result==false){
                printf("Does not exist");
            }
        }
        else if(choice==3){
            char m[500];
            printf("Enter name to delete : ");
            fflush(stdin);
            gets(m);
            remove(m);
        }

        else if(choice==4){
           show();
        }

        else if(choice==5){
            char x[50],y[50];
            printf("Enter name : ");
            fflush(stdin);
            gets(x);
            printf("Enter new class type : ");
            fflush(stdin);
            gets(y);
            update(x,y);
        }

        else if(choice==6){
           break;
        }
    }
    return 0;
}



