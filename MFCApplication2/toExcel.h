#pragma once
#include "stdafx.h"
#include "chessCharacters.h"
#include "wholePieces.h"
#include "libxl.h"
#include <iostream>
#include <sstream>
using namespace std;
using namespace libxl;
class toExcel
{
public:
	void write_array(int*, int, int);
	void write_xls(string, Format*, Sheet*, chessCharacters, wholePieces, int, int, string);
	toExcel();
	void write_whole(string, chessCharacters, wholePieces, int, int, string);
	void set_format();
	void save(string);
	~toExcel();
private:
	Book* book = xlCreateBook();
	Sheet* sheet = book->addSheet(_T("Sheet1"));
	Format* format = book->addFormat();
};

