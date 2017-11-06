def my_input():
    try:
        return input()
    except:
        return False

def main():
    rst=set()
    while True:
        tmp=my_input()

        if tmp is False:
            rst=list(rst)
            rst.sort()
            list(map(lambda x: print(x) if x else None, rst))
            exit(0)

        tmp=list(tmp)
        for i, v in enumerate(tmp):
            if not v.isalpha():
                tmp[i]=" "

        tmp = "".join(tmp)
        array = [a.lower() for a in tmp.split()]

        rst.update(array)

main()
