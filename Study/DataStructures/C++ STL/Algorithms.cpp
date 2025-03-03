#include <iostream>
#include <set>
using namespace std;

int main()
{
    // Following are the generic algos for most of the containers. Use implementation of the methods in
    // case of specific data structure

    // 1) find() - Returns iterator. The following syntax is not applicable for strings
    //      find(v.begin(), v.end(), 4);

    // 2) count() - Returns int. Majorly used to check the presence of elements in maps and sets (Respective methods of the containers are used).
    //      count(v.begin(), v.end(), 5);

    // 3) unique() -Returns forward iterator to the new end of the range. Remove consecutive duplicates ƒrom the container. Returns iterator to the element from where
    //            all the elements are stored.
    //      auto it=unique(v.begin(), v.end());
    //      erase(it, v.end());                 // removes the consecutive duplicates.

    // 4) reverse() - Returns none
    //      reverse(v.begin(), v.end())

    // 5) random_shuffle()
    //      random_shuffle(v.begin(), v.end());
    //      random_shuffle(v.begin(), v.end(), cmp);

    // 6) next_permutation - Returns bool. Used to shuffle the container and get the next possible permutation.
    //                    Does not take care of the first permuation, which is to be processed before. Hence, use with do while loop for considering current permutation.
    //                    Returns a boolean false when none of the permutations are left to be computed.
    //      bool doesNextPermutationExist = next_permutation(v.begin(), v.end())

    // 7) is_sorted() - Returns bool. Returns whether the current range is sorted or not.
    //      bool isSorted = is_sorted(v.begin(), v.end());

    // 8) is_permutation() - Returns bool. Checks whether the two ranges are permutation or not.
    //      v1, v2
    //      bool isPermutation = is_permutation(v1.begin(), v1.end(), v2.begin(), v2.end())

    // 9) merge() - Returns void. Merges two containers into one final container.
    //      v1, v2, v3
    //      merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

    // 10) distance() - Returns int. Returns the index of the element from the start iterator.
    //      v
    //      int index = distance(v.begin(), lower_bound(all(v), 5));  // Possible Implementation. The second parameter
    //      can be replaced by any function which returns a forward iterator.

    // 11) is_sorted(.begin(), .end()) - Checks whether the range is sorted in non-decreasing order.

    // 12) fill() - The fill() function in C++ assigns a specific value to a range of elements in an array, vector, or any other container. It is part of the <algorithm> library.
    // void fill(ForwardIterator first, ForwardIterator last, const T& value);
    return 0;
}