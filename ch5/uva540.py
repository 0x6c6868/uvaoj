import queue

def main():
    task_no=0
    while True:
        q_n = int(input())
        if q_n == 0:
            return

        team = dict()
        for i in range(q_n):
            tmp = input()
            tmp = tmp.split()
            n = int(tmp[0])
            for j in range(n):
                team[tmp[j+1]] = i

        task_no += 1
        print("Scenario #%d" % task_no)
        q = queue.Queue()
        q2 = [queue.Queue() for _ in range(q_n)]
        while True:
            tmp = input()
            if tmp == "STOP":
                break
            elif tmp == "DEQUEUE":
                t = q.queue[0]
                print(q2[t].get())

                if q2[t].empty():
                    q.get()

            else:
                oper, x = tmp.split()
                t = team[x]

                if q2[t].empty():
                    q.put(t)

                q2[t].put(x)

        print("")

main()
