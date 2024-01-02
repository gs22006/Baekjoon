# [Diamond IV] Pork barrel - 10511 

[문제 링크](https://www.acmicpc.net/problem/10511) 

### 성능 요약

메모리: 166392 KB, 시간: 3236 ms

### 분류

자료 구조, 분리 집합, 그래프 이론, 최소 스패닝 트리, 퍼시스턴트 세그먼트 트리, 세그먼트 트리, 제곱근 분할법

### 제출 일자

2024년 1월 2일 18:57:55

### 문제 설명

<p>Winning the election was simpler than you expected: it was enough to promise to finally build a good quality, country-wide road infrastructure, of course without crippling the budget... Your happiness did not last long, however: it seems, that the citizens have found a way to actually hold you accountable for your promise!</p>

<p>There are n major cities in your country. The Ministry of Transport has prepared a detailed map, outlining  <span style="line-height:1.6em">m possible highway connections, together with their costs. The Quality Assurance Committee will not let you build a highway cheaper than l, and the National Spendings Regulatory Committee will not let you build a highway more expensive than h. To claim a “country-wide” network, you have to connect (possibly indirectly) as many pairs of cities, as it is possible within these two constraints. You have to find the cheapest way to do it, and you have to find it quickly! Of all networks that meet the constraints and connect the most pairs of cities, compute the cost of the cheapest one.</span></p>

<p>To make things worse, both committees are heavily influenced by your angry competitors: each time you publish your hard-prepared plan, they immediately change their rulings l and h, and you are forced to start from scratch.</p>

### 입력 

 <p>The first line of input contains the number of test cases T. The descriptions of the test cases follow: </p>

<p>The first line of each test case contains integers n and m (1 ≤ n ≤ 1000; 0 ≤ m ≤ 100 000) – the number of cities in the country, and of possible direct connections, respectively.</p>

<p>Each of the following m lines contains three integers x, y, w (1 ≤ x ≠ y ≤ n; 1 ≤ w ≤ 1 000 000), denoting that the cities x and y can be connected by a bidirectional highway at cost w. There might be many ways to connect a single pair of cities.</p>

<p>The following line contains an integer q (1 ≤ q ≤ 1 000 000) – the number of rulings of the committees. Each of the following q lines contains two integers. The first of the lines contains the initial rulings l<sub>1</sub>, h<sub>1</sub>, given directly. The rest of the rulings are encoded. The numbers in the j-th of the lines for j > 1 are l<sub>j</sub> + c<sub>j−1</sub> and h<sub>j</sub> + c<sub>j−1</sub>, where l<sub>j</sub> and h<sub>j</sub> are the actual rulings and c<sub>j−1</sub> is the correct answer for the preceding rulings l<sub>j−1</sub> and h<sub>j−1</sub>. </p>

<p>All rulings satisfy 1 ≤ l<sub>j</sub> ≤ h<sub>j</sub> ≤ 1 000 000.</p>

### 출력 

 <p>For each test case, output q lines, one for each ruling. In the j-th of them, output the minimal cost c<sub>j</sub> of building a highway network which adheres to the committees’ constraints, and creates the maximum number of connected pairs of cities.</p>

