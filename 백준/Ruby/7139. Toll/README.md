# [Ruby IV] Toll - 7139 

[문제 링크](https://www.acmicpc.net/problem/7139) 

### 성능 요약

메모리: 34628 KB, 시간: 752 ms

### 분류

브루트포스 알고리즘, 자료 구조, 깊이 우선 탐색, 분리 집합, 그래프 이론, 그래프 탐색, 최소 공통 조상, 최소 스패닝 트리, 트리

### 문제 설명

<p>Happyland can be described by a set of N towns (numbered 1 to N) initially connected by M bidirectional roads (numbered 1 to M). Town 1 is the central town. It is guaranteed that one can travel from town 1 to any other town through these roads. The roads are toll roads. A user of the road i has to pay a toll fee of c<sub>i</sub> cents to the owner of the road. It is known that all of these c<sub>i</sub>’s are distinct. Recently, K additional new roads are completed and they are owned by a billionaire Mr Greedy. Mr Greedy can decide the toll fees (not necessarily distinct) of the new roads, and he has to announce the toll fees tomorrow.</p>

<p>Two weeks later, there will be a massive carnival in Happyland! Large number of participants will travel to the central town and parade along the roads. A total of p<sub>j</sub> participants will leave from town j and travel toward the central town. They will only travel on a set of selected roads, and the selected roads will be announced a day before the event. By an old tradition, the roads are to be selected by the richest person in Happyland, who is Mr Greedy. Constrained by the same tradition, Mr Greedy must select a set of roads that minimizes the sum of toll fees in the selected set and yet at the same time allow anyone to travel from town j to town 1 (hence, the selected roads form a “minimum spanning tree” where the toll fees are the weights of the corresponding edges). If there are multiple such sets of roads, Mr Greedy can select any set as long as the sum is minimum.</p>

<p>Mr Greedy is well-aware that the revenue he received from the K new roads does not solely depends on the toll fees. The revenue from a road is actually the total fee collected from people who travel along the road. More precisely, if p people travel along road i, the revenue from the road i is the product cip. Note that Mr Greedy can only collect fees from the new roads since he does not own any of the old roads.</p>

<p>Mr Greedy has a sneaky plan. He plans to maximize his revenue during the carnival by manipulating the toll fees and the roads selection. He wants to assign the toll fees to the new roads (which are to be announced tomorrow), and select the roads for the carnival (which are to be announced a day before the carnival), in such a way that maximizes his revenue from the K new roads. Note that Mr Greedy still has to follow the tradition of selecting a set of roads that minimizes the sum of toll fees.</p>

<p>You are a reporter and want to expose his plan. To do so, you have to first write a program to determine how much revenue Mr Greedy can make with his sneaky plan.</p>

### 입력 

 <p>Your program must read from the standard input. The first line contains three space-separated integers N, M and K. The next M lines describe the initial M roads. The ith of these lines contains space-separated integers a<sub>i</sub>, b<sub>i</sub> and c<sub>i</sub>, indicating that there is a bidirectional road between towns a<sub>i</sub> and b<sub>i</sub> with toll fee c<sub>i</sub>. The next K lines describe the newly built K additional roads. The ith of these lines contains space-separated integers x<sub>i</sub> and y<sub>i</sub>, indicating that there is a new road connecting towns x<sub>i</sub> and y<sub>i</sub>. The last line contains N space-separated integers, the j-th of which is p<sub>j</sub>, the number of people from town j traveling to town 1.</p>

<p>The input also satisfies the following constraints.</p>

<ul>
	<li>1 ≤ N ≤ 100000.</li>
	<li>1 ≤ K ≤ 20.</li>
	<li>1 ≤ M ≤ 300000.</li>
	<li>1 ≤ c<sub>i</sub>, p<sub>j</sub> ≤ 10<sup>6</sup> for each i and j.</li>
	<li>c<sub>i</sub> ≠ c<sub>i'</sub>, if i ≠ i'.</li>
	<li>Between any two towns, there is at most one road (including newly built ones).</li>
</ul>

### 출력 

 <p>Your program must write to the standard output a single integer, which is the maximum total revenue obtainable.</p>

