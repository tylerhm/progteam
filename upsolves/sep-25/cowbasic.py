import sys

MOD = int(1e9+7)

lines = [s.strip() for s in sys.stdin.readlines()]
lines = ["1 MOO {"] + lines + ["}"]
lines[len(lines)-2], lines[len(lines)-1] = lines[len(lines)-1], lines[len(lines)-2]

vars = {}
for line in lines:
    if "=" in line:
        var = line.split("=")[0].strip()
        if var not in vars:
            vars[var] = len(vars)

matsize = len(vars) + 1

def ident(n):
    R = [[0 for i in range(n)] for j in range(n)]
    for i in range(n):
        R[i][i] = 1
    return R

def mult(A, B):
    C = [[0 for i in range(len(A))] for j in range(len(B[0]))]
    for i in range(len(C)):
        for j in range(len(C[0])):
            for k in range(len(A[i])):
                C[i][j] = (C[i][j] + A[i][k]*B[k][j]) % MOD
    return C

def fastExpo(A, pow):
    if (pow == 0): return ident(matsize)
    if (pow == 1): return A;
    if (pow % 2 == 1): return mult(A, fastExpo(A, pow - 1))
    return fastExpo(mult(A, A), pow / 2)

def parse(pc):
    curline = lines[pc]
    mat = ident(matsize)
    if "=" in curline:
        curline = curline.replace("(", "").replace(")", "").replace("+", "").replace("=", "")
        while "  " in curline:
            curline = curline.replace("  ", " ")
        tokens = curline.strip().split(" ")
        var = vars[tokens[0]]
        mat[var][var] = 0
        for token in tokens[1:]:
            if token in vars: mat[var][vars[token]] += 1
            else: mat[var][matsize - 1] = (mat[var][matsize - 1] + int(token)) % MOD
        return (mat, pc + 1)
    elif "MOO" in curline:
        tokens = curline.split(" ")
        pw = int(tokens[0])
        pc += 1
        while '}' not in lines[pc]:
            A, pc = parse(pc)
            mat = mult(A, mat)

        return (fastExpo(mat, pw), pc+1)

A, r = parse(0)

toReturn = vars[lines[r].split(" ")[1]]
print(A[toReturn][matsize-1])
