#include <iostream>
using namespace std;

struct Node
{
    string data;
    struct Node *right, *left;
}*root;

class Tree
{
public:
    void insertion()
    {
        string choice, ans;
        root = NULL;
        do
        {
            struct Node *temp = new (struct Node);
            cout << "Enter node data: ";
            cin >> temp->data;
            temp->right = temp->left = NULL;
            int flag = 0;
            if (root == NULL)
            {
                root = temp;
            }
            else
            {
                struct Node *p = root;
                do
                {
                    cout << "Want to add it to right or left of "<<p->data<<" ? [L or R]";
                    cin >> choice;
                    if (choice == "R")
                    {
                        if (p->right == NULL)
                        {
                            p->right = temp;
                            flag = 1;
                        }
                        else
                        {
                            p = p->right;
                        }
                    }
                    else
                    {
                        if (p->left == NULL)
                        {
                            p->left = temp;
                            flag = 1;
                        }
                        else
                        {
                            p = p->left;
                        }
                    }
                } while (flag == 0);
            }
            cout << "Do you want to continue insertion? [y/n]";
            cin >> ans;
        } while (ans == "y");
    }
    void preorder_travesal(struct Node *q)   //VLR
    {
        if(q)
        {
            cout<<q->data;
            preorder_travesal(q->left);
            preorder_travesal(q->right);
        }
        else{
            return;
        }
    }
    void postorder_travesal(struct Node *r)   //LRV
    {
        if(r)
        {
            preorder_travesal(r->left);
            preorder_travesal(r->right);
            cout<<r->data;
        }
        else
        {
            return;
        }
    }
    void inorder_travesal(struct Node *s)   //LVR
    {
        if(s)
        {
            preorder_travesal(s->left);
            cout<<s->data;
            preorder_travesal(s->right);
        }
        else{
            return;
        }
    }
};
int main()
{
    Tree obj;
    // Node obj1;
    obj.insertion();
    obj.preorder_travesal(root);
    cout<<"\n";
    obj.postorder_travesal(root);
    cout<<"\n";
    obj.inorder_travesal(root);
    return 0;
}
