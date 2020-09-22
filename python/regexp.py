import re

expression = '[A-Z]'
matches = re.findall(expression, "NazwaProjektu")
print(matches)
print(str().join(matches[:]))
