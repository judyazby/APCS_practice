import math
def all_even(s):
	ans = True
	for i in range(len(s)):
		if int(s[i]) % 2:
			ans = False
			break
	return ans

def find_pfs(n):
	
	if n ==1:	num = 2
	elif n % 2:	
		num = 10**((n-1)//2)
	else:
		num = int(math.sqrt(10**(n-1)))
		if num % 2:	num += 1
	# print('starts from',num)
	while not all_even(str(num**2)):
		num += 2
	return num**2

# print(all_even(str(26244)))

n = int(input())
for i in range(n):
	k = int(input())
	num = find_pfs(k)
	print(num)