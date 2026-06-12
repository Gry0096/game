#include"libOne.h"
#include"game.h"

//画面切り替え
int Title = 0, Play = 1, Over = 2, State = Title;

struct CIRCLE
{
	float px, py, vx, vy, radius;
};

struct TRIANGLE
{
	float adj;//底辺
	float opp;//高さ
	float hyp_sqrd;//斜辺_二乗
	float dis_sqrd;
};

struct DATA
{
	struct CIRCLE a;
	struct CIRCLE b;
	struct TRIANGLE t;
	float enl;//enlarge(拡大)
};

void title(struct DATA* d)
{
	init(d);
	draw(d);

	//画面切り替え
	if (isTrigger(MOUSE_LBUTTON))
	{
		State = Play;
	}
}

void init(struct DATA* d)
{
	//円A初期化
	d->a.px = width / 3;
	d->a.py = height / 2;
	d->a.vx = 4;
	d->a.vy = 3;
	d->a.radius = 25;

	//円B初期化
	d->b.px = 0;
	d->b.py = 0;
	d->b.vx = 0;
	d->b.vy = 0;
	d->b.radius = 25;

	//三角形初期化
	d->t.adj = 0;
	d->t.opp = 0;
	d->t.hyp_sqrd = 0;
	d->t.dis_sqrd = 0;

	//拡大速度
	d->enl = 0.3f;
}

void play(struct DATA* d)
{
	//円B_位置
	d->b.px = mouseX;
	d->b.py = mouseY;

	//円A_位置
	d->a.px += d->a.vx;
	d->a.py += d->a.vy;
	
	//円A_拡大速度
	d->a.radius += d->enl;

	//三角形_当たり判定距離
	d->t.adj = d->a.px - d->b.px;
	d->t.opp = d->a.py - d->b.py;
	d->t.hyp_sqrd = (d->t.adj * d->t.adj) + (d->t.opp * d->t.opp);
	d->t.dis_sqrd = (d->a.radius + d->b.radius) * (d->a.radius + d->b.radius);

	//円A_移動挙動
	if (d->a.px + d->a.radius > width && d->a.vx > 0 || d->a.px - d->a.radius < 0 && d->a.vx < 0)
	{
		d->a.vx *= -1;
	}
	if (d->a.py + d->a.radius > height && d->a.vy > 0 || d->a.py - d->a.radius < 0 && d->a.vy < 0)
	{
		d->a.vy *= -1;
	}

	if (d->t.hyp_sqrd < d->t.dis_sqrd)
	{
		State = Over;
	}

	draw(d);
}

void over(struct DATA* d)
{
	//円A_移動挙動
	d->a.vx = 0;
	d->a.vy = 0;

	//円A_拡大速度
	d->enl = 0;

	//円B_位置
	d->b.px = d->b.px;
	d->b.py = d->b.py;

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
		circle(d->a.px, d->a.py, d->a.radius * 2);
		circle(d->b.px, d->b.py, d->b.radius * 2);

		line(d->a.px, d->a.py, d->b.px, d->b.py);
		
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