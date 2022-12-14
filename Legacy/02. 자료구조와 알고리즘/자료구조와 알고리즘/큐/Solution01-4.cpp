#ifdef SOLUTION_01_4
#include <iostream>
#include <string>

using namespace std;

class Deque
{
private:
	int _Queue[20001] = { 0 };	//���� ������...
	int _front = 10000;
	int _back = 10000;
public:
	// size: ���� ����ִ� ������ ������ ����Ѵ�.
	int size() { return _back - _front; }

	// empty: ���� ��������� 1��, �ƴϸ� 0�� ����Ѵ�.
	bool empty() { return _front == _back; }


	// push_front X: ���� X�� ���� �տ� �ִ´�.
	void push_front(int a) { _Queue[_front--] = a; }

	// pop_front: ���� ���� �տ� �ִ� ���� ����, �� ���� ����Ѵ�. 
	int pop_front() { return _Queue[++_front]; }

	// front: ���� ���� �տ� �ִ� ������ ����Ѵ�. 
	int front() { return _Queue[_front + 1]; }


	// push_back X: ���� X�� ���� �ڿ� �ִ´�.
	void push_back(int a) { _Queue[++_back] = a; }

	// pop_back: ���� ���� �ڿ� �ִ� ���� ����, �� ���� ����Ѵ�. 
	int pop_back() { return _Queue[_back--]; }

	// back: ���� ���� �ڿ� �ִ� ������ ����Ѵ�. 
	int back() { return _Queue[_back]; }
};

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	// �갡 �׽�Ʈ ���̽��ε��밡��
	int N = 0;
	cin >> N;

	Deque deque;


	// ���� value
	int Num = 0;
	// ��ɾ�
	string str = {};

	//�׽�Ʈ ���̽� ��ŭ �ݺ�
	for (int i = 0; i < N; ++i)
	{
		cin >> str;

		// push_front X: ���� X�� ���� �տ� �ִ´�.������
		if (str == "push_front")
		{
			cin >> Num;
			deque.push_front(Num);
		}
		// push_back X: ���� X�� ���� �ڿ� �ִ´�. ������
		else if (str == "push_back")
		{
			cin >> Num;
			deque.push_back(Num);
		}
		// pop_front: ���� ���� �տ� �ִ� ���� ����, �� ���� ����Ѵ�. 
		// ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.������
		else if (str == "pop_front")
		{
			if (deque.empty())
				cout << "-1\n";
			else
				cout << deque.pop_front() << "\n";
		}
		// pop_back: ���� ���� �ڿ� �ִ� ���� ����, �� ���� ����Ѵ�. 
		// ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
		else if (str == "pop_back")
		{
			if (deque.empty())
				cout << "-1\n";
			else
				cout << deque.pop_back() << "\n";
		}
		// size: ���� ����ִ� ������ ������ ����Ѵ�.
		else if (str == "size")
		{
			cout << deque.size() << "\n";
		}
		// empty: ���� ��������� 1��, �ƴϸ� 0�� ����Ѵ�.
		else if (str == "empty")
		{
			cout << deque.empty() << "\n";
		}
		// front: ���� ���� �տ� �ִ� ������ ����Ѵ�. 
		// ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
		else if (str == "front")
		{
			if (deque.empty())
				cout << "-1\n";
			else
				cout << deque.front() << "\n";
		}
		// back: ���� ���� �ڿ� �ִ� ������ ����Ѵ�. 
		// ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
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