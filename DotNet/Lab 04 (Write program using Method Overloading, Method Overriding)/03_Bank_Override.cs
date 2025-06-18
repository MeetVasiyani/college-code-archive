class RBI
{
    public virtual int CalculateInterest(int deposit)
    {
        return deposit * 10 * 1 / 100;
    }
}

class SBI : RBI
{
    public override int CalculateInterest(int deposit)
    {
        return deposit * 5 * 1 / 100;

    }
}

class HDFC : RBI
{
    public override int CalculateInterest(int deposit)
    {
        return deposit * 2 * 1 / 100;
    }
}

class ICICI : RBI
{
    public override int CalculateInterest(int deposit)
    {
        return deposit * 15 * 1 / 100;
    }
}

class Bank_Override
{
    public static void Main(string[] args)
    {
        RBI rbi = new RBI();
        SBI sbi = new SBI();
        HDFC hdfc = new HDFC();
        ICICI icici = new ICICI();

        System.Console.WriteLine("Interest on RBI is: " + rbi.CalculateInterest(10000));
        System.Console.WriteLine("Interest on SBI is: " + sbi.CalculateInterest(10000));
        System.Console.WriteLine("Interest on HDFC is: " + hdfc.CalculateInterest(10000));
        System.Console.WriteLine("Interest on ICICI is: " + icici.CalculateInterest(10000));
    }
}