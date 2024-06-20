# [Gold I] Andrew’s Amazing Architecture - 16100 

[문제 링크](https://www.acmicpc.net/problem/16100) 

### 성능 요약

메모리: 9832 KB, 시간: 28 ms

### 분류

그리디 알고리즘, 두 포인터

### 제출 일자

2024년 6월 20일 10:57:41

### 문제 설명

<p>Aaron has a large supply of blocks and has challenged Andrew to build a structure out of them. All of the blocks are k × 1 × 1 for various values of k. The structure must be made up of n nonempty columns lined up in a sequence such that all blocks in column i have dimensions h<sub>i</sub> × 1 × 1, and have a 1 × 1 face that is parallel to the ground. Moreover, the structure must be a pyramid. A pyramid must contain an apex column such that for each column j to the left of the apex, the height of column j is no more than the height of column j + 1 and for each column k to the right of the apex, the height of column k is no more than the height of column k −1. For example, the left structure in Figure A.1 is not a pyramid since it does not have an apex column, while the right structure is a pyramid because the third column from the left is an apex column (as is the fourth column from the left).</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/bc2574d3-0ba0-4f0a-ae3d-4a3a0ef3f7eb/-/preview/" style="width: 466px; height: 323px;"></p>

<p style="text-align: center;">Figure A.1: (left) An example that is not a pyramid. (right) An example of a pyramid. In both cases, n = 8 with blocks of size 6, 8, 4, 5, 6, 4, 2, 3 in the columns from left to right. This sequence is given in Sample Input 3.</p>

<p>Of course, just building a pyramid is easy, so Aaron has asked Andrew to find the pyramid with the smallest volume given a sequence of block sizes to use. Help Andrew by determining the smallest volume possible. You may assume that there is an unlimited supply of blocks of each size.</p>

### 입력 

 <p>The input starts with a line containing a single integer n (1 ≤ n ≤ 200 000), which is the length of the sequence.</p>

<p>The second line describes the blocks. This line contains n integers h<sub>1</sub>, h<sub>2</sub>, . . . , h<sub>n</sub> (1 ≤ h<sub>i</sub> ≤ 100 000), denoting that the blocks used in column i must be h<sub>i</sub> × 1 × 1.</p>

### 출력 

 <p>Display the smallest volume of a pyramid.</p>

