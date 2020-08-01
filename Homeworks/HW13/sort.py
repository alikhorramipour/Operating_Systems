numbers = [] #[50, 95, 180, 34, 119, 11, 123, 62, 64, 100, 78, 102]
tmp = 0
tmp = int(input("Enter the numbers you want to be sorted (finish is fockin terminal):\n"))
while True:
    if tmp == "finish":
        break
    numbers.append(int(tmp))
    tmp = input()

numbers.sort()

print("Sorted:\n\n", numbers)

sum = 0

for x in xrange(0, numbers.length() - 1):
	sum += abs(numbers[x] - numbers[x+1])

print("Sum is = ", sum)