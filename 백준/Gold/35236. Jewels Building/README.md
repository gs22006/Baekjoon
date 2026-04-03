# [Gold II] Jewels Building - 35236 

[문제 링크](https://www.acmicpc.net/problem/35236) 

### 성능 요약

메모리: 127708 KB, 시간: 124 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2026년 4월 3일 13:39:54

### 문제 설명

<p>You are playing a fantasy game where you start with a row of $n$ power crystals. The $i$-th crystal has energy level $a_i$.</p>

<p>You can perform the following operation any number of times:</p>

<ul>
<li>choose a consecutive group of identical crystals, that is, choose $l$ and $r$ ($1 ≤ l ≤ r ≤ |a|$) such that $a_l = a_{l+1} = \dots = a_r$;</li>
<li>fuse them into a single crystal whose energy becomes $r − l + 1$, obtaining the new sequence $[a_1, \dots , a_{l−1}, r − l + 1, a_{r+1}, \dots , a_{|a|} ]$.</li>
</ul>

<p>Note that you may also choose $l = r$.</p>

<p>You want to craft a specific configuration of crystals with energy levels $b_1, \dots , b_m$. Determine whether it is possible.</p>

### 입력 

 <p>Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 ≤ t ≤ 500$). The description of the test cases follows.</p>

<p>The first line of each test case contains two integers $n$, $m$ ($1 ≤ m ≤ n ≤ 4000$) — the number of crystals in the initial and target configurations, respectively.</p>

<p>The second line of each test case contains $n$ integers $a_1, a_2, \dots , a_n$ ($1 ≤ a_i ≤ 10^9$) — the energy levels of the initial crystals.</p>

<p>The third line of each test case contains $m$ integers $b_1, b_2, \dots , b_m$ ($1 ≤ b_i ≤ 10^9$) — the desired energy levels of the target crystals.</p>

<p>It is guaranteed that the sum of $n$ over all test cases does not exceed $4000$.</p>

### 출력 

 <p>For each test case, output <code>YES</code> if you can transform the initial configuration into the target one, and <code>NO</code> otherwise.</p>

