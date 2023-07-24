# [Gold III] Stone Arranging 2 - 27536 

[문제 링크](https://www.acmicpc.net/problem/27536) 

### 성능 요약

메모리: 17824 KB, 시간: 184 ms

### 분류

자료 구조, 스택, 트리를 사용한 집합과 맵

### 문제 설명

<p>JOI-kun has $N$ go stones. The stones are numbered from $1$ to $N$. The color of each stone is an integer between $1$ and $10^9$, inclusive. In the beginning, the color of Stone $i$ ($1 ≤ i ≤ N$) is $A_i$.</p>

<p>From now, JOI-kun will perform $N$ operations. He will put the stones on the table in a line. The operation $i$ ($1 ≤ i ≤ N$) will be performed as follows:</p>

<ol>
	<li>JOI-kun will put Stone $i$ on the immediate right of Stone $i - 1$. However, when $i = 1$, JOI-kun will put Stone $1$ on the table.</li>
	<li>If there is a stone among Stones $1$, $2$, $\dots$, $i - 1$ whose current color is the same as Stone $i$, let $j$ be the maximum index of such stones, and JOI-kun will paint all of Stones $j + 1$, $j + 2$, $\dots$, $i - 1$ with the color $A_i$.</li>
</ol>

<p>In order to confirm whether the operations are correctly performed, JOI-kun wants to know in advance the colors of the stones after all the operations are performed.</p>

<p>Given information of the go stones, write a program which determines the colors of the stones after the N operations are performed.</p>

### 입력 

 <p>Read the following data from the standard input.</p>

<blockquote>
<p>$N$</p>

<p>$A_1$</p>

<p>$A_2$</p>

<p>$\vdots$</p>

<p>$A_N$</p>
</blockquote>

### 출력 

 <p>Write $N$ lines to the standard output. The $i$-th line ($1 ≤ i ≤ N$) should contain the color of Stone $i$ after the $N$ operations are performed.</p>

