#include "stdafx.h"
#include "toExcel.h"

wchar_t* stringTowchar_t(string s)
{
	char a[100];
	strcpy_s(a, s.c_str());
	int size = ::MultiByteToWideChar(CP_ACP, 0, a, strlen(a) + 1, NULL, 0);
	wchar_t* widename = new wchar_t[size];
	::MultiByteToWideChar(CP_ACP, 0, a, strlen(a) + 1, widename, size);
	return widename;
}

void toExcel::write_array(int* x,int i,int result)
{
	if (sheet)
	{
		sheet->writeNum(i, 0, result);
		/*for (int j = 0; j < 10; j++)
			for (int k = 0; k < 9; k++)
				sheet->writeNum(i, 9 * j + k + 1, *(x + 9 * j + k));*/
	}
}

void toExcel::write_xls(string name, Format* format, Sheet* sheet, chessCharacters c, wholePieces wp, int i, int result, string result_type)
{
	wchar_t* widename = stringTowchar_t(name);
	wchar_t* widename1 = stringTowchar_t(result_type);

	sheet->writeNum(i, 1 - 1, wp.track(4, 0).get_exist(), format);
	sheet->writeNum(i, 9 - 1, wp.track(13, 0).get_exist(), format);
	sheet->writeNum(i, 17 - 1, wp.track(0, 0).get_exist(), format);
	sheet->writeNum(i, 25 - 1, wp.track(0, 1).get_exist(), format);
	sheet->writeNum(i, 33 - 1, wp.track(9, 0).get_exist(), format);
	sheet->writeNum(i, 41 - 1, wp.track(9, 1).get_exist(), format);
	sheet->writeNum(i, 49 - 1, wp.track(1, 0).get_exist(), format);
	sheet->writeNum(i, 57 - 1, wp.track(1, 1).get_exist(), format);
	sheet->writeNum(i, 65 - 1, wp.track(10, 0).get_exist(), format);
	sheet->writeNum(i, 73 - 1, wp.track(10, 1).get_exist(), format);
	sheet->writeNum(i, 81 - 1, wp.track(5, 0).get_exist(), format);
	sheet->writeNum(i, 89 - 1, wp.track(5, 1).get_exist(), format);
	sheet->writeNum(i, 97 - 1, wp.track(8, 0).get_exist(), format);
	sheet->writeNum(i, 105 - 1, wp.track(8, 1).get_exist(), format);
	sheet->writeNum(i, 113 - 1, wp.track(2, 0).get_exist(), format);
	sheet->writeNum(i, 121 - 1, wp.track(2, 1).get_exist(), format);
	sheet->writeNum(i, 129 - 1, wp.track(11, 0).get_exist(), format);
	sheet->writeNum(i, 137 - 1, wp.track(11, 1).get_exist(), format);
	sheet->writeNum(i, 145 - 1, wp.track(3, 0).get_exist(), format);
	sheet->writeNum(i, 153 - 1, wp.track(3, 1).get_exist(), format);
	sheet->writeNum(i, 161 - 1, wp.track(12, 0).get_exist(), format);
	sheet->writeNum(i, 169 - 1, wp.track(12, 1).get_exist(), format);
	sheet->writeNum(i, 177 - 1, wp.track(6, 0).get_exist(), format);
	sheet->writeNum(i, 185 - 1, wp.track(6, 1).get_exist(), format);
	sheet->writeNum(i, 193 - 1, wp.track(6, 2).get_exist(), format);
	sheet->writeNum(i, 201 - 1, wp.track(6, 3).get_exist(), format);
	sheet->writeNum(i, 209 - 1, wp.track(6, 4).get_exist(), format);
	sheet->writeNum(i, 217 - 1, wp.track(7, 0).get_exist(), format);
	sheet->writeNum(i, 225 - 1, wp.track(7, 1).get_exist(), format);
	sheet->writeNum(i, 233 - 1, wp.track(7, 2).get_exist(), format);
	sheet->writeNum(i, 241 - 1, wp.track(7, 3).get_exist(), format);
	sheet->writeNum(i, 249 - 1, wp.track(7, 4).get_exist(), format);
	//sheet->writeStr( 0, 2, _T("位置"), format);
	sheet->writeNum(i, 2 - 1, wp.track(4, 0).getChara_zuobiao(), format);
	sheet->writeNum(i, 10 - 1, wp.track(13, 0).getChara_zuobiao(), format);
	sheet->writeNum(i, 18 - 1, wp.track(0, 0).getChara_zuobiao(), format);
	sheet->writeNum(i, 26 - 1, wp.track(0, 1).getChara_zuobiao(), format);
	sheet->writeNum(i, 34 - 1, wp.track(9, 0).getChara_zuobiao(), format);
	sheet->writeNum(i, 42 - 1, wp.track(9, 1).getChara_zuobiao(), format);
	sheet->writeNum(i, 50 - 1, wp.track(1, 0).getChara_zuobiao(), format);
	sheet->writeNum(i, 58 - 1, wp.track(1, 1).getChara_zuobiao(), format);
	sheet->writeNum(i, 66 - 1, wp.track(10, 0).getChara_zuobiao(), format);
	sheet->writeNum(i, 74 - 1, wp.track(10, 1).getChara_zuobiao(), format);
	sheet->writeNum(i, 82 - 1, wp.track(5, 0).getChara_zuobiao(), format);
	sheet->writeNum(i, 90 - 1, wp.track(5, 1).getChara_zuobiao(), format);
	sheet->writeNum(i, 98 - 1, wp.track(8, 0).getChara_zuobiao(), format);
	sheet->writeNum(i, 106 - 1, wp.track(8, 1).getChara_zuobiao(), format);
	sheet->writeNum(i, 114 - 1, wp.track(2, 0).getChara_zuobiao(), format);
	sheet->writeNum(i, 122 - 1, wp.track(2, 1).getChara_zuobiao(), format);
	sheet->writeNum(i, 130 - 1, wp.track(11, 0).getChara_zuobiao(), format);
	sheet->writeNum(i, 138 - 1, wp.track(11, 1).getChara_zuobiao(), format);
	sheet->writeNum(i, 146 - 1, wp.track(3, 0).getChara_zuobiao(), format);
	sheet->writeNum(i, 154 - 1, wp.track(3, 1).getChara_zuobiao(), format);
	sheet->writeNum(i, 162 - 1, wp.track(12, 0).getChara_zuobiao(), format);
	sheet->writeNum(i, 170 - 1, wp.track(12, 1).getChara_zuobiao(), format);
	sheet->writeNum(i, 178 - 1, wp.track(6, 0).getChara_zuobiao(), format);
	sheet->writeNum(i, 186 - 1, wp.track(6, 1).getChara_zuobiao(), format);
	sheet->writeNum(i, 194 - 1, wp.track(6, 2).getChara_zuobiao(), format);
	sheet->writeNum(i, 202 - 1, wp.track(6, 3).getChara_zuobiao(), format);
	sheet->writeNum(i, 210 - 1, wp.track(6, 4).getChara_zuobiao(), format);
	sheet->writeNum(i, 218 - 1, wp.track(7, 0).getChara_zuobiao(), format);
	sheet->writeNum(i, 226 - 1, wp.track(7, 1).getChara_zuobiao(), format);
	sheet->writeNum(i, 234 - 1, wp.track(7, 2).getChara_zuobiao(), format);
	sheet->writeNum(i, 242 - 1, wp.track(7, 3).getChara_zuobiao(), format);
	sheet->writeNum(i, 250 - 1, wp.track(7, 4).getChara_zuobiao(), format);
	//sheet->writeStr( 0, 3, _T("控制区域价值加权"), format);
	sheet->writeNum(i, 3 - 1, wp.track(4, 0).return_control(), format);
	sheet->writeNum(i, 11 - 1, wp.track(13, 0).return_control(), format);
	sheet->writeNum(i, 19 - 1, wp.track(0, 0).return_control(), format);
	sheet->writeNum(i, 27 - 1, wp.track(0, 1).return_control(), format);
	sheet->writeNum(i, 35 - 1, wp.track(9, 0).return_control(), format);
	sheet->writeNum(i, 43 - 1, wp.track(9, 1).return_control(), format);
	sheet->writeNum(i, 51 - 1, wp.track(1, 0).return_control(), format);
	sheet->writeNum(i, 59 - 1, wp.track(1, 1).return_control(), format);
	sheet->writeNum(i, 67 - 1, wp.track(10, 0).return_control(), format);
	sheet->writeNum(i, 75 - 1, wp.track(10, 1).return_control(), format);
	sheet->writeNum(i, 83 - 1, wp.track(5, 0).return_control(), format);
	sheet->writeNum(i, 91 - 1, wp.track(5, 1).return_control(), format);
	sheet->writeNum(i, 99 - 1, wp.track(8, 0).return_control(), format);
	sheet->writeNum(i, 107 - 1, wp.track(8, 1).return_control(), format);
	sheet->writeNum(i, 115 - 1, wp.track(2, 0).return_control(), format);
	sheet->writeNum(i, 123 - 1, wp.track(2, 1).return_control(), format);
	sheet->writeNum(i, 131 - 1, wp.track(11, 0).return_control(), format);
	sheet->writeNum(i, 139 - 1, wp.track(11, 1).return_control(), format);
	sheet->writeNum(i, 147 - 1, wp.track(3, 0).return_control(), format);
	sheet->writeNum(i, 155 - 1, wp.track(3, 1).return_control(), format);
	sheet->writeNum(i, 163 - 1, wp.track(12, 0).return_control(), format);
	sheet->writeNum(i, 171 - 1, wp.track(12, 1).return_control(), format);
	sheet->writeNum(i, 179 - 1, wp.track(6, 0).return_control(), format);
	sheet->writeNum(i, 187 - 1, wp.track(6, 1).return_control(), format);
	sheet->writeNum(i, 195 - 1, wp.track(6, 2).return_control(), format);
	sheet->writeNum(i, 203 - 1, wp.track(6, 3).return_control(), format);
	sheet->writeNum(i, 211 - 1, wp.track(6, 4).return_control(), format);
	sheet->writeNum(i, 219 - 1, wp.track(7, 0).return_control(), format);
	sheet->writeNum(i, 227 - 1, wp.track(7, 1).return_control(), format);
	sheet->writeNum(i, 235 - 1, wp.track(7, 2).return_control(), format);
	sheet->writeNum(i, 243 - 1, wp.track(7, 3).return_control(), format);
	sheet->writeNum(i, 251 - 1, wp.track(7, 4).return_control(), format);
	//sheet->writeStr( 0, 4, _T("走法数"), format);
	sheet->writeNum(i, 4 - 1, wp.track(4, 0).get_move(), format);
	sheet->writeNum(i, 12 - 1, wp.track(13, 0).get_move(), format);
	sheet->writeNum(i, 20 - 1, wp.track(0, 0).get_move(), format);
	sheet->writeNum(i, 28 - 1, wp.track(0, 1).get_move(), format);
	sheet->writeNum(i, 36 - 1, wp.track(9, 0).get_move(), format);
	sheet->writeNum(i, 44 - 1, wp.track(9, 1).get_move(), format);
	sheet->writeNum(i, 52 - 1, wp.track(1, 0).get_move(), format);
	sheet->writeNum(i, 60 - 1, wp.track(1, 1).get_move(), format);
	sheet->writeNum(i, 68 - 1, wp.track(10, 0).get_move(), format);
	sheet->writeNum(i, 76 - 1, wp.track(10, 1).get_move(), format);
	sheet->writeNum(i, 84 - 1, wp.track(5, 0).get_move(), format);
	sheet->writeNum(i, 92 - 1, wp.track(5, 1).get_move(), format);
	sheet->writeNum(i, 100 - 1, wp.track(8, 0).get_move(), format);
	sheet->writeNum(i, 108 - 1, wp.track(8, 1).get_move(), format);
	sheet->writeNum(i, 116 - 1, wp.track(2, 0).get_move(), format);
	sheet->writeNum(i, 124 - 1, wp.track(2, 1).get_move(), format);
	sheet->writeNum(i, 132 - 1, wp.track(11, 0).get_move(), format);
	sheet->writeNum(i, 140 - 1, wp.track(11, 1).get_move(), format);
	sheet->writeNum(i, 148 - 1, wp.track(3, 0).get_move(), format);
	sheet->writeNum(i, 156 - 1, wp.track(3, 1).get_move(), format);
	sheet->writeNum(i, 164 - 1, wp.track(12, 0).get_move(), format);
	sheet->writeNum(i, 172 - 1, wp.track(12, 1).get_move(), format);
	sheet->writeNum(i, 180 - 1, wp.track(6, 0).get_move(), format);
	sheet->writeNum(i, 188 - 1, wp.track(6, 1).get_move(), format);
	sheet->writeNum(i, 196 - 1, wp.track(6, 2).get_move(), format);
	sheet->writeNum(i, 204 - 1, wp.track(6, 3).get_move(), format);
	sheet->writeNum(i, 212 - 1, wp.track(6, 4).get_move(), format);
	sheet->writeNum(i, 220 - 1, wp.track(7, 0).get_move(), format);
	sheet->writeNum(i, 228 - 1, wp.track(7, 1).get_move(), format);
	sheet->writeNum(i, 236 - 1, wp.track(7, 2).get_move(), format);
	sheet->writeNum(i, 244 - 1, wp.track(7, 3).get_move(), format);
	sheet->writeNum(i, 252 - 1, wp.track(7, 4).get_move(), format);
	//sheet->writeStr( 0, 5, _T("机动性评分"), format);
	sheet->writeNum(i, 5 - 1, wp.track(4, 0).return_move(), format);
	sheet->writeNum(i, 13 - 1, wp.track(13, 0).return_move(), format);
	sheet->writeNum(i, 21 - 1, wp.track(0, 0).return_move(), format);
	sheet->writeNum(i, 29 - 1, wp.track(0, 1).return_move(), format);
	sheet->writeNum(i, 37 - 1, wp.track(9, 0).return_move(), format);
	sheet->writeNum(i, 45 - 1, wp.track(9, 1).return_move(), format);
	sheet->writeNum(i, 53 - 1, wp.track(1, 0).return_move(), format);
	sheet->writeNum(i, 61 - 1, wp.track(1, 1).return_move(), format);
	sheet->writeNum(i, 69 - 1, wp.track(10, 0).return_move(), format);
	sheet->writeNum(i, 77 - 1, wp.track(10, 1).return_move(), format);
	sheet->writeNum(i, 85 - 1, wp.track(5, 0).return_move(), format);
	sheet->writeNum(i, 93 - 1, wp.track(5, 1).return_move(), format);
	sheet->writeNum(i, 101 - 1, wp.track(8, 0).return_move(), format);
	sheet->writeNum(i, 109 - 1, wp.track(8, 1).return_move(), format);
	sheet->writeNum(i, 117 - 1, wp.track(2, 0).return_move(), format);
	sheet->writeNum(i, 125 - 1, wp.track(2, 1).return_move(), format);
	sheet->writeNum(i, 133 - 1, wp.track(11, 0).return_move(), format);
	sheet->writeNum(i, 141 - 1, wp.track(11, 1).return_move(), format);
	sheet->writeNum(i, 149 - 1, wp.track(3, 0).return_move(), format);
	sheet->writeNum(i, 157 - 1, wp.track(3, 1).return_move(), format);
	sheet->writeNum(i, 165 - 1, wp.track(12, 0).return_move(), format);
	sheet->writeNum(i, 173 - 1, wp.track(12, 1).return_move(), format);
	sheet->writeNum(i, 181 - 1, wp.track(6, 0).return_move(), format);
	sheet->writeNum(i, 189 - 1, wp.track(6, 1).return_move(), format);
	sheet->writeNum(i, 197 - 1, wp.track(6, 2).return_move(), format);
	sheet->writeNum(i, 205 - 1, wp.track(6, 3).return_move(), format);
	sheet->writeNum(i, 213 - 1, wp.track(6, 4).return_move(), format);
	sheet->writeNum(i, 221 - 1, wp.track(7, 0).return_move(), format);
	sheet->writeNum(i, 229 - 1, wp.track(7, 1).return_move(), format);
	sheet->writeNum(i, 237 - 1, wp.track(7, 2).return_move(), format);
	sheet->writeNum(i, 245 - 1, wp.track(7, 3).return_move(), format);
	sheet->writeNum(i, 253 - 1, wp.track(7, 4).return_move(), format);
	//sheet->writeStr( 0, 6, _T("棋子威胁"), format);
	sheet->writeNum(i, 6 - 1, wp.map_threat(4, 0), format);
	sheet->writeNum(i, 14 - 1, wp.map_threat(13, 0), format);
	sheet->writeNum(i, 22 - 1, wp.map_threat(0, 0), format);
	sheet->writeNum(i, 30 - 1, wp.map_threat(0, 1), format);
	sheet->writeNum(i, 38 - 1, wp.map_threat(9, 0), format);
	sheet->writeNum(i, 46 - 1, wp.map_threat(9, 1), format);
	sheet->writeNum(i, 54 - 1, wp.map_threat(1, 0), format);
	sheet->writeNum(i, 62 - 1, wp.map_threat(1, 1), format);
	sheet->writeNum(i, 70 - 1, wp.map_threat(10, 0), format);
	sheet->writeNum(i, 78 - 1, wp.map_threat(10, 1), format);
	sheet->writeNum(i, 86 - 1, wp.map_threat(5, 0), format);
	sheet->writeNum(i, 94 - 1, wp.map_threat(5, 1), format);
	sheet->writeNum(i, 102 - 1, wp.map_threat(8, 0), format);
	sheet->writeNum(i, 110 - 1, wp.map_threat(8, 1), format);
	sheet->writeNum(i, 118 - 1, wp.map_threat(2, 0), format);
	sheet->writeNum(i, 126 - 1, wp.map_threat(2, 1), format);
	sheet->writeNum(i, 134 - 1, wp.map_threat(11, 0), format);
	sheet->writeNum(i, 142 - 1, wp.map_threat(11, 1), format);
	sheet->writeNum(i, 150 - 1, wp.map_threat(3, 0), format);
	sheet->writeNum(i, 158 - 1, wp.map_threat(3, 1), format);
	sheet->writeNum(i, 166 - 1, wp.map_threat(12, 0), format);
	sheet->writeNum(i, 174 - 1, wp.map_threat(12, 1), format);
	sheet->writeNum(i, 182 - 1, wp.map_threat(6, 0), format);
	sheet->writeNum(i, 190 - 1, wp.map_threat(6, 1), format);
	sheet->writeNum(i, 198 - 1, wp.map_threat(6, 2), format);
	sheet->writeNum(i, 206 - 1, wp.map_threat(6, 3), format);
	sheet->writeNum(i, 214 - 1, wp.map_threat(6, 4), format);
	sheet->writeNum(i, 222 - 1, wp.map_threat(7, 0), format);
	sheet->writeNum(i, 230 - 1, wp.map_threat(7, 1), format);
	sheet->writeNum(i, 238 - 1, wp.map_threat(7, 2), format);
	sheet->writeNum(i, 246 - 1, wp.map_threat(7, 3), format);
	sheet->writeNum(i, 254 - 1, wp.map_threat(7, 4), format);
	//sheet->writeStr(0, 7, _T("棋子保护"), format);
	sheet->writeNum(i, 7 - 1, wp.map_allpro(c, 4, 0), format);
	sheet->writeNum(i, 15 - 1, wp.map_allpro(c, 13, 0), format);
	sheet->writeNum(i, 23 - 1, wp.map_allpro(c, 0, 0), format);
	sheet->writeNum(i, 31 - 1, wp.map_allpro(c, 0, 1), format);
	sheet->writeNum(i, 39 - 1, wp.map_allpro(c, 9, 0), format);
	sheet->writeNum(i, 47 - 1, wp.map_allpro(c, 9, 1), format);
	sheet->writeNum(i, 55 - 1, wp.map_allpro(c, 1, 0), format);
	sheet->writeNum(i, 63 - 1, wp.map_allpro(c, 1, 1), format);
	sheet->writeNum(i, 71 - 1, wp.map_allpro(c, 10, 0), format);
	sheet->writeNum(i, 79 - 1, wp.map_allpro(c, 10, 1), format);
	sheet->writeNum(i, 87 - 1, wp.map_allpro(c, 5, 0), format);
	sheet->writeNum(i, 95 - 1, wp.map_allpro(c, 5, 1), format);
	sheet->writeNum(i, 103 - 1, wp.map_allpro(c, 8, 0), format);
	sheet->writeNum(i, 111 - 1, wp.map_allpro(c, 8, 1), format);
	sheet->writeNum(i, 119 - 1, wp.map_allpro(c, 2, 0), format);
	sheet->writeNum(i, 127 - 1, wp.map_allpro(c, 2, 1), format);
	sheet->writeNum(i, 135 - 1, wp.map_allpro(c, 11, 0), format);
	sheet->writeNum(i, 143 - 1, wp.map_allpro(c, 11, 1), format);
	sheet->writeNum(i, 151 - 1, wp.map_allpro(c, 3, 0), format);
	sheet->writeNum(i, 159 - 1, wp.map_allpro(c, 3, 1), format);
	sheet->writeNum(i, 167 - 1, wp.map_allpro(c, 12, 0), format);
	sheet->writeNum(i, 175 - 1, wp.map_allpro(c, 12, 1), format);
	sheet->writeNum(i, 183 - 1, wp.map_allpro(c, 6, 0), format);
	sheet->writeNum(i, 191 - 1, wp.map_allpro(c, 6, 1), format);
	sheet->writeNum(i, 199 - 1, wp.map_allpro(c, 6, 2), format);
	sheet->writeNum(i, 207 - 1, wp.map_allpro(c, 6, 3), format);
	sheet->writeNum(i, 215 - 1, wp.map_allpro(c, 6, 4), format);
	sheet->writeNum(i, 223 - 1, wp.map_allpro(c, 7, 0), format);
	sheet->writeNum(i, 231 - 1, wp.map_allpro(c, 7, 1), format);
	sheet->writeNum(i, 239 - 1, wp.map_allpro(c, 7, 2), format);
	sheet->writeNum(i, 247 - 1, wp.map_allpro(c, 7, 3), format);
	sheet->writeNum(i, 255 - 1, wp.map_allpro(c, 7, 4), format);
	sheet->writeNum(i, 8 - 1, wp.map_attack(4, 0), format);
	sheet->writeNum(i, 16 - 1, wp.map_attack(13, 0), format);
	sheet->writeNum(i, 24 - 1, wp.map_attack(0, 0), format);
	sheet->writeNum(i, 32 - 1, wp.map_attack(0, 1), format);
	sheet->writeNum(i, 40 - 1, wp.map_attack(9, 0), format);
	sheet->writeNum(i, 48 - 1, wp.map_attack(9, 1), format);
	sheet->writeNum(i, 56 - 1, wp.map_attack(1, 0), format);
	sheet->writeNum(i, 64 - 1, wp.map_attack(1, 1), format);
	sheet->writeNum(i, 72 - 1, wp.map_attack(10, 0), format);
	sheet->writeNum(i, 80 - 1, wp.map_attack(10, 1), format);
	sheet->writeNum(i, 88 - 1, wp.map_attack(5, 0), format);
	sheet->writeNum(i, 96 - 1, wp.map_attack(5, 1), format);
	sheet->writeNum(i, 104 - 1, wp.map_attack(8, 0), format);
	sheet->writeNum(i, 112 - 1, wp.map_attack(8, 1), format);
	sheet->writeNum(i, 120 - 1, wp.map_attack(2, 0), format);
	sheet->writeNum(i, 128 - 1, wp.map_attack(2, 1), format);
	sheet->writeNum(i, 136 - 1, wp.map_attack(11, 0), format);
	sheet->writeNum(i, 144 - 1, wp.map_attack(11, 1), format);
	sheet->writeNum(i, 152 - 1, wp.map_attack(3, 0), format);
	sheet->writeNum(i, 160 - 1, wp.map_attack(3, 1), format);
	sheet->writeNum(i, 168 - 1, wp.map_attack(12, 0), format);
	sheet->writeNum(i, 176 - 1, wp.map_attack(12, 1), format);
	sheet->writeNum(i, 184 - 1, wp.map_attack(6, 0), format);
	sheet->writeNum(i, 192 - 1, wp.map_attack(6, 1), format);
	sheet->writeNum(i, 200 - 1, wp.map_attack(6, 2), format);
	sheet->writeNum(i, 208 - 1, wp.map_attack(6, 3), format);
	sheet->writeNum(i, 216 - 1, wp.map_attack(6, 4), format);
	sheet->writeNum(i, 224 - 1, wp.map_attack(7, 0), format);
	sheet->writeNum(i, 232 - 1, wp.map_attack(7, 1), format);
	sheet->writeNum(i, 240 - 1, wp.map_attack(7, 2), format);
	sheet->writeNum(i, 248 - 1, wp.map_attack(7, 3), format);
	sheet->writeNum(i, 256 - 1, wp.map_attack(7, 4), format);
}

toExcel::toExcel()
{
}

void toExcel::write_whole(string names, chessCharacters chch, wholePieces whpi ,int i, int result,string result_type)
{
	if (sheet)
		write_xls(names, format, sheet, chch, whpi, i, result, result_type);
}

void toExcel::set_format()
{
	format->setAlignH(ALIGNH_CENTER);
	format->setAlignV(ALIGNV_CENTER);
	sheet->setCol(0, 0, 50);
}

void toExcel::save(string s)
{
	wstring ws(s.length(), L' ');
	copy(s.begin(), s.end(), ws.begin());
	book->save(ws.c_str());
	book->release();
}

toExcel::~toExcel()
{
}


