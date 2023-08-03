# [Diamond III] Robot - 20987 

[문제 링크](https://www.acmicpc.net/problem/20987) 

### 성능 요약

메모리: 46508 KB, 시간: 24 ms

### 분류

데이크스트라, 그래프 이론, 그리디 알고리즘

### 문제 설명

<p>There are N crossings in the IOI town, numbered from 1 to N. There are M roads, numbered from 1 to M. Each road connects two different crossings in both directions. The road i (1 ≤ i ≤ M) connects the crossing A<sub>i</sub> and the crossing B<sub>i</sub>. No two different roads connect the same pair of crossings. Each of the roads has a color, which is described as an integer between 1 and M, inclusive. Currently, the color of the road i is C<sub>i</sub>. More than one road may have the same color.</p>

<p>The JOI Co., Ltd. developed a robot moving around the crossings of the IOI town. Whenever you tell a color to the robot, the robot will find the road with that color, and then the robot will pass through it and moves to the adjacent crossing. However, if there are more than one roads with the told color connected to the current crossing of the robot, it cannot decide which road it should pass through, and will halt.</p>

<p>The robot is currently in the crossing 1. Your task is to move the robot to the crossing N by telling colors to it. However, it is not always true that the robot can be moved to the crossing N. You may change the colors of some of the roads <strong>in advance</strong> so that the robot can be moved to the crossing N. It costs P<sub>i</sub> yen to change the color of the road i (1 ≤ i ≤ M) to any color between 1 and M, inclusive.</p>

<p>Write a program which, given the information of the crossings and the roads, calculates the minimum total cost. However, if it is impossible to move the robot to the crossing N even if you change the colors of the roads, output -1 instead.</p>

### 입력 

 <p>Read the following data from the standard input. Given values are all integers.</p>

<pre>N M
A<sub>1</sub> B<sub>1</sub> C<sub>1</sub> P<sub>1</sub>
.
.
.
A<sub>M</sub> B<sub>M</sub> C<sub>M</sub> P<sub>M</sub></pre>

### 출력 

 <p>Write one line to the standard output. The output should contain the minimum total cost. However, if it is impossible to move the robot to the crossing N even if you change the colors of the roads, output -1 instead.</p>

