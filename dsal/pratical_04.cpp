#include <iostream>
using namespace std;
struct node
{
    int data;
    node *L;
    node *R;
} * root, *temp;
class BST
{
public:
    void create();
    void insert(node *, node *);
    int height(node *);
    void min(node *);
    void mirror(node *);
    void search(node *);
};
void BST::create()
{
    char ans;
    do
    {
        temp = new node;
        cout << "Enter the data : " << endl;
        cin >> temp->data;
        temp->L = NULL;
        temp->R = NULL;
        if (root == NULL)
        {
            root = temp;
        }
        else
            insert(root, temp);
        cout << "Do you want to insert more value : " << endl;
        cin >> ans;
        // count++;

    } while (ans == 'y');
}
void BST::insert(node *root, node *temp)
{
    if (temp->data > root->data)
    {
        if (root->R == NULL)
        {
            root->R = temp;
        }
        else
            insert(root->R, temp);
    }
    else
    {
        if (root->L == NULL)
        {
            root->L = temp;
        }
        else
            insert(root->L, temp);
    }
}

int BST::height(node *root)
{
    int hr, hl;
    if (root == NULL)
    {
        return 0;
    }
    else if (root->L == NULL && root->R == NULL)
    {
        return 0;
    }
    hr = height(root->R);
    hl = height(root->L);
    if (hr > hl)
    {
        return (1 + hr);
    }
    else
    {
        return (1 + hl);
    }
}
void BST::min(node *root)
{
    temp = root;
    while (temp->L != NULL)
    {
        temp = temp->L;
    }
    cout << "MINIMUM VALUE IN THE TREE : " << temp->data << endl;
}

void BST ::mirror(node *root)
{
    temp = root;
    if (root != NULL)
    {
        mirror(root->L);
        mirror(root->R);
        temp = root->L;
        root->L = root->R;
        root->R = temp;
    }
}
void BST::search(node *root)
{
    int flag;
    temp = root;
    int key;
    cout << "\nEnter the element to be search" << endl;
    cin >> key;
    while (temp != NULL)
    {
        if (key == temp->data)
        {
            cout << "ELEMENT FOUND " << endl;
            flag = 1;
            break;
        }

        node *parent = temp;
        if (key > parent->data)
        {
            temp = temp->R;
        }
        else
        {
            temp = temp->L;
        }
    }
    if (flag == 0)
    {
        cout << "ELEMENT NOT FOUND " << endl;
    }
}
int main()
{
    BST b;
    b.create();

    int ch;
    do
    {
        cout << "1.no of nodes in logest path\n2.min value in tree\n3.serach a value\n4.mirror image\n5.exit" ;
        cin>>ch;
        int x = b.height(root);
        switch (ch)
        {
            case 1:
               
                cout << "\nNo of nodes in the longest path of BST : " << (1 + x) << endl;
                break;

            case 2:
                b.min(root);
                break;
            
            case 3:
                b.search(root);
                break;

            case 4:
                b.mirror(root);
                break;

            case 5:
                break;

        }

        
        
    } while (ch != 5);
    return 0;
}