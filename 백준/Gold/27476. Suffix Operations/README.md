# [Gold III] Suffix Operations - 27476 

[문제 링크](https://www.acmicpc.net/problem/27476) 

### 성능 요약

메모리: 9740 KB, 시간: 52 ms

### 분류

브루트포스 알고리즘

### 제출 일자

2023년 11월 20일 21:49:26

### 문제 설명

<p>Gildong has an interesting machine that has an array $a$ with $n$ integers. The machine supports two kinds of operations:</p>

<ol>
	<li>Increase all elements of a suffix of the array by $1$.</li>
	<li>Decrease all elements of a suffix of the array by $1$.</li>
</ol>

<p>A suffix is a subsegment (contiguous elements) of the array that contains $a_n$. In other words, for all $i$ where $a_i$ is included in the subsegment, all $a_j$’s where $i\lt j\le n$ must also be included in the subsegment.</p>

<p>Gildong wants to make all elements of $a$ equal --- he will always do so using the minimum number of operations necessary. To make his life even easier, before Gildong starts using the machine, you have the option of changing one of the integers in the array to any other integer. You are allowed to leave the array unchanged. You want to minimize the number of operations Gildong performs. With your help, what is the minimum number of operations Gildong will perform?</p>

<p>Note that even if you change one of the integers in the array, you should <strong>not</strong> count that as one of the operations because Gildong did not perform it.</p>

### 입력 

 <p>Each test contains one or more test cases. The first line contains the number of test cases $t$ ($1\le t\le 1000$).</p>

<p>Each test case contains two lines. The first line of each test case consists of an integer $n$ ($2\le n\le 2\cdot 10^5$) --- the number of elements of the array $a$.</p>

<p>The second line of each test case contains $n$ integers. The $i$-th integer is $a_i$ ($-5\cdot 10^8\le a_i\le 5\cdot 10^8$).</p>

<p>It is guaranteed that the sum of $n$ in all test cases does not exceed $2\cdot 10^5$.</p>

### 출력 

 <p>For each test case, print one integer --- the minimum number of operations Gildong has to perform in order to make all elements of the array equal.</p>

