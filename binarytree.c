#include<stdio.h>
#include<stdlib.h>

struct Node
{
 int data;
 struct Node *left,*right;
};


struct Node* create(int val)
{
 struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
 newNode->data = val;
 newNode->left=newNode->right=NULL;
 return newNode;
}

struct Node* insert()
{
 int val;
 printf("\n Value to enter(-1 for no node):");
 scanf("%d",&val);
 if(val==-1)
 {
   return NULL;
 }
 struct Node* root=create(val);
 printf("Enter left child of %d :",val);
 root->left=insert();
 printf("Enter right child of %d :",val);
 root->right=insert();
 return root;
}

void preorder(struct Node* root)
{
 if(root)
 {
  printf("%d\t",root->data);
  preorder(root->left);
  preorder(root->right);
 }
 return;
}

void inorder(struct Node* root)
{
 if(root)
 {
  inorder(root->left);
  printf("%d\t",root->data);
  inorder(root->right);
 }
 return;
}

void postorder(struct Node* root)
{
 if(root)
 {
  postorder(root->left);
  postorder(root->right);
  printf("%d\t",root->data);
 }
 return;
}

void delete(struct Node* root)
{
 if(root)
 {
  delete(root->left);
  delete(root->right);
  printf("\n%d is deleted",root->data);
  free(root);
 }
 return;
}

int main()
{
 struct Node* root=NULL;
 int c;
 printf("Binary tree:");
 printf("\n1. insert\n2. delete \n3. preorder\n4. inorder\n5. postorder\n 6. Exit");
 while(1)
 {
   printf("choice:");
   scanf("%d",&c);
  
   switch(c)
   {
     	case 1: root=insert();
     		printf("tree created");
     		break;
     		
    	case 2: if(root==NULL)
			printf("Tree empty");
		else
			delete(root);
		break;
	
	case 3: if(root==NULL)
			printf("Tree empty");
		else
			preorder(root);
		break;
	
	case 4: if(root==NULL)
			printf("Tree empty");
		else
			inorder(root);
		break;
	
	case 5: if(root==NULL)
			printf("Tree empty");
		else
			postorder(root);
		break;
	
	case 6: printf("Exiting");
		exit(0);
		
	default: printf("invalid choice");
   }
 }
 return 0;
}

		
		




