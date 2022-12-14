// Error CS0017: 프로그램에 진입점이 두 개 이상 정의되어 있습니다. /main으로 컴파일하여 진입점이 포함된 형식을 지정하세요. (CS0017) (Sandbox-Console)

class Program
{
    static void Main()
    {
        System.Console.WriteLine("Hello World!");
    }
}

class Program2
{
    static void Main()
    {
        System.Console.WriteLine("Hello World!");
    }
}

// Error CS0111: 'Program' 형식은 동일한 매개 변수 형식을 가진 'Main' 멤버를 미리 정의합니다. (CS0111) (Sandbox-Console)
class Program
{
    static void Main()
    {
        System.Console.WriteLine("Hello World!");
    }

    static void Main()
    {
        System.Console.WriteLine("Hello World!");
    }
}