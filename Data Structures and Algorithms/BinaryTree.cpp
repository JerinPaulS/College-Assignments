// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        
        Node(){
            data = 0;
            left = NULL;
            right = NULL;
        }
        
        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

class BinaryTree{
    Node* root;
    
    public:
        BinaryTree(){
            root = NULL;
        }
        void createNode(int num, Node* root);
        void inorder(Node* root);
        void preorder(Node* root);
        void postorder(Node* root);
};

void BinaryTree::inorder(Node* node){
    if(node == NULL)
        return;
    inorder(node->left);
    cout<<node->data<<"\t";
    inorder(node->right);
}

void BinaryTree::postorder(Node* node){
    if(node == NULL)
        return;
    inorder(node->left);    
    inorder(node->right);
    cout<<node->data<<"\t";
}

void BinaryTree::preorder(Node* node){
    if(node == NULL)
        return;
    cout<<node->data<<"\t";
    inorder(node->left);
    inorder(node->right);
}

void BinaryTree::createNode(int data, Node* root){
    Node* newnode = new Node(data);
    Node* curr = root;
    // 0 -> left ; 1 -> right
    int ch = 0;
    int flag = 0;
    int temp = 0;
    do{
        temp = curr->data;
        cout<<"Where do you wish to insert the number: (0 -> left ; 1 -> right) " + to_string(temp) + " ";
        cin>>ch;
        if(ch == 0){
            if(curr->left == NULL){
            	cout<<"New node inserted at the left of "<<temp<< "\n";
                curr->left = newnode;
                flag = 0;
            }
            else{
                flag = 1;
                curr = curr->left;
            }
        }
        if(ch == 1){
            if(curr->right == NULL){
            	cout<<"New node inserted at the right of "<<temp<< "\n";            
                curr->right = newnode;
                flag = 0;
            }
            else{
                flag = 1;
                curr = curr->right;
            }
        }
    }while(flag == 1);
}

int main(){
    int num;
    string choice;
    BinaryTree obj;
    Node* root = NULL;
    do{
        cout<< "Enter the number: ";
        cin>>num;
        if(root == NULL){
            Node* newnode = new Node(num);
            root = newnode;
        }
        else
            obj.createNode(num, root);
        cout<<"Do you  want to enter more numbers? ";
        cin>>choice;
    }while(choice == "Y");
    BinaryTree obj1;
    cout<<"\nInorder\n";
    obj1.inorder(root);
    cout<<"\nPreorder\n";
    obj1.preorder(root);
    cout<<"\nPostorder\n";
    obj1.postorder(root);
    return 0;
}
