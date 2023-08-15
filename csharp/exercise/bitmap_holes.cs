// Have the function BitmapHoles(strArr) take the array of strings stored in strArr, which will be a 2D matrix of 0 and 1's, and determine how many holes, or contiguous regions of 0's, exist in the matrix. A contiguous region is one where there is a connected group of 0's going in one or more of four directions: up, down, left, or right. For example: if strArr is ["10111", "10101", "11101", "11111"], then this looks like the following matrix:

// 1 0 1 1 1
// 1 0 1 0 1
// 1 1 1 0 1
// 1 1 1 1 1

// For the input above, your program should return 2 because there are two separate contiguous regions of 0's, which create "holes" in the matrix. You can assume the input will not be empty. 


using System;
using System.Linq;

class MainClass {

  public static int BitmapHoles(string[] strArr) {
    int row_of_zeros_length = 0;
    string sample = "0";
    foreach(string row in strArr){
      while(true){
        if(row.Contains(sample)){
          row_of_zeros_length +=1;
          sample += "0";
          continue;
        }
        break;
      }
    }

    if(row_of_zeros_length < strArr.Length )    
      for(int i=0; i < strArr[0].Length; i++){
        var column = strArr.Select(row => row[i]).ToArray();
        while(true){
          if(new string(column).Contains(sample)){
            row_of_zeros_length +=1;
            sample += "0";
            continue;
          }
          break;
        }
      }
    return row_of_zeros_length;

  }

  static void Main() {  
    // keep this function call here
    Console.WriteLine(BitmapHoles(Console.ReadLine()));
  } 

}