# [Platinum III] Poklon - 12700 

[문제 링크](https://www.acmicpc.net/problem/12700) 

### 성능 요약

메모리: 84628 KB, 시간: 368 ms

### 분류

애드 혹(ad_hoc), 깊이 우선 탐색(dfs), 그래프 이론(graphs), 그래프 탐색(graph_traversal), 수학(math), 트리(trees)

### 문제 설명

<p>The main (potentially tragic) hero of this task is Kile, otherwise known as the joker from the bench of the semiliterate team El Locos, and who is celebrating his birthday today.</p>

<p>His best friend Ivan has decided to gift him a special pharmaceutical scale. The specialty of this scale is that it is recursive, i.e., at the end of each beam, there is either a weight, a new scale, or nothing. Of course, the scale leans to the left if the total mass on its left beam is larger than the total mass on its right beam. Analogously, if the mass is larger on the right beam, then the scale leans to the right. Otherwise, we say that the scale is balanced.</p>

<p><img alt="" src="https://onlinejudgeimages.s3.amazonaws.com/problem/12700/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7%202017-03-09%20%EC%98%A4%ED%9B%84%208.57.34.png" style="height:156px; width:300px"></p>

<p>Kile really likes the gift, and, as a true computer scientist, he immediately tries to balance it using new weights for which total mass is the lowest possible ​. New weights should be positive real numbers. We say that a recursive scale is balanced if it is balanced and all its subscales are balanced.</p>

<p>After having successfully balanced the scale, Kile decided to tattoo on his chest the total mass of the weights placed on the scale, in binary notation, without leading zeros. What number is tattooed on Kile’s chest?</p>

### 입력 

 <p>The first line of input contains the positive integer that represents the total N (1 ≤ N ≤ 10<sup>6</sup>) number of scales Kile’s recursive scale consists of (including itself).</p>

<p>The ith of the following N lines contains two whole numbers that respectively describe the left and the right beam of the scale with index i. A positive number in the scale description denotes the index of the scale located on that beam, whereas a non-positive number denotes that there is a weight on that beam, with its mass corresponding to the absolute value of the number. Root scale which contains all other scales has index 1.</p>

<p>All numbers from the input are in absolute value less than or equal to 10<sup>9</sup>.</p>

### 출력 

 <p>The first and only line of output must contain the total mass of the weights located on Kile’s scale. This number needs to be in binary notation, without leading zeros.</p>

