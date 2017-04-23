#include <iostream>

using namespace std;

struct Node
{
    int key, balance;
    Node *left, *right;
    Node(int Key)//: key(Key), balance(0), left(NULL), right(NULL)
    {
        key=Key;
        balance=0;
        left=right=NULL;
    }
};

class AVLtree
{
//private:
    Node *root;
    void print(Node *root)
    {
        if (root!=NULL)
        {
            print(root->left);
            cout <<root->key<<"("<<root->balance<<") ";
            print(root->right);
        }
    }
    void clear(Node *root)
    {
        if (root!=NULL)
        {
            clear(root->left);
            clear(root->right);
            delete root;
        }
    }
    void rotate_left(Node *&root)
    {
       Node *tmp=root;
       root=root->right;
       tmp->right=root->left;
       root->left=tmp;
    }
    void rotate_right(Node *&root)
    {
       Node *tmp=root;
       root=root->left;
       tmp->left=root->right;
       root->right=tmp;
    }
    bool insert(Node *&root,int key)
    {
        if (root==NULL)
        {
            root=new Node(key);
            return true;
        }
        if (key<root->key)
        {
            bool changed = insert(root->left,key);
            if (!changed)
            {
                return false;
            }
            if (root->balance==-1)
            {
                if (root->left->balance==-1)
                {
                    rotate_right(root);
                    root->right->balance=0;
                }
                else
                {
                    rotate_left(root->left);
                    rotate_right(root);
                    if (root->balance==1)
                    {
                        root->left->balance=-1;
                        root->right->balance=0;
                    }
                    else if (root->balance==-1)
                    {
                        root->left->balance=0;
                        root->right->balance=1;
                    }
                    else
                    {
                        root->left->balance=0;
                        root->right->balance=0;
                    }
                }
                root->balance=0;
            }
            else
            {
                root->balance--;
            }
            return root->balance==-1;
        }
        if (key>root->key)
        {
            bool changed = insert(root->right,key);
            if (!changed)
            {
                return false;
            }
            if (root->balance==1)
            {
                if (root->right->balance==1)
                {
                    rotate_left(root);
                    root->left->balance=0;
                }
                else
                {
                    rotate_right(root->right);
                    rotate_left(root);
                    if (root->balance==1)
                    {
                        root->left->balance=-1;
                        root->right->balance=0;
                    }
                    else if (root->balance==-1)
                    {
                        root->left->balance=0;
                        root->right->balance=1;
                    }
                    else
                    {
                        root->left->balance=0;
                        root->right->balance=0;
                    }
                }
                root->balance=0;
            }
            else
            {
                root->balance++;
            }
            return root->balance==1;
        }
        return false;
    }
public:
    //конструктор
    AVLtree()//: root(NULL)
    {
        root=NULL;
    }
    //деструктор
    ~AVLtree()
    {
        clear(root);
        root=NULL;
    }
    void insert(int key)
    {
        insert(root,key);
    }
    bool search(int key)
    {
        Node *pointer;
        for (pointer=root; pointer!=NULL; )
        {
            if (key==pointer->key)
            {
                return true;
            }
            if (key<pointer->key)
            {
                pointer=pointer->left;
            }
            else if (key>pointer->key)
            {
                pointer=pointer->right;
            }
        }
        return false;
    }
    void print()
    {
        print(root);
        cout<<endl;
    }
};

int main()
{
    AVLtree t;
    t.print();
    t.insert(8);
    t.print();
    t.insert(3);
    t.print();
    t.insert(6);
    t.print();
    t.insert(10);
    t.print();
    t.insert(14);
    t.print();
    int k=10;
    cout<<k<<" "<<boolalpha<<t.search(k)<<endl;
    return 0;
}
