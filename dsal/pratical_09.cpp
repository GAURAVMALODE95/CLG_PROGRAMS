#include <iostream>
#include <string>
using namespace std;

class AVLNode
{
public:
    string keyword;
    string meaning;
    int height;
    AVLNode *left;
    AVLNode *right;

    AVLNode(string key, string mean)
    {
        keyword = key;
        meaning = mean;
        height = 1;
        left = right = nullptr;
    }
};

class AVLDictionary
{
private:
    AVLNode *root;

public:
    AVLDictionary()
    {
        root = nullptr;
    }

    int getHeight(AVLNode *node)
    {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int getBalanceFactor(AVLNode *node)
    {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    AVLNode *rotateLeft(AVLNode *node)
    {
        AVLNode *newRoot = node->right;
        AVLNode *leftSubtree = newRoot->left;

        newRoot->left = node;
        node->right = leftSubtree;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

        return newRoot;
    }

    AVLNode *rotateRight(AVLNode *node)
    {
        AVLNode *newRoot = node->left;
        AVLNode *rightSubtree = newRoot->right;

        newRoot->right = node;
        node->left = rightSubtree;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

        return newRoot;
    }

    AVLNode *insert(AVLNode *node, string key, string mean)
    {
        if (node == nullptr)
            return new AVLNode(key, mean);

        if (key < node->keyword)
            node->left = insert(node->left, key, mean);
        else if (key > node->keyword)
            node->right = insert(node->right, key, mean);
        else
        {
            // Keyword already exists, update the meaning
            node->meaning = mean;
            return node;
        }

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

        int balanceFactor = getBalanceFactor(node);

        // Left Left Case
        if (balanceFactor > 1 && key < node->left->keyword)
            return rotateRight(node);

        // Right Right Case
        if (balanceFactor < -1 && key > node->right->keyword)
            return rotateLeft(node);

        // Left Right Case
        if (balanceFactor > 1 && key > node->left->keyword)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Left Case
        if (balanceFactor < -1 && key < node->right->keyword)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    AVLNode *findMinNode(AVLNode *node)
    {
        AVLNode *current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    AVLNode *deleteNode(AVLNode *node, string key)
    {
        if (node == nullptr)
            return node;

        if (key < node->keyword)
            node->left = deleteNode(node->left, key);
        else if (key > node->keyword)
            node->right = deleteNode(node->right, key);
        else
        {
            // Node to be deleted found
            if (node->left == nullptr || node->right == nullptr)
            {
                AVLNode *temp = node->left ? node->left : node->right;

                if (temp == nullptr)
                {
                    temp = node;
                    node = nullptr;
                }
                else
                {
                    *node = *temp;
                }

                delete temp;
            }
            else
            {
                AVLNode *minNode = findMinNode(node->right);
                node->keyword = minNode->keyword;
                node->meaning = minNode->meaning;
                node->right = deleteNode(node->right, minNode->keyword);
            }
        }

        if (node == nullptr)
            return node;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

        int balanceFactor = getBalanceFactor(node);

        // Left Left Case
        if (balanceFactor > 1 && getBalanceFactor(node->left) >= 0)
            return rotateRight(node);

        // Left Right Case
        if (balanceFactor > 1 && getBalanceFactor(node->left) < 0)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Right Case
        if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0)
            return rotateLeft(node);

        // Right Left Case
        if (balanceFactor < -1 && getBalanceFactor(node->right) > 0)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    void inorderTraversal(AVLNode *node)
    {
        if (node == nullptr)
            return;

        inorderTraversal(node->left);
        cout << node->keyword << " : " << node->meaning << endl;
        inorderTraversal(node->right);
    }

    void displayAscending()
    {
        inorderTraversal(root);
    }

    void displayDescending()
    {
        descendingTraversal(root);
    }

    void descendingTraversal(AVLNode *node)
    {
        if (node == nullptr)
            return;

        descendingTraversal(node->right);
        cout << node->keyword << " : " << node->meaning << endl;
        descendingTraversal(node->left);
    }

    void searchKeyword(AVLNode *node, string key, int &comparisons)
    {
        if (node == nullptr)
        {
            cout << "Keyword not found" << endl;
            return;
        }

        if (key == node->keyword)
        {
            cout << "Meaning: " << node->meaning << endl;
            return;
        }

        if (key < node->keyword)
        {
            comparisons++;
            searchKeyword(node->left, key, comparisons);
        }
        else
        {
            comparisons++;
            searchKeyword(node->right, key, comparisons);
        }
    }

    void search(string key)
    {
        int comparisons = 0;
        searchKeyword(root, key, comparisons);
        cout << "Number of comparisons: " << comparisons
    }
    int getMaxComparisons(AVLNode *node, string key, int comparisons)
    {
        if (node == nullptr)
            return comparisons;

        if (key == node->keyword)
            return comparisons + 1;

        if (key < node->keyword)
            return getMaxComparisons(node->left, key, comparisons + 1);
        else
            return getMaxComparisons(node->right, key, comparisons + 1);
    }

    int getMaxComparisons(string key)
    {
        int comparisons = 0;
        return getMaxComparisons(root, key, comparisons);
    }
};

int main()
{
    AVLDictionary dictionary;

    // Adding new keywords
    dictionary.root = dictionary.insert(dictionary.root, "apple", "A fruit");
    dictionary.root = dictionary.insert(dictionary.root, "banana", "A yellow fruit");
    dictionary.root = dictionary.insert(dictionary.root, "cat", "A domestic animal");
    dictionary.root = dictionary.insert(dictionary.root, "dog", "A loyal pet");

    // Displaying the data in ascending order
    cout << "Data in ascending order:" << endl;
    dictionary.displayAscending();

    // Deleting a keyword
    dictionary.root = dictionary.deleteNode(dictionary.root, "banana");

    // Displaying the data in descending order
    cout << "Data in descending order:" << endl;
    dictionary.displayDescending();

    // Updating the value of a keyword
    dictionary.root = dictionary.insert(dictionary.root, "apple", "A delicious fruit");

    // Searching for a keyword
    dictionary.search("apple");

    // Finding maximum comparisons for a keyword
    int maxComparisons = dictionary.getMaxComparisons("dog");
    cout << "Maximum comparisons required for finding 'dog': " << maxComparisons << endl;

    return 0;
}
