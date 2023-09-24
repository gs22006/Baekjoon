# [Diamond V] The Firm Knapsack Problem - 21644 

[문제 링크](https://www.acmicpc.net/problem/21644) 

### 성능 요약

메모리: 10836 KB, 시간: 40 ms

### 분류

그리디 알고리즘, 정렬

### 문제 설명

<p>The Knapsack problem is a classic problem in Computer Science.</p>

<p>It is stated the following way. There are $n$ items, for each item you know its weight $w_i$ and cost $cost_i$. Also you know the capacity of the knapsack $W$ --- the upper limit for the total weight of taken items. The task is to select several items with total weight at most $W$ so that their total cost is as large as possible.</p>

<p>In this problem you don't have to solve the classic Knapsack problem. The jury has already solved it and found the exact answer: $x$ is the maximal possible total cost of items that fit into a knapsack of capacity $W$. The jury doesn't tell you this value.</p>

<p>Your task is to solve The Firm Knapsack Problem. Now the knapsack of claimed capacity $W$ can hold the weight of items up to $\frac{3}{2}W$. You need to solve the problem with this weakened constraint not worse than the jury have solved the problem with the original constraint $W$.</p>

<p>In other words, you need to find a set of items with total cost at least $x$ and total weight at most $\frac{3}{2}W$.</p>

### 입력 

 <p>The input data contains one or several test cases.</p>

<p>The first line contains the number of test cases. Then follow the tests in the following format.</p>

<p>The first line of the test case contains two integers $n$ and $W$ ($1 \le n \le 10^5$; $1 \le W \le 10^{12}$) --- the number of items and the claimed capacity of the knapsack.</p>

<p>The next $n$ lines describe items. Each line contains two integers $w_i$ and $cost_i$ ($1 \le w_i, cost_i \le 10^6$) --- the weight and the cost of an item.</p>

<p>The sum of $n$ over all test cases is at most $10^5$.</p>

### 출력 

 <p>For each test case, output the selected set of items for weight constraint $\frac{3}{2}W$ in the following format.</p>

<p>The first line should contain the number of taken items.</p>

<p>The second line should contain the indices of taken items $i_1\ i_2\ \dots \ i_k$ ($1 \le i_j \le n$). All indices $i_j$ should be distinct. Items are numbered from $1$ to $n$ in the same order as they are given in the input.</p>

<p>If there are several solutions, output any one of them.</p>

