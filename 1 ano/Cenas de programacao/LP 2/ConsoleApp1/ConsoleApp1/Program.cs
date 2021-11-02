using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    public class Program
    {
        static void Main(string[] args)
        {
            #region teste
            int x = 2;
            int y = 3;
            Console.WriteLine("Ola."); //printf("%s\n", "ola");

            Console.ReadKey();          //getch():
            Console.ReadLine();         //getchar(); scanf();

            string nome;

            nome = Console.ReadLine();

            int z;

            z = int.Parse(Console.ReadLine());

            Console.WriteLine(nome);

            #endregion

            #region Variaveis
            int a = 2;
            char b;
            float c;
            double d = a;
            bool e;

            //int v[10]
            int[] v = { 1, 2, 3, 4 };
            int[] v1 = new int[4];
            string[] nomes = new string[20];
            nomes[0] = "ola";
            v1[0] = v[0];

        }
    }
}
