#include <vector>
#include <unordered_map>
#include <iostream>


/**
 * Runtime: 12 ms, faster than 83.45% of C++ online submissions for Two Sum.
 * Memory Usage: 11.9 MB, less than 5.01% of C++ online submissions for Two Sum.
 */
class Solution {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		// Construct a hash map
		std::unordered_map<int, std::vector<int>> hash;
		for (int i = 0; i < nums.size(); i++)
		{
			hash[nums[i]].push_back(i);
		}

		for (int i = 0; i < nums.size(); i++)
		{
			int remain = target - nums[i];

			if (remain != nums[i])
			{
				auto findResult = hash.find(remain);
				if (findResult != hash.end())
				{
					return std::vector<int> { i, hash[remain][0] };
				}
				else
				{
					continue;
				}
			}

			// Hash collision
			std::vector<int> indices = hash[nums[i]];
			if (indices.size() == 1)
				continue;

			indices.resize(2);

			return indices;
		}

		return std::vector<int>();
	}
};

int main()
{
	std::vector<int> arr = std::vector<int>{ 230,863,916,585,981,404,316,785,88,12,70,435,384,778,887,755,740,337,86,92,325,422,815,650,920,125,277,336,221,847,168,23,677,61,400,136,874,363,394,199,863,997,794,587,124,321,212,957,764,173,314,422,927,783,930,282,306,506,44,926,691,568,68,730,933,737,531,180,414,751,28,546,60,371,493,370,527,387,43,541,13,457,328,227,652,365,430,803,59,858,538,427,583,368,375,173,809,896,370,789};
	std::vector<int> sums = Solution().twoSum(arr, 542);
	for (int i = 0; i < sums.size(); i++)
	{
		std::cout << sums[i] << " ";
	}

	return 0;
}