#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

int main() {
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
			switch (cell[i]) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			{
				if (slot1 == 0)
					slot1 = cell[i];
				else
					slot2 = cell[i];
			}
			break;
			case 'o':
			{
				if (cell.substr(i, 3) == L"one") {
					if (slot1 == 0)
						slot1 = '1';
					else
						slot2 = '1';
				}
			}
			break;
			case 't':
			{
				if (cell.substr(i, 3) == L"two") {
					if (slot1 == 0)
						slot1 = '2';
					else
						slot2 = '2';
				}
				if (cell.substr(i, 5) == L"three") {
					if (slot1 == 0)
						slot1 = '3';
					else
						slot2 = '3';
				}

			}
			break;
			case 'f':
			{
				if (cell.substr(i, 4) == L"four") {
					if (slot1 == 0)
						slot1 = '4';
					else
						slot2 = '4';
				}
				if (cell.substr(i, 4) == L"five") {
					if (slot1 == 0)
						slot1 = '5';
					else
						slot2 = '5';
				}
			}
			break;
			case 's':
			{
				if (cell.substr(i, 3) == L"six") {
					if (slot1 == 0)
						slot1 = '6';
					else
						slot2 = '6';
				}
				if (cell.substr(i, 5) == L"seven") {
					if (slot1 == 0)
						slot1 = '7';
					else
						slot2 = '7';
				}
			}
			break;
			case 'e':
			{
				if (cell.substr(i, 5) == L"eight") {
					if (slot1 == 0)
						slot1 = '8';
					else
						slot2 = '8';
				}
			}
			break;
			case 'n':
			{
				if (cell.substr(i, 4) == L"nine") {
					if (slot1 == 0)
						slot1 = '9';
					else
						slot2 = '9';
				}
			}
			break;

			default:
				break;
			}

			if (i == cell.length() - 1) {
				//wcout << cell << " " << slot1 << " " << slot2;
				slot3 += slot1;
				if (slot2 == 0) slot2 = slot1;
				slot3 += slot2;
				
				sum += stoi(slot3);
				//wcout << " " << slot3 << " " << sum << endl;
			}
		}

	}
	wcout << sum;
}