.Select(m => new[] { m.SK_NO, m.ITEM_NM, m.PLN_ITEM_NM }); // nowy anonimowy obiekt

// przypisanie wartości wyznacoznym elementą 
result.Where(d => d.Location==null).ToList().ForEach(d => d.Location=Location.Default);


.Distinct() // unikaty
.GroupBy() // IEnumerate<T>
