# [Diamond II] Skyscraper - 16781 

[문제 링크](https://www.acmicpc.net/problem/16781) 

### 성능 요약

메모리: 288456 KB, 시간: 800 ms

### 분류

다이나믹 프로그래밍(dp)

### 문제 설명

<p>The International Olympiad in Informatics will be held in Tsukuba City, Japan. In order to prepare for IOI, we are planning to construct skyscraper buildings in the main street of Tsukuba City. Since we want to create a new sightseeing spot, the buildings have to satisfy the following conditions.</p>

<p>We are planning to construct N buildings along a straight line in the main street. The heights of them are A<sub>1</sub>, A<sub>2</sub>, A<sub>3</sub>, . . . , A<sub>N</sub>. They are different from each other. Since the order of N buildings are not yet decided, we can permute their heights if necessary. We will decorate them for IOI. Due to the constraints of materials used for decoration, the sum of the absolute values of the differences of the heigts of two adjacent buildings must be less than or equal to L. In other words, if the heights of the buildings from one side of the main street are f<sub>1</sub>, f<sub>2</sub>, f<sub>3</sub>, . . . , f<sub>N</sub>, we must have |f<sub>1</sub> − f<sub>2</sub>| + |f<sub>2</sub> − f<sub>3</sub>| + . . . + |f<sub>N−1</sub> − f<sub>N</sub>| ≤ L. Here, |x| is the absolute value of x.</p>

<p>How many permutations of buildings satisfy the above condition?</p>

<p>Given the number N of buildings, their heights, and the upper limit L of the sum of the absolute values of the differences of the heigts of two adjacent buildings, write a program which calculates the number of permutations of buildings satisfying the condition. Since this number can be too big, output the remainder of division of it by 1 000 000 007.</p>

### 입력 

 <p>Read the following data from the standard input.</p>

<ul>
	<li>The first line of input contains two space separated integers N, L. This means the number of buildings is N, and the upper limit of the sum of the absolute values of the differences of the heigts of two adjacent buildings is L.</li>
	<li>The second line contains N space separated integers A<sub>1</sub>, A<sub>2</sub>, A<sub>3</sub>, . . . , A<sub>N</sub>. This means the height of the i-th building (1 ≤ i ≤ N) is A<sub>i</sub>.</li>
</ul>

### 출력 

 <p>The output consists of one line. It contains an integer, the remainder of division of the number of permutations of buildings satisfying the condition by 1 000 000 007.</p>

