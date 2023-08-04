# [Diamond I] Broken Line 10 - 19926 

[문제 링크](https://www.acmicpc.net/problem/19926) 

### 성능 요약

메모리: 4528 KB, 시간: 4 ms

### 분류

애드 혹, 많은 조건 분기, 해 구성하기, 구현

### 문제 설명

<p>Azerbaijan is famous for its carpets. As a master carpet designer you want to make a new design by drawing a <strong>broken line</strong>. A broken line is a sequence of $t$ line segments in a two-dimensional plane, which is defined by a sequence of $t+1$ points $p_0, \ldots, p_t$ as follows. For each $0 \leq j \leq t-1$ there is a segment connecting points $p_j$ and $p_{j+1}$.</p>

<p>In order to make the new design, you have already marked $n$ <strong>dots</strong> in a two-dimensional plane. The coordinates of dot $i$ ($1 \leq i \leq n$) are $(x[i], y[i])$. <strong>No two dots have the same x or the same y coordinate.</strong></p>

<p>You now want to find a sequence of points $(sx[0], sy[0]), (sx[1], sy[1]), \ldots, (sx[k], sy[k])$, which defines a broken line that</p>

<ul>
	<li>starts at $(0, 0)$ (that is, $sx[0] = 0$ and $sy[0] = 0$),</li>
	<li>contains all of the dots (not necessarily as the endpoints of the segments), and</li>
	<li>consists solely of horizontal or vertical segments (two consecutive points defining the broken line have an equal x or y coordinate).</li>
</ul>

<p>The broken line is allowed to intersect or overlap itself in any way. Formally, each point of the plane may belong to any number of segments of the broken line.</p>

<p>This is an output-only task with partial scoring. You are given $10$ input files specifying the locations of dots. For each input file, you should submit an output file describing a broken line with the required properties. For each output file that describes a valid broken line your score depends on the <strong>number of segments</strong> in the broken line (see Scoring below).</p>

### 입력 

 <p>Each input file is in the following format:</p>

<ul>
	<li>line $1$: $\;\;n$</li>
	<li>line $1+i$ (for $1 \leq i \leq n$): $\;\; x[i] \;\; y[i]$</li>
</ul>

### 출력 

 <p>Each output file must be in the following format:</p>

<ul>
	<li>line $1$: $\;\;k$</li>
	<li>line $1+j$ (for $1 \leq j \leq k$): $\;\; sx[j] \;\; sy[j]$</li>
</ul>

<p>Note that the second line should contain $sx[1]$ and $sy[1]$ (i.e., the output <strong>should not</strong> contain $sx[0]$ and $sy[0]$). Each $sx[j]$ and $sy[j]$ should be an integer.</p>

