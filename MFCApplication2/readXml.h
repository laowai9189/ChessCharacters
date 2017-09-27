#pragma once
#include <vector>
#include "tinyxml.h"
#include "tinystr.h"
using namespace std;
class readXml
{
public:
	readXml();
	void read_path(CString);
	void read_move();
	string read_fen();
	int read_result();
	string read_resulttype();
	~readXml();
	vector<int> From_x() const { return from_x; }
	vector<int> From_y() const { return from_y; }
	vector<int> To_x() const { return to_x; }
	vector<int> To_y() const { return to_y; }
private:
	CString path;
	vector<int> from_x;
	vector<int> from_y;
	vector<int> to_x;
	vector<int> to_y;
};

