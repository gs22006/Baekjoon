# [Diamond II] Beech Tree - 29748 

[문제 링크](https://www.acmicpc.net/problem/29748) 

### 성능 요약

메모리: 87820 KB, 시간: 188 ms

### 분류

이분 탐색, 자료 구조, 그리디 알고리즘, 작은 집합에서 큰 집합으로 합치는 테크닉, 정렬, 트리, 트리를 사용한 집합과 맵

### 문제 설명

<p>Vétyem Woods is a famous woodland with lots of colorful trees. One of the oldest and tallest beech trees is called Ős Vezér.</p>

<p>The tree Ős Vezér can be modeled as a set of $N$ <strong>nodes</strong> and $N-1$ <strong>edges</strong>. Nodes are numbered from $0$ to $N-1$ and edges are numbered from $1$ to $N-1$. Each edge connects two distinct nodes of the tree. Specifically, edge $i$ ($1 \le i \lt N$) connects node $i$ to node $P[i]$, where $0 \le P[i] \lt i$. Node $P[i]$ is called the <strong>parent</strong> of node $i$, and node $i$ is called a <strong>child</strong> of node $P[i]$.</p>

<p>Each edge has a color. There are $M$ possible edge colors numbered from $1$ to $M$. The color of edge $i$ is $C[i]$. Different edges may have the same color.</p>

<p>Note that in the definitions above, the case $i = 0$ does not correspond to an edge of the tree. For convenience, we let $P[0] = -1$ and $C[0] = 0$.</p>

<p>For example, suppose that Ős Vezér has $N = 18$ nodes and $M = 3$ possible edge colors, with $17$ edges described by connections $P = [-1, 0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 3, 4, 4, 5, 10, 11, 11]$ and colors $C = [0, 1, 2, 3, 1, 2, 3, 1, 3, 3, 2, 1, 1, 2, 2, 1, 2, 3]$. The tree is displayed in the following figure:</p>

<p style="text-align: center;"><img alt="" src="" style="width: 558px; height: 357px;"></p>

<p>Árpád is a talented forester who likes to study specific parts of the tree called <strong>subtrees</strong>. For each $r$ such that $0 \le r \lt N$, the subtree of node $r$ is the set $T(r)$ of nodes with the following properties:</p>

<ul>
	<li>Node $r$ belongs to $T(r)$.</li>
	<li>Whenever a node $x$ belongs to $T(r)$, all children of $x$ also belong to $T(r)$.</li>
	<li>No other nodes belong to $T(r)$.</li>
</ul>

<p>The size of the set $T(r)$ is denoted as $|T(r)|$.</p>

<p>Árpád recently discovered a complicated but interesting subtree property. Árpád's discovery involved a lot of playing with pen and paper, and he suspects you might need to do the same to understand it. He will also show you multiple examples you can then analyze in detail.</p>

<p>Suppose we have a fixed $r$ and a permutation $v_0, v_1, \ldots, v_{|T(r)|-1}$ of the nodes in the subtree $T(r)$.</p>

<p>For each $i$ such that $1 \le i \lt |T(r)|$, let $f(i)$ be the number of times the color $C[v_i]$ appears in the following sequence of $i-1$ colors: $C[v_1], C[v_2], \ldots, C[v_{i-1}]$.</p>

<p>(Note that $f(1)$ is always $0$ because the sequence of colors in its definition is empty.)</p>

<p>The permutation $v_0, v_1, \ldots, v_{|T(r)|-1}$ is a <strong>beautiful permutation</strong> if and only if all the following properties hold:</p>

<ul>
	<li>$v_0 = r$.</li>
	<li>For each $i$ such that $1 \le i \lt |T(r)|$, the parent of node $v_i$ is node $v_{f(i)}$.</li>
</ul>

<p>For any $r$ such that $0 \le r \lt N$, the subtree $T(r)$ is a <strong>beautiful subtree</strong> if and only if there exists a beautiful permutation of the nodes in $T(r)$. Note that according to the definition every subtree which consists of a single node is beautiful.</p>

<p>Consider the example tree above. It can be shown that the subtrees $T(0)$ and $T(3)$ of this tree are not beautiful. The subtree $T(14)$ is beautiful, as it consists of a single node. Below, we will show that the subtree $T(1)$ is also beautiful.</p>

<p>Consider the sequence of distinct integers $[v_0, v_1, v_2, v_3, v_4, v_5, v_6] = [1, 4, 5, 12, 13, 6, 14]$. This sequence is a permutation of the nodes in $T(1)$. The figure below depicts this permutation. The labels attached to the nodes are the indices at which those nodes appear in the permutation.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 509px; height: 328px;"></p>

<p>Clearly, the above sequence is a permutation of the nodes in $T(1)$. We will now verify that it is <em>beautiful</em>.</p>

<ul>
	<li>$v_0 = 1$.</li>
	<li>$f(1) = 0$ since $C[v_1] = C[4] = 1$ appears $0$ times in the sequence $[]$.
	<ul>
		<li>Correspondingly, the parent of $v_1$ is $v_0$. That is, the parent of node $4$ is node $1$. (Formally, $P[4] = 1$.)</li>
	</ul>
	</li>
	<li>$f(2) = 0$ since $C[v_2] = C[5] = 2$ appears $0$ times in the sequence $[1]$.
	<ul>
		<li>Correspondingly, the parent of $v_2$ is $v_0$. That is, the parent of $5$ is $1$.</li>
	</ul>
	</li>
	<li>$f(3) = 1$ since $C[v_3] = C[12] = 1$ appears $1$ time in the sequence $[1, 2]$.
	<ul>
		<li>Correspondingly, the parent of $v_3$ is $v_1$. That is, the parent of $12$ is $4$.</li>
	</ul>
	</li>
	<li>$f(4) = 1$ since $C[v_4] = C[13] = 2$ appears $1$ time in the sequence $[1, 2, 1]$.
	<ul>
		<li>Correspondingly, the parent of $v_4$ is $v_1$. That is, the parent of $13$ is $4$.</li>
	</ul>
	</li>
	<li>$f(5) = 0$ since $C[v_5] = C[6] = 3$ appears $0$ times in the sequence $[1, 2, 1, 2]$.
	<ul>
		<li>Correspondingly, the parent of $v_5$ is $v_0$. That is, the parent of $6$ is $1$.</li>
	</ul>
	</li>
	<li>$f(6) = 2$ since $C[v_6] = C[14] = 2$ appears $2$ times in the sequence $[1, 2, 1, 2, 3]$.
	<ul>
		<li>Correspondingly, the parent of $v_6$ is $v_2$. That is, the parent of $14$ is $5</li>
	</ul>
	</li>
</ul>

<p>As we could find a beautiful permutation of the nodes in $T(1)$, the subtree $T(1)$ is indeed beautiful.</p>

<p>Your task is to help Árpád decide for every subtree of Ős Vezér whether it is beautiful.</p>

### 입력 

 Empty

### 출력 

 Empty

