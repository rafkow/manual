.Select(m => new[] { m.SK_NO, m.ITEM_NM, m.PLN_ITEM_NM }); // nowy anonimowy obiekt

.Distinct() // unikaty
.GroupBy() // IEnumerate<T>
