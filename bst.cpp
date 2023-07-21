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
                saveMemory();
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
            std::vector<int> orderedList;
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

        void saveMemory()
        {
            saveMemory(root);
        }
    private:
        NODE *root;
        int height, parentNode;

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
            if (node->left != NULL)
            {
                saveMemory(node->left);
            }

            if (node->right != NULL)
            {
                saveMemory(node->right);
            }

            delete(node);
        }
};

int main()
{
    std::vector<int> inputs, orderedList;
    int searchKey;
    std::string input;
    BST bst;

    std::cout << "Enter the numbers to be stored (end with a letter): ";

    std::cin >> input;

    while(!isalpha(input.at(0)))
    {
        inputs.push_back(std::stoi(input));
        std::cin >> input;
    }

    std::cout << std::endl << "Which number do you want to look up? ";

    std::cin >> searchKey;

    for (int i = 0; i < inputs.size(); i++)
    {
        bst.insertKey(inputs.at(i));
    }

    std::cout << std::endl << searchKey << " is in the tree: ";

    if (bst.hasKey(searchKey))
    {
        std::cout << "yes" << std::endl;
    }
    else
    {
        std::cout << "no" << std::endl;
    }

    std::cout << "The numbers in sorted order: ";
    if (inputs.size() > 0)
    {
        orderedList = bst.inOrder();
        for(int i = 0; i < orderedList.size(); i++)
        {
            std::cout << orderedList.at(i) << " ";
        }

        std::cout << std::endl << "Height of the tree: " << bst.getHeight();
    }
    else
    {
        std::cout << std::endl << "Height of the tree: 0";
    }
}