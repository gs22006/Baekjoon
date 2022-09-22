# [Diamond III] Selling RNA Strands - 16780 

[문제 링크](https://www.acmicpc.net/problem/16780) 

### 성능 요약

메모리: 707644 KB, 시간: 540 ms

### 분류

자료 구조(data_structures), 오프라인 쿼리(offline_queries), 세그먼트 트리(segtree), 트리(trees), 트라이(trie)

### 문제 설명

<p>Do you know Just Odd Inventions Co., Ltd? The bussiness of this company is doing “just odd inventions.” Here we shall abbreviate its name, and call it the JOI Company.</p>

<p>Recently, the JOI Company is faced with a serious decline in its profitability by doing just odd inventions only. It is planning to start a new business. The plan is to sell liquid containing RNA chains. An RNA chain is considered as a string consisting of 4 characters ‘A’, ‘G’, ‘C’, ‘U’. For its business, the JOI Company prepares N chains of RNA.</p>

<p>The JOI Company will accept an order of RNA chains from customers in the following form:</p>

<ul>
	<li>A customer chooses two strings P, Q. Then, among RNA chains prepared by the JOI Company, it sells strings whose first |P| characters are P and last |Q| characters are Q. Here, |P|, |Q| are the length of P, Q, respectively.</li>
</ul>

<p>How many RNA chains prepared by the JOI Company match the conditions of orders from customers?</p>

<p>Given the information on RNA chains prepared by the JOI Company and orders from customers, write a program which calculates the number of RNA chains prepared by the JOI Company which match the conditions of orders from customers.</p>

### 입력 

 <p>Read the following data from the standard input.</p>

<ul>
	<li>The first line of input contains two space separated integers N, M. This means the JOI Company prepares N chains of RNA, and there are M orders from customers.</li>
	<li>The i-th line (1 ≤ i ≤ N) of the following N lines contains a string S<sub>i</sub>, which is the i-th RNA chain prepared by the JOI Company.</li>
	<li>The j-th line (1 ≤ j ≤ M) of the following M lines contains two space separated strings P<sub>j</sub>, Q<sub>j</sub>. This means, in the j-th order, the customer chooses two strings P<sub>j</sub>, Q<sub>j</sub>.</li>
</ul>

### 출력 

 <p>The output consists of M lines. The j-th line (1 ≤ j ≤ M) contains an integer, the number of RNA chains prepared by the JOI Company which match the condition of the j-th order.</p>

