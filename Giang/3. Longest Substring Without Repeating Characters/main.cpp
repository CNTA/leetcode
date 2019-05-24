#include <string>
#include <unordered_map>

#include <iostream>

class Solution {
public:
	int lengthOfLongestSubstring(std::string s) {
		if (s.size() == 0)
			return 0;

		if (s.size() == 1)
			return 1;

		std::unordered_map<char, int> hash;
		int max = 1;
		int j = 0;
		for (int i = 0; i < s.size(); i++)
		{
			char c = s.at(i);

			auto search = hash.find(c);
			if (search == hash.end())
			{
				hash[c] = 0;
				max = max > hash.size() ? max : hash.size();
			}
			else
			{
				while (j < i)
				{
					if (s.at(j) == c)
					{
						j++;
						break;
					}

					hash.erase(s[j]);
					j++;
				}
			}
		}
		return max;
	}
};


int main()
{
	std::cout << Solution().lengthOfLongestSubstring("abcabcbb");

	return 0;
}
