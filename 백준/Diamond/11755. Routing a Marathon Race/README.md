# [Diamond III] Routing a Marathon Race - 11755 

[문제 링크](https://www.acmicpc.net/problem/11755) 

### 성능 요약

메모리: 2160 KB, 시간: 1444 ms

### 분류

백트래킹(backtracking), 그래프 이론(graphs), 그래프 탐색(graph_traversal)

### 문제 설명

<p>As a member of the ICPC (Ibaraki Committee of Physical Competitions), you are responsible for planning the route of a marathon event held in the City of Tsukuba. A great number of runners, from beginners to experts, are expected to take part.</p>

<p>You have at hand a city map that lists all the street segments suited for the event and all the junctions on them. The race is to start at the junction in front of Tsukuba High, and the goal is at the junction in front of City Hall, both of which are marked on the map.</p>

<p>To avoid congestion and confusion of runners of divergent skills, the route should not visit the same junction twice. Consequently, although the street segments can be used in either direction, they can be included at most once in the route. As the main objective of the event is in recreation and health promotion of citizens, time records are not important and the route distance can be arbitrarily decided.</p>

<p>A number of personnel have to be stationed at every junction on the route. Junctions adjacent to them, i.e., junctions connected directly by a street segment to the junctions on the route, also need personnel staffing to keep casual traffic from interfering the race. The same number of personnel is required when a junction is on the route and when it is adjacent to one, but different junctions require different numbers of personnel depending on their sizes and shapes, which are also indicated on the map.</p>

<p>The municipal authorities are eager in reducing the costs including the personnel expense for events of this kind. Your task is to write a program that plans a route with the minimum possible number of personnel required and outputs that number.</p>

### 입력 

 <p>The input consists of a single test case representing a summary city map, formatted as follows.</p>

<pre>n m
c<sub>1</sub>
.
.
.
c<sub>n</sub>
i<sub>1</sub> j<sub>1</sub>
.
.
.
i<sub>m</sub> j<sub>m</sub></pre>

<p>The first line of a test case has two positive integers, n and m. Here, n indicates the number of junctions in the map (2 ≤ n ≤ 40), and m is the number of street segments connecting adjacent junctions. Junctions are identified by integers 1 through n.</p>

<p>Then comes n lines indicating numbers of personnel required. The k-th line of which, an integer c<sub>k</sub> (1 ≤ c<sub>k</sub> ≤ 100), is the number of personnel required for the junction k.</p>

<p>The remaining m lines list street segments between junctions. Each of these lines has two integers i<sub>k</sub> and j<sub>k</sub>, representing a segment connecting junctions i<sub>k</sub> and j<sub>k</sub> (i<sub>k</sub> ≠ j<sub>k</sub>). There is at most one street segment connecting the same pair of junctions.</p>

<p>The race starts at junction 1 and the goal is at junction n. It is guaranteed that there is at least one route connecting the start and the goal junctions.</p>

### 출력 

 <p>Output an integer indicating the minimum possible number of personnel required.</p>

