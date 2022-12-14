#ifdef SOLUTION_01_2
#include <stdio.h>

int n;

int container[1000000];
class MyQ
{
public:
    void Push(int value)
    {
        container[start + size] = value;
        size++;
    }

    void CardMove(int value)
    {
        container[start + size] = value;
        start++;
    }

    void Pop()
    {
        if (Empty() == false)
        {
            start++;
            size--;
        }
    }
    int Size()
    {
        return size;
    }
    bool Empty()
    {
        if (size == 0)
        {
            return true;
        }
        return false;
    }
    int Front()
    {
        return container[start];
    }

private:
    int start = 0;
    int size = 0;
};

int main()
{
    scanf("%d", &n);
    MyQ Q;

    for (int i = 0; i < n; ++i)
    {
        Q.Push(i + 1);
    }
    bool isErase = true;
    while (Q.Size() != 1)
    {
        if (isErase)
        {
            Q.Pop();
            isErase = false;
        }
        else
        {
            Q.CardMove(Q.Front());
            isErase = true;
        }
    }
    printf("%d", Q.Front());
}
#endif