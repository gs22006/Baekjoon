# [Gold I] Weird sort - 7483 

[문제 링크](https://www.acmicpc.net/problem/7483) 

### 성능 요약

메모리: 7844 KB, 시간: 120 ms

### 분류

그리디 알고리즘(greedy), 정렬(sorting)

### 문제 설명

<p>Having a sequence of N integers a<sub>1</sub>, a<sub>2</sub>, …, a<sub>N</sub>, you need to order them in a way when no two consecutive integers have consecutive values. In other words, for all i, where 0<i<N, condition a<sub>i</sub>+1≠a<sub>i+1</sub> should be satisfied for the final sequence.</p>

<p>If more than one sequence satisfying this condition exists, lexicographically minimal one should be found.</p>

### 입력 

 <p>The input file consists of several data sets. In the first line of each set the sequence length N (1≤N≤50000) is given. The second line contains N integers a<sub>1</sub>, a<sub>2</sub>, …, a<sub>N</sub>, separated by single spaces. Each integer does not exceed 10<sup>9</sup> in its absolute value. The value N=0 indicates the end of the input file.</p>

### 출력 

 <p>For each data set you need to print result sequence in separate line. Integers in the sequence must be separated by single spaces. Print "No solution" (without quotes) if requested sequence does not exist.</p>

