//Sadman Sakib Prodhan
//Id : 011151139

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

struct symbolInfo{
    char name[50];
    char type[50];
    struct symbolInfo *next;
}*s[MAX];

typedef struct symbolInfo node;



//int getHashkey(char a[]){
//
//	int i,index,cotlin=0;
//	for(i=0;a[i]!='\0';i++){
//		cotlin=cotlin+a[i];
//    }
//	index = cotlin%MAX;
//	return index;
//}
int getHashKey(char a[]){
    int i,index,cotlin=0;
    for(i=0;a[i]!='\0';i++){
            cotlin=cotlin+a[i];
    }
    index=cotlin%MAX;
    return index;
}



void insert(char name[],char type[], int index){

	node *sadman = new node();
	strcpy(sadman->name,name);
	strcpy(sadman->type,type);
	sadman->next = s[index]->next;
	s[index]->next = sadman;

	printf("\n Your values are inserted!!!!!");
}


bool search(char a[]){
    int index=getHashKey(a);
    node *sadman=s[index];
	while(sadman!=NULL && strcmp(sadman->next->name,a)!=0){
		sadman=sadman->next;
    }
	if(sadman==NULL)
            return false;
    else
            return true;
}
//bool search(char a[])
//{
//	int index = getHashkey(a);
//	node *sadman=s[index];
//	while(sadman!=NULL && strcmp(sadman->next->name,a)!=0){
//		sadman=sadman->next;
//    }
//	if (sadman = NULL)
//	{
//		return false;
//
//	}
//	else
//	{
//		return true;
//	}
//
//}


//void remove(char a []){
//
//	int i;
//	int index = getHashkey(a);
//	for (int i = 0; a[i] != '\0'; i++)
//	{
//		node *sadman=s[index];
//		while(sadman->next!=NULL && strcmp(sadman->next->name,a)!=0){
//			sadman=sadman->next;
//         }
//         if(sadman==NULL){
//            printf("\n There is nothing to Delete!!\n");
//         }
//         else{
//            node* sad=sadman->next;
//			sadman->next=sad->next;
//            free(sad);
//            printf("\n Your value has been Deleted!\n");
//         }
//    }
//
//}

void remove(char a[])
{
    int result =0;
    int i,index=getHashKey(a);
    for(i=0;a[i]!='\0';i++){
         node *sadman=s[index];
		 while(sadman->next!=NULL && strcmp(sadman->next->name,a)!=0){
			 sadman=sadman->next;
         }
		 if(sadman==NULL){
            printf("\n You have Nothing to Delete!!\n");
         }
         else{
			 node* sad=sadman->next;
			 sadman->next=sad->next;
			 free(sad);
            printf("\n Deleted!\n");
         }
       }

}

void show(){

	printf(" Index || Name || Data type");
    for(int j=0;j<MAX;j++){
            node *sadman=s[j]->next;
          //  printf("%d - ",j);
			while(sadman!=NULL){
				printf("%s -> %s\t",sadman->name,sadman->type);
				sadman=sadman->next;
            }
            printf("\n");
			
    }

}

//void update(char a[],char b[])
//{
//    int index = getHashkey(a);
//    node *sadman=s[index];
//    while(sadman!=NULL && strcmp(sadman->name,a)!=0){
//		sadman=sadman->next;
//    }
//    if(sadman==NULL){
//        printf("You have Nothing to Update!\n");
//    }
//    else{
//        strcpy(sadman->type,b);
//        printf("Your value is Updated!\n");
//    }
//}
void update(char a[],char b[])
{
    int index=getHashKey(a);
    node *sadman=s[index];
	while(sadman!=NULL && strcmp(sadman->name,a)!=0){
		sadman=sadman->next;
    }
	if(sadman==NULL){
        printf("You Have Nothing to Update!\n");
    }
    else{
		strcpy(sadman->type,b);
        printf("Sucessfully Updated!\n");
    }
}

//int main(){
//
//	int choice;
//	for (int i = 0; i < MAX; i++)
//	{
//		s[i] = new node;
//		s[i]->next = NULL;
//	}
//
//	while(1){
//
//		printf("\n1. Insert\n2. Search\n3. Delete\n4. Show\n5. Update\n6. Exit\n");
//        printf("Please Enter your choice : ");
//        scanf("%d",&choice);
//
//        if(choice==1){
//            char x[50],name[50],type[50];
//			int i,j,index;
//            printf("Enter input : ");
//            fflush(stdin);
//			gets(x);
//            for(i=0;x[i]!=',';i++){
//                name[i]=x[i];
//            }
//            int k=0;
//            for(j=i+1;x[j]!='\0';j++){
//                type[k]=x[j];
//                k++;
//            }
//            name[i]='\0';
//            type[k]='\0';
//            index = getHashKey(name);
//            insert(name,type,index);
//		
//        }
//
//        else if(choice==2){
//            char x[50];
//            printf("Enter name to search : ");
//            fflush(stdin);
//            gets(x);
//            bool result=search(x);
//            if(result==true){
//                printf("Value exist");
//            }
//            else if(result==false){
//                printf("Does not exist");
//            }
//        }
//        else if(choice==3){
//            char m[500];
//            printf("Enter name to delete : ");
//            fflush(stdin);
//            gets(m);
//            remove(m);
//        }
//
//        else if(choice==4){
//           show();
//        }
//
//        else if(choice==5){
//            char x[50],y[50];
//            printf("Enter name : ");
//            fflush(stdin);
//            gets(x);
//            printf("Enter new class type : ");
//            fflush(stdin);
//            gets(y);
//            update(x,y);
//        }
//
//        else if(choice==6){
//           break;
//        }
//    }
//
//
//
//
//
//	return 0;
//}



int main( )
{
	for (int i = 0; i < MAX; i++)
	{
	s[i] = new node;
	s[i]->next = NULL;
	}
    int choice = 0;
    while(choice != 6)
    {
        /* Printing the available options */
        printf("\n 1. Press 1 for Insert");
        printf("\n 2. Press 2 for Search");
		printf("\n 1. Press 3 for Delete");
        printf("\n 2. Press 4 for Show");
		printf("\n 1. Press 5 for update");
        printf("\n 2. Press 6 for Exit");
        printf("\n Enter your choice  : \n");
        /* Taking users input */
        scanf("%d", &choice);
        
        switch(choice)
        {
			int choice;
			//Insert
            case 1:
				{
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
						index = getHashKey(name);
						insert(name,type,index);
						break;
				}
          case 2:
			  //Search
	//			  int choice;
				  {
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
					break;
				  }
			case 3:
				//Delete
//				int choice;
				{
						char p[500];
					printf("Enter name to delete : ");
					fflush(stdin);
					gets(p);
					remove(p);
					break;
				}
				//Show
		    case 4:{
				   show();
				   break;
				   }
				   //Update
		    case 5:{
				char m[45],n[45];
            printf("Enter name : ");
            fflush(stdin);
            gets(m);
            printf("Enter new class type : ");
            fflush(stdin);
            gets(n);
            update(m,n);
			break;
				   }

		    case 6:break;

            default:
                printf("you have passed a wrong key");
                printf("\n press any key to continue");
        }
    } 
	return 0;
} 






























