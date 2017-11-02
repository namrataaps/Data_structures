#include<bits/stdc++.h>
using namespace std;


class node{

public:
    int data;
    node*left;
    node*right;

    node(int d):data(d),left(NULL),right(NULL){}
};

/*
node* buildTree(node*root){

   int data;
   cin>>data;

   if(data==-1){

    return NULL;
   }

   root =new node (data);
   root->left





}
*/

void buildTreeLevelOrder(node*&root){
    cout<<"Enter root data ";
    int d;
    cin>>d;
    root = new node(d);

    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* f = q.front();
        q.pop();


        cout<<"Enter children of "<<f->data <<" ";
        int c1,c2;
        cin>>c1>>c2;

        if(c1!=-1){
            f->left = new node(c1);
            q.push(f->left);
        }
        if(c2!=-1){
            f->right = new node(c2);
            q.push(f->right);
        }

    }
}


/*

node* insertInBST(node* root,int data){
   if(root==NULL){
    root =new node(data);
    return root;
   }

   if(data<=root->data){
    root->left=insertInBST(root->left,data);

   }
   else{

    root->right=insertInBST(root->right,data);
   }
   return root;

}
*/
/*
void takeInput(node*&root){
    int d;
    cin>>d;
    while(d!=-1){
        root=insertInBST(root,d);
        cin>>d;
    }

}
*/
void print(node*root){
  if(root==NULL){

    return ;
  }
  if(root->left==NULL&&root->right==NULL){

    cout<<root->data<<" ";

  }
  cout<<"Leaf nodes are : "<<endl;
  print(root->left);
  print(root->right);

}

int main(){

  node *root=NULL;

  buildTreeLevelOrder(root);
  print(root);


  return 0;
}
