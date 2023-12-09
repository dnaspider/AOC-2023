#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

int main() {
	auto input = "C:\\Users\\dnasp\\Desktop\\ae\\03\\input.txt";
	wifstream f(input);
	if (!f) {
		cout << "no " << input << " found\\n";
		return 0;
	}
	wstring cell, sums = L"";;
	size_t sum = 0; 

	wchar_t a[140][140]{};
	int r = 0;
	while (getline(f, cell)) {
		for (size_t i = 0; i < cell.length(); ++i) {
			a[r][i] = cell[i];
			//wcout << a[r][i];
		}
		++r;
		//wcout << endl;
	}
	bool last = 0;
	for (size_t i = 0; i <= 140; ++i) {
		last = (i == 139);

		for (size_t j = 0; j < 140; ++j) {
			if (a[i][j] >= 48 && a[i][j] <= 57) {
				sums += a[i][j];

				if (j + 1 < 140 && a[i][j + 1] >= 48 && a[i][j + 1] <= 57) {
					continue;
				}
				
				if (a[i][j - sums.length()] != 46 && (a[i][j - sums.length()] < 48 || a[i][j - sums.length()] > 57)) {
					wcout << sums << " " << a[i][j - sums.length()]; //left
					sum += stoi(sums);
					sums = L"";
					wcout << endl;
				}
				if (a[i][j + 1] != 46 && (a[i][j + 1] < 48 || a[i][j + 1] > 57)) {
					wcout << sums << " " << a[i][j + 1]; //right
					sum += stoi(sums);
					sums = L"";
					wcout << endl;
				}
				for (size_t k = 0; k < sums.length() + 2; ++k) {
					if (!last && a[i + 1][j - sums.length() + k] != 46 && (a[i + 1][j - sums.length() + k] < 48 || a[i + 1][j - sums.length() + k] > 57)) {
						wcout << sums << " " << a[i + 1][j - sums.length() + k]; //down
						sum += stoi(sums);
						sums = L"";
						wcout << endl;
						break;
					}
					if (!i) continue;

					if (a[i - 1][j - sums.length() + k] != 46 && (a[i - 1][j - sums.length() + k] < 48 || a[i - 1][j - sums.length() + k] > 57)) {
						wcout << sums << " " << a[i - 1][j - sums.length() + k]; //up
						sum += stoi(sums);
						sums = L"";
						wcout << endl;
						break;
					}
					
				}
				
				sums = L"";
			}
		}
	}
		
	cout << endl << sum << endl;
}