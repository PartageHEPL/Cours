using System;


namespace MyCartographyObjects
{
    public class Coordonnees : CartoObj
    {
        //Variables membres
        public double _latitude;
        public double _longitude;

		//Contructeurs
		public Coordonnees() : this(0.000, 0.000)
		{

		}
		public Coordonnees(double newLatitude,double newLongitude) : base()
		{
			Latitude = newLatitude;
			Longitude = newLongitude;
		}
		public Coordonnees(Coordonnees copie) : this(copie.Latitude,copie.Longitude)
		{

		}
		
        //Propriétés
        public double Latitude
        {
            set { _latitude = value; }
            get { return _latitude; }
        }
        public double Longitude
        {
            set { _longitude = value; }
            get { return _longitude; }
        }

		//Surcharge Opérateurs
		public override string ToString()
		{
			return string.Format("Id: {0} Coordonnees({1,6:0.000};{2,6:0.000})",Id,Latitude,Longitude);
		}
	}
}
