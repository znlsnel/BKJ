using System;
using System.Threading;

class Program
{
	static void Main()
	{
		// 스레드 생성 및 시작
		Thread thread1 = new Thread(() => PrintNumbers("Thread 1"));
		thread1.Start();

		Thread thread2 = new Thread(() => PrintNumbers("Thread 2"));
		thread2.Start();

		// 메인 스레드의 작업
		PrintNumbers("Main thread");
	}

	static void PrintNumbers(string threadName)
	{
		for (int i = 0; i < 5; i++)
		{
			Console.WriteLine($"{threadName}: {i}");
			// 스레드를 잠시 멈추게 하여 컨텍스트 스위칭을 유도
			Thread.Sleep(1);

			// 조건부 양도 나와 우선순위가 같거나 높은 쓰레드한테 양도 (우선수위가 낮은애 한테는 양도x)
			Thread.Sleep(0);

			// 무조건 양도 
			Thread.Yield();

		}
	}
}