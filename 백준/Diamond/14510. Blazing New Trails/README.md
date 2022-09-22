# [Diamond II] Blazing New Trails - 14510 

[문제 링크](https://www.acmicpc.net/problem/14510) 

### 성능 요약

메모리: 51788 KB, 시간: 1872 ms

### 분류

Aliens 트릭(alien), 이분 탐색(binary_search), 그래프 이론(graphs), 최소 스패닝 트리(mst)

### 문제 설명

<p>Your state has just purchased a large, unspoiled tract of land, and wishes to turn it into a nature park with hiking trails. The land has n places of interest to which guests may wish to hike, and of these, k are very special. The state wishes to connect these places with hiking trails. There are m candidate hiking trails to choose from that directly connect two places of interest with various costs. There are some constraints for choosing the trails. First, there must be exactly one way to hike from any place to any other place. Second, exactly w of the trails must directly connect a special place with a regular place. Of course, the state wishes to minimize the cost of blazing these trails.</p>

### 입력 

 <p>Each input will consist of a single test case. Note that your program may be run multiple times on different inputs. The first line of input will contain four integers n, m, k and w, where n (2 ≤ n ≤ 2 · 10<sup>5</sup>) is the number of places, m (1 ≤ m ≤ 5 · 10<sup>5</sup>) is the number of potential direct trails between places, k (1 ≤ k < n) is the number of special places, and w (1 ≤ w ≤ n − 1) is the number of special-nonspecial direct trails the state wishes to blaze. The places are numbered 1..n.</p>

<p>Each of the next k lines holds a single integer s (1 ≤ s ≤ n) indicating the special places. These values will be unique and will be in ascending order.</p>

<p>Each of the next m lines will describe a potential trail that the state could blaze. Each of these lines will consist of three integers, a, b and c, where the trail would go between places a and b (1 ≤ a, b ≤ n, a ≠ b) and would cost c (1 ≤ c ≤ 10<sup>5</sup>). No two places will have more than one potential trail between them, and a trail from a to b is the same as a trail from b to a.</p>

### 출력 

 <p>Output a single integer, which is the minimum total cost for the state to blaze trails in their new park subject to their constraints, or −1 if it isn’t possible.</p>

