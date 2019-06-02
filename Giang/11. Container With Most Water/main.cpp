#include <iostream>
#include <vector>

/**
 * Runtime: 16 ms, faster than 98.06% of C++ online submissions for Container With Most Water.
 * Memory Usage: 9.9 MB, less than 47.74% of C++ online submissions for Container With Most Water.
 */
class Solution
{
public:
	inline int min(int a, int b)
	{
		return a < b ? a : b;
	}

	int maxArea(std::vector<int>& height)
	{
		int n = height.size();

		int start = 0;
		int end = n - 1;
		int max = 0;

		while (start <= end)
		{
			int minHeight = min(height[start], height[end]);
			int current = minHeight * (end - start);

			if (current > max)
				max = current;

			if (minHeight == height[start])
				start++;
			else
				end--;
		}
		return max;
	}
};

int main()
{
	std::vector<int> height = std::vector<int>{ 1,8,6,2,5,4,8,3,7 };
	std::cout << Solution().maxArea(height);

	return 0;
}