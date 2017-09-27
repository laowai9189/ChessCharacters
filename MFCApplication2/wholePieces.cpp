#include "stdafx.h"
#include "wholePieces.h"


wholePieces::wholePieces(int *x)
{
	set_value(x);
	make_step(x);
	set_move_value(x);
}

void wholePieces::set_value(int *x)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			switch (*(x + 9 * i + j))
			{
			case 0:d->set_type(0);
				d->piece_exist(true);
				d->set_control(position_value[0][i][j]);
				d->set_point(j, i); 
				d++->Chara_zuobiao();break;
			case 1:e->set_type(1);
				e->piece_exist(true);
				e->set_control(position_value[1][i][j]);
				e->set_point(j, i);
				e++->Chara_zuobiao(); break;
			case 2:f->set_type(2);
				f->piece_exist(true);
				f->set_control(position_value[2][i][j]);
				f->set_point(j, i);
				f++->Chara_zuobiao(); break;
			case 3:g->set_type(3);
				g->piece_exist(true);
				g->set_control(position_value[3][i][j]);
				g->set_point(j, i);
				g++->Chara_zuobiao(); break;
			case 4:h->set_type(4);
				h->piece_exist(true);
				h->set_control(position_value[4][i][j]);
				h->set_point(j, i);
				h->Chara_zuobiao(); break;
			case 5:l->set_type(5);
				l->piece_exist(true);
				l->set_control(position_value[5][i][j]);
				l->set_point(j, i);
				l++->Chara_zuobiao(); break;
			case 6:m->set_type(6);
				m->piece_exist(true);
				m->set_control(position_value[6][i][j]);
				m->set_point(j, i);
				m++->Chara_zuobiao(); break;
			case 7:M->set_type(7);
				M->piece_exist(true);
				M->set_control(position_value[7][i][j]);
				M->set_point(j, i);
				M++->Chara_zuobiao(); break;
			case 8:L->set_type(8);
				L->piece_exist(true);
				L->set_control(position_value[8][i][j]);
				L->set_point(j, i);
				L++->Chara_zuobiao(); break;
			case 9:D->set_type(9);
				D->piece_exist(true);
				D->set_control(position_value[9][i][j]);
				D->set_point(j, i);
				D++->Chara_zuobiao(); break;
			case 10:E->set_type(10);
				E->piece_exist(true);
				E->set_control(position_value[10][i][j]);
				E->set_point(j, i);
				E++->Chara_zuobiao(); break;
			case 11:F->set_type(11);
				F->piece_exist(true);
				F->set_control(position_value[11][i][j]);
				F->set_point(j, i);
				F++->Chara_zuobiao(); break;
			case 12:G->set_type(12);
				G->piece_exist(true);
				G->set_control(position_value[12][i][j]);
				G->set_point(j, i);
				G++->Chara_zuobiao(); break;
			case 13:H->set_type(13);
				H->piece_exist(true);
				H->set_control(position_value[13][i][j]);
				H->set_point(j, i);
				H->Chara_zuobiao();
			default:
				break;
			}
		}
	}
	d = r; e = n; f = b; g = a; h = k; l = c; m = p; M = P; L = C; D = R; E = N; F = B; G = A; H = K;
}

void wholePieces::make_step(int *x)
{
	k[0].get_touch(x);
	r[0].get_touch(x);
	r[1].get_touch(x);
	n[0].get_touch(x);
	n[1].get_touch(x);
	c[0].get_touch(x);
	c[1].get_touch(x);
	b[0].get_touch(x);
	b[1].get_touch(x);
	a[0].get_touch(x);
	a[1].get_touch(x);
	p[0].get_touch(x);
	p[1].get_touch(x);
	p[2].get_touch(x);
	p[3].get_touch(x);
	p[4].get_touch(x);
	K[0].get_touch(x);
	R[0].get_touch(x);
	R[1].get_touch(x);
	N[0].get_touch(x);
	N[1].get_touch(x);
	C[0].get_touch(x);
	C[1].get_touch(x);
	B[0].get_touch(x);
	B[1].get_touch(x);
	A[0].get_touch(x);
	A[1].get_touch(x);
	P[0].get_touch(x);
	P[1].get_touch(x);
	P[2].get_touch(x);
	P[3].get_touch(x);
	P[4].get_touch(x);
}

void wholePieces::set_move_value(int *x)
{
	for (int i = 0;i < 10;i++)
		for (int j = 0;j < 9;j++)
			switch (*(x + 9 * i + j))
			{
			case 0:d->move_num();
				d++->mobility();break;
			case 1:e->move_num();
				e++->mobility();break;
			case 2:f->move_num();
				f++->mobility();break;
			case 3:g->move_num();
				g++->mobility();break;
			case 4:h->move_num();
				h->mobility();break;
			case 5:l->move_num();
				l++->mobility();break;
			case 6:m->move_num();
				m++->mobility();break;
			case 7:M->move_num();
				M++->mobility();break;
			case 8:L->move_num();
				L++->mobility();break;
			case 9:D->move_num();
				D++->mobility();break;
			case 10:E->move_num();
				E++->mobility();break;
			case 11:F->move_num();
				F++->mobility();break;
			case 12:G->move_num();
				G++->mobility();break;
			case 13:H->move_num();
				H->mobility();break;
			default:
				break;
			}
	d = r; e = n; f = b; g = a; h = k; l = c; m = p; M = P; L = C; D = R; E = N; F = B; G = A; H = K;
}

void wholePieces::threat(pieceCharacters p1, pieceCharacters p2)	//p1是被攻击的，p2是发起攻击的
{
	if (p2.close(p1.return_x(), p1.return_y()))
	{
		if (p2.return_type() > -1 && p2.return_type() < 7)
			th_b.push_back(p2);
		else
			th_r.push_back(p2);
	}
}

void wholePieces::attack(pieceCharacters p1, pieceCharacters p2)
{
	if (p2.close(p1.return_x(), p1.return_y()))
	{
		if (p1.return_type() > -1 && p1.return_type() < 7)
			att_b.push_back(p1);
		else
			att_r.push_back(p1);
	}
}

pieceCharacters wholePieces::track(int i, int j)
{
	pieceCharacters s;
	switch (i)
	{
	case 0:
		s = r[j];
		break;
	case 1:
		s = n[j];
		break;
	case 2:
		s = b[j];
		break;
	case 3:
		s = a[j];
		break;
	case 4:
		s = k[j];
		break;
	case 5:
		s = c[j];
		break;
	case 6:
		s = p[j];
		break;
	case 7:
		s = P[j];
		break;
	case 8:
		s = C[j];
		break;
	case 9:
		s = R[j];
		break;
	case 10:
		s = N[j];
		break;
	case 11:
		s = B[j];
		break;
	case 12:
		s = A[j];
		break;
	case 13:
		s = K[j];
		break;
	default:
		break;
	}
	return s;
}

pieceCharacters * wholePieces::track_point(int i, int j)
{
	switch (i)
	{
	case 0:
		return r + j;
		break;
	case 1:
		return n + j;
		break;
	case 2:
		return b + j;
		break;
	case 3:
		return a + j;
		break;
	case 4:
		return k + j;
		break;
	case 5:
		return c + j;
		break;
	case 6:
		return p + j;
		break;
	case 7:
		return P + j;
		break;
	case 8:
		return C + j;
		break;
	case 9:
		return R + j;
		break;
	case 10:
		return N + j;
		break;
	case 11:
		return B + j;
		break;
	case 12:
		return A + j;
		break;
	case 13:
		return K + j;
		break;
	default:
		break;
	}
}

void wholePieces::threat_b(pieceCharacters s)
{
	threat(s, k[0]);
	threat(s, r[0]);
	threat(s, r[1]);
	threat(s, n[0]);
	threat(s, n[1]);
	threat(s, c[0]);
	threat(s, c[1]);
	threat(s, b[0]);
	threat(s, b[1]);
	threat(s, a[0]);
	threat(s, a[1]);
	threat(s, p[0]);
	threat(s, p[1]);
	threat(s, p[2]);
	threat(s, p[3]);
	threat(s, p[4]);
}



void wholePieces::threat_b(int i,int j)
{
	pieceCharacters s;
	s = track(i, j);
	threat(s, k[0]);
	threat(s, r[0]);
	threat(s, r[1]);
	threat(s, n[0]);
	threat(s, n[1]);
	threat(s, c[0]);
	threat(s, c[1]);
	threat(s, b[0]);
	threat(s, b[1]);
	threat(s, a[0]);
	threat(s, a[1]);
	threat(s, p[0]);
	threat(s, p[1]);
	threat(s, p[2]);
	threat(s, p[3]);
	threat(s, p[4]);
}

void wholePieces::threat_r(pieceCharacters s)
{
	threat(s, K[0]);
	threat(s, R[0]);
	threat(s, R[1]);
	threat(s, N[0]);
	threat(s, N[1]);
	threat(s, C[0]);
	threat(s, C[1]);
	threat(s, B[0]);
	threat(s, B[1]);
	threat(s, A[0]);
	threat(s, A[1]);
	threat(s, P[0]);
	threat(s, P[1]);
	threat(s, P[2]);
	threat(s, P[3]);
	threat(s, P[4]);
}

void wholePieces::threat_r(int i, int j)
{
	pieceCharacters s;
	s = track(i, j);
	threat(s, K[0]);
	threat(s, R[0]);
	threat(s, R[1]);
	threat(s, N[0]);
	threat(s, N[1]);
	threat(s, C[0]);
	threat(s, C[1]);
	threat(s, B[0]);
	threat(s, B[1]);
	threat(s, A[0]);
	threat(s, A[1]);
	threat(s, P[0]);
	threat(s, P[1]);
	threat(s, P[2]);
	threat(s, P[3]);
	threat(s, P[4]);
}

void wholePieces::attack_r(int i, int j)	//黑打红
{
	pieceCharacters s;
	s = track(i, j);
	attack(K[0], s);
	attack(R[0], s);
	attack(R[1], s);
	attack(N[0], s);
	attack(N[1], s);
	attack(C[0], s);
	attack(C[1], s);
	attack(B[0], s);
	attack(B[1], s);
	attack(A[0], s);
	attack(A[1], s);
	attack(P[0], s);
	attack(P[1], s);
	attack(P[2], s);
	attack(P[3], s);
	attack(P[4], s);
}

void wholePieces::attack_b(int i, int j)	//红打黑
{
	pieceCharacters s;
	s = track(i, j);
	attack(k[0], s);
	attack(r[0], s);
	attack(r[1], s);
	attack(n[0], s);
	attack(n[1], s);
	attack(c[0], s);
	attack(c[1], s);
	attack(b[0], s);
	attack(b[1], s);
	attack(a[0], s);
	attack(a[1], s);
	attack(p[0], s);
	attack(p[1], s);
	attack(p[2], s);
	attack(p[3], s);
	attack(p[4], s);
}

double wholePieces::map_threat(int i, int j)
{
	vector<pieceCharacters>::iterator a;
	if (i > -1 && i < 7)
	{
		threat_r(i, j);
		if (!th_r.empty())
		{
			int whole = 0;
			for (a = th_r.begin(); a != th_r.end(); ++a)
			{
				int lei = (*a).get_ascii();
				int full = lei*a->return_control();
				whole = whole+full;
			}
			th_r.clear();
			return whole;
		}
		else {
			return 0;
		}	
	}
	else if(i > 6 && i < 14){
		threat_b(i, j);
		if (!th_b.empty())
		{
			int whole = 0;
			for (a = th_b.begin(); a != th_b.end(); ++a)
			{
				int lei = (*a).get_ascii();
				int full = lei*a->return_control();
				whole = whole+full;
			}
			th_b.clear();
			return whole;
		}
		else {
			return 0;
		}
	}
}

wstring wholePieces::map_threat(pieceCharacters p)
{
	vector<pieceCharacters>::iterator a;
	if (p.Type() > -1 && p.Type() < 7)
	{
		threat_r(p);
		if (!th_r.empty())
		{
			string whole;
			for (a = th_r.begin(); a != th_r.end(); ++a)
			{
				string lei = (*a).get_cname();
				string full = lei + (*a).return_location();
				whole += full;
			}
			th_r.clear();
			wstring ws(whole.length(), L' ');
			copy(whole.begin(), whole.end(), ws.begin());
			return ws;
		}
		else {
			string full = "0";
			wstring ws(full.length(), L' ');
			copy(full.begin(), full.end(), ws.begin());
			return ws;
		}
	}
	else if (p.Type() > 6 && p.Type() < 14) {
		threat_b(p);
		if (!th_b.empty())
		{
			string whole;
			for (a = th_b.begin(); a != th_b.end(); ++a)
			{
				string lei = (*a).get_cname();
				string full = lei + (*a).return_location();
				whole += full;
			}
			th_b.clear();
			wstring ws(whole.length(), L' ');
			copy(whole.begin(), whole.end(), ws.begin());
			return ws;
		}
		else {
			string full = "0";
			wstring ws(full.length(), L' ');
			copy(full.begin(), full.end(), ws.begin());
			return ws;
		}
	}
}

wstring wholePieces::map_protect(chessCharacters c, int i, int j)
{
	vector<pieceCharacters>::iterator a;
	if (i > -1 && i < 7)
	{
		threat_r(i, j);
		if (!th_r.empty())
		{
			wstring whole;
			for (a = th_r.begin(); a != th_r.end(); ++a)
			{
				c.change_array((*a).return_x(), (*a).return_y(), track(i, j).return_x(), track(i, j).return_y());
				int* x = c.get_point();
				int th_id = (*a).Type();
				wholePieces wp(x);
				switch (th_id)
				{
				case 7:
					for (int b = 0; b < 5; b++)
						if (wp.track(th_id, b).return_x() == track(i, j).return_x() && wp.track(th_id, b).return_y() == track(i, j).return_y())
							whole += wp.map_threat(th_id, b);
					break;
				case 8:
				case 9:
				case 10:
				case 11:
				case 12:
					for (int b = 0; b < 2; b++)
						if (wp.track(th_id, b).return_x() == track(i, j).return_x() && wp.track(th_id, b).return_y() == track(i, j).return_y())
							whole += wp.map_threat(th_id, b);
					break;
				case 13:
					whole += wp.map_threat(th_id, 0);
				}
				th_r.clear();
				return whole;
			}
		}
		else {
			string full = "0";
			wstring ws(full.length(), L' ');
			copy(full.begin(), full.end(), ws.begin());
			return ws;
		}
	}
	else if (i > 6 && i < 14) {
		threat_b(i, j);
		if (!th_b.empty())
		{
			wstring whole;
			for (a = th_b.begin(); a != th_b.end(); ++a)
			{
				c.change_array((*a).return_x(), (*a).return_y(), track(i, j).return_x(), track(i, j).return_y());
				int* x = c.get_point();
				int th_id = (*a).Type();
				wholePieces wp(x);
				switch (th_id)
				{
				case 6:
					for (int b = 0; b < 5; b++)
						if (wp.track(th_id, b).return_x() == track(i, j).return_x() && wp.track(th_id, b).return_y() == track(i, j).return_y())
							whole += wp.map_threat(th_id, b);
					break;
				case 0:
				case 1:
				case 2:
				case 3:
				case 5:
					for (int b = 0; b < 2; b++)
						if (wp.track(th_id, b).return_x() == track(i, j).return_x() && wp.track(th_id, b).return_y() == track(i, j).return_y())
							whole += wp.map_threat(th_id, b);
					break;
				case 4:
					whole += wp.map_threat(th_id, 0);
				}
				th_b.clear();
				return whole;
			}
		}
		else {
			string full = "0";
			wstring ws(full.length(), L' ');
			copy(full.begin(), full.end(), ws.begin());
			return ws;
		}
	}
}

int wholePieces::map_allpro(chessCharacters c, int i, int j)
{
	if (i > -1 && i < 7)
	{
		c.change_one(track(i, j).return_x(), track(i, j).return_y(), 7);
		int* x = c.get_point();
		wholePieces wp(x);
		for (int a = 0; a < 6; a++)
			if (wp.track(7, a).return_x() == track(i, j).return_x() && wp.track(7, a).return_y() == track(i, j).return_y())
				return wp.map_threat(7, a);
	}
	else {
		c.change_one(track(i, j).return_x(), track(i, j).return_y(), 6);
		int* x = c.get_point();
		wholePieces wp(x);
		for (int a = 0; a < 6; a++)
			if (wp.track(6, a).return_x() == track(i, j).return_x() && wp.track(6, a).return_y() == track(i, j).return_y())
				return wp.map_threat(6, a);
	}
}

double wholePieces::map_attack(int i, int j)
{
	vector<pieceCharacters>::iterator a;
	if (i > -1 && i < 7)
	{
		attack_r(i, j);
		if (!att_r.empty())
		{
			int whole = 0;
			for (a = att_r.begin(); a != att_r.end(); ++a)
			{
				int lei = (*a).get_ascii();
				int full = lei*a->return_control();
				whole += full;
			}
			att_r.clear();
			return whole;
		}
		else
			return 0;
	}
	else if (i > 6 && i < 14) {
		attack_b(i, j);
		if (!att_b.empty())
		{
			int whole = 0;
			for (a = att_b.begin(); a != att_b.end(); ++a)
			{
				int lei = (*a).get_ascii();
				int full = lei*a->return_control();
				whole += full;
			}
			att_b.clear();
			return whole;
		}
		else
			return 0;
	}
}


int wholePieces::th_bx()
{
	vector<pieceCharacters>::iterator i;
	if (!th_b.empty())
		for (i = th_b.begin(); i != th_b.end(); ++i)
		{
			return (*i).return_x();	
		}	
}

int wholePieces::th_by()
{
	vector<pieceCharacters>::iterator i;
	if (!th_b.empty())
		for (i = th_b.begin(); i != th_b.end(); ++i)
		{
			return (*i).return_y();
		}	
}

int wholePieces::th_rx()
{
	vector<pieceCharacters>::iterator i;
	if (!th_r.empty())
		for (i = th_r.begin(); i != th_r.end(); ++i)
		{
			return (*i).return_x();
		}
}

int wholePieces::th_ry()
{
	vector<pieceCharacters>::iterator i;
	if (!th_r.empty())
		for (i = th_r.begin(); i != th_r.end(); ++i)
		{
			return (*i).return_y();
		}
}


wholePieces::~wholePieces()
{
}
