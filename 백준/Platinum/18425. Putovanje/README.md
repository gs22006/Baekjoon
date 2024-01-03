# [Platinum III] Putovanje - 18425 

[문제 링크](https://www.acmicpc.net/problem/18425) 

### 성능 요약

메모리: 58112 KB, 시간: 144 ms

### 분류

깊이 우선 탐색, 그래프 이론, 그래프 탐색, 최소 공통 조상, 누적 합, 트리

### 제출 일자

2024년 1월 4일 02:11:35

### 문제 설명

<p>Little Fabijan loves bars and travels. He wishes to drink beer coffee in each of the N towns in his country conveniently numbered from 1 to N. The towns are connected via (N − 1) bidirectional roads such that each town is reachable from any other town by traversing some of the roads. Fabijan decided to drink coffee in every town in order from town number 1 to town number N. Therefore, he starts from town number 1 (where he drinks his first coffee) and travels to town number 2 for his next cup of coffee. During that travel he might pass through a number of different towns but he won’t make a coffee stop in those towns. After drinking coffee in town 2, he will proceed to travel to town 3, and so on until he finally reaches town N where he will drink his last coffee.</p>

<p>In order to traverse a certain road, he needs to have a valid ticket. The i-th road can be traversed if you have either a single-pass ticket which costs C<sub>i1</sub> euros or a multi-pass ticket which costs C<sub>i2</sub> euros. For each road, Fabijan can decide to buy a single-pass ticket each time he needs to traverse that road or he might opt to buy a multi-pass ticket once.</p>

<p>Write a program that computes the smallest number of euros Fabijan needs to spend on tickets in order to successfully complete his travels.</p>

### 입력 

 <p>The first line contains an integer N (2 ≤ N ≤ 200 000) from task description.</p>

<p>In i-th of the next (N − 1) lines there are four integers A<sub>i</sub>, B<sub>i</sub>, C<sub>i1</sub>, C<sub>i2</sub> (1 ≤ A<sub>i</sub>, B<sub>i</sub> ≤ N, 1 ≤ C<sub>i1</sub> ≤ C<sub>i2</sub> ≤ 100 000) which represent that towns A<sub>i</sub> and B<sub>i</sub> are connected with a road with ticket prices C<sub>i1</sub> and C<sub>i2</sub>.</p>

### 출력 

 <p>In a single line output the smallest cost of travel.</p>

