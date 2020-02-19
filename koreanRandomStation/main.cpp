#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <map>
#include <utility>
#include <string>
#include <fstream>
using namespace std;

int make_stationArray(map<int, pair<string, string>>& staArr, int& startNum, int& endNum);

int main() {
	srand(time(NULL));
	map<int, pair<string, string>> staArr;
	int startNum, endNum, randNum;
	make_stationArray(staArr, startNum, endNum);

	cout << "이번에 선택된 역은" << endl;
	do {
		randNum = rand() % (endNum - startNum + 1) + startNum;
	} while (staArr[randNum].second == "");
	cout << "<" <<  staArr[randNum].first << "> " << staArr[randNum].second << " 역 입니다." << endl;

}

int make_stationArray(map<int, pair<string, string>>& staArr, int& startNum, int& endNum) {
	ifstream readFile;
	readFile.open("stationList.txt");
	string tmpNo, realNo, name;

	if (readFile.is_open()) {
		readFile >> tmpNo >> realNo >> name;
		staArr.insert(make_pair(stoi(tmpNo), make_pair(realNo, name)));
		startNum = stoi(tmpNo);

		while (readFile.eof() == false) {
			readFile >> tmpNo >> realNo >> name;
			staArr.insert(make_pair(stoi(tmpNo), make_pair(realNo, name)));
			//cout << tmpNo << " " << staArr[stoi(tmpNo)].first << " " << staArr[stoi(tmpNo)].second << endl;
		}

		endNum = stoi(tmpNo);
		return 0;
	}
	else {
		cout << "역 목록을 불러올 수 없습니다." << endl;
		return -1;
	}
}