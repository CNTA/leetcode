#include <iostream>
#include <string>
#include <vector>

#define UNINITIALIZED (-1)
#define NON_PALINDROME 0
#define PALINDROME 1

/**
 * Runtime: 248 ms, faster than 17.22% of C++ online submissions for Longest Palindromic Substring.
 * Memory Usage: 157.1 MB, less than 9.92% of C++ online submissions for Longest Palindromic Substring.
 */
class Solution
{
public:

	/** Precached result to save time calculating on previous strings */
	int statusSize;
	std::vector<int> palindrome;

	void buildPalindrome(const std::string& s, int start, int end)
	{
		if (palindrome[to1D(start, end)] != UNINITIALIZED)
		{
			return;
		}

		int length = end - start + 1;
		if (length == 1)
		{
			setStatus(start, end, PALINDROME);
			return;
		}

		if (length == 2)
		{
			if (s[start] == s[end])
			{
				setStatus(start, end, PALINDROME);
			}
			else
			{
				setStatus(start, end, NON_PALINDROME);
			}

			setStatus(start, start, PALINDROME);
			setStatus(end, end, PALINDROME);

			return;
		}

		if (s[start] != s[end])
		{
			setStatus(start, end, NON_PALINDROME);
			return;
		}

		if (palindrome[to1D(start + 1, end - 1)] != UNINITIALIZED)
		{
			setStatus(start, end, palindrome[to1D(start + 1, end - 1)]);
			return;
		}

		buildPalindrome(s, start + 1, end - 1);
		if (palindrome[to1D(start + 1, end - 1)] == PALINDROME)
			setStatus(start, end, PALINDROME);
		else
			setStatus(start, end, NON_PALINDROME);
	}

	inline int to1D(int start, int end) { return start * statusSize + end; }
	inline void setStatus(int start, int end, int status) { palindrome[to1D(start, end)] = status; }

	std::string longestPalindrome(std::string s)
	{
		if (s.size() == 0)
			return "";

		if (s.size() == 1)
			return s;

		statusSize = s.size();
		palindrome = std::vector<int>(statusSize * statusSize, UNINITIALIZED);

		int max = 0;
		int maxStart = 0;
		for (int start = 0; start < s.size(); start++)
		{
			for (int end = start; end < s.size(); end++)
			{
				buildPalindrome(s, start, end);

				if (palindrome[to1D(start, end)] == PALINDROME)
				{
					int len = end - start + 1;
					if (len > max)
					{
						max = len;
						maxStart = start;
					}
				}
			}
		}

		return s.substr(maxStart, max);
	}
};

int main()
{
	std::cout << Solution().longestPalindrome("ac");
	return 0;
}
