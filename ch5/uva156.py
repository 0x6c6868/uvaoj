def my_input():
    try:
        return input()
    except:
        return False

def repr(s):
    t = list(s.lower())
    t.sort()
    return "".join(t)

def main():
    cnt = dict()
    words = list()
    while True:
        tmp=my_input()

        if tmp is False or tmp == "#":
            break

        for w in tmp.split():
            words.append(w)
            r = repr(w)
            cnt[r] = cnt.get(r, 0)+1

    ans = [t for t in words if cnt[repr(t)] == 1]
    ans.sort()
    list(map(print, ans))

main()
