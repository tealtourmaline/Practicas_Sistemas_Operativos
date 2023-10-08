using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace factorial_so
{
    class Program
    {
        static void Main(string[] args)
        {
            int nro; //$t0
            int res; //$t1
            int i = 1; //$t2
            Console.WriteLine("Número:");
            nro = int.Parse(Console.ReadLine());
            res = nro;

            while (nro > i)
            {
                nro = nro - i ;
                res = res * nro;
            }

            Console.WriteLine(res);

            Console.ReadKey();
        }
    }
}
