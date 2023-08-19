# [Diamond IV] Olympic Bus - 18434 

[문제 링크](https://www.acmicpc.net/problem/18434) 

### 성능 요약

메모리: 178668 KB, 시간: 236 ms

### 분류

데이크스트라, 그래프 이론

### 문제 설명

<p>There are N cities in JOI Kingdom, numbered from 1 to N. There are M bus lines connecting cities, numbered from 1 to M. The i-th bus line (1 ≤ i ≤ M) runs from the city U<sub>i</sub> to the city V<sub>i</sub>, and its fare is C<sub>i</sub> yen. On the i-th bus line (1 ≤ i ≤ M), a passenger cannot get on the bus in a city other than the city U<sub>i</sub>. Also, a passenger cannot get off the bus in a city other than the city V<sub>i</sub>. There may be more than one bus lines from a city to another city.</p>

<p>The Olympic Games will be held in JOI Kingdom soon. President K is the Minister of Transport of JOI Kingdom. President K will choose at most one bus line, and invert its direction without changing its fare just before the Olympic Games. Namely, if he chooses the i-th bus line (1 ≤ i ≤ M), it will not run from the city U<sub>i</sub> to the city V<sub>i</sub> during the Olympic Games; instead, it will run from the city V<sub>i</sub> to the city U<sub>i</sub>. The cost to invert the direction is D<sub>i</sub> yen, and it will be paid by President K. In order to avoid confusion, it is not allowed to invert the direction during the Olympic Games.</p>

<p>Since President K is the Minister of Transport, during the Olympic Games, he will make a round trip between the city 1 and the city N using the bus lines. By choosing (or not choosing) a bus line to be inverted appropriately, he wants to minimize the sum of the cost of the round trip and the cost to invert the chosen bus line.</p>

<p>Write a program which, given the number of cities and information of the bus lines, calculates the minimum sum of the cost of the round trip and the cost to invert the chosen bus line. If it is not possible to make a round trip between the city 1 and the city N by choosing a bus line to be inverted, output −1 instead.</p>

### 입력 

 <p>Read the following data from the standard input. Given values are all integers.</p>

<pre>N M
U<sub>1</sub> V<sub>1</sub> C<sub>1</sub> D<sub>1</sub>
.
.
.
U<sub>M</sub> V<sub>M</sub> C<sub>M</sub> D<sub>M</sub></pre>

### 출력 

 <p>Write the minimum sum of the cost of the round trip and the cost to invert the chosen bus line to the standard output. If it is not possible to make a round trip between the city 1 and the city N, write −1 instead.</p>

