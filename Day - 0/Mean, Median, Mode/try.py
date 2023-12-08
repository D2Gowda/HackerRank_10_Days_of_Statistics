n = int(input().strip())
a = [int(x) for x in input().strip().split(' ')]
a.sort()

mean = sum(a) / len(a)
mid = len(a) // 2

if len(a) % 2 != 0:
    median = a[mid]
else:
    median = (a[mid] + a[mid - 1]) / 2

count = 0
mode = a[0]

for ele in a:
    if a.count(ele) > count:
        count = a.count(ele)
        mode = ele
    elif a.count(ele) == count:
        mode = min(ele, mode)

print(round(mean, 1))
print(round(median, 1))
print(mode)