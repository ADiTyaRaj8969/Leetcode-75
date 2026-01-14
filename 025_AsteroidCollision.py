"""
Topic: Stack / Simulation
Asteroid Collision: simulate collisions using stack
Time Complexity: O(n)
Space Complexity: O(n)
"""

def asteroid_collision(asteroids):
    stack = []
    for a in asteroids:
        alive = True
        while alive and a < 0 and stack and stack[-1] > 0:
            if stack[-1] < -a:
                stack.pop()
                continue
            elif stack[-1] == -a:
                stack.pop(); alive = False; break
            else:
                alive = False; break
        if alive:
            stack.append(a)
    return stack


if __name__ == '__main__':
    print(asteroid_collision([5,10,-5]))  # [5,10]
    print(asteroid_collision([8,-8]))     # []
