#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct node{
	int data;
	node *left,*right;
};


node *newNode(ll data){
	node *temp = new node;
	temp->data = data;
	temp->left=temp->right=NULL;
	return temp;
}

node *insert(node *root,ll data){
	if(root==NULL)
	return newNode(data);
	if(root->data>data)
	root->left = insert(root->left,data);
	if(root->data<data)
	root->right = insert(root->right,data);
	return root;
}

node *search(node *root,ll data){
	if(root==NULL||root->data==data)
	return root;
	if(root->data>data)
	return search(root->left,data);
	
	return search(root->right,data);
}

void print(node *root){
	if(root==NULL)
	return;
	cout<<root->data<<" ";
	print(root->left);
	print(root->right);
	return;
}


node *bTreeToCList(node *root)
{
    if(root==NULL)
    return NULL;
    node *head = bTreeToCList(root->left);
    node *right=root->right;
    if(head==NULL){
        head=root;
        root->left=root;
        root->right=root;
    }else{
        head->left->right=root;
        root->left = head->left;
        head->left=root;
        root->right=head;
    }
    right = bTreeToCList(right);
    if(right!=NULL){
        node *p = head->left;
        head->left->right=right;
        head->left = right->left;
        right->left->right = head;
        right->left = p;
    }
    return head;
}


node *merge(node *head1,node *head2){
	if(head1==NULL)
	return NULL;
	if(head2==NULL)
	return NULL;
	node dummy;
	node *temp = &dummy;
	while(head1&&head2){
		if(head1->data<=head2->data){
			head1->left = temp;
			temp->right = head1;
			head1=head1->right;
			temp=temp->right;
		}else{
			head2->left = temp;
			temp->right = head2;
			head2=head2->right;
			temp=temp->right;
		}
	}
	if(head1)
	{
		head1->left = temp;
		temp->right = head1;
	}
	else{
		head2->left = temp;
		temp->right = head2;
	}
	dummy.right->left = NULL;
	return dummy.right;
}


ll size(node *head){
	ll cnt=0;
	while(head){
		cnt++;
		cout<<head->data<<" ";
		head=head->right;
	}
	cout<<endl;
	return cnt;
}

node *solve(node **head,ll n){
	if(n<=0)
	return NULL;
	node *left = solve(head,n/2);
	node *root = *head;
	root->left = left;
	(*head)=(*head)->right;
	root->right = solve(head,n-(n/2)-1);
	return root;
	
}

int main(){
	node *root1  		= newNode(100);
    root1->left         = newNode(50);
    root1->right        = newNode(300);
    root1->left->left   = newNode(20);
    root1->left->right  = newNode(70);
    struct node *root2  = newNode(80);
    root2->left         = newNode(40);
    root2->right        = newNode(120);
    node *head1 = bTreeToCList(root1);
    head1->left->right = NULL;
    head1->left = NULL;
    node *head2 = bTreeToCList(root2);
    head2->left->right = NULL;
    head2->left = NULL;
    node *head  = merge(head1,head2);
    ll n = size(head);
    node *root = solve(&head,n);
    print(root);
}














//



