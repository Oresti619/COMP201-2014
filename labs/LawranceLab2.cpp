#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;
int main()
{
	string sign;
	int x, left, right;
	vector <int> stack;
	char *end;
	cout << "Enter what you want to be calculated in polish style: " << endl;
	while (cin >> sign)
	{
		if (sign == "+")
		{
			left = stack.back();
			stack.pop_back();
			right = stack.back();
			stack.pop_back();
			stack.push_back(right + left);
		}
		else if (sign == "-")
		{
			left = stack.back();
			stack.pop_back();
			right = stack.back();
			stack.pop_back();
			stack.push_back(right - left);
		}
		else if (sign == "*")
		{
			left = stack.back();
			stack.pop_back();
			right = stack.back();
			stack.pop_back();
			stack.push_back(right*left);
		}
		else if (sign == "/")
		{
			left = stack.back();
			stack.pop_back();
			right = stack.back();
			stack.pop_back();
			stack.push_back(right / left);
		}
		else if (sign == ".")
		{
			break;
		}
		else
		{

			x = strtol(sign.c_str(), &end, 10);
			stack.push_back(x);
		}
	}
	for (int i = 0; i < stack.size(); i++)
	{
		cout << stack[i] << endl;
	}
	return 0;
}
