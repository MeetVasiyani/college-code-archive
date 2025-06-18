/*4.(A) Create a class Hospital with HospitalDetails() method. Create another classes Apollo, Wockhardt, Gokul_Superspeciality which 
overrides HospitalDetails() method.*/

class Hospital
{
    public virtual void HospitalDetails()
    {
        System.Console.WriteLine("Hospital Class");
    }
}

class Apollo : Hospital
{
    public override void HospitalDetails()
    {
        System.Console.WriteLine("Apollo Hospital");
    }
}

class Wockhardt : Hospital
{
    public override void HospitalDetails()
    {
        System.Console.WriteLine("Wockhardt Hospital");
    }
}

class Gokul_Superspeciality : Hospital
{
    public override void HospitalDetails()
    {
        System.Console.WriteLine("Gokul Superspeciality");
    }
}

class Hospital_Override
{
    public static void Main(string[] args)
    {
        Hospital hospital = new();
        Apollo apollo = new();
        Wockhardt wockhardt = new();
        Gokul_Superspeciality gokul = new();

        hospital.HospitalDetails();
        apollo.HospitalDetails();
        wockhardt.HospitalDetails();
        gokul.HospitalDetails();
        
    }
}