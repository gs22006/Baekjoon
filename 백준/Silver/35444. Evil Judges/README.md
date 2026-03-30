# [Silver I] Evil Judges - 35444 

[문제 링크](https://www.acmicpc.net/problem/35444) 

### 성능 요약

메모리: 2532 KB, 시간: 0 ms

### 분류

정렬, 누적 합

### 제출 일자

2026년 3월 30일 10:34:00

### 문제 설명

<p>The evil judges preparing the ICPC problem sets are tired of seeing the talented contestants AC their problems and AK ("all kill") their problem sets. They have grown so tired of this that they've started to dislike any strings where <code>AC</code> or <code>AK</code> appear as subsequences. The judges just found a string $s$ consisting of only the characters <code>A</code>, <code>C</code>, and <code>K</code> and are determined to destroy these subsequences!</p>

<p>In one operation, the judges are able to swap two adjacent characters in the string $s$. To be more precise, the judges may choose an index $i$ ($1 \le i < |s|$) and swap $s_i$ and $s_{i+1}$. The judges are very busy and don't have much time, so they can only do this operation up to $M$ times (independently choosing an index $i$ each time).</p>

<p>The judges' goal is to minimize the number of subsequences (<strong>possibly non-contiguous</strong>) that are <code>AC</code> or <code>AK</code>. Help them calculate the number of <code>AC</code> and <code>AK</code> subsequences that remain within $s$ after the judges perform an optimal sequence of up to $M$ swap operations.</p>

### 입력 

 <p>The first line of input contains the string $s$ $(1 \leq |s| \leq 2 \cdot 10^{5})$. The string consists only of the characters <code>A</code>, <code>C</code>, and <code>K</code>.</p>

<p>The second line contains an integer $M$ $(0 \leq M \leq 2 \cdot 10^{9})$, the maximum number of swaps the judges can perform.</p>

### 출력 

 <p>Print the minimum total number of <code>AC</code> and <code>AK</code> subsequences that remain in $s$ after an optimal sequence of at most $M$ swap operations.</p>

