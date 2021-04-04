/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */
using namespace std; 

template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    functionCalls.push_back("rotateLeft"); // Stores the rotation name (don't remove this)
    //rotating
    Node * node = t->right;
    t->right = node->left;
    node->left = t;

    //updating height 
    t->height = max(heightOrNeg1(t->left), heightOrNeg1(t->right)) + 1;
    t = node; 
    t->height = max(heightOrNeg1(t->left), heightOrNeg1(t->right)) + 1;
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    functionCalls.push_back("rotateLeftRight"); // Stores the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    functionCalls.push_back("rotateRight"); // Stores the rotation name (don't remove this)
    //rotating
    Node * node = t->left;
    t->left = node->right;
    node->right = t;

    //updating height 
    t->height = max(heightOrNeg1(t->left), heightOrNeg1(t->right)) + 1;
    t = node;
    t->height = max(heightOrNeg1(t->left), heightOrNeg1(t->right)) + 1;
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    functionCalls.push_back("rotateRightLeft"); // Stores the rotation name (don't remove this)
    rotateRight(t->right);
    rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
    if (!subtree|| (!subtree->right && !subtree->left)) {
        return;
    }

    //height of tree
    int bal = heightOrNeg1(subtree->right) - heightOrNeg1(subtree->left); 

    //imbalance of 2
    if (bal == 2) {
        int right_ = heightOrNeg1(subtree->right->right) - heightOrNeg1(subtree->right->left);
        //left-left imbalance
        if (right_ == 1) { 
            rotateLeft(subtree);
        //left-right imbalance 
        } else {  
            rotateRightLeft(subtree);
        }
    }
    //imbalance of -2 
    if (bal == -2) {
        int left_ = heightOrNeg1(subtree->left->right) - heightOrNeg1(subtree->left->left); 
        //right-left imbalance
        if (left_ == 1) {
            rotateLeftRight(subtree);
        //right-right imbalance
        } else {
            rotateRight(subtree); 
        }
    }
    subtree->height = max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right)) + 1;
}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    if (!subtree) {
        Node * node = new Node(key, value);
        subtree = node; 
    } else if (subtree->key > key) {
        insert(subtree->left, key, value);
    } else if (subtree->key < key) {
        insert(subtree->right, key, value);
    }
    rebalance(subtree);
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    if (!subtree) {
        return; 
    }
    if (key > subtree->key) {
        remove(subtree->right, key);
    } else if (key < subtree->key) {
        remove(subtree->left, key);
    } else {
        if (!subtree->right && !subtree->left) {
            delete subtree; 
            subtree = NULL;
        } else if (subtree->right && subtree->left) {
            Node * inorder = subtree->left;
            while (inorder->right) {
                inorder = inorder->right; 
            }
            swap(subtree, inorder);
            remove(subtree->left, key);
        } else {
            Node * temp = NULL; 
            if (subtree->left) {
                temp = subtree->left;
            } 
            if (subtree->right) {
                temp = subtree->right;
            } 
            delete subtree;
            subtree = temp; 
        }
    }
    rebalance(subtree);
}
