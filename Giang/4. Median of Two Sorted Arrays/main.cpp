#include <iostream>
#include <vector>


class Solution
{
public:
	/**
	 * Runtime: 20 ms, faster than 93.32% of C++ online submissions for Median of Two Sorted Arrays.
	 * Memory Usage: 10.3 MB, less than 60.83% of C++ online submissions for Median of Two Sorted Arrays.
	 */
	double findMedianSortedArrays(std::vector<int> nums1, std::vector<int> nums2)
	{
		if (nums1.size() == 0 && nums2.size() == 0)
			return 0;

		if (nums1.size() > nums2.size())
		{
			std::vector<int> tmp = nums1; nums1 = nums2; nums2 = tmp;
		}

		int iMin = 0;
		int iMax = nums1.size();
		int i, j;
		while (iMin <= iMax)
		{
			i = (iMin + iMax) / 2;
			j = (nums1.size() + nums2.size() + 1) / 2 - i;
			if ((j == 0 || i == nums1.size() || nums2[j - 1] <= nums1[i]) &&
				(i == 0 || j == nums2.size() || nums1[i - 1] <= nums2[j]))
			{
				break;
			}
			else
			{
				if (j > 0 && i < nums1.size() && nums2[j - 1] > nums1[i])
					iMin = i + 1;

				if (i > 0 && j < nums2.size() && nums1[i - 1] > nums2[j])
					iMax = i - 1;
			}
		}

		// Found perfect i, process result
		int maxLeft;
		if (i == 0)
			maxLeft = nums2[j - 1];
		else if (j == 0)
			maxLeft = nums1[i - 1];
		else
			maxLeft = nums1[i - 1] > nums2[j - 1] ? nums1[i - 1] : nums2[j - 1];

		if ((nums1.size() + nums2.size()) % 2 != 0)
			return maxLeft;

		int minRight = 0;
		if (i == nums1.size())
			minRight = nums2[j];
		else if (j == nums2.size())
			minRight = nums1[i];
		else
			minRight = nums1[i] < nums2[j] ? nums1[i] : nums2[j];

		return (maxLeft + minRight) / 2.0;
	}
};

int main()
{
	std::vector<int> nums1 = std::vector<int>{ 1, 2};
	std::vector<int> nums2 = std::vector<int>{ -1, 3 };

	double med = Solution().findMedianSortedArrays(nums1, nums2);

	std::cout << med;

	return 0;
}
