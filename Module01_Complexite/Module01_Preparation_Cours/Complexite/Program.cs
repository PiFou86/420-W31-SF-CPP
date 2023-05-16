// See https://aka.ms/new-console-template for more information


using System;
using Humanizer;
using Humanizer.Localisation;

int[] nombresElements = { 10, 100, 1_000, 10_000, 100_000, 1_000_000 };
long nombreInstructionsParSecond = 1_000_000_000;
long nombreOperationsParAlgorithme = 10_000;

Dictionary<string, Func<double, double>> formatNombres = new Dictionary<string, Func<double, double>>(){
    {"O(1)", (double n) => nombreOperationsParAlgorithme / nombreInstructionsParSecond},
    {"O(log(n))", (double n) => Math.Log2(n) * nombreOperationsParAlgorithme / nombreInstructionsParSecond},
    {"O(n)", (double n) => n * nombreOperationsParAlgorithme / nombreInstructionsParSecond},
    {"O(n log n)", (double n) => (n * Math.Log2(n) * nombreOperationsParAlgorithme / nombreInstructionsParSecond)},
    {"O(n^2)", (double n) => (n * n * nombreOperationsParAlgorithme / nombreInstructionsParSecond)},
    {"O(n^3)", (double n) => (n * n * n * nombreOperationsParAlgorithme / nombreInstructionsParSecond)},
    {"O(2^n)", (double n) => (Math.Pow(2, n) * nombreOperationsParAlgorithme / nombreInstructionsParSecond)}
};

foreach (var nombre in nombresElements) {
    Console.Write($";{nombre}");
}
Console.WriteLine();

foreach (var formatNombre in formatNombres)
{
    Console.Write($"{formatNombre.Key}");
    foreach (var nombre in nombresElements)
    {
        double temps = formatNombre.Value(nombre);
        string tempsFormateString = temps.ToString();

        if (temps < .001) {
            temps = temps * 1000;
            tempsFormateString = $"{temps} µs";
        } else if (temps > 60*60*24*365)
        {
            temps = temps / 60 / 60 / 24 / 365;
            tempsFormateString = $"{temps} ans";

            if (temps > 1000) {
                temps = (long)temps / 1000;
                tempsFormateString = $"{temps} millénaires";
            }
        } else {
            TimeSpan tempsFormate = TimeSpan.FromSeconds(temps);
            tempsFormateString = tempsFormate.Humanize(2, minUnit: TimeUnit.Millisecond);
        }
        Console.Write($";{tempsFormateString}");
    }
    Console.WriteLine();
}
