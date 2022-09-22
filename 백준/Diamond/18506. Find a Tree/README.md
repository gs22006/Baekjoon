# [Diamond IV] Find a Tree - 18506 

[문제 링크](https://www.acmicpc.net/problem/18506) 

### 성능 요약

메모리: 158212 KB, 시간: 1596 ms

### 분류

애드 혹(ad_hoc), 깊이 우선 탐색(dfs), 그래프 이론(graphs), 그래프 탐색(graph_traversal)

### 문제 설명

<p>Proper k-<em>coloring</em> of undirected graph G(V, E) is a mapping c : V → {1, 2, 3, . . . , k} such that for each edge (u, v) ∈ E, we have c<sub>u</sub> ≠ c<sub>v</sub>.</p>

<p>Undirected graph is k-<em>colorable</em> if a proper k-coloring exists for it.</p>

<p><em>Chromatic number</em> of a graph is the smallest k such that the graph is k-colorable.</p>

<p><em>Tree</em> is a simple acyclic undirected graph.</p>

<p>Alice has an undirected graph with chromatic number k, and Bob has a tree on k vertices. Bob wants to find k <strong>different</strong> vertices p<sub>1</sub>, p<sub>2</sub>, p<sub>3</sub>, . . . , p<sub>k</sub> in Alice’s graph such that for each edge (u, v) in Bob’s tree, there exists an edge (p<sub>u</sub>, p<sub>v</sub>) in Alice’s graph. Help him.</p>

### 입력 

 <p>The first line contains a single integer T (1 ≤ T ≤ 10<sup>6</sup>), the number of test cases to solve. Description of T testcases follows. Each testcase is described as follows.</p>

<p>The first line contains three integers n, m, and k (1 ≤ n, k ≤ 10<sup>6</sup>, 0 ≤ m ≤ 10<sup>6</sup>), the number of vertices and edges of Alice’s graph and its chromatic number, respectively.</p>

<p>Each of the next m lines contains a pair of integers u<sub>i</sub> and v<sub>i</sub> (1 ≤ u<sub>i</sub>, v<sub>i</sub> ≤ n, u<sub>i</sub> ≠ v<sub>i</sub>) describing an edge of Alice’s graph. It is guaranteed that there are no multiple edges and that Alice’s graph has chromatic number exactly equal to k.</p>

<p>Each of the next k − 1 lines contains a pair of integers p<sub>i</sub> and q<sub>i</sub> (1 ≤ p<sub>i</sub>, q<sub>i</sub> ≤ k, p<sub>i</sub> ≠ q<sub>i</sub>) describing an edge in Bob’s tree. It is guaranteed that the given set of edges forms a tree.</p>

<p>It is guaranteed that the sum of n in all test cases, as well as the sum of m in all test cases, does not exceed 10<sup>6</sup>.</p>

### 출력 

 <p>For each testcase, output the answer in the following format.</p>

<p>If it is impossible to find the required k vertices in Alice’s graph, print “No”.</p>

<p>Otherwise, print “Yes” in the first line. In the second line, print k different integers p<sub>i</sub> (1 ≤ p<sub>i</sub> ≤ n): the numbers of vertices in Alice’s graph corresponding to the respective vertices of Bob’s tree. If there are several possible answers, print any one of them.</p>

