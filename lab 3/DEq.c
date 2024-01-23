#include<stdio.h>
#include<stdlib.h>
#define N 5
int q[N];
int f=-1,r=-1;

void insert_front(int x)
{   
    
    if ((f==r+1)||(f==0&&r==N-1)) 
    {
        printf("The Queue is full&");

    }

    else if (f==-1&&r==-1){
        f=0;
        r=0;
        q[f]=x;
    }
    
    else if(f==0)

    {
        f=N-1;
        q[f]=x;
    }

    else{
        f--;
        q[f]=x;
    }
}


void insert_rear(int x)
{
    
    

    if((f==0&&r==N-1)||(f=r+1))
    {
        printf("The Queue is full");
    }

    else if (f==-1&&r==-1)
    {
        f=0;
        r=0;
        q[r]=x;
    }

    else if (r==N-1)
    {
        r=0;
        q[r]=x;
    }

    else{
        r++;
        q[r]=x;
    }
}

void get_front()
{
    printf("The front value is:-%d",q[f]);
    
}

void get_rear()
{
    printf("The rear value is:-%d",q[r]);

    
}


void display()
{
    int i=f;
    if ((f==-1&&r==-1)){
        printf("The Queue is empty");
    }
    else
    {
        while (i!=r)
        {
            printf("%d",q[i]);
            i=(i+1)%N;
        }
        printf("%d",q[r]);
    }
}

void dequeue_front()
{
    if (f==-1&&r==-1)
    {
        printf("the Queue is empty");
    }

    else if (f==r)
    {
        printf("the last element is%d",q[f]);
        f=r=-1;
    }
    else if (f==N-1)
    {
        printf("The Deleted element is%d",q[f]);
        f=0;
    }
    else 
    {
        printf("The Deleted element is%d",q[f]);
        f++;
    }
}

void dequeue_rear()
{
    if (f==-1&&r==-1)
    {
        printf("The Queue is empty");
    }
    else if (f==r){
        printf("The Deleted element is%d",q[r]);
        f=r=-1;
    }
    else if (r==0){
        printf("The Deleted element is%d",q[r]);
        r=N-1;
    }
    else 
    {
        printf("The Deleted element is%d",q[r]);
        r--;
    }
    

}
int main()
{
    int choice,x;
    while (1)
    {
        printf("\n1.insert front.\n2.insert rear.\n3.display.\n4.front value.\n5.rear value.\n6.delete from front.\n7.Delete from rear.\n8.exit.\n");
        printf("Enter your chiose:- ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf("Enter value to insert:- ");
                scanf("%d",&x);
                insert_front(x);
            break;

        case 2:printf("Enter value to insert:- ");
                scanf("%d",&x);
                insert_rear(x);
            break;
        case 3 :display();
            break;

        case 4:get_front();
            break;
        case 5:get_rear();
            break;
        case 6:dequeue_front();
            break;
        case 7:dequeue_rear();
            break;
        

        case 8:exit(0);
            
        
        default:printf("wrong value enterd!");
            break;
        }
    }
    
}
