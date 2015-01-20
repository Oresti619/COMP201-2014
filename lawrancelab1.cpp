#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int	main(int argc, char* argv[])
{
	ifstream inf;
	string	filename;
	
	filename = string(argv[1]);

	inf.open("file.txt");
	if (inf.fail())
	{
		cout << "Input file " << filename << " failed to open!" << endl;
		return	1;
	}

	int val;
	int sum = 0;

	cout << "x" << "    " << "  x^2  " << " Current sum	" << endl;
	cout << "=" << "    " << "  ===  " << " =========== " << endl;

	while (inf >> val)
	{
		sum += val;
		cout << val << "	" << val * val << "	 " << sum << endl;
	}
	inf.close();
	return	0;
}