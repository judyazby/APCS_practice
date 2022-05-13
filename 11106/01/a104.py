##N = int(input())
##if N == 1:  print(1)
##elif N == 2:  print(5)
##else: 
##  s, t, ans = 12, 4, 5
##  for _ in range(N-2):
##    t += s
##    ans += t
##    s *= 4
##  print(ans)

N = int(input())
s, t, ans = 3, 1, 1

for _ in range(N-1):
  t += s
  ans += t
  s *= 4
print(ans)
