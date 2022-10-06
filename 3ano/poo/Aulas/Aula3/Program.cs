using System;

namespace Aula3
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            #region C

            //if
            int x = 1, y = 2, z = 4;

            if (x == y)
                y = x + z;
            else
                Console.WriteLine("Os valores nao sao iguais");

            //for

            for (var i = 0; i <= z; i++) Console.WriteLine("O numero esta a aumentar: {0}", i);
            //do
            do
            {
                x++;
                Console.WriteLine("Acabou o processo de aumetar o x");
            } while (z > x);

            //switch
            switch (x)
            {
                case 1:
                {
                    Console.WriteLine("O x e this valor : {0}", x);
                    break;
                }
                case 2:
                {
                    Console.WriteLine("O x e this valor : {0}", x);
                    break;
                }
                case 3:
                {
                    Console.WriteLine("O x e this valor : {0}", x);
                    break;
                }
                case 4:
                {
                    Console.WriteLine("O x e this valor : {0}", x);
                    break;
                }
            }

            //?

            //variables
            string nome;
            string[] turma;
            //constants
            const double PI = 3.141;

            #endregion

            #region C#Arrays

            //C: int valores[20];
            int[] valores = {1, 2, 3, 4, 5};


            //Percorre todas as posicoes do array pelo h
            for (var h = 0; h < valores.Length; h++) Console.WriteLine("i= " + valores[h]);
            //Percorre todos os valores do limite imposto
            foreach (var v in valores) Console.WriteLine("i=" + v);

            string[] clubes = {"Sporting, Porto, Benfica"};

            foreach (var s in clubes) Console.WriteLine("Todos os clubes:" + s);

            //ordernar
            //procurar

            var existe = false;
            for (var j = 0; j < valores.Length; j++)
                if (valores[j] == z)
                {
                    existe = true;
                    break;
                }

            foreach (var c in valores)
                if (c == y)
                {
                    existe = true;
                    break;
                }

            if (existe)
                Console.WriteLine("existe o valor pretentido");
            else
                Console.WriteLine("o valor nao existe");

            //mostrar

            MostraArray(clubes);

            //metodo de outra class
            Teste2.MostraArray2(clubes);

            #endregion
        }

        private static void MostraArray(string[] x)
        {
            foreach (var s in x) Console.WriteLine(s);
        }
    }

    internal class Teste2
    {
        public static void MostraArray2(string[] x)
        {
            foreach (var s in x) Console.WriteLine(s);
        }
    }
}