# [Ruby IV] Dungeon 3 - 20988 

[문제 링크](https://www.acmicpc.net/problem/20988) 

### 성능 요약

메모리: 232696 KB, 시간: 660 ms

### 분류

애드 혹, 값 / 좌표 압축, 자료 구조, 함수 개형을 이용한 최적화, 스위핑

### 문제 설명

<p>There is a dungeon with N + 1 floors. There are M players in the dungeon. The floors are numbered from 1 to N + 1, starting from the entrance. The players are numbered from 1 to M.</p>

<p>A player uses energy to move from a floor to the next floor. The amount of energy a player uses is A<sub>i</sub> if he moves from the floor i (1 ≤ i ≤ N) to the floor i + 1. As this is a one-way dungeon, the only possible moves between floors are from the floor i to the floor i + 1 for some i (1 ≤ i ≤ N).</p>

<p>In each of the floors from the floor 1 to the floor N, inclusive, there is a fountain of recovery. At the fountain of recovery in the floor i (1 ≤ i ≤ N), a player can increase his energy by 1 paying B<sub>i</sub> coins. A player can use a fountain multiple times as long as he has needed coins. However, each player has a maximum value of his energy, and his energy cannot exceed that value even if he uses a fountain of recovery.</p>

<p>Now the player j (1 ≤ j ≤ M) is in the floor S<sub>j</sub>. His current energy is 0. His maximum value of energy is U<sub>j</sub>. He wants to move to the floor T<sub>j</sub>. His energy cannot be smaller than 0 along the way. How many coins does he need?</p>

<p>Write a program which, given the information of the dungeon and the players, determines whether it is possible for each player to move to the destination so that his energy does not become smaller than 0 along the way. If it is possible to move, the program should calculate the minimum number of coins he needs.</p>

### 입력 

 <p>Read the following data from the standard input. Given values are all integers.</p>

<pre>N M
A<sub>1</sub> · · · A<sub>N</sub>
B<sub>1</sub> · · · B<sub>N</sub>
S<sub>1</sub> T<sub>1</sub> U<sub>1</sub>
.
.
.
S<sub>M</sub> T<sub>M</sub> U<sub>M</sub></pre>

### 출력 

 <p>Write M lines to the standard output. The j-th line (1 ≤ j ≤ M) should contain the minimum number of coins the player j needs to move to the floor T<sub>j</sub>. If it is impossible for the player j to move to the floor T<sub>j</sub>, output −1 instead.</p>

