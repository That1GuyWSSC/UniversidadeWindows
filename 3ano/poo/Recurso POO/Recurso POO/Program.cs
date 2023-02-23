using System;
using System.Xml;

namespace Recurso_POO
{
    internal class Exercicio1
    {
        public static void Main(string[] args)
        {
            int idade = 20;
            string dataNascimento = "13/11/2002";
            string meuNome = "Joao";
            
            Console.WriteLine("A minha idade : {0}, a minha data de nascimento : {1}, e o meu nome : {2} ", idade, dataNascimento,meuNome);
            
            Console.WriteLine("Por favor escreve o teu nome e a data de nascimento ( dia / mes / ano) ");
            string teuNome = Console.ReadLine();
            string teuDia = Console.ReadLine();
            string teuMes = Console.ReadLine();
            string teuAno = Console.ReadLine();

            int tDia = Int32.Parse(teuDia);
            int tMes = Int32.Parse(teuMes);
            int tAno = Int32.Parse(teuAno);

            int ano = 2023, mes = 2, dia = 5;

            if (tAno > ano)
            {
                Console.WriteLine("Escreve uma idade valida");
            }

            Console.WriteLine("{0},{1}", teuNome,ano-tAno);
            

        }
    }
}