/**
 * @file huffman_tree.cpp
 * Implementation of a Huffman Tree class.
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>

#include "huffman_tree.h"

using namespace std;

HuffmanTree::HuffmanTree(vector<Frequency> frequencies)
{
    std::stable_sort(frequencies.begin(), frequencies.end());
    buildTree(frequencies);
    vector<bool> path;
    buildMap(root_, path);
}

HuffmanTree::HuffmanTree(const HuffmanTree& other)
{
    copy(other);
}

HuffmanTree::HuffmanTree(BinaryFileReader& bfile)
{
    root_ = readTree(bfile);
    vector<bool> path;
    buildMap(root_, path);
}

HuffmanTree::~HuffmanTree()
{
    clear(root_);
}

const HuffmanTree& HuffmanTree::operator=(const HuffmanTree& rhs)
{
    if (this != &rhs) {
        clear(root_);
        copy(rhs);
    }
    return *this;
}

void HuffmanTree::clear(TreeNode* current)
{
    if (current == NULL)
        return;
    clear(current->left);
    clear(current->right);
    delete current;
}

void HuffmanTree::copy(const HuffmanTree& rhs)
{
    root_ = copy(rhs.root_);
}

HuffmanTree::TreeNode* HuffmanTree::copy(const TreeNode* current)
{
    if (current == NULL)
        return NULL;
    TreeNode* node = new TreeNode(current->freq);
    node->left = copy(current->left);
    node->right = copy(current->right);
    return node;
}

HuffmanTree::TreeNode*
HuffmanTree::removeSmallest(queue<TreeNode*>& singleQueue,
                            queue<TreeNode*>& mergeQueue)
{
    if (singleQueue.empty() == 0 && mergeQueue.empty()) {
        return NULL; 
    }

    if (mergeQueue.empty()) {
        TreeNode * smallest = singleQueue.front(); 
        singleQueue.pop(); 
        return smallest; 
    }

    if (singleQueue.empty()) {
        TreeNode * smallest = mergeQueue.front(); 
        mergeQueue.pop(); 
        return smallest; 
    }

    if (mergeQueue.front()->freq.getFrequency() < singleQueue.front()->freq.getFrequency()) {
        TreeNode * smallest = mergeQueue.front(); 
        mergeQueue.pop(); 
        return smallest; 
    } else {
        TreeNode * smallest = singleQueue.front();
        singleQueue.pop(); 
        return smallest; 
    }
}

void HuffmanTree::buildTree(const vector<Frequency>& frequencies)
{
    queue<TreeNode*> singleQueue; // Queue containing the leaf nodes
    queue<TreeNode*> mergeQueue;  // Queue containing the inner nodes

    //First, place all of the leaf nodes into the singleQueue 
    //in increasing order of frequency. Note: frequencies is already sorted for you.
    for (unsigned i = 0; i < frequencies.size(); i++) {
        TreeNode * node = new TreeNode(frequencies[i]);
        singleQueue.push(node);
    }

    //Next, until there is only one node on the two queues (that is, one of the queues is empty 
    //and one has a single node), remove the two smallest entries from the two queues.
    while (mergeQueue.size() + singleQueue.size() > 1) {
        TreeNode * smallest1 = removeSmallest(singleQueue, mergeQueue);
        TreeNode * smallest2 = removeSmallest(singleQueue, mergeQueue);

        //Then, create a new internal node with these nodes as children, 
        //whose frequency is the sum of these two children's frequencies.
        TreeNode * internal = new TreeNode(smallest1->freq.getFrequency() + smallest2->freq.getFrequency());

        //Place the new internal node onto the back of the mergeQueue
        // To facilitate grading, make sure that when building internal nodes, 
        //the left child has the smallest frequency
        internal->left = smallest1; 
        internal->right = smallest2; 
        mergeQueue.push(internal);
    }

    //Finally, when there is a single node left, it is the root. 
    //Assign it to the root and you're done!
    if (singleQueue.empty()) {
        root_ = mergeQueue.front();
    } else if (mergeQueue.empty()) {
        root_ = singleQueue.front(); 
    }
}

string HuffmanTree::decodeFile(BinaryFileReader& bfile)
{
    stringstream ss;
    decode(ss, bfile);
    return ss.str();
}

void HuffmanTree::decode(stringstream& ss, BinaryFileReader& bfile)
{
    TreeNode* current = root_;
    while (bfile.hasBits()) {
        //we go left if the bit was a 0(or false) 
        if (!bfile.getNextBit()) {
            current = current->left;
        }
        else
        //we go right if the bit was a 1 (or true)
        {
            current = current->right;
        }
        //if we are at a leaf node, we should "print" its character to 
        //the stringstream (with operator<<, just like cout) 
        //and start traversing from the root node again
        if (current->right == NULL && current->left == NULL) {
            ss << current->freq.getCharacter();
            current = root_; 
        }
    }
}

void HuffmanTree::writeTree(BinaryFileWriter& bfile)
{
    writeTree(root_, bfile);
}

void HuffmanTree::writeTree(TreeNode* current, BinaryFileWriter& bfile)
{
    //If we are a leaf node, write the bit "1" followed by the byte that is the 
    //character of this node
    if (current->left == NULL && current->left == NULL) {
        bfile.writeBit(1);
        bfile.writeByte(current->freq.getCharacter());
    } else {
        //If we are an internal node, writ the bit "0", and then encode the 
        //left and right subtree, recursively
        bfile.writeBit(0);
        writeTree(current->right, bfile);
        writeTree(current->left, bfile);
    }
}

HuffmanTree::TreeNode* HuffmanTree::readTree(BinaryFileReader& bfile)
{
    //If the file has no more bits, we're done.
    if (!bfile.hasBits()) {
        return NULL; 
    }

    TreeNode * node; 
    
    //If we read a 1 bit, we are a leaf node: create a new TreeNode with the 
    //character that is the next byte in the file (its frequency should be 0, 
    //since we are ignoring frequency data now).
    if (bfile.getNextBit()) {
        node = new TreeNode(Frequency(bfile.getNextByte(), 0));
    } else {
        node = new TreeNode(0);
        node ->left = readTree(bfile);
        node ->right = readTree(bfile);
    }
    return node; 
}

void HuffmanTree::buildMap(TreeNode* current, vector<bool>& path)
{
    // Base case: leaf node.
    if (current->left == NULL && current->right == NULL) {
        bitsMap_[current->freq.getCharacter()] = path;
        return;
    }

    // Move left
    path.push_back(false);
    buildMap(current->left, path);
    path.pop_back();

    // Move right
    path.push_back(true);
    buildMap(current->right, path);
    path.pop_back();
}

void HuffmanTree::printInOrder() const
{
    printInOrder(root_);
    cout << endl;
}

void HuffmanTree::printInOrder(const TreeNode* current) const
{
    if (current == NULL)
        return;
    printInOrder(current->left);
    cout << current->freq.getCharacter() << ":" << current->freq.getFrequency()
         << " ";
    printInOrder(current->right);
}

void HuffmanTree::writeToFile(const string& data, BinaryFileWriter& bfile)
{
    for (auto it = data.begin(); it != data.end(); ++it)
        writeToFile(*it, bfile);
}

void HuffmanTree::writeToFile(char c, BinaryFileWriter& bfile)
{
    vector<bool> bits = getBitsForChar(c);
    for (auto it = bits.begin(); it != bits.end(); ++it)
        bfile.writeBit(*it);
}

vector<bool> HuffmanTree::getBitsForChar(char c)
{
    return bitsMap_[c];
}

// class for generic printing

template <typename TreeNode>
class HuffmanTreeNodeDescriptor
    : public GenericNodeDescriptor<HuffmanTreeNodeDescriptor<TreeNode>>
{
  public:
    HuffmanTreeNodeDescriptor(const TreeNode* root) : subRoot_(root)
    { /* nothing */
    }

    string key() const
    {
        std::stringstream ss;
        char ch = subRoot_->freq.getCharacter();
        int freq = subRoot_->freq.getFrequency();

        // print the sum of the two child frequencies
        if (ch == '\0')
            ss << freq;
        // print the leaf containing a character and its count
        else {
            if (ch == '\n')
                ss << "\\n";
            else
                ss << ch;
            ss << ":" << freq;
        }
        return ss.str();
    }

    bool isNull() const
    {
        return subRoot_ == NULL;
    }
    HuffmanTreeNodeDescriptor left() const
    {
        return HuffmanTreeNodeDescriptor(subRoot_->left);
    }
    HuffmanTreeNodeDescriptor right() const
    {
        return HuffmanTreeNodeDescriptor(subRoot_->right);
    }

  private:
    const TreeNode* subRoot_;
};

int HuffmanTree::height(const TreeNode* subRoot) const
{
    if (subRoot == NULL)
        return -1;
    return 1 + std::max(height(subRoot->left), height(subRoot->right));
}

void HuffmanTree::print(std::ostream& out) const
{
    int h = height(root_);
    if (h > _max_print_height) {
        out << "Tree is too big to print. Try with a small file (e.g. "
               "data/small.txt)"
            << endl;
        return;
    }

    printTree(HuffmanTreeNodeDescriptor<TreeNode>(root_), out);
}

Frequency
HuffmanTree::testRemoveSmallest(vector<Frequency> single,
                                vector<Frequency> merge)
{
    queue<TreeNode*> singleQueue;
    queue<TreeNode*> mergeQueue;
    for (auto it = single.begin(); it != single.end(); ++it) {
         singleQueue.push(new TreeNode(*it));
    }
    for (auto it = merge.begin(); it != merge.end(); ++it) {
         mergeQueue.push(new TreeNode(*it));
    }

    TreeNode* testNode = removeSmallest(singleQueue, mergeQueue);
    Frequency testFreq = testNode->freq;

    delete testNode;
    while (!singleQueue.empty()) {
        delete singleQueue.front();
        singleQueue.pop();
    }
    while (!mergeQueue.empty()) {
        delete mergeQueue.front();
        mergeQueue.pop();
    }

    return testFreq;
}
