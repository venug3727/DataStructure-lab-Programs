 #include <stdio.h>
 #include<stdlib.h>
 #define SIZE 5
 int items[SIZE], rear= 1, front=-1;

 int isFull()

 {
    if((front==rear+1)||(front== 0 && rear==SIZE-1))
    {
        return 1;
    }
    return 0;
 }



 int isEmpty()

 {

    if(front== 1)
    return 1;
    return 0;

 }

void enqueue(int element)

{
    if(isFull())
    {
    printf("\nqueue is full");

    }

    else {
    if(front==-1)
    front=0;
    rear=(rear+1)%SIZE;
    items[rear]=element;
    printf("%d is inserted", element);



 }

}

 int deQueue()
 {
    int value;
    if(isEmpty())
    {
        printf("\nQueue is empty!!\n");
        return -1;
}
    else

    {
        value=items[front];
        if(front-rear)
        {
        front=-1;
        rear=-1;

        }
        else
        {
        front=(front+1)%SIZE;
        }

    printf("%d is deleted from queue", value);
    return(value);

    }

 }

void display()

{
    int i;
    if(isEmpty())
    {
        printf("\nqueue is empty");

    }

    else
    {
        printf("\nfront position=%d\n",front);

        for(i=front;i!=rear;i=(i+1)%SIZE)

        {
        printf("\t%d\t",items[i]);

        }
        printf("%d\t",items[i]);

    }

 }

int main()
{

    int choice, element;

    while(1)
    {

       

        printf("\n1.insert\n2.delete\n3.display\n4.exit");

        printf("\nenter choice");

        scanf("%d",&choice);

        switch(choice)
        {

            case 1 :printf("\nenter the element to insert");

                    scanf("%d",&element);

                    enqueue(element);

                break;

            case 2 :element =deQueue();

                    if(element!=1){

                        printf("%d element is deleted",element);
                    }

                break;

            case 3:display();

                break;

            case 4:exit(0);

            default:printf(" invalid choice");
                break;
        }
    }

}