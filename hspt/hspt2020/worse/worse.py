import sys

def solve():

    # Get the full line from input
    word = sys.stdin.readline()

    # Remove newline from end
    word.rstrip('\n')

    # Split it by space
    letters = word.split()

    # For every letter, add it's length to A and append
    ans = ""
    for l in letters:
        ans+=chr(ord('A')+len(l)-1)
    print(ans)

if __name__ == "__main__":
    cases = int(input())
    for _ in range(cases):
        solve()