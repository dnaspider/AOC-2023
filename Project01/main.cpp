#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

int main() {
	//char cr = '9';
	//cout << (int)cr;

	//Sleep(2222);
	//return 0;

	auto db = "C:\\Users\\dnasp\\Desktop\\ae\\01\\input.txt";
	wifstream f(db);
	if (!f) {
		cout << "no " << db << " found\\n";
		return 0;
	}
	wstring cell;
	size_t sum = 0;
	while(getline(f, cell)){
		wchar_t slot1{}, slot2{};
		wstring slot3{};
		for (size_t i = 0; i <= cell.length(); ++i) {
			if(cell[i] >= 48 && cell[i] <= 57 && slot1 == 0) {
				slot1 = cell[i];
				//continue;
			}
			if (cell[i] >= 48 && cell[i] <= 57)
				slot2 = cell[i];
			if (i == cell.length() - 1) {
				wcout << cell << " " << slot1 << " " << slot2;
				slot3 += slot1; slot3 += slot2;
				wcout << " " << slot3;
				sum += stoi(slot3); //- (48*2);
				//sum += (slot1 + slot2); //- (48*2);
				wcout << " " << sum << endl;
			}
		}

	}
	wcout << sum;
}