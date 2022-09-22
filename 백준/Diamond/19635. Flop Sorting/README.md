# [Diamond I] Flop Sorting - 19635 

[문제 링크](https://www.acmicpc.net/problem/19635) 

### 성능 요약

메모리: 18180 KB, 시간: 192 ms

### 분류

구성적(constructive), 분할 정복(divide_and_conquer), 정렬(sorting)

### 문제 설명

<p>Desperate to contribute to the CCO, Robert tried inventing a segment tree problem. The specification for that problem is:</p>

<blockquote>
<p>You are given a list of N distinct integers between 1 and N. These are arranged in a row such that the i-th integer from the left is a<sub>i</sub>, where 1 ≤ i ≤ N. We define a flop operation on a set of elements as swapping the minimum element of the set with the maximum element of the set. There will be Q flop operations, each specifying two numbers l and r (1 ≤ l ≤ r ≤ N). For each operation, you must perform a flop on the interval [l, r] (that is, on the segment of numbers a<sub>l</sub>, a<sub>l+1</sub>, . . . , a<sub>r−1</sub>, a<sub>r</sub>). You must perform the Q flops in the order given, and report the final result.</p>
</blockquote>

<p>Now that he is finished with the problem statement, Robert needs to create some test data. For one test case in particular, he is trying to encode an inside joke into the initial and final sequences of numbers. With these two sequences fixed, help him find any sequence of flop operations that transforms the first sequence into the second.</p>

### 입력 

 <p>The first line will contain the integer N (1 ≤ N ≤ 4096). The second line will contain N distinct space separated integers between 1 and N, representing the initial sequence. The third line will also contain N distinct space separated integers between 1 and N, representing the final sequence.</p>

### 출력 

 <p>The first line of output should contain the integer Q, with Q ≤ 300 000. The next Q lines should contain two integers l and r with 1 ≤ l ≤ r ≤ N.</p>

