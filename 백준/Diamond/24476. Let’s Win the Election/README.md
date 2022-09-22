# [Diamond IV] Let’s Win the Election - 24476 

[문제 링크](https://www.acmicpc.net/problem/24476) 

### 성능 요약

메모리: 6100 KB, 시간: 700 ms

### 분류

다이나믹 프로그래밍(dp), 그리디 알고리즘(greedy)

### 문제 설명

<p>Republic of JOI consists of $N$ states, numbered from $1$ to $N$. In 2022, the presidential election will be held in Republic of JOI. The election will be held in each state. The winner of the election in a state will get the vote of the state.</p>

<p>Rie will run for the president. She is planning to win the election. Her plan is to deliver a speech in order to increase the degree of reliability. After she delivers a speech, the following will happen.</p>

<ul>
	<li>If the total time of speech in State $i$ ($1 ≤ i ≤ N$) reaches $A_i$ hours, she will get the vote of State $i$.</li>
	<li>If the total time of speech in State $i$ ($1 ≤ i ≤ N$) reaches $B_i$ hours, she will get a collaborator from State $i$. After that, the collaborator will be able to deliver a speech in order to increase the total time of speech.</li>
	<li>It may be the case that Rie cannot get any collaborator from State $i$. In this case, $B_i = -1$. Otherwise, it is guaranteed that $B_i ≥ A_i$ holds.</li>
</ul>

<p>A collaborator from State $i$ ($1 ≤ i ≤ N$) may deliver a speech outside State $i$. More than one person may deliver a speech in the same state simultaneously. For example, if two people deliver a speech in a state for $x$ hours, the total time of speech in the state will be increased by $2x$ hours. The time of speech needs not be an integer. We will ignore the travel time between states.</p>

<p>Since the election day is coming soon, Rie would like to get $K$ votes as soon as possible.</p>

<p>Given the number of the states and information of each state, write a program which calculate the minimum number of hours required to get $K$ votes.</p>

### 입력 

 <p>Read the following data from the standard input. Given values are all integers.</p>

<p>$\begin{align*} & N \\ & K \\ & A_1 \, B_1 \\ & A_2 \, B_2 \\ & \vdots \\ & A_N \, B_N  \end{align*}$</p>

### 출력 

 <p>Write one line to the standard output. The output should contain the minimum number of hours required to get $K$ votes. Your solution will be judged correct if the absolute value of the difference from correct answer is less than or equal to $0.01$. The output should be written in one of the following formats.</p>

<ul>
	<li>An integer. (Example: <code>123</code>, <code>0</code>, <code>-2022</code>)</li>
	<li>A sequence consisting of an integer, a period, and a sequence of digits between $0$ and $9$. It should not contain separating characters. There is no restriction on the number of digits after the decimal point. (Example: <code>123.4</code>, <code>-123.00</code>, <code>0.00288</code>)</li>
</ul>

<p>The output should not be written in exponential notation. For example, <code>1.23456e+05</code> and <code>1.23456e5</code> are not allowed.</p>

