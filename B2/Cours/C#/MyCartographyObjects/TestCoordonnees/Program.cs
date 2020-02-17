using System;
using System.Threading;
using MyCartographyObjects;

namespace TestCoordonnees
{
    class Program
    {
        static void Main(string[] args)
        {
			Coordonnees c1 = new Coordonnees();
			Coordonnees c2 = new Coordonnees(1, 2);
			Console.WriteLine(c1);
			Console.WriteLine(c2);
			c1._latitude = 0;
			c1.Longitude = 10.12345;
			Console.WriteLine(c1);
			Console.WriteLine(c2);
			POI p1 = new POI("Coucou",new Coordonnees(10, 14.5892));
			POI p2 = new POI(p1);
			Console.WriteLine(p1);
			Console.WriteLine(p2);

			Polyline p = new Polyline();
			Console.WriteLine(p);

			Polygon poly1 = new Polygon();
			poly1.Draw();

			Thread.Sleep(10000);
		}
    }
	
}

