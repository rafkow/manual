Console.WriteLine(new DateTime(2013,1,1).ToString("yyyy-MM-dd'T'HH:mm:ss.fffffff'Z'"));
2013-01-01T00:00:00.0000000Z

DateTime.ParseExeact(string, 'yyyyMMdd') // wybierasz format wprowadzonej daty do parsowania

MMM - sty
MMMM - styczeń

// zwraca liczbę dni
(Exp_date-Begin_date).TotalDays;

public IEnumerable<DateTime> EachDay(DateTime from, DateTime thru)
{
    for(var day = from.Date; day.Date <= thru.Date; day = day.AddDays(1))
        yield return day;
}

foreach (DateTime day in EachDay(StartDate, EndDate))
    // print it or whatever
