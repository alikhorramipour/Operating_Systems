numbers = [50, 62, 64, 78, 95, 100, 102, 119, 123, 180, 11, 34]
sum = 0

for x in xrange(0, len(numbers) - 1):
	sum += abs(numbers[x] - numbers[x+1])

print("Sum is = ", sum)
