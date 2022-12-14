#ifdef SOLUTION_01_4
#include <iostream>
#include <string>

using namespace std;

class Deque
{
private:
	int _Queue[20001] = { 0 };	//헤응 변수명...
	int _front = 10000;
	int _back = 10000;
public:
	// size: 덱에 들어있는 정수의 개수를 출력한다.
	int size() { return _back - _front; }

	// empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
	bool empty() { return _front == _back; }


	// push_front X: 정수 X를 덱의 앞에 넣는다.
	void push_front(int a) { _Queue[_front--] = a; }

	// pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 
	int pop_front() { return _Queue[++_front]; }

	// front: 덱의 가장 앞에 있는 정수를 출력한다. 
	int front() { return _Queue[_front + 1]; }


	// push_back X: 정수 X를 덱의 뒤에 넣는다.
	void push_back(int a) { _Queue[++_back] = a; }

	// pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 
	int pop_back() { return _Queue[_back--]; }

	// back: 덱의 가장 뒤에 있는 정수를 출력한다. 
	int back() { return _Queue[_back]; }
};

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	// 얘가 테스트 케이스인데용가리
	int N = 0;
	cin >> N;

	Deque deque;


	// 넣을 value
	int Num = 0;
	// 명령어
	string str = {};

	//테스트 케이스 만큼 반복
	for (int i = 0; i < N; ++i)
	{
		cin >> str;

		// push_front X: 정수 X를 덱의 앞에 넣는다.헤으응
		if (str == "push_front")
		{
			cin >> Num;
			deque.push_front(Num);
		}
		// push_back X: 정수 X를 덱의 뒤에 넣는다. 헤으응
		else if (str == "push_back")
		{
			cin >> Num;
			deque.push_back(Num);
		}
		// pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 
		// 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.헤으응
		else if (str == "pop_front")
		{
			if (deque.empty())
				cout << "-1\n";
			else
				cout << deque.pop_front() << "\n";
		}
		// pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 
		// 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
		else if (str == "pop_back")
		{
			if (deque.empty())
				cout << "-1\n";
			else
				cout << deque.pop_back() << "\n";
		}
		// size: 덱에 들어있는 정수의 개수를 출력한다.
		else if (str == "size")
		{
			cout << deque.size() << "\n";
		}
		// empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
		else if (str == "empty")
		{
			cout << deque.empty() << "\n";
		}
		// front: 덱의 가장 앞에 있는 정수를 출력한다. 
		// 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
		else if (str == "front")
		{
			if (deque.empty())
				cout << "-1\n";
			else
				cout << deque.front() << "\n";
		}
		// back: 덱의 가장 뒤에 있는 정수를 출력한다. 
		// 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
		else if (str == "back")
		{
			if (deque.empty())
				cout << "-1\n";
			else
				cout << deque.back() << "\n";
		}
	}
}
#endif