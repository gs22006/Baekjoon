# [Platinum I] Lights Off - 27556 

[문제 링크](https://www.acmicpc.net/problem/27556) 

### 성능 요약

메모리: 336432 KB, 시간: 684 ms

### 분류

비트마스킹, 다이나믹 프로그래밍

### 제출 일자

2023년 10월 31일 20:20:29

### 문제 설명

<p>Bessie wants to go to sleep, but the farm's lights are keeping her awake. How can she turn them off?</p>

<p>Bessie has two bit strings of length $N$ ($2\le N\le 20$), representing a sequence of lights and a sequence of switches, respectively. Each light is either on (1) or off (0). Each switch is either active (1) or inactive (0).</p>

<p>A *move* consists of the following sequence of operations:</p>

<ol>
	<li>Toggle exactly one switch (set it to active if it is inactive, or vice versa).</li>
	<li>For each active switch, toggle the state of the corresponding light (turn it off if it is on, or vice versa).</li>
	<li>Cyclically rotate the switches to the right by one. Specifically, if the bit string corresponding to the switches is initially $s_0s_1\dots s_{N-1}$ then it becomes $s_{N-1}s_0s_1\dots s_{N-2}$.</li>
</ol>

<p>For $T$ ($1\le T\le 2\cdot 10^5$) instances of the problem above, count the minimum number of moves required to turn all the lights off.</p>

### 입력 

 <p>First line contains $T$ and $N$.</p>

<p>Next $T$ lines each contain a pair of length-$N$ bit strings.</p>

### 출력 

 <p>For each pair, the minimum number of moves required to turn all the lights off.</p>

