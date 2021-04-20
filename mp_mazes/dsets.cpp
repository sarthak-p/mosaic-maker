/* Your code here! */
#include "dsets.h"
#include <vector>

using namespace std;

void DisjointSets::addelements(int num)	{
    //adding n connected roots to the end of the vector 
    int i = 0; 
    while (i < num) {
        vect.push_back(-1);
        i++; 
    }
}

int DisjointSets::find(int elem) {
    //find the representative element of the set that contains the element  
    int index; 
    if (vect[elem] < 0) {
        return elem; 
    } 
    index = find(vect[elem]);
    vect[elem] = index; 
    return index; 
}


void DisjointSets::setunion(int a, int b) {
    //merging two disjoint sets, updating size and parent pointer 
    a = find(a); 
    b = find(b);

    int size = vect[a] + vect[b];

    if (vect[a] <= vect[b]) {
        vect[b] = a; 
        vect[a] = size; 
    }

    if (vect[b] <= vect[a]) {
        vect[a] = b;
        vect[b] = size;
    }
}

int DisjointSets::size(int elem) {
    //returning size of the set that contains the element 
    int i = find(elem);
    int size = vect[i];
    return -1 * size; 
}
