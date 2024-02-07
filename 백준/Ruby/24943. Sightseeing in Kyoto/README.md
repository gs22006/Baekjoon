# [Ruby V] Sightseeing in Kyoto - 24943 

[문제 링크](https://www.acmicpc.net/problem/24943) 

### 성능 요약

메모리: 7052 KB, 시간: 32 ms

### 분류

볼록 껍질, 기하학, 그리디 알고리즘

### 제출 일자

2024년 2월 7일 22:53:11

### 문제 설명

<p>Kyoto City is a worldwide sightseeing place. It is also known as a city with grid of streets. You are now visiting Kyoto City for sightseeing. You are planning to visit a famous spot on foot. You want to arrive there as early as possible. In this task, we consider the following simplified situation.</p>

<p>In this city, there are $H$ streets in the east-west direction, and $W$ streets in the south-north direction. The shape of the city is a grid of $(H - 1) \times (W - 1)$ cells. The crossing of the $i$-th street ($1 ≤ i ≤ H$) from the north and the $j$-th street ($1 ≤ j ≤ W$) from the west is denoted by $(i, j)$.</p>

<p>Different streets may have different width, material, and crowdedness. Your walking speed may be different for different streets. For each street, your walking speed is determined as follows.</p>

<ul>
	<li>If you walk on the $i$-th street ($1 ≤ i ≤ H$) from the north for the unit length, it takes $A_i$ seconds. In other words, for each $c$ ($1 ≤ c ≤ W - 1$), it takes $A_i$ seconds to walk from the crossing $(i, c)$ to the crossing $(i, c + 1)$.</li>
	<li>If you walk on the $j$-th street ($1 ≤ j ≤ W$) from the west for the unit length, it takes $B_j$ seconds. In other words, for each $r$ ($1 ≤ r ≤ H - 1$), it takes $B_j$ seconds to walk from the crossing $(r, j)$ to the crossing $(r + 1, j)$.</li>
</ul>

<p>In order not to destroy the beautiful landscape of Kyoto City, you are not allowed to walk outside the streets.</p>

<p>Now you are in the crossing $(1, 1)$. You want to walk to the crossing $(H, W)$. Since you will be tired if you walk for long distance, you do not want to make a detour. You will not walk to the north or west direction. Under this condition, you want to arrive at the destination as early as possible.</p>

<p>Write a program which, given information of the streets, calculates the minimum time to walk from the crossing $(1, 1)$ to the crossing $(H, W)$ without making a detour</p>

### 입력 

 <p>Read the following data from the standard input. Given values are all integers.</p>

<p>$\begin{align*} & H \, W \\ & A_1 \, A_2 \, \cdots \, A_H \\ & B_1 \, B_2 \, \cdots \, B_W \end{align*}$</p>

### 출력 

 <p>Write one line to the standard output. The output should contain the minimum time (seconds) to walk from the crossing $(1, 1)$ to the crossing $(H, W)$ without making a detour.</p>

