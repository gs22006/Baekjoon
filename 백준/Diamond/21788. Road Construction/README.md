# [Diamond V] Road Construction - 21788 

[문제 링크](https://www.acmicpc.net/problem/21788) 

### 성능 요약

메모리: 1397536 KB, 시간: 3412 ms

### 분류

이분 탐색, 자료 구조, 매개 변수 탐색, 퍼시스턴트 세그먼트 트리, 세그먼트 트리, 스위핑

### 제출 일자

2024년 1월 19일 23:26:43

### 문제 설명

<p>There are N towns in JOI Kingdom. The towns are numbered from 1 to N. The land of JOI Kingdom is considered as the xy-plane. The coordinates of the town i (1 ≤ i ≤ N) is (X<sub>i</sub>, Y<sub>i</sub>).</p>

<p>In JOI Kingdom, they are planning to construct K roads connecting towns. It costs |X<sub>i</sub> − X<sub>j</sub>| + |Y<sub>i</sub> − Y<sub>j</sub>| yen to construct a road connecting the town i and the town j (i , j). Note that we consider “the construction of a road connecting the town i and the town j” and “the construction of a road connecting the town j and the town i” to be the same.</p>

<p>Since you are in charge of the construction project, you want to know the cost to construct roads connecting some pairs of towns, in order to estimate the cost. Among the N(N − 1)/2 pairs of towns to construct roads, you want to know the costs of the K cheapest roads.</p>

<p>Write a program which, given the coordinates of the towns of JOI Kingdom and the value of K, calculates the costs of the K cheapest roads.</p>

### 입력 

 <p>Read the following data from the standard input. Given values are all integers.</p>

<pre>N K
X<sub>1</sub> Y<sub>1</sub>
.
.
.
X<sub>N</sub> Y<sub>N</sub></pre>

### 출력 

 <p>Write K lines to the standard output. In the k-th line (1 ≤ k ≤ K), output the cost of the k-th cheapest road.</p>

