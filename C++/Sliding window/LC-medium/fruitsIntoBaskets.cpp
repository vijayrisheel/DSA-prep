//https://leetcode.com/problems/fruit-into-baskets/

// You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

// You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

// You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
// Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
// Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
// Given the integer array fruits, return the maximum number of fruits you can pick.

/*NOTE:
======

This is esentially longest substring with 2(No of baskets) max chars. 

*/

#include <bits/stdc++.h>

using namespace std;

int totalFruit(vector<int> &fruits) {
        int n = fruits.size();
        int windowStart = 0;
        int windowEnd = 0;
        unordered_map<int, int> umap;
        int res = 0;

        while(windowEnd < n) {
            umap[fruits[windowEnd]]++;

            while(umap.size() > 2) {
                umap[fruits[windowStart]]--;
                if(umap[fruits[windowStart]] == 0) {
                    umap.erase(fruits[windowStart]);
                }
                windowStart++;
            }

            res = max(res, windowEnd-windowStart+1);
            windowEnd++;
        }
        return res;
}

int main() {
    vector<int> fruits{1,2,1};   //Ans: 3
    // vector<int> fruits{0,1,2,2};     //Ans: 3
    // vector<int> fruits{1,2,3,2,2};   //Ans: 4

    cout << totalFruit(fruits) << endl;

    return 0;
}