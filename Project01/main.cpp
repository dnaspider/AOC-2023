#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

int main() {
	auto input = "C:\\Users\\dnasp\\Desktop\\ae\\02\\input.txt";
	wifstream f(input);
	if (!f) {
		cout << "no " << input << " found\\n";
		return 0;
	}
	wstring game, cell;
	size_t sum = 0;
	int r{}, rF{}, g{}, gF{}, b{}, bF{}, count{}, min{};
	while (getline(f, cell)) {
		game = cell.substr(4, cell.find(':') - 4);
		wcout << "game:" << game << endl;

		wstring c = cell.substr(cell.find(':') + 2);
		wstring v = L"";

		while (c > L"") {
			v = c.substr(0, c.find(' ', c[0] == ',' || c[0] == ';' ? 2 : 0));
			if (v[0] == ',' || v[0] == ';') { v = v.substr(2); c = c.substr(2); }
			if (c[v.length() + 1] == 'r') {
				r = stoi(v); if (r >= stoi(v) && rF < stoi(v)) rF = stoi(v);
				c = c.substr(v.length() + 1 + 3);
			}
			else if (c[v.length() + 1] == 'g') {
				g = stoi(v); if (g >= stoi(v) && gF < stoi(v)) gF = stoi(v);
				c = c.substr(v.length() + 1 + 5);
			}
			else if (c[v.length() + 1] == 'b') {
				b = stoi(v); if (b >= stoi(v) && bF < stoi(v)) bF = stoi(v);
				c = c.substr(v.length() + 1 + 4);
			}
		}
		cout << rF << " " << gF << " " << bF << endl;
		min = rF * gF * bF;
		r = 0; rF = 0; g = 0; gF = 0; b = 0; bF = 0;
		wcout << "min: " << min << endl;
		sum += min;
	}
	wcout << "\nsum: " << sum;
}