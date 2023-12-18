#include <iostream>
#include <fstream>
#include <string>
//#include <algorithm>
#include <Windows.h>
using namespace std;

int main() {
	auto input = "C:\\Users\\dnasp\\Desktop\\ae\\03\\input.txt";
	wifstream f(input);
	if (!f) {
		wcout << "no " << input << " found\\n";
		return 0;
	}
	wstring cell, sums = L"", sums1 = L"";
	size_t sum = 0;

	wchar_t a[140][140]{};
	int r = 0, i_ = 0, j_ = 0;
	bool i_t = 0;
	while (getline(f, cell)) {
		for (size_t i = 0; i < cell.length(); ++i) {
			a[r][i] = cell[i];
			//wcout << a[r][i];
		}
		++r;
		//wcout << endl;
	}


	for (size_t i = 0; i <= 140; ++i) {

		for (size_t j = 0; j < 140; ++j) {

			if (a[i][j] >= 48 && a[i][j] <= 57) {
				sums += a[i][j];
				a[i][j] = '.';
				if (j + 1 < 140 && a[i][j + 1] >= 48 && a[i][j + 1] <= 57) {
					continue;
				}
			}


			if (sums > L"") {

				//		.....
				//		.890.
				//		.....

				for (size_t k = 0; k < sums.length() + 2; ++k) {

					if (a[i - 1][j - sums.length() + k] == '*') {
						i_ = i - 1;
						j_ = j - sums.length() + k;
						i_t = 1;
						break;
					}
					if (a[i][j - sums.length() + k] == '*') {
						i_ = i;
						j_ = j - sums.length() + k;
						i_t = 1;
						break;
					}
					if (a[i + 1][j - sums.length() + k] == '*') {
						i_ = i + 1;
						j_ = j - sums.length() + k;
						i_t = 1;
						break;
					}

					//wcout << a[i - 1][j - sums.length() + k];
					//wcout << a[i][j - sums.length() + k];
					//wcout << a[i + 1][j - sums.length() + k];


					//a[i - 1][j - 1];		a[i - 1][j];		a[i - 1][j + 1];
					//a[i][j - 1];			a[i][j];			a[i][j + 1];
					//a[i + 1][j - 1];		a[i + 1][j];		a[i + 1][j + 1];


									//		.....
									//		.890.
									//		.....

					i_t = 0;
				}

				if (i_t) {
					wcout << "sums: " << sums << endl;
					for (size_t m = 0; m < 3; ++m) {
						if (a[i_ + 1][j_ - 1 + m] >= 48 && a[i_ + 1][j_ - 1 + m] <= 57) {
							//wcout << a[i_ + 1][j_ - 1 + m];
							int s = 1;
							if (a[i_ + 1][j_ - 2 + m] >= 48 && a[i_ + 1][j_ - 2 + m] <= 57 && a[i_ + 1][j_ - 3 + m] >= 48 && a[i_ + 1][j_ - 3 + m] <= 57) { s = 3; }
							else if (a[i_ + 1][j_ - 2 + m] >= 48 && a[i_ + 1][j_ - 2 + m] <= 57) { s = 2; }
							while (a[i_ + 1][j_ - s + m] >= 48 && a[i_ + 1][j_ - s + m] <= 57) {
								sums1 += a[i_ + 1][j_ - s + m];
								a[i_ + 1][j_ - s + m] = '.';
								--s;
								wcout << "*" << sums1 << endl;
							}
							break;
						}
						if (a[i_][j_ - 1 + m] >= 48 && a[i_][j_ - 1 + m] <= 57) {
							//wcout << a[i_][j_ - 1 + m];

							int s = 1;
							if (a[i_][j_ - 2 + m] >= 48 && a[i_][j_ - 2 + m] <= 57 && a[i_][j_ - 3 + m] >= 48 && a[i_][j_ - 3 + m] <= 57) { s = 3; }
							else if (a[i_][j_ - 2 + m] >= 48 && a[i_][j_ - 2 + m] <= 57) { s = 2; }
							while (a[i_][j_ - s + m] >= 48 && a[i_][j_ - s + m] <= 57) {
								sums1 += a[i_][j_ - s + m];
								a[i_][j_ - s + m] = '.';
								--s;
								wcout << "*" << sums1 << endl;
							}
							break;

						}
						if (a[i_ - 1][j_ - 1 + m] >= 48 && a[i_ - 1][j_ - 1 + m] <= 57) {
							//wcout << a[i_ - 1][j_ - 1 + m];

							int s = 1;
							if (a[i_ - 1][j_ - 2 + m] >= 48 && a[i_ - 1][j_ - 2 + m] <= 57 && a[i_ - 1][j_ - 3 + m] >= 48 && a[i_ - 1][j_ - 3 + m] <= 57) { s = 3; }
							else if (a[i_ - 1][j_ - 2 + m] >= 48 && a[i_ - 1][j_ - 2 + m] <= 57) { s = 2; }
							while (a[i_ - 1][j_ - s + m] >= 48 && a[i_ - 1][j_ - s + m] <= 57) {
								sums1 += a[i_ - 1][j_ - s + m];
								a[i_ - 1][j_ - s + m] = '.';
								--s;
								wcout << "*" << sums1 << endl;
							}
							break;
						}

						//wcout << a[i_ + 1][j_ - 1 + m];
						//wcout << a[i_][j_ - 1 + m];
						//wcout << a[i_ - 1][j_ - 1 + m];

					}
					if (sums > L"" && sums1 > L"") { sum += (stoi(sums) * stoi(sums1)); }
				}
				sums = L"";
				sums1 = L"";
			}



		}
	}

	wcout << endl << "sum: " << sum << endl;
	//for (size_t i = 0; i <= 139; ++i) {
	//	for (size_t j = 0; j <= 139; ++j) {
	//		wcout << a[i][j];
	//	}
	//	cout << endl;
	//}

}