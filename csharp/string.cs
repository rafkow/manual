@ - multiline string
string przyklad = @"to jest
napis wielo-
liniowy"

$ - wstaw zmienne w string
int liczba = 5;
Console.WriteLine($"to jest brakująca {liczba} liczba");


Console.WriteLine($"{DateTime.Now,  25} Hello World"); //       07/16/2021 06:59:32 Hello World
Console.WriteLine($"{DateTime.Now, -25} Hello World"); // 07/16/2021 06:58:45       Hello World

// just two decimal places
String.Format("{0:0.00}", 123.4567);      // "123.46"
String.Format("{0:0.00}", 123.4);         // "123.40"
String.Format("{0:0.00}", 123.0);         // "123.00"
// max. two decimal places
String.Format("{0:0.##}", 123.4567);      // "123.46"
String.Format("{0:0.##}", 123.4);         // "123.4"
String.Format("{0:0.##}", 123.0);         // "123"
// max. two decimal places
String.Format("{0:0.##}", 123.4567);      // "123.46"
String.Format("{0:0.##}", 123.4);         // "123.4"
String.Format("{0:0.##}", 123.0);         // "123"
String.Format("{0:0,0.0}", 12345.67);     // "12,345.7"
String.Format("{0:0,0}", 12345.67);       // "12,346"
String.Format("{0:0.0}", 0.0);            // "0.0"
String.Format("{0:0.#}", 0.0);            // "0"
String.Format("{0:#.0}", 0.0);            // ".0"
String.Format("{0:#.#}", 0.0);            // ""
String.Format("{0,10:0.0}", 123.4567);    // "     123.5"
String.Format("{0,-10:0.0}", 123.4567);   // "123.5     "
String.Format("{0,10:0.0}", -123.4567);   // "    -123.5"
String.Format("{0,-10:0.0}", -123.4567);  // "-123.5    "
String.Format("{0:0.00;minus 0.00;zero}", 123.4567);   // "123.46"
String.Format("{0:0.00;minus 0.00;zero}", -123.4567);  // "minus 123.46"
String.Format("{0:0.00;minus 0.00;zero}", 0.0);        // "zero"
tring.Format("{0:my number is 0.0}", 12.3);   // "my number is 12.3"
String.Format("{0:0aaa.bbb0}", 12.3);          // "12aaa.bbb3"
