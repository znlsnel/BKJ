using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Threading;
using System.Xml.Linq;

class Snake
{
	Direction _dir;
	int _len;

	public Point _point;
	Snake _child = null;
	public bool isRoot = false;

	public Snake(Point point, int len, Direction dir)
	{
		_len = len;
		_dir = dir;
		_point = point;

		if (len > 1)
			AddChild();
	}

	public void Draw()
	{
		if (_child != null)
			_child.Draw();

		_point.Draw();
	}

	public void AddChild()
	{
		if (_child == null)
		{
			int x = _point.x;
			int y = _point.y;

			if (_dir == Direction.LEFT)
				x += 1;
			else if (_dir == Direction.RIGHT)
				x -= 1;
			else if (_dir == Direction.UP)
				y += 1;
			else if (_dir == Direction.DOWN)
				y -= 1;

			Point point = new Point(x, y, _point.sym);
			_child = new Snake(point, _len - 1, _dir);
		}
		else
			_child.AddChild();
	}

	public bool Move()
	{
		int x = _point.x;
		int y = _point.y;

		if (_dir == Direction.LEFT)
			x -= 1;
		else if (_dir == Direction.RIGHT)
			x += 1;
		else if (_dir == Direction.UP)
			y -= 1;
		else
			y += 1;

		Point next = new Point(x, y, _point.sym);
		if (isRoot && isHit(next))
		{
			return false;
		}
		_point = next;

		if (_child != null)
		{
			_child.Move();
			_child._dir = _dir;
		}
		return true;
	}

	int[] dy = new int[4] { 0, 0, 1, -1 };
	int[] dx = new int[4] { -1, 1, 0, 0 };

	public void Turn(Direction dir)
	{
		if (_child != null)
		{
			int x = _point.x + dx[(int)dir];
			int y = _point.y + dy[(int)dir];

			if (_child.isHit(new Point(x, y, 'x')))
				return;
		}
		_dir = dir;
	}

	public bool isHit(Point point)
	{
		bool ret = _point.IsHit(point);
		if (_child != null)
			ret = ret || _child.isHit(point);

		return ret;
	}
}

class FoodCreator
{
	int size_x;
	int size_y;
	char _sym;
	Random random = new Random();

	public FoodCreator(int a, int b, char sym)
	{
		size_x = a;
		size_y = b;
		_sym = sym;
	}

	public Point CreateFood(Snake snake)
	{
		int x = random.Next(1, size_x);
		int y = random.Next(1, size_y);
		Point point = new Point(x, y, _sym);

		if (snake.isHit(point))
			return CreateFood(snake);

		return point;
	}
}



class Program
{
	static public void DrawWall(int x, int y)
	{
		for (int i = 0; i <= y; i++)
		{
			if (i == 0 || i == y)
			{
				for (int k = 0; k <= x; k++)
					Console.Write("-");
				Console.WriteLine();

				continue;
			}

			Console.Write("|");
			for (int k = 0; k <= x - 2; k++)
				Console.Write(" ");
			Console.Write("|");
			Console.WriteLine();
		}
	}

	static void Main(string[] args)
	{
		// 뱀의 초기 위치와 방향을 설정하고, 그립니다.
		Point p = new Point(4, 5, '*');
		Snake snake = new Snake(p, 4, Direction.RIGHT);
		snake.isRoot = true;
		// 음식의 위치를 무작위로 생성하고, 그립니다.
		LinkedList<Point> foods = new LinkedList<Point>();
		int cnt = 0;

		int mapX = 80;
		int mapY = 20;
		FoodCreator foodCreator = new FoodCreator(mapX, mapY, '$');

		// 게임 루프: 이 루프는 게임이 끝날 때까지 계속 실행됩니다.
		while (true)
		{
			Console.Clear();

			DrawWall(mapX, mapY);

			if (cnt++ == 5)
			{
				Point food = foodCreator.CreateFood(snake);
				foods.AddLast(food);
				cnt = 0;
			}

			List<Point> temp = new List<Point>();
			foreach(Point f in foods)
			{
				if (snake._point.IsHit(f))
					temp.Add(f);

				else
					f.Draw();
			}

			if (temp.Count > 0)
				snake.AddChild();

			foreach(Point f in temp)
				foods.Remove(f);


			if (Console.KeyAvailable)
			{
				ConsoleKeyInfo keyInfo = Console.ReadKey(intercept: true); // 키 입력 받기
				Direction dir = Direction.NONE;

				if (keyInfo.Key == ConsoleKey.DownArrow)
					dir = Direction.DOWN;
				else if (keyInfo.Key == ConsoleKey.UpArrow)
					dir = Direction.UP;
				else if (keyInfo.Key == ConsoleKey.LeftArrow)
					dir = Direction.LEFT;
				else if (keyInfo.Key == ConsoleKey.RightArrow)
					dir = Direction.RIGHT;

				if (dir != Direction.NONE)
					snake.Turn(dir);
			}

			// 뱀이 이동하고, 음식을 먹었는지, 벽이나 자신의 몸에 부딪혔는지 등을 확인하고 처리하는 로직을 작성하세요.
			if (snake.Move() == false)
			{
				Console.Clear();
				Console.WriteLine("꼬리에 충돌 하였습니다.");
				break;
			}
			else if (snake._point.x <= 0 || snake._point.x >= mapX || snake._point.y <= 0 || snake._point.y >= mapY)
			{
				Console.Clear();
				Console.WriteLine("벽 충돌 하였습니다.");
				break;
			}

			snake.Draw();





			Thread.Sleep(100); // 게임 속도 조절 (이 값을 변경하면 게임의 속도가 바뀝니다)

			// 뱀의 상태를 출력합니다 (예: 현재 길이, 먹은 음식의 수 등)
		}
	}
}

public class Point
{
	public int x{ get; set; }
	public int y{ get; set; }
	public char sym{ get; set; }

		// Point 클래스 생성자
		public Point(int _x, int _y, char _sym)
	{
		x = _x;
		y = _y;
		sym = _sym;
	}

	// 점을 그리는 메서드
	public void Draw()
	{
		Console.SetCursorPosition(x, y);
		Console.Write(sym);
	}

	// 점을 지우는 메서드
	public void Clear()
	{
		sym = ' ';
		Draw();
	}

	// 두 점이 같은지 비교하는 메서드
	public bool IsHit(Point p)
	{
		return p.x == x && p.y == y;
	}
}
// 방향을 표현하는 열거형입니다.
public enum Direction : int
{
	NONE = -1,
	LEFT,
	RIGHT,
	UP,
	DOWN
}