/*
 * autor : joao machado
 * purpose : arrays
 * 
 */


using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;



namespace AulaArray
{
    class Program
    {
        struct Aluno
        {
            public int numero;
            public string nome;

        }

        static void Main(string[] args)
        {
            #region ArraysSimples

            //int valores[40]; em c
            //int[] valores = new int[40]; uma forma para fazer um array
            int[] valores = new int[] { 1, 2, 3, 4 }; // outra forma
            valores[2] = valores[1] * 2;

            //array de struct
            Aluno[] turma = new Aluno[20];
            turma[0].numero = 10;
            turma[0].nome = "Ola";

            //mostrar alunos
            for(int i=0; i< turma.Length; i++)
            {
                Console.WriteLine("Nome: {0}   -   Numero: {1}", turma[i].nome, turma[i].numero.ToString());
            }

            //foreach(Tipo x in array) fazer{}

            foreach(Aluno a in turma)
            {
                Console.WriteLine("Nome: {0}   -   Numero: {1}", a.nome, a.numero.ToString());
            }

            //verificar se existe algo no array
            int x = 20;
            bool existe=false;

            foreach(int a in valores)
            {

                if (a == x)
                {
                    existe = true;
                    break;
                }

            }

            Console.WriteLine("{0}", (existe==true ? "sim" : "nao"));

            #endregion
        }

        /// <summary>
        /// Se existe um valor dentro do array 
        /// </summary>
        /// <param name="valores"></param>
        /// <param name="valor"></param>
        /// <returns></returns>
        public static bool Existe(int[] valores, int valor)
        {
            bool existe = false;
            foreach (int a in valores)
            {

                if (a == valor)
                {
                    existe = true;
                    break;
                }

            }

            /*
             for(int i=0; i<valores.Length; i++)
            {

                if(valores)

            }
            */
            return existe;
        }
    }
}
