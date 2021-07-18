@ - multiline string
string przyklad = @"to jest
napis wielo-
liniowy"

$ - wstaw zmienne w string
int liczba = 5;
Console.WriteLine($"to jest brakująca {liczba} liczba");


Console.WriteLine($"{DateTime.Now,  25} Hello World"); //       07/16/2021 06:59:32 Hello World
Console.WriteLine($"{DateTime.Now, -25} Hello World"); // 07/16/2021 06:58:45       Hello World
