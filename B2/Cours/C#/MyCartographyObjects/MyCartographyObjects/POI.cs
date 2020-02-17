using System;

namespace MyCartographyObjects
{
	public class POI : Coordonnees
	{
		//Variables membres
		private string _description;

		//Contructeurs
		public POI() : this("Quai Gloesener",new Coordonnees(50.620090, 5.581406))
		{
			Description = null;
		}
		public POI(string newDescription, Coordonnees newCoordonnees) : base(newCoordonnees.Latitude,newCoordonnees.Longitude)
		{
			Description = newDescription;
		}
		public POI(POI copie) : this(copie.Description, new Coordonnees(copie.Latitude,copie.Longitude))
		{

		}

		//Propriétés
		public string Description
		{
			set { _description = value; }
			get { return _description; }
		}

		//Surcharge Opérateurs
		public override string ToString()
		{
			if (Description == null)
				return string.Format("Id: {0}",Id) + " Desciprtion: / " + string.Format("Coordonnees({0,6:0.000};{1,6:0.000})",Latitude, Longitude);
			else
				return string.Format("Id: {0}", Id) + " Desciption: " + Description + " " + string.Format("Coordonnees({0,6:0.000};{1,6:0.000})",Latitude, Longitude);
		}
	}
}
