using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int t = Int32.Parse(Console.ReadLine());
            string[][] initArray = new string[t][];
            string[] answersArr = new string[t];
            for (int i = 0; i < t; i++)
            {
                initArray[i] = Console.ReadLine().Split(' ');
            }
            for (int i = 0; i < t; i++)
            {
                long a = Int32.Parse(initArray[i][0]);
                long b = Int32.Parse(initArray[i][1]);
                long ab = a;
                for (long j = a + 1; j <= b; j++)
                {
                    ab *= j;
                }
                long c = Int32.Parse(initArray[i][2]);
                long d = Int32.Parse(initArray[i][3]);
                long cd = c;
                for (long j = c + 1; j <= d; j++)
                {
                    cd *= j;
                }
                if (cd % ab == 0)
                    answersArr[i] = "YES";
                else
                    answersArr[i] = "NO";
            }
            for (long i = 0; i < t; i++)
            {
                Console.WriteLine(answersArr[i]);
            }
        }
    }
}
