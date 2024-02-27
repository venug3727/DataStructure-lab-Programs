#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *pre;
    struct node *next;
};

struct node *head=NULL;
struct node *createll();
struct node *insert_beg();
struct node *insert_end();
struct node *insert_ran_bef();
struct node *insert_ran_aft();
struct node *delete_beg();
struct node *delete_end();
struct node *delete_ran();
struct node *display();
struct node *search();

struct node *createll()
{
    struct node *newnode ,*temp;
    newnode=(struct node *) malloc(sizeof(struct node));
    printf("Enter data:- ");
    scanf("%d",&newnode->data);
    newnode->pre=NULL;
    newnode->next=NULL; 
   
    
    if (head==NULL)
    {
        head=newnode;
        

    }
    else
    {
        temp=head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->pre=temp;
        
        
    }
    
}

struct node *display()
{
    struct node *temp;
    temp=head;
    if (head==NULL)
    {
        printf("empty");

    }
    else
    {
        while (temp!=NULL)
        {
            printf("\t%d\n",temp->data);
            temp=temp->next;
        }
        
    }
    
    
}

struct node *insert_beg()
{
    struct node *newnode;
    newnode = (struct node *) malloc (sizeof (struct node));
    if (newnode==NULL)
    {
        printf("memory not allowted");
    }
    printf("enter data:- ");
    scanf("%d",&newnode->data);
    newnode->pre=NULL;
    head->pre=newnode;
    newnode->next=head;
    head=newnode;
    
}

struct node *insert_end()
{
    struct node *newnode,*temp;
    temp=head;

    newnode=(struct node *) malloc (sizeof (struct node));
    if (newnode==NULL)
    {
        printf("memory not allowted");
    }
    printf("enter data:- ");
    scanf("%d",&newnode->data);
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->pre=temp;
    
    newnode->next=NULL;

    return head;
}

struct node *insert_ran_bef()
{
    struct node *newnode, *temp;
    temp=head;
    int idata;
    newnode=(struct node *) malloc(sizeof (struct node ));
    printf("Enter data:- ");
    scanf("%d",&newnode->data);
    printf("enter data where you want to insret new data:-  ");
    scanf("%d",&idata);

    while (temp->data!=idata)
    {
        temp=temp->next;
    }

    newnode->next=temp;
    newnode->pre=temp->pre;
    temp->pre->next=newnode;
    temp->pre=newnode;
    
}

struct node *search()
{
    struct node *temp;
    temp=head;
    int udata;
    printf("Enter which data you want to search:-");
    scanf("%d",&udata);
    while (temp!=NULL)
    {
        if (temp->data==udata)
        {
            printf("enterd data is present in list:%d",temp->data);
            return temp;
        }

        
        temp=temp->next;
        
        
        
    }
    
    printf("%d data not found",udata);
    return NULL;
        
    

   
    

}

struct node *insert_ran_aft()
{
    struct node *newnode, *temp;
    temp=head;
    int idata;
    newnode=(struct node *) malloc(sizeof (struct node ));
    printf("Enter data:- ");
    scanf("%d",&newnode->data);
    printf("enter data where you want to insret new data:-  ");
    scanf("%d",&idata);

    while (temp->data!=idata)
    {
        temp=temp->next;
    }

   newnode->next=temp->next;
   newnode->pre = temp;
   temp->next->pre=newnode;
   temp->next=newnode;
    
}

struct node *delete_beg()
{
    struct node *temp;
    temp=head;
    head=head->next;
    head->pre=NULL;
    free(temp);
}

struct node *delete_end()
{
    struct node *temp;
    temp=head;
    if (head==NULL)
    {
        printf("empty");
    }
    
    else
    {   
         while (temp->next!=NULL)
        {
            temp=temp->next;
        }
    }

    temp->pre->next=NULL;
    free(temp);
    
}

int main()
{
    int option;
    while (1)
    {
        printf("<<<<<<<<<<<<<<<##################MENU##################>>>>>>>>>>>>>>\n");
        printf("\n1.create nodes.\n2.display.\n3.insert beging\n4.insert end\n5.insret Before\n6.insert after\n7.delete at beging\n8.delete at end\n9.search data\n10.Exit.");
        printf("\nEnter your option.");
        scanf("%d",&option);
        switch (option)
        {
            case 1:createll(head);
                printf("\nLIST CREATED");
                break;

            case 2:display(head);
                break;

            
        
            case 3:insert_beg(head);
                break;

            case 4:insert_end(head);
                break;

            case 5: insert_ran_bef(head);
                break;

            case 6: insert_ran_aft(head);
                break;

            case 7: delete_beg(head);
                break;
            case 8:delete_end(head);
                break;

            case 9:search(head);
                break;

        // case 8:delet_ran(head);
        //     break;

        // case 9:reverse();
        //     break;

        case 10:exit(0);
        
        default:printf("wrong value");
            break;
        }
    }
}