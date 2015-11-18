#pragma once
#include "stdafx.h"
#include <string>
using namespace std;

class chessCharacters
{
private:
	int locationarray[10][9] = {
		{ -1,-1,-1,-1,-1,-1,-1,-1,-1 },
		{ -1,-1,-1,-1,-1,-1,-1,-1,-1 },
		{ -1,-1,-1,-1,-1,-1,-1,-1,-1 },
		{ -1,-1,-1,-1,-1,-1,-1,-1,-1 },
		{ -1,-1,-1,-1,-1,-1,-1,-1,-1 },
		{ -1,-1,-1,-1,-1,-1,-1,-1,-1 },
		{ -1,-1,-1,-1,-1,-1,-1,-1,-1 },
		{ -1,-1,-1,-1,-1,-1,-1,-1,-1 },
		{ -1,-1,-1,-1,-1,-1,-1,-1,-1 },
		{ -1,-1,-1,-1,-1,-1,-1,-1,-1 }
	};
	string fen;
public:
	chessCharacters();
	int charToint(char);
	string set_fen(string);
	int set_array();
	int* get_point();
	~chessCharacters();
};



