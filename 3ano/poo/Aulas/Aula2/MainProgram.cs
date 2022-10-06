using System;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;

/*
 * author : Joao Machado
 * date of creation : 29/09/2022 
 */

namespace Aula2
{
    internal class MainProgram
    {
        static int Soma(int x, int y)
        {

            return x + y;
        }
        public static void Main(string[] args)
        {
            int age;
            bool x;
            string valor;

            Console.WriteLine("Hello world!");
            Console.Write("Age : ");
            valor = Console.ReadLine();
            //age = int.Parse(Console.ReadLine());
            x = int.TryParse(valor, out age);
            if (x == false)
            {
                Console.WriteLine("nao funcionou o parser");

            }
            else
            {
                Console.WriteLine("Your age is : " + age);

                
            }
            
        }
    }
}