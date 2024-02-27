#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *root=NULL;
void insert()
{
    struct node *newnode ,*parent,*curr;
    newnode =(struct node*)malloc(sizeof(struct node ));
    printf("Enter data:- ");
    scanf("%d",&newnode->data);
    newnode->left=newnode->right=NULL;
    
    
    if (root==NULL)
    {
        root=newnode;
        return;
        
    }
    

    
    parent=NULL;
    curr=root;
        
    while (curr!=NULL)
    {
        parent=curr;
        if (newnode->data > curr->data )
        {
            curr=curr->right;
        }
        else
        {
            curr = curr->left;
        }

    }

    

    
    if (newnode->data > parent->data)
    {
        parent->right=newnode;
    }
    else
    {
        parent->left=newnode;

    }
}


void inorder(struct node *root)
{
    if (root!=NULL)
    {
        inorder(root->left);
        printf("\t %d",root->data);
        inorder(root->right);
    }

}

void preorder(struct node *root)
{
    if (root!=NULL)
    {
        
        printf("\t %d",root->data);
        preorder(root->left);
        preorder(root->right);
    }

}

void postorder(struct node *root)
{
    if (root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("\t %d",root->data);
    }

}


int main()
{
    int option;



    while(1)
    {
        printf("\n \t1.Create tree\n\t 2.Inorder \n \t3.Postorder\n \t4.Preorder\n\t5.Exit");
        printf("\nEnter option:- ");
        scanf("%d",&option);
        switch(option)
        {
            case 1 :insert();
                    break;
            case 2: inorder(root);
                break;

            case 3:postorder(root);
                    break;
            case 4: preorder(root);
                break;
            case 5:exit(0);
            default:printf("\n \t Enterd wrong option!!....\n \tTry again.......\n \t Thanks");
                break;
        }
    }
}
