# [Diamond II] Electric Vehicle - 20172 

[문제 링크](https://www.acmicpc.net/problem/20172) 

### 성능 요약

메모리: 299132 KB, 시간: 1784 ms

### 분류

다이나믹 프로그래밍(dp)

### 문제 설명

<p>An electric vehicle(EV) is an alternative fuel automobile which uses one or more electric motors for propulsion, in place of the internal combustion engine such as diesel engine or gasoline one. The EV stores electricity in an energy storage device, such as a battery, and the electricity powers the vehicle’s wheels via an electric motors. Due to its limited energy storage capacity, the EV must be regularly recharged by plugging into an electrical source.</p>

<p>There are <em>n</em> villages, referred to points on a plane. For arbitrary two villages, there is only one road between them. Thus, there are exactly <em>n</em> × (<em>n</em> − 1)/2 roads connecting villages each other. Let two villages <em>A</em> and <em>B</em> have coordinates (<em>a</em>, <em>b</em>) and (<em>c</em>, <em>d</em>), respectively. Then the length of the road between <em>A</em> and <em>B</em> is defined to be <em>d</em>(<em>A</em>, <em>B</em>) = |<em>a</em> – <em>c</em>| + |<em>b</em> – <em>d</em>|, which is called the distance between <em>A</em> and <em>B</em>. For convenience, it is assumed that the distance between <em>A</em> and <em>B</em> is equivalent to the amount of electricity needed for an EV to move between <em>A</em> and <em>B</em>. That is, while an EV consumes a unit electricity, say electricity 1, it can move a unit distance, say distance 1.</p>

<p>Each village has a charging station for an EV and the cost of charging may vary from village to village. Let <em>c</em>(<em>A</em>) be the cost per electricity 1 when an EV is charged in village <em>A</em>. By the above assumption, an EV with zero charge at village <em>A</em> must be charged at the cost of at least <em>c</em>(<em>A</em>)<em>d</em>(<em>A</em>, <em>B</em>) in <em>A</em> to arrive at village <em>B</em>.</p>

<p>Minsu should go from the village <em>S</em> to the village <em>T</em> by his EV. The EV is discharged, that is, with zero charge, at <em>S</em> before departure. Also the EV has a battery of maximum charge capacity <em>W</em>. That is, the EV cannot store the amount of electricity more than <em>W</em>. Thus if the EV is fully charged, then it can move as much as <em>W</em>. During the way from <em>S</em> to <em>T</em>, Minsu is allowed to make at most ∆ stops for recharging. Also the charging at the starting village <em>S</em> is considered as one of the stops for recharging. Then Minsu should find the cheapest way possible to move from <em>S</em> to <em>T</em>.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 251px; height: 217px;"></p>

<p>For example, the above figure shows five villages in a plane with the costs of charging represented by the numbers in pentagons. Also, let <em>W</em> = 3 and ∆= 2. Three ways from <em>S</em> to <em>T</em>, <em>P</em><sub>1</sub>, <em>P</em><sub>2</sub>, and <em>P</em><sub>3</sub>, are shown as red, purple, and blue, respectively. In <em>P</em><sub>1</sub>, the EV is charged by electricity 2 at <em>S</em>, and it is recharged by electricity 2 at (1, 3). So, totally the cost of 2 × 4 + 2 × 4 = 16 is incurred. For the case of <em>P</em><sub>2</sub>, the EV is fully charged at <em>S</em>, and so the electricity 1 remains in the battery of EV when arriving at (2, 2). Then the EV is recharged at (2, 2) only by electricity 1 to reach <em>T</em>. So, totally the cost of 3 × 4 + 1 × 5 = 17 is incurred. Finally, in <em>P</em><sub>3</sub>, the EV is charged by electricity 2 at <em>S</em> to move to (3, 1) and it is recharged by electricity 2 at (3, 1). So, totally the cost of 2 × 4 + 2 × 3 = 14 is incurred. The cost 14 is minimum and <em>P</em><sub>3</sub> is the cheapest way to move from <i>S</i> to <em>T</em>.</p>

<p>Given the coordinates of <em>n</em> villages including <em>S</em> and <em>T</em>, the charging cost at each village, the maximum charge capacity <em>W</em> of EV’s battery, and the arbitrary positive integer ∆, write a program to find the cheapest way to move from <em>S</em> to <em>T</em> with at most ∆ stops for recharging.</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with an integer <em>n</em> (2 ≤ <em>n</em> ≤ 1,000), representing the number of villages. Each of the following <em>n</em> lines contains three integers, <em>a</em>, <em>b</em>, and <em>c</em> (0 ≤ <em>a</em>, <em>b</em> ≤ 10<sup>6</sup> and 1 ≤ <em>c</em> ≤ 10<sup>4</sup>), where (<em>a</em>, <em>b</em>) is the coordinate of a village and <em>c</em> is the charging cost at the village. Here, in the <em>n</em> lines, the first line contains the coordinate of the starting village <em>S</em> and the second line contains the coordinate of the destination village <em>T</em>. Note that the coordinates of villages are all distinct. The next line contains an integer <em>W</em> (1 ≤ <em>W</em> ≤ 10<sup>5</sup>) that represents the maximum charge capacity of EV’s battery. The last line contains a positive integer ∆ (1 ≤ ∆ ≤ 10), which indicates the maximum number of times for recharging while the EV travels from <em>S</em> to <em>T</em>. The charging at the starting village <em>S</em> is considered as one of the stops for recharging.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line. The line should contain the cost of the cheapest way for the EV to move from <em>S</em> to <em>T</em> with at most ∆ stops for recharging. If such a way does not exist, then the line should contain -1.</p>

