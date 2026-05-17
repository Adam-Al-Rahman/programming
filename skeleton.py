import sys
import os

# ALIAS | PRECOMPUTE | HELPER FUNCTIONS

# PROBLEM KEYPOINTS
def solution(it, out):
    pass


def main():
    if os.path.exists('input.txt'):
        sys.stdin = open('input.txt', 'r')
        sys.stdout = open('output.txt', 'w')

    input_data = sys.stdin.read().split()
    if not input_data: return
        
    it = iter(input_data)
    out = []
    
    tests = 1
    tests = int(next(it)) # OVERWRITE
        
    for _ in range(tests): solution(it, out)
        
    if out: sys.stdout.write('\n'.join(out) + '\n')

if __name__ == '__main__':
    # sys.setrecursionlimit(200000) # RECURSION DEPTH
    main()
