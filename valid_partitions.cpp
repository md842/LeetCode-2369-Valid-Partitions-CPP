/*
 * Leetcode 2369: Check if There is a Valid Partition For The Array
   https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/.

 * You are given a 0-indexed integer array nums. You have to partition the
    array into one or more contiguous subarrays.

 * We call a partition of the array valid if each of the obtained subarrays
    satisfies one of the following conditions:

 *  The subarray consists of exactly 2 equal elements. For example, the
     subarray [2, 2] is good.
 *  The subarray consists of exactly 3 equal elements. For example, the
     subarray [4, 4, 4] is good.
 *  The subarray consists of exactly 3 consecutive increasing elements, that
     is, the difference between adjacent elements is 1. For example, the
     subarray [3,4,5] is good, but the subarray [1,3,5] is not.

 * Return true if the array has at least one valid partition. Otherwise, return
    false.
 
 * Constraints:
 *  2 <= nums.length <= 10^5
 *  1 <= nums[i] <= 10^6
 */

#include <iostream>
#include <vector>
#include <iomanip> // This is used by test(), not the main algorithm
#include <string> // This is used by test(), not the main algorithm

using std::vector;
using std::cout; // This is used by test(), not the main algorithm
using std::endl; // This is used by test(), not the main algorithm

bool validPartition(vector<int>& nums) {
  if (nums.size() < 2) // No partitions can exist for an array smaller than 2
    return false; // Exit early

  // Performance optimization: Convert vector to array for faster accesses
  int *numsArr = &nums[0];
  int dp[nums.size()]; // Dynamic programming array
  std::fill(dp, dp + nums.size(), 0); // Initialize all subproblems to false
  
  // Dynamic programming: 0 through subProblem is a sub-array of nums.
  for (int subProblem = 1; subProblem < nums.size(); subProblem++) {
    // Condition 1: Exactly 2 equal elements
    if (numsArr[subProblem] == numsArr[subProblem - 1]){
      if (subProblem == 1) // If this is the first eligible subproblem
        dp[subProblem] = 1; // Set it to true
      else if (dp[subProblem - 2]) // or the subproblem 2 before this was true
        dp[subProblem] = 1; // Set it to true
    }
    // Condition 2: Exactly 3 equal elements
    if ((subProblem > 1) && (numsArr[subProblem] == numsArr[subProblem - 1]) &&
                            (numsArr[subProblem] == numsArr[subProblem - 2])){
      if (subProblem == 2) // If this is the first eligible subproblem
        dp[subProblem] = 1; // Set it to true
      else if (dp[subProblem - 3]) // or the subproblem 3 before this was true
        dp[subProblem] = 1; // Set it to true
    }
    // Condition 3: Exactly 3 consecutive increasing elements
    if ((subProblem > 1) &&
        (numsArr[subProblem] == numsArr[subProblem - 1] + 1) &&
        (numsArr[subProblem] == numsArr[subProblem - 2] + 2)){
      if (subProblem == 2) // If this is the first eligible subproblem
        dp[subProblem] = 1; // Set it to true
      else if (dp[subProblem - 3]) // or the subproblem 3 before this was true
        dp[subProblem] = 1; // Set it to true
    }
  }
  
  return dp[nums.size() - 1]; // Return solution from dynamic programming array
}

void test(vector<int>& nums, bool exp){
  std::string testCase = "nums: [";
  for (int i = 0; i < nums.size(); i++){
    testCase += std::to_string(nums[i]);
    if (i < nums.size() - 1)
      testCase += ", ";
  }
  testCase += "]";

  std::string details = "Expected ";
  if (exp)
    details += "true";
  else
    details += "false";
  details += ", got ";

  bool output = validPartition(nums);
  if (output)
    details += "true";
  else
    details += "false";

  std::string status = "";
  if (exp == output)
    status = "OK";
  else
    status = "Error";

  cout << std::setw(50) << testCase << std::setw(11) << status << std::setw(30)
  << details << endl;
}

int main(){
  // Test cases
  cout << endl << std::setw(50) << "Test case" << std::setw(11) << "Status";
  cout << std::setw(30) << "Details" << endl;
  cout << std::string(91, '-') << endl;

  vector<int> nums;
  
  nums = {4, 4, 4, 5, 6};
  test(nums, true);

  nums = {1, 1, 1, 2};
  test(nums, false);

  return 0;
}

