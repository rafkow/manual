Poprawna konfiguracja wyświetli widok bazy danych w
Server-Explorer ctrl+W,L

Zainstaluj z Package-Manager
Install-Package MySQL.Data -Version 6.9.9
Install-Package MySql.Data.Entity -Version 6.9.10

Install-Package Microsoft.EntityFrameworkCore
Install-Package Microsoft.EntityFrameworkCore.Tools
Install-Package Oracle.EntityFrameworkCore



Enable-Migrations
Add-Migration [-Context PTWContext] [nazwa migracji]
Update-Database

Scaffold-DbContext "PASSWORD=Eurochem;USER ID=ECM;DATA SOURCE=oradb.pl.indorama.net:1521/skecm" Oracle.EntityFrameworkCore -OutputDir Models -Tables GB_COMPANY,GB_COMPANY_OBJ,GB_ENTER_REGISTER,GB_INVITATIONS,GB_VISIT,GB_VISIT2OBJ
Scaffold-DbContext "PASSWORD=Vigran;USER ID=Vigran;DATA SOURCE=oradb.pl.indorama.net:1521/skecm" Oracle.EntityFrameworkCore -OutputDir Models


builder.Services.AddDbContext<PTWContext>(options =>
    options.UseOracle(@"User Id=RK;Password=RKOWALEWSKI;Data Source=oradb.pl.indorama.net:1521/poligon.pl.indorama.net", b => b.UseOracleSQLCompatibility("12"))
);

protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
       {
           optionsBuilder.UseOracle(@"User Id=RK;Password=RKOWALEWSKI;Data Source=oradb.pl.indorama.net:1521/poligon.pl.indorama.net", b => b.UseOracleSQLCompatibility("12");
           base.OnConfiguring(optionsBuilder);
       }
