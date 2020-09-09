variable = 0b11111111
#variable = 15
motor0 = 0b00001101

print(0b10001111)
print(bin(variable | 7<<4))  	# wstawia zawsze jedynke w maske
print(bin(motor0 ^ 5))			# maska wstawia 0 jezeli sa 2 prawdziwe
print(bin(variable & motor0))
print(bin(variable & 1<<3))
print(bin(variable & 0b10001111)) # to jest prawdziwe and

print('gear test ')
print(bin((6 - 1) << 4))
print(bin((6 - 2) << 4))
print(bin((6 - 3) << 4))
print(bin((6 - 4) << 4))
print(bin((6 - 5) << 4))
print(bin((6 - 6) << 4))


def BitRevers(var): # revers bit
	if (var>>3 & 1):
		print('bylo {0} jest {1}'.format(var, (var ^ 1<<3)))
	else:
		print('nie bylo {0} jest {1}'.format(var, (var | 1<<3)))

if not variable & 1<<0:
	print("udalo sie")

print(bin(variable | 1<<1))

BitRevers(16)