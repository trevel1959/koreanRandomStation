#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <map>
#include <utility>
#include <string>
#include <fstream>
using namespace std;

int make_stationArray(map<int, pair<string, string>>& staArr);

int main() {
	srand(time(NULL));
	map<int, pair<string, string>> staArr;
	make_stationArray(staArr);

	cout << staArr[100].second << endl;
}

int make_stationArray(map<int, pair<string, string>>& staArr) {
	ifstream readFile;
	readFile.open("stationList.txt");
	string tmpNo, realNo, name;

	if (readFile.is_open()) {
		readFile >> tmpNo >> realNo>> name;
		cout << tmpNo << realNo << name << endl;
	}
	else {
		cout << "�� ����� �ҷ��� �� �����ϴ�." << endl;
		return -1;
	}

	//staArr.insert(make_pair(100, make_pair("100", "�ҿ��")));

	return 0;
}