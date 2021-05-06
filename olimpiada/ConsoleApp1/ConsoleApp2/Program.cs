using System;
using System.Collections.Generic;
using System.Linq;

namespace task1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] size = Console.ReadLine().Split(' ');

            int n = Convert.ToInt32(size[0]);
            int m = Convert.ToInt32(size[0]);
            string[] initArray = new string[n];
            for (int i = 0; i < n; i++)
            {
                initArray[i] = Console.ReadLine();
            }

            int index = 0;
            List<int> list = new List<int>();
            Random random = new Random();
            int[,] arr2 = new int[Convert.ToInt32(size[0]), Convert.ToInt32(size[1])];


            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    arr2[i, j] = (int)initArray[i][j];

                    Console.Write(" " + arr2[i, j]);
                }
                Console.WriteLine();
            }

            Console.WriteLine();
            Rekursiya(arr2, n, m, list);
            // минимальное число, и значение его  jго индекса
            foreach (var VARIABLE in list)
            {
                for (int i = list.Count - 1; i > 0; i--)
                {
                    if (list[i] < VARIABLE)
                    {
                        index = i;
                    }
                }
            }
            Console.WriteLine("Кратчайший путь ");
            for (int i = 0; i < n; i++)
            {
                for (int j = (list.Count - 1 - index); j == list.Count - 1 - index; j--)
                {
                    Console.WriteLine(arr2[i, j] + " " + i + "," + j);
                }
            }
            Console.ReadLine();
        }
        // Собственно сама рекурсия.
        static void Rekursiya(int[,] arr, int x, int y, List<int> list)
        {
            int temp;

            temp = 0;

            for (int i = 0; i < y; i++)
            {
                for (int j = x - 1; j >= 0; j--)
                {
                    temp += arr[i, j];

                    break;
                }
            }
            if (list.Count < y)
            {
                list.Add(temp);
            }

            if (x > 1)
            {
                x--;
                Rekursiya(arr, x, y, list);
            }
        }
    }
}