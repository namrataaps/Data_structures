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
///Binary Search Tree Functions -----------------start here
node* insertInBST(node*root,int data){
    if(root==NULL){
        root = new node(data);
        return root;
    }
    if(data <= root->data){
        root->left = insertInBST(root->left,data);
    }
    else{
        root->right = insertInBST(root->right,data);
    }
    return root;
}
void takeInput(node*&root){
    int d;
    cin>>d;
    while(d!=-1){
        root = insertInBST(root,d);
        cin>>d;
    }
}
node* search(node*root,int key){
    if(root==NULL){
            return NULL;
    }
    if(key==root->data){
        return root;
    }
    if(key>root->data){
        return search(root->right,key);
    }
    return search(root->left,key);

}

class ll{
public:
    node*head;
    node*tail;

};

ll tree2LL(node*root){
    ll l;
    if(root==NULL){
        l.head = l.tail = NULL;
        return l;
    }
    ///Leaf Node
    if(root->left==NULL && root->right==NULL){
        l.head = l.tail = root;
        return l;
    }
    ///Left is NonNull
    if(root->left!=NULL && root->right==NULL){
        ll leftLL = tree2LL(root->left);
        leftLL.tail->right = root;
        l.head = leftLL.head;
        l.tail = root;
    }
    else if(root->left==NULL && root->right!=NULL){
        ll rightLL = tree2LL(root->right);
        root->right = rightLL.head;
        l.head = root;
        l.tail = rightLL.tail;
    }
    else{
        ll leftLL = tree2LL(root->left);
        ll rightLL = tree2LL(root->right);
        leftLL.tail->right = root;
        root->right = rightLL.head;
        l.head = leftLL.head;
        l.tail = rightLL.tail;
    }
    return l;

}

bool isBST(node*root,int minV,int maxV){
    if(root==NULL){
        return true;
    }
    if(root->data>=minV && root->data<=maxV && isBST(root->left,minV,root->data)&&isBST(root->right,root->data,maxV)){
        return true;
    }
    return false;
}


int main(){
    node*root = NULL;
    takeInput(root);
    printPreorder(root);
    cout<<endl;
    printinorder(root);
    cout<<endl;
    printpostorder(root);
    cout<<endl;
    levelOrderPrint2(root);
    cout<<"Diameter is  "<<diameter(root)<<endl;
    cout<<"Fast diameter is "<<diameterFast(root).diameter<<endl;
    //mirror(root);
    levelOrderPrint2(root);
    if(isBalanced2(root).balance){
        cout<<"Tree is balanced !"<<endl;
    }
    else{
        cout<<"Tree is not balanced !"<<endl;
    }
    if(isBST(root,INT_MIN,INT_MAX)){
        cout<<"Hai bhai !";
    }
    else{
        cout<<"Not a bst"<<endl;
    }
    /*
    ll l = tree2LL(root);
    node*temp = l.head;

   while(temp!=NULL){
        cout<<temp->data<<"=>";
        temp = temp->right;
    }
    cout<<endl;
    */


return 0;
}
