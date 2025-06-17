/*6. (B) Write a program to calculate Celsius to Fahrenheit and vice-versa using function.*/

static double convertCelsiusToFahrenheit(double celsius)
{
    return (celsius * (9 / 5)) + 32;
}

static double convertFahrenheitToCelsius(double fahrenheit){
    return (fahrenheit - 32)*(5/9);
}

Console.WriteLine("Enter 1 for Celsius to Fahrenheit\nEnter 2 for Fahrenheit to Celsius");
int temp = Convert.ToInt32(Console.ReadLine());
switch (temp)
{
    case 1:
        Console.WriteLine("Enter temperature in Celcius : ");
        double celsius = Convert.ToDouble(Console.ReadLine());
        System.Console.WriteLine($"Temperature in Fahrenheit : {convertCelsiusToFahrenheit(celsius)}");
        break;
    case 2:
        Console.WriteLine("Enter temperature in Fahrenheit : ");
        double fahrenheit = Convert.ToDouble(Console.ReadLine());
        System.Console.WriteLine($"Temperature in Celcius : {convertFahrenheitToCelsius(fahrenheit)}");
        break;

    default:
        System.Console.WriteLine("Invalid input");
        break;
}