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
		cout << "역 목록을 불러올 수 없습니다." << endl;
		return -1;
	}

	//staArr.insert(make_pair(100, make_pair("100", "소요산")));

	return 0;
}