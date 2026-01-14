"""
Topic: Queue / Sliding Window
Number of Recent Calls: implement class with queue storing timestamps
Time Complexity: O(1) amortized per call
Space Complexity: O(n) where n is number of recent calls
"""

from collections import deque

class RecentCounter:
    def __init__(self):
        self.q = deque()
    def ping(self, t: int) -> int:
        self.q.append(t)
        while self.q and self.q[0] < t - 3000:
            self.q.popleft()
        return len(self.q)


if __name__ == '__main__':
    rc = RecentCounter()
    print(rc.ping(1))    # 1
    print(rc.ping(100))  # 2
    print(rc.ping(3001)) # 3
