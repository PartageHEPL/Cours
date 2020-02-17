using System;
using System.Windows.Media;

namespace MyCartographyObjects
{
	public class Polyline : CartoObj
	{
		//Variables Membres
		private Coordonnees[] _collection;
		private Color _couleur;
		private int _epaisseur;

		//Constructeurs
		public Polyline() : this(null,Colors.Black,1)
		{

		}
		public Polyline(Coordonnees[] newCoordonnees,Color newCouleur,int newEpaisseur) : base()
		{
			Collection = newCoordonnees;
			Couleur = newCouleur;
			Epaisseur = newEpaisseur;
		}
		//Propriétés
		public Coordonnees[] Collection
		{
			set { _collection = value; }
			get { return _collection; }
		}
		public Color Couleur
		{
			set { _couleur = value; }
			get { return _couleur; }
		}
		public int Epaisseur
		{
			set { _epaisseur = value; }
			get { return _epaisseur; }
		}

		//Méthode
		public override void Draw()
		{
			Console.WriteLine(this.ToString());
		}

		//Surcharge Opérateurs
		public override string ToString()
		{
			//Tester si la collection est null
			if(Collection == null)
				return string.Format("Id: {0}", Id) + " Collection: / " + "Couleur: " + Couleur + string.Format(" Epaisseur: {0}", Epaisseur);
			else
				return string.Format("Id: {0}",Id) + " Collection: " + Collection.ToString() + " Couleur: " + Couleur + string.Format(" Epaisseur: {0}",Epaisseur);
		}
	}
}
