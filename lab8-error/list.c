#include<stdio.h>
#include<stdlib.h>
#include <string.h>
typedef char *String;
struct node
{
    char info[100];
    struct node *link;
};
typedef struct node *NODE;
NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("memory full\n");
        exit(0);
    }
    return x;
}
void freenode(NODE x)
{
    free(x);
}
NODE insert_front(NODE first,String item)
{
    NODE temp;
    temp=getnode();
    strcpy(temp->info,item);
    temp->link=NULL;
    if(first==NULL)
        return temp;
    temp->link=first;
    first=temp;
    return first;
}
NODE delete_rear(NODE first)
{
    NODE cur,prev;
    if(first==NULL)
    {
        printf("list is empty cannot delete\n");
        return first;
    }
    if(first->link==NULL)
    {
        printf("item deleted is %s\n",first->info);
        free(first);
        return NULL;
    }
    prev=NULL;
    cur=first;
    while(cur->link!=NULL)
    {
        prev=cur;
        cur=cur->link;
    }
    printf("item deleted at rear-end is %s",cur->info);
    free(cur);
    prev->link=NULL;
    return first;
}
void swap(NODE a,NODE b)
{
	String temp;
    strcpy(temp,a->info);
    strcpy(a->info,b->info);
    strcpy(b->info,temp);
}
/*void bubbleSort(NODE first)
{
    int swapped;
    NODE cur;
    NODE prev = NULL;

    if (first == NULL)
    {
        printf("Empty Linked List\n");
        return;
    }
    do
    {
        swapped = 0;
        cur = first;

        while (cur->link != prev)
        {
        	if(cur->info < 91 && cur->link->info < 91 || cur->info > 96 && cur->link->info < 96)
		     {
		        if (cur->info > cur->link->info)
		        {
		            swap(cur, cur->link);
		            swapped = 1;
		        }
		     }
		     else if(cur->info < 91 && cur->link->info > 96)
             {
		        if (cur->info + 32 > cur->link->info)
		        {
		            swap(cur, cur->link);
		            swapped = 1;
		        }
		     }
		     else
		     {
		        if (cur->info > cur->link->info + 32)
		        {
		            swap(cur, cur->link);
		            swapped = 1;
		        }
		     }
            cur = cur->link;
        }
        prev=cur;
    }
    while (swapped);
}*/
int list_length(NODE first)
{
    NODE temp;
    int count = 0;
    if(first==NULL)
        return 0;
    for(temp=first;temp!=NULL;temp=temp->link)
    {
        count++;
    }
    return count;
}
void search(NODE first, String item)
{
    NODE temp;
    int pos = 0;
    if(first==NULL)
        printf("list empty cannot search items\n");
    for(temp=first;temp!=NULL;temp=temp->link)
    {
        pos++;
        if(strcmp(item,temp->info) == 0)
        {
            printf("Element found and is in the position %d\n", pos);
        }
    }
    printf("Element not found in the list\n");
    return;
}
void display(NODE first)
{
    NODE temp;
    if(first==NULL)
        printf("list empty cannot display items\n");
    for(temp=first;temp!=NULL;temp=temp->link)
    {
        printf("%s\n",temp->info);
    }
}
int main()
{
    String item;
    int choice,pos,i,n;
    NODE first=NULL,a,b;
    for(;;){
        printf("\n 1:Insert_front\n 2.Delete_rear\n 3.Sort\n 4.Total items in the list\n 5.Search\n 6.Display \n 7.Exit\n");
        printf(" Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("enter the item at front-end\n");
                scanf("%s", item);
                first=insert_front(first, item);
                break;
            case 2:first=delete_rear(first);
                break;
           /* case 3:bubbleSort(first);
                printf("Items In Sorted Order are\n");
                display(first);*/
                break;
            case 4:printf("Total items in the list is %d\n", list_length(first));
                    break;
            case 5:printf("Enter the item that you want to search:\n");
                   scanf("%s", item);
                   search(first, item);
            case 6:printf("List : \n");
                display(first);
                break;
            case 7:exit(0);
            default:printf("Enter correct instruction!!!");
                break;
        }
    }
    return 0;
}
