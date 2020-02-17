using System;
using System.Windows.Media;

namespace MyCartographyObjects
{
	public class Polygon : CartoObj
	{
		//Variables Membres
		private Coordonnees[] _collection;
		private Color _remplissage;
		private Color _contour;
		private double _opacite;

		//Constructeurs
		public Polygon() : this(null,Colors.Black,Colors.Black,1)
		{

		}
		public Polygon(Coordonnees[] newCollection,Color newRemplissage,Color newContour,double newOpacite) : base()
		{
			Collection = newCollection;
			Remplissage = newRemplissage;
			Contour = newContour;
			Opacite = newOpacite;
		}

		//Propriétés
		public Coordonnees[] Collection
		{
			set { _collection = value; }
			get { return _collection; }
		}
		public Color Remplissage
		{
			set { _remplissage = value; }
			get { return _remplissage; }
		}
		public Color Contour
		{
			set { _contour = value; }
			get { return _contour; }
		}
		public double Opacite
		{
			set 
			{
				if(value > 0 && value < 1)
					_opacite = value; 
			}
			get { return _opacite; }
		}

		//Methodes
		public override void Draw()
		{
			Console.WriteLine(this);
		}
		//Surchage Opérateurs
		public override string ToString()
		{
			if (Collection == null)
				return string.Format("ID: {0}", Id) + " Collection: / " + "Remplissage: " + Remplissage + " Contour: " + Contour + string.Format(" Opacité: {0,3:0.0}",Opacite);
			else
				return string.Format("ID: {0}", Id) + " Collection: " + Collection + "Remplissage: " + Remplissage + " Contour: " + Contour + string.Format(" Opacité: {0,4:0.0}", Opacite);
		}
	}
}
