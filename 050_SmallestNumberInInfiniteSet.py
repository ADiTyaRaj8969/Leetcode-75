"""
Topic: Design / Heap
Problem: Smallest Number in Infinite Set
Description: Implement a class that returns and adds back the smallest number.
Time: push/addBack: O(log n), popSmallest: O(log n)
Space: O(n)
"""

import heapq


class SmallestInfiniteSet:
    def __init__(self):
        self.heap = list(range(1, 1001))  # cap initial range reasonably
        heapq.heapify(self.heap)
        self.present = set(self.heap)

    def popSmallest(self) -> int:
        if not self.heap:
            # expand if needed
            v = max(self.present) + 1 if self.present else 1
            return v
        x = heapq.heappop(self.heap)
        self.present.remove(x)
        return x

    def addBack(self, num: int) -> None:
        if num not in self.present:
            heapq.heappush(self.heap, num)
            self.present.add(num)


if __name__ == '__main__':
    s = SmallestInfiniteSet()
    print(s.popSmallest())  # 1
    print(s.popSmallest())  # 2
    s.addBack(1)
    print(s.popSmallest())  # 1
