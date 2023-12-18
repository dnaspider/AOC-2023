#include <iostream>
#include <fstream>
#include <string>
#include <regex>
//#include <algorithm>
#include <Windows.h>
using namespace std;

int main() {
	auto input = "C:\\Users\\dnasp\\Desktop\\ae\\04\\input.txt";
	ifstream f(input);
	if (!f) {
		cout << "no " << input << " found\\n";
		return 0;
	}

	size_t sum = 0, points = 0;
	string cell = "", wns = "", mns = "", wn = "", mn = "";


	while (getline(f, cell)) {
		wns = cell.substr(cell.find(':') + 2);
		wns = wns.substr(0, wns.find('|') - 1);
		mns = cell.substr(cell.find('|') + 2);

		if (wns[0] == ' ') wns[0] = '0';
		if (mns[0] == ' ') mns[0] = '0';
		wns = regex_replace(wns, regex("  "), " 0");
		mns = regex_replace(mns, regex("  "), " 0");

		cout << wns << '\n' << mns << '\n';

		for (size_t i = 0; i < wns.length(); ++i) {
			if (wns[i] != ' ') wn += wns[i];
			if (wns[i] == ' ' || i == wns.length() - 1) {
				if (mns.find(wn) != string::npos) {
					cout << wn << endl;
					if (points == 0)
						points = 1;
					else
						points += points;
				}
				wn = "";
			}
		}
		cout << "points: " << points << endl;
		sum += points;
		cout << "sum: " << sum << endl;
		points = 0;
	}

	cout << "\nsum: " << sum;


}