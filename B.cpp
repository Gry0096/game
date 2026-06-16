#include"libOne.h"
#include"B.h"

void B_init(struct CIRCLE_B* b)
{
	//円B_初期化
	b->px = 0;
	b->py = 0;
	b->vx = 0;
	b->vy = 0;
	b->radius = 50;
}

void B_play(struct CIRCLE_B* b)
{
	//円B_位置
	b->px = mouseX;
	b->py = mouseY;
}

void B_over(struct CIRCLE_B* b)
{
	//円B_位置
	b->px = b->px;
	b->py = b->py;
}

void B_draw(struct CIRCLE_B* b)
{
	//円B_描画
	circle(b->px, b->py, b->radius * 2);
}
