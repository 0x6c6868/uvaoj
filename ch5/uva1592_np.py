def my_input():
    try:
        return input()
    except:
        return False

def main():
    while True:
        n=my_input()

        if n is False:
            return

        col, row = list(map(int, n.split()))

        l=[]
        for i in range(col):
            t = my_input()
            tl = t.split(",")
            l.append(tl)

        def _f(l):
            d = dict()
            l = list(zip(*l))
            for i, iv in enumerate(l):
                for j, jv in enumerate(l):
                    if i == j: continue

                    for x in range(col):
                        t = iv[x] + "_________" + jv[x]
                        if t in d:
                            print("NO")
                            print(d[t]+1, x+1)
                            print(i+1, j+1)
                            return False
                        d[t] = x

            return True

        if _f(l): print("YES")

main()
