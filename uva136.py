import queue

def main():
    q = queue.PriorityQueue()
    exists = set()

    q.put(1)
    i = 1

    while True:
        x = q.get()
        if i == 1500:
            print("The 1500'th ugly number is %d." % x)
            return
        i+=1

        for j in (2, 3, 5):
            x2 = x*j
            if x2 not in exists:
                exists.add(x2)
                q.put(x2)

main()
