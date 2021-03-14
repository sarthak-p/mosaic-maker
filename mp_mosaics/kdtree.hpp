/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

#include <utility>
#include <algorithm>

using namespace std;

template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
  //since dimension is sort of like an index to a data structure,
  //we can access the element at the dimension through indexing
  if (first[curDim] < second[curDim]) {
    return true; 
  } else if (first[curDim] > second[curDim]) {
    return false; 
  }
  if (first[curDim] == second[curDim]) {
    return first < second; 
  }
  return false;
}
  
  template <int Dim>
  bool KDTree<Dim>::shouldReplace(const Point<Dim> &target,
                                  const Point<Dim> &currentBest,
                                  const Point<Dim> &potential) const
  {
    double current_to_target = 0;
    double potential_to_target = 0;

    for (int i = 0; i < Dim; i++)
    {
      current_to_target += (currentBest[i] - target[i]) * (currentBest[i] - target[i]);
      potential_to_target += (potential[i] - target[i]) * (potential[i] - target[i]);
    }

    if (potential_to_target < current_to_target)
    {
      return true;
    } else if (current_to_target < potential_to_target) {
    return false; 
  }
  if (potential_to_target == current_to_target) {
    return potential < currentBest;
  }
  return false; 
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>> & newPoints)
{
  //pushing all points in newPoints into our helper vector 
  for (unsigned long i = 0; i < newPoints.size(); i++) { 
    vect.push_back(newPoints[i]);
  }
  //calling the buildtree function. Note: we don't need to pass in a vector
  //since our vect is made global 
  root = buildTree(0, newPoints.size() - 1, 0);
}

template <int Dim>
typename KDTree<Dim>::KDTreeNode * KDTree<Dim>::buildTree(int left, int right, int d) {
  if (left > right) {
    return NULL; 
  }

  //median point 
  int m = (left + right) / 2;
  Point <Dim> out = select(left, right, m, d);

  //Create root based on the median
  KDTreeNode * root_ = new KDTreeNode(out);

  //recursive steps 

  //recurse indices between a through m - 1 for left subtree
  //splitting dimension: (d + 1) mod Dim 
  root_->left = buildTree(left, m - 1, (d + 1) % Dim); 

  //recurse indices between m + 1 through b for right subtree 
  //splitting dimension: (d - 1) mod Dim 
  root_->right = buildTree(m + 1, right, (d - 1) % Dim);
  return root_; 
}

//select helper function required for the quickselect algorithm.
template <int Dim>
Point<Dim> KDTree<Dim>::select(int left, int right, int guess, int d)
{
  //edge case: only element in the vector 
  if (left == right) {
    return vect[left];
  }

  //chosing a random index to pass into partition 
  int position = guess; 
  //position is the index of our guess after partitioning 
  position = partition(left, right, position, d);

  //we have found our element 
  if (guess == position) {
    return vect[guess];
  //recursive steps
  //smallest element is on the left side of the pivot 
  } else if (guess < position) {
    return select(left, position - 1, guess, d);
  } else {
  //smallest element is on the right side of the pivot 
    return select(position + 1, right, guess, d);
  }
}
 
//partition helper function required for the quickselect algorithm.
//arranges the vector such that the elements less than pivot are on the left 
//and the elements greater or equal to pivot are on the right of pivot 
template <int Dim>
int KDTree<Dim>::partition(int left, int right, int index, int d)
{
  // 1. first we chose a number at a given index 
  //pivot is the ele at the index given 
  Point <Dim> pivot = vect[index];

  //temp var swap used for swapping
  Point<Dim> swap; 

  //2. move our ele to the end of the array i.e to the right
  //swap pivot and right without using built-in swap function
  swap = vect[index];
  vect[index] = vect[right];
  vect[right] = swap; 

  //3. create a temp var which points to the left index 
  int store = left; 

  //iterate from the left to right index 
  for (int i = left; i < right; i++) {
    //check if our current ele is less than pivot using smallerDimVal()
    if (smallerDimVal(vect[i], pivot, d)) {
      //if yes, then swap
      swap = vect[store];
      vect[store] = vect[i];
      vect[i] = swap; 
      store += 1;
    }
  }

  //move pivot to its final place 
  swap = vect[store];
  vect[store] = vect[right];
  vect[right] = swap; 
  return store; 
}


template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim> &other)
{
  vect = other.vect; 
  root = buildTree(root, 0, vect.size() - 1, 0);
}

template <int Dim>
const KDTree<Dim> &KDTree<Dim>::operator=(const KDTree<Dim> &rhs)
  {
    if (this != rhs) {
      delete *this; 
      this = new KDTree(rhs);
    }
    return *this; 
  }

template <int Dim>
KDTree<Dim>::~KDTree()
{
  clear(root); 
}

// template<int Dim>
// void KDTree<Dim>::copy(KDTreeNode *& other, KDTreeNode *& node) {
//   if (other == NULL) {
//     return; 
//   }
//   node = new KDTreeNode(other->point);
//   copy(node->left, other->left);
//   copy(node->right, other->right);
// }

template <int Dim>
void KDTree<Dim>::clear(KDTreeNode * r) {
  if (r == NULL) {
    return;
  } 
  clear(r->left);
  clear(r->right);
  delete r; 
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim> &query) const
{

  //using helper function near that takes in the current (root), query, and dimension; 
  Point<Dim> best = root->point; 
  return nearest(root, query, 0, root->point);
}

template <int Dim>
Point<Dim> KDTree<Dim>::nearest(KDTreeNode * curRoot, const Point<Dim> q, int d, Point<Dim> best) const {
  //implementing function based on pseudocode shown in AMA 

  //if curRoot is leaf, then return curRoot
  if (curRoot->left == NULL && curRoot->right == NULL) {
    return curRoot->point; 
  }

  //if query[dim] is on the left side of curRoot[dim] -- can use smallerDimVal() to check
  // if (smallerDimVal(q, curRoot->point, d)) {
  //   if (curRoot->left == NULL) {
  //     //best = nearest(curRoot->left, q, best, (d + 1) % Dim);
  //   }
  // }
  return best; 
}


