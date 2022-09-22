# [Diamond IV] Spring cleaning - 19683 

[문제 링크](https://www.acmicpc.net/problem/19683) 

### 성능 요약

메모리: 27984 KB, 시간: 512 ms

### 분류

자료 구조(data_structures), Heavy-light 분할(hld), 세그먼트 트리(segtree), 트리(trees)

### 문제 설명

<p>Spring cleanings are probably the most boring parts of our lives, except this year, when Flóra and her mother found a dusty old tree graph under the carpet.</p>

<p>This tree has <em>N</em> nodes (numbered from 1 to <em>N</em>), connected by <em>N</em> − 1 edges. The edges gathered too much dust, so Flóra’s mom decided to clean them.</p>

<p>Cleaning the edges of an arbitrary tree is done by repeating the following process: She chooses 2 different leaves (a node is a leaf if it is connected to exactly one other node by an edge), and cleans every edge lying on the shortest path between them. If this path has <em>d</em> edges, then the cost of cleaning this path is <em>d</em>.</p>

<p>She doesn’t want to harm the leaves of the tree, so she chooses every one of them <strong>at most once</strong>. A tree is cleaned when all of its edges are cleaned. The cost of this is the sum of costs for all cleaned paths.</p>

<p>Flóra thinks the tree they found is too small and simple, so she imagines <em>Q</em> variations of it. In the <em>i</em>-th variation, she adds a total of <em>D<sub>i</sub></em> extra leaves to the <strong>original</strong> tree: for each new leaf, she chooses a node from the <strong>original</strong> tree, and connects that node with the new leaf by an edge. Note that some nodes may stop being leaves during this step.</p>

<p>For all these <em>Q</em> variations, we are interested in the minimum cost that is required to clean the tree.</p>

### 입력 

 <p>The first line contains two space-separated integers, <em>N</em> and <em>Q</em>.</p>

<p>Each of the next <em>N</em> − 1 lines contains two space-separated integers <em>u</em> and <em>v</em>, denoting that nodes <em>u</em> and <em>v</em> are connected by an edge.</p>

<p>The next <em>Q</em> lines describe the variations: the first integer in the <em>i</em>-th line is <em>D<sub>i</sub></em>. Then <em>D<sub>i</sub></em> space-separated integers follow: if the <em>j</em>-th number is <em>a<sub>j</sub></em>, it means that Flóra adds a new leaf to the node <em>a<sub>j</sub></em>. We may add more than one leaf to the same node.</p>

<p>After each variation, Flóra restarts and adds extra leaves to the <strong>original</strong> tree.</p>

### 출력 

 <p>You should print <em>Q</em> lines. In the <em>i</em>-th line print a single integer: the minimum cost required to clean the <em>i</em>-th variation of the tree. If the tree cannot be cleaned, print −1.</p>

