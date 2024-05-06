#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
using namespace std;
ifstream inFile;
ofstream outFile;
class node
{
public:
    int data;
    node *left;
    node *right;
    node()
    {
        left = NULL;
        right = NULL;
    }
    node(int item, node *left = NULL, node *right = NULL)
    {
        data = item;
        this->left = left;
        this->right = right;
    }
    ~node()
    {
        delete left;
        delete right;
    }
};
void print_tree(node *r)
{
    if (r == NULL)
        return;
    outFile << r->data;
    if (r->left != NULL || r->right != NULL)
    {
        outFile << "(";
        print_tree(r->left);
        outFile << ")(";
        print_tree(r->right);
        outFile << ")";
    }
}
class BST
{
    node *root;
    node *inserting(node *r, int value)
    {
        if (r == NULL)
            return new node(value);
        else if (value > r->data)
            r->right = inserting(r->right, value);
        else if (value < r->data)
            r->left = inserting(r->left, value);
        return r;
    }
    node *searching(node *r, int value)
    {
        if (r == NULL)
            return r;
        else if (r->data == value)
            return r;
        else if (r->data < value)
            return searching(r->right, value);
        else if (r->data > value)
            return searching(r->left, value);
    }
    node *removing(node *r, int value)
    {
        if (r == NULL)
            return r;
        else if (value < r->data)
            r->left = removing(r->left, value);
        else if (value > r->data)
            r->right = removing(r->right, value);
        else
        {
            if (r->left == NULL)
            {
                r = r->right;
            }
            else if (r->right == NULL)
                r = r->left;
            else
            {
                int item = find_max(r->left);
                r->data = item;
                r->left = remove_max(r->left);
            }
        }
        return r;
    }
    int find_max(node *r)
    {
        if (r->right == NULL)
            return r->data;
        else
            return find_max(r->right);
    }
    node *remove_max(node *r)
    {
        if (r->right == NULL)
            r = r->left;
        else
            r->right = remove_max(r->right);
        return r;
    }

public:
    BST(node *r = NULL)
    {
        root = r;
    }
    ~BST()
    {
        delete root;
    }
    node *getRoot()
    {
        return root;
    }
    void Insert(int value)
    {
        root = inserting(root, value);
    }
    bool Find(int value)
    {
        node *temp = searching(root, value);
        if (temp == NULL)
            return false;
        else
            return true;
    }
    void in_order(node *r)
    {
        if (r == NULL)
            return;
        in_order(r->left);
        outFile << r->data << " ";
        in_order(r->right);
    }
    void pre_order(node *r)
    {
        if (r == NULL)
            return;
        outFile << r->data << " ";
        pre_order(r->left);
        pre_order(r->right);
    }
    void post_order(node *r)
    {
        if (r == NULL)
            return;
        post_order(r->left);
        post_order(r->right);
        outFile << r->data << " ";
    }
    void Delete(int value)
    {
        node *temp = searching(root, value);
        if (temp != NULL && temp->left == NULL && temp->right == NULL)
        {
            root = removing(root, value);
            print_tree(root);
        }
        else
            outFile << "Invalid Operation";
        outFile << endl;
    }
};
int main()
{
    inFile.open("input.txt");
    outFile.open("output.txt");
    char command;
    char param[10];
    BST tree;
    while (true)
    {
        inFile >> command;
        inFile >> param;
        int value;
        switch (command)
        {
        case 'I':
            value = atoi(param);
            tree.Insert(value);
            print_tree(tree.getRoot());
            outFile << endl;
            break;
        case 'F':
            value = atoi(param);
            if (tree.Find(value))
                outFile << "True" << endl;
            else
                outFile << "False" << endl;
            break;
        case 'D':
            value = atoi(param);
            tree.Delete(value);
            break;
        case 'T':
            if (strcmp("In", param) == 0)
                tree.in_order(tree.getRoot());
            else if (strcmp("Pre", param) == 0)
                tree.pre_order(tree.getRoot());
            else if (strcmp("Post", param) == 0)
                tree.post_order(tree.getRoot());
            outFile << endl;
            break;
        }
        if (inFile.eof())
            break;
    }
    inFile.close();
    outFile.close();
}