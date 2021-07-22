# Template #3 is another unique form of Binary Search. It is used to search for an 
# element or condition which requires accessing the current index and its immediate 
# left and right neighbor's index in the array.


# Key Attributes:
# ----------------------------------------------------------------------------------
# 	1. An alternative way to implement Binary Search
# 	2. Search Condition needs to access element's immediate left and right neighbors
# 	3. Use element's neighbors to determine if condition is met and decide whether 
#      to go left or right
# 	4. Gurantees Search Space is at least 3 in size at each step
# 	5. Post-processing required. Loop/Recursion ends when you have 2 elements left.
# 	   Need to assess if the remaining elements meet the condition.


# Distinguishing Syntax:
# ---------------------------------------------------------------
# 	1. Initial Condition: left = 0, right = length - 1
# 	2. Termination: left + 1 == right
# 	3. Searching Left: right = mid
# 	4. Searching Right: left = mid
def binarySearch(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: int
    """
    if len(nums) == 0:
        return -1

    left, right = 0, len(nums) - 1
    while left + 1 < right:
        mid = (left + right) // 2
        if nums[mid] == target:
            return mid
        elif nums[mid] < target:
            left = mid
        else:
            right = mid

    # Post-processing:
    # End Condition: left + 1 == right
    if nums[left] == target: return left
    if nums[right] == target: return right
    return -1
