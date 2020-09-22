import re
from os import linesep

begin = '{'
end = '}'
project = 'WorkApproval'
table = 'wapp_sheet'
entity = 'WAppSheet'

column = """
ID
WORK_TIME
PLACE
MACHINE
DESCRIPTON
MOC
WORK_TYPE
TOOLS
OTHER_TOOLS
RISK
PROFFESION
EXECUTOR_NAME
EXTRA_PERMISSION
KONTAKT
FIREWORK_PERMISSON_NO
DEEPWORK_PERMISSION_NO
INTERLOCK_NO
LOCKOUT_NO
SCAFFOLDING_NO
START_DATE
END_DATE
APPROVE_DATE
JOB_DONE
JOB_ACCEPT
SIGN
"""

properties = [ word for word in column.split()]
dubledot_properties = [f':{prop}' for prop in properties]
properties_and_values = [f'{prop}=:{prop}' for prop in properties if prop != "ID"]

def ParametersGenerator():
    parameters_set = ''
    for prop in properties:
        parameters_set = parameters_set + f'    command.Parameters.Add("{prop}", item.{prop});{linesep}'
    return parameters_set



for word in properties:
    print('public string '+ word + '{ get; set; }')

print()
print("tworzenie")
print()

print(f'public void Add{entity}({entity} item)')
print('{')
print(f'    {project}DB.{project}DB.Instance.Add{entity}(item);')
print('}')

dbmethod = f"""

public void Add{entity}({entity} item) {begin}
    string query = "INSERT INTO {table} ({properties.__str__()[1:-1].replace("'","")}) "+
                   "VALUES ({dubledot_properties.__str__()[1:-1].replace("'","")})";
    OracleCommand command = new OracleCommand();
    command.CommandType=System.Data.CommandType.Text;
    command.CommandText=query;
    command.BindByName=true;
    {ParametersGenerator()}
    command.Connection=GetOracleConnection();
    SendToDB(command);
{end}

"""
print(dbmethod)

print()
print("pobierz wszystkie")
print()

print(f'public List<{entity}> GetAll{entity}()')
print('{')
print(f'    return {project}DB.{project}DB.Instance.GetAll{entity}();')
print('}')

dbmethod = f"""

public List<{entity}> GetAll{entity}() {begin}
    string query = "select {properties.__str__()[1:-1].replace("'","")} from {table}";
    OracleCommand command = new OracleCommand {begin}
        CommandType=System.Data.CommandType.Text,
        CommandText=query,
        BindByName=true,
        Connection=GetOracleConnection()
    {end};
    return ReflectPropertyInfo.ReflectTypeList<{entity}>(command);
{end}

"""
print(dbmethod)

print()
print("pobierz wybrany")
print()

print(f'public {entity} Get{entity}(int id)')
print('{')
print(f'    return {project}DB.{project}DB.Instance.Get{entity}(id);')
print('}')

dbmethod = f"""

public {entity} Get{entity}(int id) {begin}
    string query = "select {properties.__str__()[1:-1].replace("'","")} from {table} where id=:id";
    OracleCommand command = new OracleCommand {begin}
        CommandType=System.Data.CommandType.Text,
        CommandText=query,
        BindByName=true,
        Connection=GetOracleConnection()
    {end};
    command.Parameters.Add("id", id);
    return ReflectPropertyInfo.ReflectType<{entity}>(command);
{end}

"""
print(dbmethod)

print()
print(10*'=', " pobierz wybrane ", 10*'=' )
print()

print(f'public List<{entity}> GetSelected{entity}(int id)')
print('{')
print(f'    return {project}DB.{project}DB.Instance.GetSelected{entity}(id);')
print('}')

dbmethod = f"""

public List<{entity}> GetSelected{entity}(int id) {begin}
    string query = "select {properties.__str__()[1:-1].replace("'","")} from {table} where id=:id";
    OracleCommand command = new OracleCommand {begin}
        CommandType=System.Data.CommandType.Text,
        CommandText=query,
        BindByName=true,
        Connection=GetOracleConnection()
    {end};
    command.Parameters.Add("id", id);
    return ReflectPropertyInfo.ReflectTypeList<{entity}>(command);
{end}

"""
print(dbmethod)

print()
print(f"{'='*10} edytuj {'='*10}")
print()

print(f'public void Edit{entity}(int id)')
print('{')
print(f'    {project}DB.{project}DB.Instance.Edit{entity}(id);')
print('}')

dbmethod = f"""

public void Edit{entity}({entity} item) {begin}
    string query = "update {table} set {properties_and_values.__str__().replace("'","")[1:-1]} where id=:id";
    OracleCommand command = new OracleCommand();
    command.CommandType=System.Data.CommandType.Text;
    command.CommandText=query;
    command.BindByName=true;
{ParametersGenerator()}
    command.Connection=GetOracleConnection();
    SendToDB(command);
{end}

"""
print(dbmethod)

print()
print(f"{'='*10} usuń {'='*10}")
print()

print(f'public void Delete{entity}({entity} item)')
print('{')
print(f'    {project}DB.{project}DB.Instance.Delete{entity}(item);')
print('}')

dbmethod = f"""

public void Delete{entity}({entity} item) {begin}
    string query = "delete from {table} where id=:id";
    OracleCommand command = new OracleCommand();
    command.CommandType=System.Data.CommandType.Text;
    command.CommandText=query;
    command.BindByName=true;
    command.Parameters.Add("id", item.id);
    command.Connection=GetOracleConnection();
    SendToDB(command);
{end}

"""
print(dbmethod)
