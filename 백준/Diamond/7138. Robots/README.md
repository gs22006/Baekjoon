# [Diamond IV] Robots - 7138 

[문제 링크](https://www.acmicpc.net/problem/7138) 

### 성능 요약

메모리: 77760 KB, 시간: 1560 ms

### 분류

자료 구조, 데이크스트라, 그래프 이론, 구현, 우선순위 큐

### 문제 설명

<p>The engineers at VRI (Voltron Robotics Institute) have built a swarm of n robots. Any two compatible robots that stands on the same grid can merge to form another composite robot.</p>

<p>We label the robots with number 1 to n (n ≤ 9). Two robots are compatible if they have labels that are consecutive. Originally, each of the n robot has one unique label. A composite robot that is formed after merging two or more robots is assigned two labels, consisting of the minimum and maximum label of the robots that merge into the composite robot.</p>

<p>For example, robot 2 can only merge with robot 3 or robot 1. If robot 2 merges with robot 3, a composite robot 2-3 is formed. If robot 2-3 merges with robot 4-6, a composite robot 2-6 is formed. The robot 1-n is formed when all robots have merged.</p>

<p>The engineers place n robots in a room consisting of w×h grids, surrounded by walls. Some grids are occluded and cannot be accessed by the robots. Each grid can hold one or more robots, and a robot always occupies exactly one grid. Initially, each robot is placed on a different grid.</p>

<p>The robots are rather primitives. They can move only in a straight line along either the xaxis or y-axis after being pushed by an engineer. After it is pushed in one of the four directions parallel to the x- and y-axis, the robot continues moving, in the direction it is pushed in, until it is blocked either by an occlusion or a wall. After the robot stops moving, it scans for other compatible robots occupying the same grid, and merge with any compatible robot it finds into a larger robot. The merging process continues until no further merging is possible.</p>

<p>To help the robots change direction, the engineers have placed rotating plates in some of the grids. The rotating plates can either rotate in a clockwise or anti-clockwise direction. A robot that moves into a grid with the rotating plate always changes its moving direction by 90 degree in the same direction as the rotating plate. If a robot is being pushed while resting on top of a rotating plate, it rotates by 90 degree before moving off in a straight line, in a direction perpendicular to the direction it is pushed in.</p>

<p>Only one robot can move at one time.</p>

<p>You task is to find the minimum number of pushes such that all n robots are merged together (if possible).</p>

### 입력 

 <p>Your program must read from the standard input. The first line of the input file contains three integers, n, w, and h, separated by a space.</p>

<p>The next h lines of the input file describe the room, each line contains w characters. Each of these w × h characters represents a grid in the room.</p>

<p>A numeric character (’1’ to ’9’) indicates that there is a robot labeled with the corresponding number in the grid. A character ‘x’ indicates that there is an occlusion in the grid. A character ‘A’ or ‘C’ indicates that there is a rotating plate in the grid. ‘A’ indicates that the plate is rotating anti-clockwise. ‘C’ indicates that the plate is rotating clockwise. The ‘.’ characters fill all other grid locations.</p>

<p>n ≤ 9, w ≤ 500, h ≤ 500</p>

### 출력 

 <p>Your program must write to the standard output, either a single number indicating the minimum number of pushes needed to merge all n robots, or -1 if merging is not possible.</p>

