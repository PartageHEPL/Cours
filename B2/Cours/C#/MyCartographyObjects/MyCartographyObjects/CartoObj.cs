using System;

namespace MyCartographyObjects
{
	public abstract class CartoObj
	{
		//Variables memebres
		private static int compteur = 0;
		private int _id;

		//Constructeurs
		public CartoObj()
		{
			compteur++;
			_id = compteur;
		}
		
		//Propriétés
		//On ne met pas de set pour éviter de pouvoir modifier l'id
		//car c'est le constructeur qui s'en charge et deux instance
		//du meme objet ne peuvent pas avoir le meme id
		public int Id
		{
			get { return _id; }
		}

		//Méthodes
		public virtual void Draw()
		{
			Console.WriteLine(this);
		}

		//Surcharge Opérateurs
		public override string ToString()
		{
			return string.Format("{0}",Id);
		}
	}
}

