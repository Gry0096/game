#include"libOne.h"
#include"TRIANGLE.h"
#include"CIRCLE.h"

void T_init(struct TRIANGLE* t)
{
	//三角形初期化
	t->adj = 0;
	t->opp = 0;
	t->hyp_sqrd = 0;
	t->dis_sqrd = 0;
}

void T_play(struct TRIANGLE* t, struct CIRCLE_A* a, struct CIRCLE_B* b)
{
	//三角形_当たり判定距離
	t->adj = a->px - b->px;
	t->opp = a->py - b->py;
	t->hyp_sqrd = (t->adj * t->adj) + (t->opp * t->opp);
	t->dis_sqrd = (a->radius + b->radius) * (a->radius + b->radius);
}
