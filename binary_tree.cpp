#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

class node{
public:
    int data;
    node*left;
    node*right;

    node(int d):data(d),left(NULL),right(NULL){}
};


node* buildTree(node*root){
    int data;

    cout<<"Enter data ";
    cin>>data;

    if(data==-1){
        return NULL;
    }

    root = new node(data);
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);
    return root;
}
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
void printPreorder(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);

}
void printinorder(node*root){
    if(root==NULL){
        return;
    }
    printinorder(root->left);
    cout<<root->data<<" ";
    printinorder(root->right);
}
void printpostorder(node*root){
    if(root==NULL){
        return;
    }
    printpostorder(root->left);
    printpostorder(root->right);
    cout<<root->data<<" ";
}
void levelOrderPrint(node*root){
    queue<node*> q;

    q.push(root);


    while(!q.empty()){
        node* f = q.front();
        cout<< f->data<<" ";


        q.pop();
        if(f->left){
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }
    }
}

void levelOrderPrint2(node*root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);


    while(!q.empty()){
        node* f = q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
        cout<< f->data<<" ";

        q.pop();
        if(f->left){
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
            }
        }
    }

}



int height(node*root){
    if(root==NULL){
        return 0;
    }
    return max(height(root->left),height(root->right))+1;
}

int diameter(node*root){
    if(root==NULL){
        return 0;
    }
    int op1 = height(root->left) + height(root->right);
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);

    return max(op1,max(op2,op3));
}

class Pair{
public:
    int height;
    int diameter;
};

Pair diameterFast(node*root){
    Pair p;
    if(root==NULL){
        p.diameter = 0;
        p.height = 0;
        return p;

    }
    ///Rec Case
    Pair left = diameterFast(root->left);
    Pair right = diameterFast(root->right);

    int op1 = left.height  + right.height;
    int op2 = left.diameter;
    int op3 = right.diameter;

    p.diameter = max(op1,max(op2,op3));
    p.height = max(left.height,right.height)+1;
    return p;
}

void mirror(node*root){
    if(root==NULL){
        return;
    }
    swap(root->left,root->right);
    mirror(root->left);
    mirror(root->right);
}


bool isBalanced(node*root){
    if(root==NULL){
        return true;
    }

    int h1 = height(root->left);
    int h2  = height(root->right);
    if(abs(h1-h2)<=1 && isBalanced(root->left)&&isBalanced(root->right)){
        return true;
    }
    return false;
}
class myPair{
public:
    bool balance;
    int height;
};

myPair isBalanced2(node*root){
    myPair p;
    if(root==NULL){
        p.balance = true;
        p.height = 0;
        return p;
    }

    ///Rec case
    myPair left = isBalanced2(root->left);
    myPair right = isBalanced2(root->right);

    if(abs(left.height-right.height)<=1 && left.balance && right.balance){
       p.balance = true;
    }
    else{
        p.balance = false;
    }
    p.height = max(left.height,right.height)+1;
    return p;

}


int main(){
    node*root = NULL;
    buildTreeLevelOrder(root);
    printPreorder(root);
    cout<<endl;
    printinorder(root);
    cout<<endl;
    printpostorder(root);
    cout<<endl;
    levelOrderPrint2(root);
    cout<<"Diameter is  "<<diameter(root)<<endl;
    cout<<"Fast diameter is "<<diameterFast(root).diameter<<endl;
    mirror(root);
    levelOrderPrint2(root);
    if(isBalanced2(root).balance){
        cout<<"Tree is balanced !"<<endl;
    }
    else{
        cout<<"Tree is not balanced !"<<endl;
    }

return 0;
}
