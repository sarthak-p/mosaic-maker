/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */

#include "List.h"
#include <iostream>

using namespace std; 

template <class T>
List<T>::List() { 
  // @TODO: graded in MP3.1
    ListNode* head_ = NULL;
    ListNode* tail_ = NULL;
    length_ = 0; 
}

/**
 * Returns a ListIterator with a position at the beginning of
 * the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::begin() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(head_);

}

/**
 * Returns a ListIterator one past the end of the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::end() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(NULL);
}


/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <typename T>
void List<T>::_destroy() {

  if (length_ == 0) {
    return; 
  } else { 
    while (head_ != NULL) {
    ListNode *next = head_->next;
    delete head_; 
    head_ = next;
    }
    head_ = NULL;
    tail_ = NULL; 
  }
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertFront(T const & ndata) {
  /// @todo Graded in MP3.1

  ListNode * newNode = new ListNode(ndata);

  if (length_ == 0) {
    head_ = newNode; 
    tail_ = newNode; 
    length_ = 1;  
  } else {
    newNode->next = head_; 
    head_->prev = newNode;
    head_ = newNode; 
    length_ ++;
  }
}
/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertBack(const T & ndata) {
  /// @todo Graded in MP3.1
  ListNode * newNode = new ListNode(ndata);

  //if length_ = 0, then the array is empty in which case both head and tail are newNode 
  if (length_ == 0)
  {
    head_ = newNode;
    tail_ = newNode; 
    length_ = 1; 
  } else {
    newNode->prev = tail_; 
    tail_->next = newNode;
    tail_ = newNode;  
    length_++; 
  }
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List or ListNode objects!
 *
 * This function is also called by the public split() function located in
 * List-given.hpp
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <typename T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint) {
  /// @todo Graded in MP3.1

  ListNode *curr = start;

  if (length_ < splitPoint || curr->next == NULL) {
    return curr;
  } 
  
  for (int i = 0; i < splitPoint; i++ && curr->next != NULL) {
    curr = curr->next;
  }

  curr->prev->next = NULL; 
  curr->prev = NULL; 
  return curr; 
}
  /**
  * Modifies List using the rules for a TripleRotate.
  *
  * This function will to a wrapped rotation to the left on every three 
  * elements in the list starting for the first three elements. If the 
  * end of the list has a set of 1 or 2 elements, no rotation all be done 
  * on the last 1 or 2 elements.
  * 
  * You may NOT allocate ANY new ListNodes!
  */
  template <typename T>
  void List<T>::tripleRotate() {

    ListNode *curr = head_;
    ListNode *node1 = NULL;
    ListNode *node2 = NULL;
    ListNode *node4 = NULL; 
    ListNode *node0 = NULL;
    if (length_ == 1 || length_ == 2) {
      return; 
    }

    // node1 -> node2 -> node3 -> node4  
    // 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
    
    for (int i = 1; i <= length_; i++) {

      ListNode * curr2 = head_; 
      while (curr2 != NULL) {
        curr2 = curr2->next;
      }
      
      if (i % 3 == 0) {
        node2 = curr->prev;
        node1 = curr->prev->prev;
        node4 = curr->next;
        node0 = node1->prev;
        node2->prev = node1->prev;
        if (node0 != NULL) {
          node0->next = node2;
        }
        node2->next = curr;
        curr->prev = node2;
        node2->next = curr;
        if (curr->next == NULL) {
          node1->next = NULL;
          node1->prev = curr;
          tail_ = node1;
        } else {
          node1->next = node4;
          node1->prev = curr;
          node4->prev = node1;
        }
        curr->next = node1;
                
        if (i == 3) {
          head_ = node2;   
        }
        curr = curr->next->next;
      } else {
        curr = curr->next;
      }
    }
  }

  /**
 * Reverses the current List.
 */
        template <typename T>
        void List<T>::reverse()
        {
          reverse(head_, tail_);
        }

        /**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
        template <typename T>
        void List<T>::reverse(ListNode * &startPoint, ListNode * &endPoint)
        {
          ListNode * temp = startPoint;
          ListNode * temp_next;
          ListNode * end_next = endPoint->next; 
          ListNode * start_prev = startPoint->prev; 

          if (startPoint == NULL) {
            return; 
          } else if (endPoint == NULL) {
            return; 
          } else if (temp->next == endPoint) {
            return; 
          }
          
          while (temp != endPoint) {
            temp_next = temp->next; 
            temp->next = temp->prev;
            temp->prev = temp_next;
            temp = temp_next;
          } 

          ListNode * new_end = startPoint; 

          startPoint->next = endPoint->next; 
          endPoint->next = endPoint->prev; 
          endPoint->prev = startPoint->prev; 

          new_end = startPoint; 
          startPoint = endPoint;
          endPoint = new_end;
          
          //checking if our new start and end are actually new start and end
          if (start_prev != NULL) {
            start_prev->next = startPoint; 
          } else if (end_next != NULL) {
            end_next->prev = endPoint;
          }
        }

        /**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
        template <typename T>
        void List<T>::reverseNth(int n)
        {
          int i = 0; 
          ListNode * curr = head_;
          ListNode * start = head_;

          for (int x = 1; x <= length_; x++) {
            while (curr != NULL && i < n) {
              curr = curr->next;
              i++;
              }
            }
            reverse(start, curr);
            curr = curr->next;
            start = curr;
        }

        /**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
        template <typename T>
        void List<T>::mergeWith(List<T> & otherList)
        {
          // set up the current list
          head_ = merge(head_, otherList.head_);
          tail_ = head_;

          // make sure there is a node in the new list
          if (tail_ != NULL)
          {
            while (tail_->next != NULL)
              tail_ = tail_->next;
          }
          length_ = length_ + otherList.length_;

          // empty out the parameter list
          otherList.head_ = NULL;
          otherList.tail_ = NULL;
          otherList.length_ = 0;
        }

        /**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
        template <typename T>
        typename List<T>::ListNode *List<T>::merge(ListNode * first, ListNode * second)
        {
          ListNode * temp = NULL; 

          //if one list doesn't exist, return the other. If either don't exist, return.  
          if (first == NULL) {
            return second; 
          } else if (second == NULL) {
            return first; 
          }

          //determine the first node in our end list 
          if (second->data < first->data) {
            temp = second;
            second = second->next;
          } else if (first->data < second->data) {
            temp = first;
            first = first->next;
          }

          ListNode * out = temp; 

          //compare both nodes simulataneously and create a new list 
          while(first != NULL && second != NULL) {
            if (second->data < first->data) {
              temp->next = second; 
              temp = second; 
              second = second->next; 
            } else {
              temp->next = first;
              temp = first; 
              first = first->next; 
            }
          }

          //if one list reaches NULL, then we connect our temp var to the other 
          //list and our end list is complete 
          if (second == NULL) {
            temp ->next = first; 
            temp = first; 
          } else if (first == NULL) {
            temp ->next = second; 
            temp = second; 
          }
          return out; 
        }

        /**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * Called by the public sort function in List-given.hpp
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
        template <typename T>
        typename List<T>::ListNode *List<T>::mergesort(ListNode * start, int chainLength)
        {
          //base case: if size = 1 then return the head 
          if (chainLength == 1) {
            return start; 
          }

          //split the list into two smaller parts
          ListNode * head_second = split(start, (int)chainLength / 2);

          //recursively sort the first half 
          start = mergesort(start, (int) chainLength / 2); 
          //recursively sort the second half 
          head_second = mergesort(head_second, (int) (chainLength % 2) + (chainLength / 2));

          //merge the two lists 
          return merge(start, head_second);
          
          return NULL; 
        }
