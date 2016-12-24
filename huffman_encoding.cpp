/*
Huffman encoding is a lossless data compression technique that uses greedy approach
Author: Shubham Chaturvedi
23 December,2016
*/

#include <queue>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct node
{
	string a;
	int f;  //frequency
	node* left;
	node* right;
};

struct comparenode
{
  bool operator()(const node* l, const node* r)
	{
		return l->f > r->f;
	}
};

void traverse(node* root)
{
if(root->left->left != NULL && root->left->right != NULL) //checking if left child is non-leaf
	{root->left->a = root->a + "0"; traverse(root->left);}
else 
{
	string s1 = root->a + "0";
	cout <<"The encoding of "<< root->left->a <<" is "<<s1<<"\n";
}

if(root->right->left != NULL && root->right->right != NULL) //checking if right child is non-leaf
{root->right->a = root->a + "1";traverse(root->right);}
else
{
	string s2 = root->a + "1";
	cout<<"The encoding of "<< root->right->a <<" is "<<s2<<"\n";
}

}


void huffman_encoding(vector<char> c,vector<int> f,int n)
{

priority_queue<node*,vector<node*>,comparenode> q;
//push nodes into priority queue
for(int i=0;i<n;i++)
{
	node* temp= new node();	
	temp->f = f[i];
	temp->a = c[i];
	temp->left = NULL;
	temp->right = NULL;
	q.push(temp);
}


node* root;
//make binary tree
for(int j=1;j<n;j++)
{
	node* temp1 = new node();
	temp1->left = q.top();
	q.pop();
	temp1->right = q.top();
	q.pop();
	temp1->f = temp1->left->f + temp1->right->f;
	q.push(temp1);
	if(j==n-1) root = temp1;
}
//traverse binary tree
root->a = "";
traverse(root);

}


int main()
{

int n;
//cout<<"Enter the number of characters";
cin>>n;
vector<char> c;
vector<int> f;
//cout<<"Enter character and their corresponding frequencies";
char c1;int f1;
for(int i=0;i<n;i++)
{	
	cin>>c1>>f1;
	c.push_back(c1);
	f.push_back(f1);
}

huffman_encoding(c,f,n);
}
