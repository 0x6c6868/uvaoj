def main():
    oper_n = int(input())
    for _ in range(oper_n):
        n = int(input())
        rst = list()
        for _ in range(n):
            s = input()
            if s == "PUSH":
                rst.append(set())

            elif s == "DUP":
                t = rst.pop()
                rst.append(t)
                rst.append(t)

            elif s == "UNION":
                t1 = rst.pop()
                t2 = rst.pop()

                rst.append(t1 | t2)

            elif s == "INTERSECT":
                t1 = rst.pop()
                t2 = rst.pop()

                rst.append(t1 & t2)

            elif s == "ADD":
                t1 = rst.pop()
                t2 = rst.pop()

                t2.add(id(t1))
                rst.append(t2)

            print(len(rst[-1]))

        print("***")

main()
