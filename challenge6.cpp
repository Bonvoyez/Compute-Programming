#include <iostream>
#include <vector>

class NODE{
    public:
        NODE(){}

        int strtNode;
        NODE *left;
        NODE *right;

    private:
};

class BST{
    public:
        BST() 
        {
            root = NULL;
        }

        ~BST() 
        {
            if (root != NULL)
            {
                saveMemory(root);
            }
        }

        void insertKey(int newKey)
        {
            if (root == NULL)
            {
                root = new NODE();
                root->strtNode = newKey;
                root->left = NULL;
                root->right = NULL;

                parentNode = newKey;
            }
            else
            {
                insertKey(root, newKey);
            }
        }

        bool hasKey(int searchKey)
        {
            return hasKey(root, searchKey);
        }

        std::vector<int> inOrder()
        {
            inOrder(root, orderedList);

            return orderedList;
        }

        int getHeight()
        {
            if (root != NULL)
            {
                height = 0;
                getHeight(root, 1);
                return height;
            }

            return 0;
        }

        void balance()
        {
            NODE* n = NULL;
            saveMemory(root);
            balance(0, orderedList.size() - 1);


            for (int i = 0; i < balanceOrderedList.size(); i++)
            {
                if (n == NULL)
                {
                    n = new NODE();
                    n->strtNode = balanceOrderedList.at(i);
                    n->left = NULL;
                    n->right = NULL;

                    parentNode = balanceOrderedList.at(i);
                }
                else
                {
                    insertKey(n, balanceOrderedList.at(i));
                }
            }

            root = n;
            //saveMemory(n);
            
            
            orderedList.clear();
            balanceOrderedList.clear();
        }

        void removeKey(int oldKey)
        {
            for (int i = 0; i < orderedList.size(); i++)
            {
                if (orderedList.at(i) == oldKey)
                {
                    orderedList.erase(orderedList.begin() + i);
                }
            }
            balance();
        }

    private:
        NODE *root;
        int height, parentNode;
        std::vector<int> orderedList, balanceOrderedList;

        void insertKey(NODE *node, int newKey)
        {
            if (node->strtNode < newKey)
            {
                if (node->right == NULL)
                {
                    node->right = new NODE();
                    node->right->strtNode = newKey;
                    node->right->left = NULL;
                    node->right->right = NULL;
                }
                else
                {
                    insertKey(node->right, newKey);
                }
            }
            else
            {
                if (node->left == NULL)
                {
                    node->left = new NODE();
                    node->left->strtNode = newKey;
                    node->left->left = NULL;
                    node->left->right = NULL;
                }
                else
                {
                    insertKey(node->left, newKey);
                }
            }
        }

        void balance(int start, int end)
        {
            int mid = (end + 1 + start) / 2;

            balanceOrderedList.push_back(orderedList.at(mid));

            if (start != end) {
                if (mid != end)
                {
                    balance(start, mid - 1);
                    balance(mid + 1, end);
                }
                else
                {
                    balance(start, mid - 1);
                }
            }
        }

        bool hasKey(NODE *node, int searchKey)
        {
            bool exist = false;

            if (node != NULL)
            {
                if (node->strtNode == searchKey)
                {
                    return true;
                }
                else if (node->strtNode < searchKey)
                {
                    exist = hasKey(node->right, searchKey);
                }
                else
                {
                    exist = hasKey(node->left, searchKey);
                }
            }

            return exist;
        }

        void inOrder(NODE *node, std::vector<int> &orderedList)
        {
            if (node->left != NULL)
            {
                inOrder(node->left, orderedList);
            } 
            orderedList.push_back(node->strtNode);

            if (node->right != NULL)
            {
                inOrder(node->right, orderedList);
            }
        }

        void getHeight(NODE *node, int level)
        {
            if (node->left != NULL)
            {
                getHeight(node->left, level + 1);
            }
            if (node->right != NULL)
            {
                getHeight(node->right, level + 1);
            }
            if (height < level)
            {
                height = level;
            }
        }

        void saveMemory(NODE *node)
        {
            // if (node != NULL) {
            //     if (node->left != NULL)
            //     {
            //         saveMemory(node->left);
            //     }
            //     if (node->right != NULL)
            //     {
            //         saveMemory(node->right);
            //     }
            //     delete(node);
            // }
            // else
            // {
            //     return;
            // }
            if( node == NULL ) return;
            else{
                saveMemory(node->left);
                saveMemory(node->right);
                delete node;    
            }
        }
};

void print(BST& tree){
    std::vector<int> inOrder = tree.inOrder();
    std::cout << "The numbers in sorted order: ";
    for (int i=0; i<inOrder.size(); i++){
        std::cout << inOrder.at(i) << ' ';
    }
    std::cout << std::endl;
    std::cout << "Height of the tree: " << tree.getHeight() << std::endl;
}

int main(){
    BST tree;
    for (int i=0; i<17; i++){
        tree.insertKey(i+1);
    }
    print(tree);
    tree.balance();
    print(tree);
    tree.removeKey(42);
    print(tree);
    tree.removeKey(6);
    print(tree);
    tree.removeKey(2);
    print(tree);
    
    return 0;
}