using System.Runtime.Serialization;

namespace Aula4
{
    public class Opers
    {
        public static double Average(int[] valores)
        {
            int s = 0;
            double av;
            foreach (var x in valores)
            {
                s += x; // s=s+x
            }

            av = (double)s / valores.Length;
            return av;
        }

        public static double Soma(int x, int z)
        {
            return (x + z);

        }
    }
}