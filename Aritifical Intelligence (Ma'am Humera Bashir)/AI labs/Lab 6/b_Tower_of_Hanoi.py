def hanoi(n, src, aux, dest):
    if n == 1:
        print("Move disk 1 from", src, "to", dest)
        return
    hanoi(n - 1, src, dest, aux)
    print("Move disk", n, "from", src, "to", dest)
    hanoi(n - 1, aux, src, dest)


hanoi(5, "A", "B", "C")
