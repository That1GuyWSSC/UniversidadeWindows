
/*
 * autor : Joao Machado
 * data : 2/03/2021
 * email : 
 * vers :
 * */
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using AulaHoje2;

namespace AulaHoje
{
     /// <summary>
     /// Class que faz nao sei o que
     /// </summary>
    class Program
    {
        /// <summary>
        /// Programa para qualquer cena
        /// </summary>
        /// <param name="args"></param>
        static void Main(string[] args)
        {
            int x = 10, y;


            Console.Write("Valor 1 :");
            x = int.Parse(Console.ReadLine()); // "12"
            Console.Write("Valor 2 :");
            y= int.Parse(Console.ReadLine()); // ""


            Console.WriteLine(" {0} + {1} = {2} ",x,y,x+y );

            Console.WriteLine(" {0} + {1} = {2} ", x, y, Oper.Soma(x, y));

            Oper.X aux = Oper.SomaProduto(2, 3);

            Oper.SomaProduto(2, 3, out x, out y);

            Oper.SomaProdutoII(4, 5, ref x, ref y);

            Escreve("xau");

            Console.ReadKey();
        }

        static void Escreve(string s)
        {

            Console.WriteLine(s);

        }

        
        
    }
}
