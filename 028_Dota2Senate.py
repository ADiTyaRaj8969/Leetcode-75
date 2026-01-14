"""
Topic: Queue / Simulation
Dota2 Senate: simulate bans with two queues of indices
Time Complexity: O(n)
Space Complexity: O(n)
"""

from collections import deque

def predict_party_victory(senate: str) -> str:
    n = len(senate)
    rq = deque()
    dq = deque()
    for i, c in enumerate(senate):
        if c == 'R': rq.append(i)
        else: dq.append(i)
    while rq and dq:
        r = rq.popleft(); d = dq.popleft()
        if r < d:
            rq.append(r + n)
        else:
            dq.append(d + n)
    return 'Radiant' if rq else 'Dire'


if __name__ == '__main__':
    print(predict_party_victory('RD'))   # Radiant
    print(predict_party_victory('RDD'))  # Dire
