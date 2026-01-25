"""
Minimum Number of Arrows to Burst Balloons

Given a set of intervals representing balloons, find the minimum number of arrows
that must be shot to burst all balloons. Greedy by sorting intervals by end.
"""

from typing import List, Tuple

def find_min_arrow_shots(points: List[Tuple[int,int]]) -> int:
    if not points: return 0
    points.sort(key=lambda x: x[1])
    arrows = 1
    cur_end = points[0][1]
    for a,b in points[1:]:
        if a > cur_end:
            arrows += 1
            cur_end = b
    return arrows


if __name__ == '__main__':
    print('Arrows 1:', find_min_arrow_shots([(10,16),(2,8),(1,6),(7,12)]))
    print('Arrows 2:', find_min_arrow_shots([(1,2),(3,4),(5,6),(7,8)]))
    print('Arrows 3:', find_min_arrow_shots([(1,2),(2,3),(3,4),(4,5)]))

# Time Complexity: O(n log n)
# Space Complexity: O(1)
