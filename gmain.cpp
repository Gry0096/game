#include"libOne.h"
#include"game.h"
#include"DRAW.h"

//画面切り替え
int Title = 0, Play = 1, Over = 2, State = Title;

struct DATA
{
	struct CIRCLE_A a;
	struct CIRCLE_B b;
	struct TRIANGLE t;
};

void title(struct DATA* d)
{
	init(d);
	D_title();

	//画面切り替え
	if (isTrigger(MOUSE_LBUTTON))
	{
		State = Play;
	}

}

void init(struct DATA* d)
{
	//円A初期化
	A_init(&d->a);

	//円B初期化
	B_init(&d->b);

	//三角形初期化
	T_init(&d->t);
}

void play(struct DATA* d)
{
	D_play();

	//円B
	B_play(&d->b);
	
	//円A
	A_play(&d->a);

	//三角形_当たり判定距離
	T_play(&d->t, &d->a, &d->b);

	//Over_判定
	if (d->t.hyp_sqrd < d->t.dis_sqrd)
	{
		State = Over;
	}

}

void over(struct DATA* d)
{
	D_over();

	//円A
	A_over(&d->a);

	//円B
	B_over(&d->b);

	//画面切り替え
	if (isTrigger(MOUSE_LBUTTON))
	{
		State = Title;
	}

}

void gmain()
{
	window(1920, 1080, full);
	struct DATA d;

	//ゲームループ
	repeat()
	{
		if (State == Title)
		{
			title(&d);
		}
		else if (State == Play)
		{
			play(&d);
		}
		else if(State == Over)
		{
			over(&d);
		}
	}
}