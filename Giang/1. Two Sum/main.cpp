#include <vector>
#include <unordered_map>
#include <iostream>


/**
 * Runtime: 8 ms, faster than 98.75% of C++ online submissions for Two Sum.
 * Memory Usage: 10.7 MB, less than 6.09% of C++ online submissions for Two Sum.
 */
class Solution {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::vector<int> result;

		// Construct a hash map
		std::unordered_multimap<int, int> hash;
		for (int i = 0; i < nums.size(); i++)
		{
			hash.insert({nums[i], i});
		}

		for (int i = 0; i < nums.size(); i++)
		{
			result.clear();

			int remain = target - nums[i];

			if (remain != nums[i])
			{
				auto findResult = hash.find(remain);
				if (findResult != hash.end())
				{
					result.push_back(i);
					result.push_back(hash.find(remain)->second);

					return result;
				}
				else
				{
					continue;
				}
			}

			// Hash collision
			auto range = hash.equal_range(remain);

			for (auto it = range.first; it != range.second; it++)
			{
				result.push_back(it->second);
			}

			if (result.size() == 2)
				return result;
		}

		result.clear();
		return result;
	}
};

int main()
{
	std::vector<int> arr = std::vector<int>{ 230,863,916,585,981,404,316,785,88,12,70,435,384,778,887,755,740,337,86,92,325,422,815,650,920,125,277,336,221,847,168,23,677,61,400,136,874,363,394,199,863,997,794,587,124,321,212,957,764,173,314,422,927,783,930,282,306,506,44,926,691,568,68,730,933,737,531,180,414,751,28,546,60,371,493,370,527,387,43,541,13,457,328,227,652,365,430,803,59,858,538,427,583,368,375,173,809,896,370,789 };
	std::vector<int> sums = Solution().twoSum(arr, 542);
	for (int i = 0; i < sums.size(); i++)
	{
		std::cout << sums[i] << " ";
	}

	return 0;
}