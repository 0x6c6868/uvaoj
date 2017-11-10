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

        n = int(n)
        print("-"*60)
        M=0
        l=list()
        for _ in range(n):
            w = my_input()
            l.append(w)
            M = max(M, len(w))

        cols = int((60 - M)/(M+2)) + 1
        rows = int((n-1)/cols) + 1

        l.sort()

        for r in range(rows):
            t = ""
            for c in range(cols):
                idx = c * rows + r
                if idx < n:
                    t += (l[idx] + ' '*(M-len(l[idx])+2))
            print(t)

main()
