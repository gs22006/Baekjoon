# [Gold III] Just Long Neckties - 18431 

[문제 링크](https://www.acmicpc.net/problem/18431) 

### 성능 요약

메모리: 11400 KB, 시간: 104 ms

### 분류

자료 구조, 그리디 알고리즘, 누적 합, 정렬

### 문제 설명

<p>Have you ever heard of Just Odd Inventions, Ltd.? This company is known for their “just odd inventions.” We call it JOI, Ltd. in this problem. JOI, Ltd. has invented its newest product “Just Long Neckties”. There are N + 1 types of neckties, numbered 1 to N + 1. The length of the i-th necktie (1 ≤ i ≤ N + 1) is A<sub>i</sub>.</p>

<p>The company gathered their employees to hold a try-on party. N employees participate in the party, and the j-th employee (1 ≤ j ≤ N) initially wears a necktie of length B<sub>j</sub>.</p>

<p>The try-on party is held following this procedure:</p>

<ol>
	<li>CEO of JOI, Ltd. chooses a necktie, which is not used at the party.</li>
	<li>Then, each employee chooses one of the remaining neckties to try on. No two employees choose the same necktie.</li>
	<li>Finally, each employee takes off the necktie which (s)he initially wears and puts the selected necktie on.</li>
</ol>

<p>If an employee initially wearing a necktie of length b tries a necktie of length a, (s)he feels strangeness of max{a − b, 0}. The oddity of the try-on party is defined as the maximum strangeness among the employees.</p>

<p>We also define C<sub>k</sub> as the minimum oddity of the try-on party if CEO of JOI, Ltd. chooses the k-th necktie.</p>

<p>Write a program which, given the lengths of the neckties used at the party and the neckties each employee initially wears, calculates the values of C<sub>1</sub>,C<sub>2</sub>, . . . ,C<sub>N+1</sub>.</p>

### 입력 

 <p>Read the following data from the standard input. Given values are all integers.</p>

<pre>N
A<sub>1</sub> . . . A<sub>N+1</sub>
B<sub>1</sub> . . . B<sub>N</sub></pre>

### 출력 

 <p>Write one line to the standard output. The output should contain the values of C<sub>1</sub>,C<sub>2</sub>, . . . ,C<sub>N+1</sub>, separated by a space.</p>

