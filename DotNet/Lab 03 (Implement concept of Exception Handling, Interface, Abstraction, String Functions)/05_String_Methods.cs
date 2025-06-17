/* 5.(A) Write program showing use of common methods of String class.*/

class String_Methods
{
    public static void Main(string[] args)
    {
        string str = "Darshan University";

        System.Console.WriteLine($"Original String : {str}");
        System.Console.WriteLine($"Uppercase String : {str.ToUpper()}");
        System.Console.WriteLine($"Lowercase String : {str.ToLower()}");
        System.Console.WriteLine($"String Length : {str.Length}");
        System.Console.WriteLine($"String Contains \"University\" : {str.Contains("University")}");
        System.Console.WriteLine($"String Starts With \"Darshan\" : {str.StartsWith("Darshan")}");
        System.Console.WriteLine($"String Ends With \"University\" {str.EndsWith("University")}");
        System.Console.WriteLine($"String Index Of \"University\" : {str.IndexOf("University")}");
    }
}