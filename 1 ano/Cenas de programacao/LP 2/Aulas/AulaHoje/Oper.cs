/*
 * 
 * autor
 * 
 * */
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AulaHoje2
{
    class Oper
    {
        public struct X
        {
            public int s;
            public int p;
        }


        /// <summary>
        /// Soma de dois numeros
        /// </summary>
        /// <param name="x">Valor 1 </param>
        /// <param name="y">Valor 2</param>
        /// <returns></returns>
        ///
        public static int Soma(int x, int y)
        {

            return x + y;
        }

        public static void SomaProduto(int x, int y, out int s, out int p)
        {
            X aux;
            s = x + y;
            p = x * y;
        

        }

        public static void SomaProdutoII(int x, int y, ref int s, ref int p)
        {
            X aux;
            s = x + y;
            p = x * y;


        }

    }
}
