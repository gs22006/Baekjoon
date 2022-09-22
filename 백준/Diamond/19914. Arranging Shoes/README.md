# [Diamond V] Arranging Shoes - 19914 

[문제 링크](https://www.acmicpc.net/problem/19914) 

### 성능 요약

메모리: 152784 KB, 시간: 44 ms

### 분류

자료 구조(data_structures), 그리디 알고리즘(greedy), 세그먼트 트리(segtree)

### 문제 설명

<p>Adnan owns the biggest shoe store in Baku. A box containing $n$ pairs of shoes has just arrived at the store. Each pair consists of two shoes of the same size: a left and a right one. Adnan has put all of the $2n$ shoes in a row consisting of $2n$ <strong>positions</strong> numbered $0$ through $2n-1$ from left to right.</p>

<p>Adnan wants to rearrange the shoes into a <strong>valid arrangement</strong>. An arrangement is valid if and only if for every $i$ ($0 \leq i \leq n-1$), the following conditions hold:</p>

<ul>
	<li>The shoes at positions $2i$ and $2i+1$ are of the same size.</li>
	<li>The shoe at position $2i$ is a left shoe.</li>
	<li>The shoe at position $2i+1$ is a right shoe.</li>
</ul>

<p>For this purpose, Adnan can make a series of swaps.</p>

<p>In each swap, he selects two shoes that are <strong>adjacent</strong> at that moment and exchanges them (i.e., picks them up and puts each one on the former position of the other shoe).</p>

<p>Two shoes are adjacent if their positions differ by one.</p>

<p>Determine the minimum number of swaps that Adnan needs to perform in order to obtain a valid arrangement of the shoes.</p>

### 입력 

 Empty

### 출력 

 Empty

