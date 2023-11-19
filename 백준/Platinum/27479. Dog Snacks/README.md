# [Platinum III] Dog Snacks - 27479 

[문제 링크](https://www.acmicpc.net/problem/27479) 

### 성능 요약

메모리: 30104 KB, 시간: 168 ms

### 분류

다이나믹 프로그래밍, 트리에서의 다이나믹 프로그래밍, 그래프 이론, 그래프 탐색, 그리디 알고리즘, 트리

### 제출 일자

2023년 11월 20일 01:37:35

### 문제 설명

<p>Gildong is playing with his dog, Badugi. They’re at a park that has $n$ intersections and $n-1$ bidirectional roads, each $1$ meter in length and connecting two intersections with each other. The intersections are numbered from $1$ to $n$, and for every $a$ and $b$ ($1\le a,b\le n$), it is possible to get to the $b$-th intersection from the $a$-th intersection using some set of roads.</p>

<p>Gildong has put one snack at every intersection of the park. Now Gildong will give Badugi a mission to eat all of the snacks. Badugi starts at the $1$-st intersection, and he will move by the following rules:</p>

<ul>
	<li>Badugi looks for snacks that are as close to him as possible. Here, the distance is the length of the shortest path from Badugi’s current location to the intersection with the snack. However, Badugi’s sense of smell is limited to $k$ meters, so he can only find snacks that are less than or equal to $k$ meters away from himself. If he cannot find any such snack, he fails the mission.</li>
	<li>Among all the snacks that Badugi can smell from his current location, he chooses a snack that minimizes the distance he needs to travel from his current intersection. If there are multiple such snacks, Badugi will choose one arbitrarily.</li>
	<li>He repeats this process until he eats all $n$ snacks. After that, he has to find the $1$-st intersection again which also must be less than or equal to $k$ meters away from the last snack he just ate. If he manages to find it, he completes the mission. Otherwise, he fails the mission.</li>
</ul>

<p>Unfortunately, Gildong doesn’t know the value of $k$. So, he wants you to find the minimum value of $k$ that makes it possible for Badugi to complete his mission, if Badugi moves optimally.</p>

### 입력 

 <p>Each test contains one or more test cases. The first line contains the number of test cases $t$ ($1\le t\le 10^4$).</p>

<p>The first line of each test case contains one integer $n$ ($2\le n\le 2\cdot 10^5$) --- the number of intersections of the park.</p>

<p>The next $n-1$ lines contain two integers $u$ and $v$ ($1\le u,v\le n$, $u\ne v$) each, which means there is a road between intersection $u$ and $v$. All roads are bidirectional and distinct.</p>

<p>It is guaranteed that:</p>

<ul>
	<li>For each test case, for every $a$ and $b$ ($1\le a,b\le n$), it is possible to get to the $b$-th intersection from the $a$-th intersection.</li>
	<li>The sum of $n$ in all test cases doesn’t exceed $2\cdot 10^5$.</li>
</ul>

### 출력 

 <p>For each test case, print one integer --- the minimum possible value of $k$ such that Badugi can complete the mission.</p>

