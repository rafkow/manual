using CsvHelper;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace ArchiwumSprawSadowych {
    class CsvMenage {
        public static void FileCreataor() {
            using(FileStream fs = File.Create(@"lokator.txt")) {
                fs.Write(new UTF8Encoding().GetBytes("elo"), 0, 3);
            }
        }

        public static void ReadCSV() {
            string myname = "żółć";
            Console.WriteLine(myname);
            List<string> lines = new List<string>();
            if(File.Exists(@"Doradca\Repetytorium17.csv"))
                using(StreamReader reader = new StreamReader(@"Doradca\Repetytorium17.csv", Encoding.UTF8))
                    while(!reader.EndOfStream)
                        lines.Add(reader.ReadLine());

            List<string[]> splited = new List<string[]>();

            foreach(string line in lines) {
                splited.Add(line.Split(separator: new char[] {';'}, count:3));
            }
            Console.WriteLine("done");
        }
    }
}
