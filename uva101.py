pile = list()

def find_block(a):
    global pile
    for i_i, i_v in enumerate(pile):
        for j_i, j_v in enumerate(i_v):
            if a == j_v:
                return i_i, j_i
    return None, None

def clear_above(p, h):
    global pile
    for i in range(h+1, len(pile[p])):
        b = pile[p][i]
        pile[int(b)].append(b)
    pile[p][h+1:] = []

def pile_onto(p, h ,p2):
    global pile
    for i in range(h, len(pile[p])):
        pile[p2].append(pile[p][i])
    pile[p][h:] = []

def print_pile():
    global pile
    for i, v in enumerate(pile):
        if v:
            print("%s: %s" % (i, " ".join(v)))
        else:
            print("%s:" % i)

def main():
    n = int(input())
    global pile
    pile = [[str(i),] for i in range(n)]

    while True:
        tmp = input()
        if tmp == "quit":
            print_pile()
            exit(0)
        s1, a, s2, b = tmp.split()

        pa, ha = find_block(a)
        pb, hb = find_block(b)

        if pa==pb: continue

        if s2 == "onto": clear_above(pb, hb)
        if s1 == "move": clear_above(pa, ha)

        pile_onto(pa, ha, pb)

main()
