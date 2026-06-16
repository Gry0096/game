#include"libOne.h"
#include"game.h"
#include"CIRCLE.h"
#include"TRIANGLE.h"

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

	//画面切り替え
	if (isTrigger(MOUSE_LBUTTON))
	{
		State = Play;
	}

	//背景描画
	background(255, 200, 255);

	//ロゴ描画
	fill(70, 255, 255);
	print("title");

	//info
	print((let)"w:" + width + " h:" + height);
	print((let)"x:" + (int)mouseX + " y:" + (int)mouseY);
	print((let)"delta:" + delta);
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

	draw(d);
}

void over(struct DATA* d)
{
	//円A
	A_over(&d->a);

	//円B
	B_over(&d->b);

	//画面切り替え
	if (isTrigger(MOUSE_LBUTTON))
	{
		State = Title;
	}

	draw(d);
}

void draw(struct DATA* d)
{
	//背景描画
	background(255, 200, 255);
	
	if (State == Title)
	{
		//ロゴ描画
		fill(70, 255, 255);
		print("title");
	}

	if (State != Title)
	{
		//円描画
		if (d->t.hyp_sqrd > d->t.dis_sqrd)
		{
			fill(255, 255, 0, 128);
		}
		else
		{
			fill(255, 0, 0, 128);
		}
		//circle(d->a.px, d->a.py, d->a.radius * 2);
		A_draw(&d->a);
		//circle(d->b.px, d->b.py, d->b.radius * 2);
		B_draw(&d->b);

		//line(d->a.px, d->a.py, d->b.px, d->b.py);
		
		if (State == Play)
		{
			//ロゴ描画
			fill(255, 255, 70);
			print("play");
		}
		else if (State == Over)
		{
			//ロゴ描画
			fill(255, 70, 255);
			print("over");
		}
	}

	//info
	print((let)"w:" + width + " h:" + height);
	print((let)"x:" + (int)mouseX + " y:" + (int)mouseY);
	print((let)"delta:" + delta);
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