#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <Windows.h>
using namespace std;

int main() {
	auto input = "C:\\Users\\dnasp\\Desktop\\ae\\04\\input.txt";
	ifstream f(input);
	if (!f) {
		cout << "no " << input << " found\\n";
		return 0;
	}


	int copies[202], current = 0;
	for (size_t i = 0; i <= 201; ++i) copies[i] = 1;
	size_t sum = 0, points = 0;
	string cell = "", wns = "", mns = "", wn = "", mn = "";

	while (getline(f, cell)) {
		cout << "Card: " << current + 1 << " copies: " << copies[current] << endl;
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
					points += 1;
				}
				wn = "";
			}
		}
		cout << "points: " << points << endl;

		//1
		//11
		//11
		//11
		//11
		//1
		//
		//1
		//11
		//1111
		//1111
		//11
		//1
		//
		//1
		//11
		//1111
		//11111111
		//111111
		//1
		//
		//1
		//11
		//1111
		//11111111
		//11111111111111
		//1
		//


		//if(copies[current] == 0) 
		//	copies[current] += 1;

		for (size_t i = 1; i <= points; ++i) {
			copies[current + i] += 1;
		}
		if (copies[current] > 1 && points) {
			for (size_t i = 1; i <= copies[current] - 1; ++i) {
				for (size_t j = 1; j <= points; ++j) {
					copies[current + j] += 1;
				}
			}
		}
		cout << "Copies: ";
		for (auto i : copies) {
			cout << i << " ";
		}
		cout << "\n\n";
		points = 0;
		++current;
	}

	cout << "\n";
	cout << "\n";

	for (auto i : copies) {
		sum += i;
		cout << i << " ";
	}


	cout << "\nsum: " << sum;


}