#include "stdafx.h"
#include "readXml.h"
#include "chessCharacters.h"
#include "wholePieces.h"
#include "libxl.h"
#include "toExcel.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
using namespace libxl;

int main()
{
	readXml rx;
	rx.read_name("adminli(∑Áƒß)-∏∫-√Î…±(µÿ…∑).xml");
	rx.read_move();
	string str;
	string s = ".xls";
	chessCharacters ca;
	string fen = rx.read_fen();
	ca.set_fen(fen);
	ca.set_array();
	vector<int> from_x = rx.From_x();
	vector<int> from_y = rx.From_y();
	vector<int> to_x = rx.To_x();
	vector<int> to_y = rx.To_y();
	for (int i = 0; i < from_x.size(); i++)
	{
		stringstream ss;
		ss << (i + 1);
		ss >> str;
		string str1 = str + s;
		ca.change_array(from_x[i], from_y[i], to_x[i], to_y[i]);
		int* x = ca.get_point();
		wholePieces wp(x);
		toExcel te(ca, wp, str1);
	}
}