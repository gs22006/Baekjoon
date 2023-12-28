# [Diamond II] Treatment Project - 18855 

[문제 링크](https://www.acmicpc.net/problem/18855) 

### 성능 요약

메모리: 99304 KB, 시간: 504 ms

### 분류

자료 구조, 데이크스트라, 그래프 이론, 우선순위 큐, 세그먼트 트리, 스위핑, 최단 경로

### 제출 일자

2023년 12월 28일 12:20:18

### 문제 설명

<p>There are N houses in the JOI kingdom, numbered from 1 to N. The houses lie on a line in numerical order. A citizen lives in each house. The citizen living in the house x (1 ≤ x ≤ N) is denoted by the citizen x.</p>

<p>Recently, new virus appeared, and every citizen was infected with the virus. In order to deal with the problem, M treatment projects are proposed. The cost of the project i (1 ≤ i ≤ M) is C<sub>i</sub>. If the project i is performed, the following happens:</p>

<p>In the evening of the T<sub>i</sub>-th day, if the citizen x with L<sub>i</sub> ≤ x ≤ R<sub>i</sub> is infected with the virus, then the citizen x is treated.</p>

<p>The virus is transmitted through the neighboring citizens in the following way.</p>

<p>If the citizen x (1 ≤ x ≤ N) is infected with the virus in the morning of some day, then the citizen x − 1 (if x ≥ 2) and the citizen x + 1 (if x ≤ N − 1) become infected with the virus at noon of the same day.</p>

<p>A citizen who was already treated can be infected with the virus again.</p>

<p>Since you are a minister of the JOI kingdom, you need to choose some of the projects so that the following condition is satisfied.</p>

<p><strong>Condition</strong>. After all the chosen projects are performed, no citizen is infected with the virus.</p>

<p>It is possible to perform more than one project on the same day.</p>

<p>Write a program which, given the number of houses and the information of the treatment projects, determines whether it is possible to satisfy the above condition, and calculates the minimum total cost if it is possible.</p>

### 입력 

 <p>Read the following data from the standard input. All the values in the input are integers.</p>

<pre>N M
T<sub>1</sub> L<sub>1</sub> R<sub>1</sub> C<sub>1</sub>
.
.
.
T<sub>M</sub> L<sub>M</sub> R<sub>M</sub> C<sub>M</sub></pre>

### 출력 

 <p>Write one line to the standard output. If the condition cannot be satisfied, output −1. Otherwise, output the minimum total cost.</p>

