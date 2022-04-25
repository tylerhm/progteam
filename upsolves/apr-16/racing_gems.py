import matplotlib.pyplot as plt

n, r, w, h = [int(x) for x in input().split()]
xs = []
ys = []
for i in range(n):
    x, y = [int(x) for x in input().split()]
    xs.append(x)
    ys.append(y)

plt.scatter(xs, ys)
plt.show()
