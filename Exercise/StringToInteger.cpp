#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

int myAtoi(string str) {
	if (str.length() == 0)
		return 0;

	long long result = 0;//防止越界
	int sign = 1;
	int i = 0;
	while (str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	for (; i < str.length(); i++)
	{
		int num = str[i] - '0';

		if (num >= 0 && num <= 9)
		{
			result = result * 10 + num;
			if (result > INT_MAX)
			{
				cout << "test" << endl;
				return sign == -1 ? INT_MIN : INT_MAX;
			}

		}
		else
			return int(result*sign);

	}

	return int(result*sign);
}

int main()
{
	string str;
	cin >> str;

	int result = myAtoi(str);
	cout << "result: " << result << endl;

	return 0;
}
