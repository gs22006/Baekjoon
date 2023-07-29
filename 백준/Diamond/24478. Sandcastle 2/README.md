# [Diamond II] Sandcastle 2 - 24478 

[문제 링크](https://www.acmicpc.net/problem/24478) 

### 성능 요약

메모리: 72436 KB, 시간: 1568 ms

### 분류

애드 혹, 누적 합

### 문제 설명

<p>JOI-kun is playing on a sand beach. He makes a sandcastle. The sandcastle made by JOI-kun is contained in a rectangular region in the sand beach. The rectangular region consists of cells of $H$ horizontal rows and $W$ vertical columns. The cell in the $i$-th row ($1 ≤ i ≤ H$) from the north and the $j$-th column ($1 ≤ j ≤ W$) from the west has height $A_{i,j}$. <strong>Note that the values of $A_{i, j}$ are different from each other.</strong></p>

<p>To the sandcastle, JOI-kun performed the following actions.</p>

<ol>
	<li>First, JOI-kun chose a cell, and he started moving from the chosen cell.</li>
	<li>Then, he moved from the current cell to an adjacent cell in one of the four direction. He had to move to a cell which is lower than the current cell. He repeated this zero or more times.</li>
</ol>

<p>Finally, if we view the cells he visited from above, the cells form a rectangle.</p>

<p>Given the information of the height $A_{i, j}$ of each cell, write a program which calculates the number of possible rectangles formed by the the cells JOI-kun visited.</p>

### 입력 

 <p>Read the following data from the standard input. Given values are all integers.</p>

<p>$\begin{align*}& H\,W \\ & A_{1,1}\,A_{1,2} \, \cdots \, A_{1,W} \\ & A_{2,1} \, A_{2,2} \, \cdots \, A_{2,W} \\ & \vdots \\ & A_{H,1} \, A_{H,2} \, \cdots \, A_{H,W}\end{align*}$</p>

### 출력 

 <p>Write one line to the standard output. The output should contain the number of possible rectangles formed by the cells JOI-kun visited.</p>

