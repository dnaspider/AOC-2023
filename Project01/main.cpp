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
	int r{}, g{}, b{}, count{};
	while (getline(f, cell)) {
		game = cell.substr(4, cell.find(':') - 4);
		wcout << "game:" << game << endl;

		wstring c = cell.substr(cell.find(':') + 2);
		wstring v = L"";

		while (c > L"") {
			v = c.substr(0, c.find(' ', c[0] == ',' || c[0] == ';' ? 2 : 0));
			if (v[0] == ',' || v[0] == ';') { v = v.substr(2); c = c.substr(2); }
			if (c[v.length() + 1] == 'r') {
				c = c.substr(v.length() + 1 + 3);
				if (stoi(v) <= 12) {} else { game = L""; break; }
			}
			else if (c[v.length() + 1] == 'g') {
				c = c.substr(v.length() + 1 + 5);
				if (stoi(v) <= 13) {} else { game = L""; break; }
			}
			else if (c[v.length() + 1] == 'b') {
				c = c.substr(v.length() + 1 + 4);
				if (stoi(v) <= 14) {} else { game = L""; break; }
			}
			if (game == L"") break;
		}
		if (game > L"") sum += stoi(game);
		wcout << "sum: " << sum << endl;;

	}
	wcout << "\n" << sum;
}