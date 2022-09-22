# [Diamond IV] Newspapers - 23065 

[문제 링크](https://www.acmicpc.net/problem/23065) 

### 성능 요약

메모리: 2080 KB, 시간: 0 ms

### 분류

구성적(constructive), 깊이 우선 탐색(dfs), 그래프 이론(graphs), 그래프 탐색(graph_traversal), 트리(trees)

### 문제 설명

<p>„<em>Ulovi me, ulovi me, kupit ću ti novine!</em>” – a popular play song among Croatian children. Translates to <em>catch me, and I’ll buy you newspapers</em>.</p>

<p>Ankica and Branko are playing a chasing game on an undirected, connected graph. Namely, Branko is moving around the graph, while Ankica is attempting to catch him. The game proceeds in turns, and a single turn consists of the following:</p>

<ul>
	<li><strong>Ankica makes a guess on Branko’s whereabouts.</strong> More precisely, she guesses that Branko is currently located at a specific node. If she guesses correctly, Branko is caught and the game ends. Otherwise,</li>
	<li><strong>Branko traverses an edge incident to his current location.</strong> In other words, Branko moves to one of his neighbouring nodes. Note that Branko cannot stay at his present location.</li>
</ul>

<p>Given a graph, determine if Ankica has a finite strategy which always catches Branko regardless of the way Branko plays and what his starting position may be.</p>

<p>More formally, we represent Ankica’s strategy as an array $A = (a_1, a_2, \dots , a_k)$, where $a_i$ denotes Ankica’s guess in the $i$-th turn (i.e. she guesses that Branko is located in the node $a_i$).</p>

<p>Similarly, we represent Branko’s movements as an array $B = (b_1, b_2, \dots , b_k)$, where $b_i$ represents the node in which Branko is located before the $i$-th turn. Additionally, for each two successive elements $b_i$ and $b_{i+1}$ ($1 \le i < k$), there must exist an edge in the graph connecting nodes $b_i$ and $b_{i+1}$. Note that no such constraint is imposed on array $A$.</p>

<p>We say that Ankica’s strategy is successful, i.e. she catches Branko in at most $k$ turns, if, for every valid array $B$ of length $k$, there exists some $i$ ($1 \le i \le k$) such that $a_i = b_i$ holds.</p>

<p>If such strategy exists, you should find one that minimizes the number $k$.</p>

<p>You can score some points in this task if you are able to provide a succesful, but not optimal, strategy for Ankica (i.e. a strategy where $k$ is not minimal). See the <em>Scoring</em> section for more details.</p>

### 입력 

 <p>The first line contains two integers $N$ and $M$ ($N - 1 \le M \le \frac{N(N-1)}{2}$) that represent the number of nodes and edges in the graph (respectively). Nodes of the graph are denoted with integers from 1 to $N$.</p>

<p>The $i$-th of the next $M$ lines contains two space-separated integers $u_i$ and $v_i$ ($1 \le u_i, v_i \le N$, $u_i \ne v_i$), representing that an undirected edge connects nodes $u_i$ and $v_i$. No edge will appear more than once in the input, and the graph will be connected.</p>

### 출력 

 <p>If there is no successful strategy for Ankica, simply output "<code>NO</code>" in the first line and terminate the program.</p>

<p>Otherwise, you should output "<code>YES</code>" in the first line.</p>

<p>The second line should contain the number $k$ from the task description. The third line should contain $k$ numbers $a_1, a_2, \dots , a_k$ from the task description.</p>

