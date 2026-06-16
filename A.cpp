#include"libOne.h"
#include"A.h"

void A_init(struct CIRCLE_A* a)
{
	//円A_初期化
	a->px = width / 3;
	a->py = height / 2;
	a->vx = 4;
	a->vy = 3;
	a->radius = 25;
	a->enl = 0.3f;
}

void A_play(struct CIRCLE_A* a)
{
	//円A_位置
	a->px += a->vx;
	a->py += a->vy;

	//円A_拡大速度
	a->radius += a->enl;

	//円A_移動挙動
	if (a->px + a->radius > width && a->vx > 0 || a->px - a->radius < 0 && a->vx < 0)
	{
		a->vx *= -1;
	}
	if (a->py + a->radius > height && a->vy > 0 || a->py - a->radius < 0 && a->vy < 0)
	{
		a->vy *= -1;
	}
}

void A_over(struct CIRCLE_A* a)
{
	//円A_移動挙動
	a->vx = 0;
	a->vy = 0;

	//円A_拡大速度
	a->enl = 0;
}

void A_draw(struct CIRCLE_A* a)
{
	//円A_描画
	circle(a->px, a->py, a->radius * 2);
}