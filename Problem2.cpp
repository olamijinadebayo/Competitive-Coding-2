// 0-1 knapsack

// Time complexity-O(nW)
// space complexity O(n);
// Did this code successfully run on Leetcode :not on leetcode
// Any problem you faced while coding this : no

// we create 2d array to hold results of any problem which we have solved earlier
//we check to see if the solution to a particular sub problem is present so we can move to the next one
// we calculate the maximum possible profit if we include the current item or we dont include it
#include <iostream>
#include <vector>
using namespace std;

int knapsackRecursive(vector< vector<int> > lookupTable, int profits[], int profitsLength, int weights[], int capacity, int currentIndex) {

  // base checks  
  if (capacity <= 0 || currentIndex >= profitsLength || currentIndex < 0)
    return 0;

  // if we have already solved the problem, return the result from the table  
  if (lookupTable[currentIndex][capacity] != 0)
    return lookupTable[currentIndex][capacity];

  // recursive call after choosing the element at the currentIndex
  // if the weight of the element at currentIndex exceeds the capacity, we shouldn't process this
  int profit1 = 0;
  if (weights[currentIndex] <= capacity)
    profit1 = profits[currentIndex] + knapsackRecursive(lookupTable, profits, profitsLength, weights,
      capacity - weights[currentIndex], currentIndex + 1);

  // recursive call after excluding the element at the currentIndex
  int profit2 = knapsackRecursive(lookupTable, profits, profitsLength, weights, capacity, currentIndex + 1);

  lookupTable[currentIndex][capacity] = max(profit1, profit2);
  return lookupTable[currentIndex][capacity];
}

int knapSack(int profits[], int profitsLength, int weights[], int capacity) {
  vector< vector<int> > lookupTable(
    profitsLength,
    std::vector<int>(capacity + 1, 0));
  return knapsackRecursive(lookupTable, profits, profitsLength, weights, capacity, 0);
}

int main() {
    int profits[] = {1, 6, 10, 16};
    int weights[] = {1, 2, 3, 5};
    cout << "Total knapsack profit = " << knapSack(profits,4, weights, 7) << endl;
    cout << "Total knapsack profit = " << knapSack(profits,4, weights, 6) << endl;
}
