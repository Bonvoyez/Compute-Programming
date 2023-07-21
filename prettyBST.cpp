#include <iostream>
#include <vector>
#include <iomanip>

class Matrix
{
    public:
        Matrix(int row, int column) 
        {
            rowsNum = row;
            columnsNum = column;
            matrix.resize(row*column);
        }

        std::string& at(int row, int column)
        {
            return matrix.at(row*columnsNum + column);
        }

    private:
        std::vector<std::string> matrix;
        int rowsNum, columnsNum;
};

class Node
{
    public:
        Node(){}

        int strtNode;
        Node *left;
        Node *right;
};

class BST
{
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

        void insertKey(int newKey);
        bool hasKey(int searchKey);
        std::vector<int> inOrder();
        int setHeight();
        void prettyPrint();

    private:
        Node *root;
        int height, parentNode;
        std::vector<int> orderedList;

        void insertKey(Node *Node, int newKey);
        bool hasKey(Node *Node, int searchKey);
        void inOrder(Node *Node, std::vector<int> &orderedList);
        void setHeight(Node *Node, int level);
        void getLevel(Node *node, int key, int& column, int c);
        void saveMemory(Node *Node);
};

void BST::insertKey(int newKey)
{
    if (root == NULL)
    {
        root = new Node();
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

bool BST::hasKey(int searchKey)
{
    return hasKey(root, searchKey);
}

std::vector<int> BST::inOrder()
{
    inOrder(root, orderedList);

    return orderedList;
}

int BST::setHeight()
{
    if (root != NULL)
    {
        height = 1;
        setHeight(root, 1);
        return height;
    }
    return 0;
}

void BST::prettyPrint()
{
    Matrix m(orderedList.size(), height);

    for (int i = 0; i < orderedList.size(); i++)
    {
        int level, count = 0;
        getLevel(root, orderedList.at(i), level, count);

        m.at(i, level) = std::to_string(orderedList.at(i));
    }

    for (int i = 0; i < (2 * height) + 1; i++)
    {
        for (int j = 0; j < (2 * orderedList.size()) + 1; j++)
        {
            if (j % 2 == 0 && i % 2 == 0)
            {
                std::cout << "-";
            }
            else if (j % 2 != 0 && i % 2 == 0)
            {
                std::cout << "----";
            }
            else if (j % 2 == 0 && i % 2 != 0)
            {
                std::cout << "|";
            }
            else 
            {
                std::cout << std::setw(4) << m.at((j - 1) / 2, (i - 1) / 2);
            }
        }
        std::cout << std::endl;
    }
}

void BST::insertKey(Node *node, int newKey)
{
    if (node->strtNode < newKey)
    {
        if (node->right == NULL)
        {
            node->right = new Node();
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
            node->left = new Node();
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

bool BST::hasKey(Node *node, int searchKey)
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

void BST::inOrder(Node *node, std::vector<int> &orderedList)
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

void BST::setHeight(Node *node, int level)
{
    if (node->left != NULL)
    {
        setHeight(node->left, level + 1);
    }
    if (node->right != NULL)
    {
        setHeight(node->right, level + 1);
    }
    if (height < level)
    {
        height = level;
    }
}

void BST::getLevel(Node *node, int key, int& level, int count)
{
    if (node->strtNode != key)
    {
        if (node->left != NULL)
        {
            getLevel(node->left, key, level, count + 1);
        }
        if (node->right != NULL)
        {
            getLevel(node->right, key, level, count + 1);
        }
    }
    else
    {
        level = count;
        return;
    }
}

void BST::saveMemory(Node *node)
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

int main()
{
    std::vector<int> inputs, orderedList;
    int searchKey;
    std::string input;
    BST bst;

    std::cout << "Enter the numbers to be stored: ";
    std::cin >> input;

    while(!isalpha(input.at(0)))
    {
        inputs.push_back(std::stoi(input));
        std::cin >> input;
    }

    for (int i = 0; i < inputs.size(); i++)
    {
        bst.insertKey(inputs.at(i));
    }

    std::cout << std::endl << "The numbers in sorted order: ";
    if (inputs.size() > 0)
    {
        orderedList = bst.inOrder();

        for(int i = 0; i < orderedList.size(); i++)
        {
            std::cout << orderedList.at(i) << " ";
        }
        std::cout << std::endl;

        bst.setHeight();
        bst.prettyPrint();
    }

    return 0;
}