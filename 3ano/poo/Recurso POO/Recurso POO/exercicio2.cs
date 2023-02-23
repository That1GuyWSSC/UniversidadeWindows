using System;
using System.Data.SqlTypes;

namespace Recurso_POO
{
    public class exercicio2
    {
        static void Main()
        {
            int cont = 0, contpair = 0;
            int[] valores;
            valores = new int[100];
            
            Console.WriteLine("Este progama acaba apos a insersao do numero ZERO");
            Console.WriteLine("Por favor insira um numeros");
          

            for (int i = 0; i < valores.Length; i++)
            {
                string inputString = Console.ReadLine();
                int numeros = int.Parse(inputString);
                valores[i] = numeros;
                if (valores[i] == 0)
                {
                    Console.WriteLine("stop");
                    break;
                }
                cont++;
                if (valores[i] % 2 == 0)
                {
                    contpair++;
                }
            }

            int aux = -1;
            for (int i = 0; i < valores.Length; i++)
            {
                aux = valores[i];
                if (aux < valores[i++])
                {
                    aux = valores[i++];
                }
                
            }

            int x = 0;
            foreach (var s in valores)
            {
                
            }
            //Console.WriteLine(" {0} ",aux);
            
            Console.WriteLine("Foram inseridos numeros : {0}", cont);
            Console.WriteLine("Foram inseridos {0} numeros pares", contpair);

        }
    }
}