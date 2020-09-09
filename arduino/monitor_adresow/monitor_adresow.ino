#include <Wire.h>                                           //importujemy bibliotekę odpowiedzialną za uruchomienie I2C
 
byte blad, adres;                                           //definiujemy zmienne blad i adres jako byte (0-255)
int urzadzenia;                                             //definiujemy zmienną urzadzenia jako int
    
void setup()
{
  
  Wire.begin();                                              //uruchamiamy I2C
 
  Serial.begin(9600);                                        //uruchamiamy UART
  
  Serial.println("Skaner kodow I2C");                        //tytuł programu
  Serial.println("KURS I2C FERIAR-LABORATORY");
  Serial.println("========================");
}
 
 
void loop()
{
 
 
  Serial.println("Skanuje...");
 
  urzadzenia = 0;                                             //ilosc znalezionych urządzeń na początku wykonywania programu
                                                              //jest równa zero
  
  for(adres = 1; adres < 127; adres++ )                       //wykonaj funkcję od 1 do 127 co odpowiada ilości bitów
                                                              //bo 7 bit = > 7^2 = 127
  {
   
    Wire.beginTransmission(adres);                            //wyslij do urządzenia slave aktualną wartość zmiennej adres
    blad = Wire.endTransmission();                            //przypisz zmiennej blad, odczyt danych 
  
 
    switch (blad) 
    {
      
    case 0:                                                   //jak funkcja endTransmission zwróci wartość 0
    
       Serial.print("* Znaleziono urzadzenie o adresie 0x");
       if (adres<16)                                          //jezeli adres jest mniejszy od 16
       {
         Serial.print("0");                                   //wstaw 0
       }
       
       Serial.println(adres,HEX);                               //wydrukuj wartość zmniennej adres, pod którą wykryto urządzenie
                                                              //wartość zmiennej jest równoznaczna z adresem urządzenia
       urzadzenia++;                                          //inkrementuj zmienną urządzenia o 1 
     
    break;
 
      
    case 4:                                                  //jak funkcja endTransmission zwróci wartość 4
    
      Serial.print("Nieznany błąd przy adresie 0x");
      if (adres<16) 
      {
        Serial.print("0");
      }
      
      Serial.println(adres,HEX);
      
    break;
 
  
  }
 
      
 } 
 
  if (urzadzenia == 0)                                        //jezeli wartosc zmienniej urzadzenia jest 0 
  {
                
    Serial.println("Nie znaleziono zadnych urzadzen I2C");
    
  }
  
  Serial.println("===================================");
  delay(5000);                                                 //odczekaj 5 sekund
  
}
