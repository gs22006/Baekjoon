# [Diamond II] Cookies - 27999 

[문제 링크](https://www.acmicpc.net/problem/27999) 

### 성능 요약

메모리: 308720 KB, 시간: 756 ms

### 분류

비트 집합, 다이나믹 프로그래밍, 그리디 알고리즘, 배낭 문제

### 제출 일자

2024년 2월 5일 03:55:24

### 문제 설명

<p>Rie likes to make cookies. She made $N$ types of cookies. She made $A_i$ cookies of type $i$ ($1 ≤ i ≤ N$). In order to sell the cookies made by her, she will pack them into boxes. However, the following conditions should be satisfied.</p>

<ul>
	<li>For every box, the types of the cookies in it should be different.</li>
	<li>For every box, the number of cookies in it should be equal to one of the following $M$ numbers: $B_1, B_2, \dots , B_M$.</li>
</ul>

<p>Write a program which, given information of cookies made by Rie and the conditions to pack the cookies into boxes, determines whether it is possible to pack all the cookies into boxes. Moreover, if it is possible to pack all the cookies into boxes, your program should output a way to pack the cookies into the minimum number of boxes.</p>

### 입력 

 <p>Read the following data from the standard input.</p>

<blockquote>
<p>$N$</p>

<p>$A_1$ $A_2$ $\cdots$ $A_N$</p>

<p>$M$</p>

<p>$B_1$ $B_2$ $\cdots$ $B_M$</p>
</blockquote>

### 출력 

 <p>If it is possible to pack all the cookies into boxes so that the conditions are satisfied, let $x$ be the number of used boxes, $c_k$ be the number of cookies in the $k$-th box ($1 ≤ k ≤ x$), and $v_{k,1}, v_{k,2}, \dots , v_{k,c_k}$ be the types of the cookies in the $k$-th box. Write these numbers to the standard output as in the following format.</p>

<blockquote>
<p>$x$</p>

<p>$c_1$ $v_{1,1}$ $v_{1,2}$ $\cdots$ $v_{1,c_1}$</p>

<p>$c_2$ $v_{2,1}$ $v_{2,2}$ $\cdots$ $v_{2,c_2}$</p>

<p>$\vdots$</p>

<p>$c_x$ $v_{x,1}$ $v_{x,2}$ $\cdots$ $v_{x,c_x}$</p>
</blockquote>

<p>Here, the number of used boxes $x$ should be the minimum possible number. If there are several ways to pack the cookies into boxes satisfying the conditions, output any one of them.</p>

<p>If it is impossible to pack all the cookies into boxes so that the conditions are satisfied, write <code>-1</code> to the standard output.</p>

