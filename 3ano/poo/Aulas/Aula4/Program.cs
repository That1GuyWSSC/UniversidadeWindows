using System;
using System.Net.Sockets;
using System.Runtime.Serialization;

namespace Aula4
{
    internal class Program
    {
        static void Main(string[] args)
        {
            #region Primeira parte da aula
            
            /*int[] valores={7,8,9,11,-1};
            double so = 0;
            double m = 0;
            double a = 0;

            for (int i = 0; i < valores.Length; i++)
            {
                so = so + valores[i];
            }

            m = so/valores.Length;
            Console.WriteLine("A media e de : " + m);

            foreach (var s in valores)
            {
                a += s; // a variavel s e o valor dos contents array 
            }
            
            Console.WriteLine("A soma de todos os valores e de :  " + a);*/
            #endregion

            #region segunda parte da aula

            /*
            int[] valores = {7, 6, -1, 11, 0};
            double av;
            av = Opers.Average(valores);

            Console.WriteLine("Teste" + av);

            int x = 2, y = 3;
            double aux = Opers.Soma(x, y);
            */

            #endregion

            //classes e objetos 
            #region terceira parte da aula
            
            //p e um objeto do tipo pessoa
            Pessoa p = new Pessoa();

            //p.idade = 12;
            p.nome = "ok";

            Pessoa q = new Pessoa();
            q.idade = p.idade * 2;


            #endregion
        }
    }
}