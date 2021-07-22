# Template #1 is the most basic and elementary form of Binary Search. It is the 
# standard Binary Search Template that most high schools or universities use when 
# they first teach students computer science. Template #1 is used to search for an 
# element or condition which can be determined by accessing a single index in the array.


# Key Attributes:
# ---------------------------------------------------------------------------------------
# 	1. Most basic and elementary form of Binary Search
# 	2. Search Condition can be determined without comparing 
# 	   to the element's neighbors (or use specific elements around it)
# 	3. No post-processing required because at each step, you are checking to see if the 
# 	   element has been found. If you reach the end, then you know the element is not found


# Distinguishing Syntax:
# ---------------------------------------------------------------------------------------
# 	1. Initial Condition: left = 0, right = length - 1
# 	2. Termination: left > right
# 	3. Searching Left: right = mid - 1
# 	4. Searching Right: left = mid + 1
def binarySearch(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: int
    """
    if len(nums) == 0:
        return -1

    left, right = 0, len(nums) - 1
    while left <= right:
        mid = (left + right) // 2
        if nums[mid] == target:
            return mid
        elif nums[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    # End Condition: left > right
    return -1
