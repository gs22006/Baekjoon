# [Diamond III] Kangaroo - 13188 

[문제 링크](https://www.acmicpc.net/problem/13188) 

### 성능 요약

메모리: 128272 KB, 시간: 280 ms

### 분류

다이나믹 프로그래밍(dp)

### 문제 설명

<p>A garden is composed of a row of N cells numbered from 1 to N. Initially, all cells contain plants. A kangaroo arrived in the garden in cell numbered cs. Then he jumps from cell to cell, eating the plants as he goes. He will always finish in cell numbered cf, after visiting each of the N cells exactly once, including cs and cf. Obviously, the kangaroo will make N-1 jumps.</p>

<p>The kangaroo doesn't want to be caught, so after each jump he changes the direction in which he jumps next: if he is currently in cell numbered current after he jumped there from a cell numbered prev, and will jump from current to cell numbered next, then:</p>

<ul>
	<li>if prev < current, then next < current; else,</li>
	<li>if current < prev, then current < next.</li>
</ul>

<p>Knowing the number N of cells in the garden, the starting cell cs from where the kangaroo starts to eat plants and the final cell cf where the kangaroo finishes, you should calculate the number of distinct routes the kangaroo can take while jumping through the garden.</p>

### 입력 

 <p>The input will contain three space separated positive integers N, cs, cf.</p>

<ul>
	<li>2 ≤ N ≤ 2000</li>
	<li>1 ≤ cs ≤ N</li>
	<li>1 ≤ cf ≤ N</li>
	<li>cs ≠ cf</li>
	<li>Any route is uniquely determined by the order in which cells are visited.</li>
	<li>We guarantee that for each test there is at least one route which follow the rules.</li>
	<li>The kangaroo can start jumping in any direction from cs.</li>
</ul>

### 출력 

 <p>In the output you should write a single integer, the number of distinct routes the kangaroo can take modulo 1000000007 (10<sup>9</sup> + 7).</p>

