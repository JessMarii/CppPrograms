#include <iostream>
#include <vector>

using namespace std;


class BinarySearchTree 
{
    private: 
        typedef struct BtreeNode 
        {
            double value;
            BtreeNode* L, * R;
        };
        BtreeNode* root;

        bool search(double x, BtreeNode* t) 
        {
            if (t == NULL)
                return false;                    // node is null return false
        
            if (t->value == x) 
            {
                return true;                         //if value found
            }
            // searches subtrees
            if (x <= t->value)
                return search(x, t->L);               //search left adn right subtrees

            return search(x, t->R);
        }

        void insert(double x, BtreeNode* newNode, BtreeNode* t) 
        {
            //If value less than current value
            if (x <= t->value) 
            {
                if (t->L == NULL) 
                {
                    t->L = newNode;                        //if left node is null insert new node
                    return;
                }

                insert(x, newNode, t->L);                 //recursive call when left node is not null
            }
            else 
            {
                if (t->R == NULL) 
                {
                    t->R = newNode;
                    return;
                }

                insert(x, newNode, t->R);
            }
        }

        void inorder(vector<double>& v, BtreeNode* node) 
        {
            //Return if node is null
            if (node == NULL) {
                return;
            }

           //Left root Right is inorder
            inorder(v, node->L);
            v.push_back(node->value);
            inorder(v, node->R);
        }

    public: 
        BinarySearchTree() 
        {
            root = NULL;
        }

        void insert(double x) 
        {
            BtreeNode* newNode = new BtreeNode();
            newNode->value = x;

            if (root == NULL) 
            {
                root = newNode;
                return;
            }

            insert(x, newNode, root);
        } 
        
        bool search(double x) 
        {
            return search(x, root);
        }

        void inorder(vector<double>& v) 
        {
            inorder(v, root);
        }
};
int main()
{
    BinarySearchTree BST;

    BST.insert(12);
    BST.insert(5);
    BST.insert(45);
    BST.insert(86);
    BST.insert(23);
    BST.insert(0);
    BST.insert(7);         //create the tree

    vector<double> vec;
    BST.inorder(vec);

    vector<double>::iterator iter;

    for (iter = vec.begin(); iter < vec.end(); ++iter) 
    {
        cout << *iter << " ";
    }

    cout << endl;
    cout << "Searching 23 ";
        if (BST.search(23) == 1)
            cout<< "number is IN the tree" << endl;

    cout << "Search for 10 ";
        if (BST.search(10) == 0)
            cout << "number is NOT in the tree" << endl;

    return 0;
}