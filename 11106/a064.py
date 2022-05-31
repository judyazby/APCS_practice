n = int(input())
a = list(map(int, input().split()))
good = 101
bad = -1
a.sort()
for s in a:
  if s >= 60 and s < good:  good = s
  if s < 60 and s > bad:  bad = s
print(' '.join([str(s) for s in a]))
print('best case' if bad == -1 else bad)
print('worst case' if good == 101 else good)
