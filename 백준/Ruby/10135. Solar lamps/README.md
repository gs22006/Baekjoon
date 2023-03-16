# [Ruby V] Solar lamps - 10135 

[문제 링크](https://www.acmicpc.net/problem/10135) 

### 성능 요약

메모리: 83180 KB, 시간: 460 ms

### 분류

자료 구조, 세그먼트 트리, 분할 정복

### 문제 설명

<p>Byteasar has a large and pretty garden. As he would like to be able to appreciate its beauty even after dusk, he installed lamps across the garden.</p>

<p>The lamps are directional, i.e., they illuminate only a certain angle, common to them all. Moreover, Byteasar has aligned them so that they all face the same direction. Last but not least, these are solar lamps, i.e., they come with solar panels but no batteries, strangely enough! You might think the panels are thus useless, and each lamp will require electricity at night, but not quite: A lamp will produce light if a sufficient number of lamps illuminate it.</p>

<p>By now, Byteasar has even come up with an order he is going supply the lamps with electricity, thus turning them on. For simplicity, we number the lamps from 1 to  in this order, i.e., the lamp no.  is supplied with electricity at time . The only thing left for Byteasar (and you, of course!) is to figure out when exactly each lamp will start emitting light. Help Byteasar by writing a program that will determine the answer to this question.</p>

### 입력 

 <p>The first line of the standard input contains a single integer n(1 ≤ n ≤ 200,000): the number of lamps Byteasar installed. In the second line of input, there are four integers X<sub>1</sub>,Y<sub>1</sub>,X<sub>2</sub>,Y<sub>2</sub>(-10<sup>9</sup> ≤ X<sub>i</sub>,Y<sub>i</sub> ≤ 10<sup>9</sup>, (X<sub>i</sub>,Y<sub>i</sub>)≠(0,0)), separated by single spaces, that describe the area illuminated by every lamp. Namely, if there is a lamp located at the point (x,y), then it illuminates the area (together with its edge) within the smaller of the two angles formed by two rays that both originate at (x,y) such that the i-th (for i=1,2) ray passes through (x+X<sub>i</sub>, y+Y<sub>i</sub>). This angle is always smaller than 180 degrees.</p>

<p>The n input lines that follow specify the locations of the lamps: the i-th such line contains two integers x<sub>i</sub>,y<sub>i</sub>, (-10<sup>9</sup> ≤ x<sub>i</sub>,y<sub>i</sub> ≤ 10<sup>9</sup>) separated by a single space, that indicate that the lamp no. i is located at the point (x<sub>i</sub>,y<sub>i</sub>). You may assume that no two lamps share their location.</p>

<p>The last line of the input contains n integers k<sub>1</sub>,k<sub>2</sub>,…,k<sub>n</sub>(1 ≤ k<sub>i </sub>≤ n), separated by single spaces, that signify that if the lamp no. i is in the area illuminated by at least k<sub>i</sub> other lamps, then it will start emitting light as well.</p>

<p>In tests worth 30% of the total score, it holds that n ≤ 1,000.</p>

### 출력 

 <p>Your program should print out to the standard output a single line with n integers t<sub>1</sub>,…,t<sub>n</sub>, separated by single spaces. The number t<sub>i</sub> should be the time when the lamp no. i starts producing light.</p>

