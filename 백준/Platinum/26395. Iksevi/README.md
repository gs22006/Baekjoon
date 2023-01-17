# [Platinum IV] Iksevi - 26395 

[문제 링크](https://www.acmicpc.net/problem/26395) 

### 성능 요약

메모리: 2288 KB, 시간: 156 ms

### 분류

수학(math), 정수론(number_theory), 소수 판정(primality_test), 에라토스테네스의 체(sieve)

### 문제 설명

<p>After ten years of programming, Vinko has decided to change his profession and become a ceramist. Already on the first day of his new job he got an extremely difficult task.</p>

<p>He has to pave the concert hall’s floor with square ceramic tiles. However, he won’t pave the floor so that the tiles are parallel with the hall’s walls. Instead, he will rotate them so that the diagonals of the tiles are parallel to the walls.</p>

<p>Vinko has not decided which size of tiles he will use, but he knows they all have to be the same size, and that the length of their diagonals in millimeters has to be a positive even integer. He will put the first tile so that it touches the bottom and left walls, and then he will pave the others so that they share a side with some of the previously set tiles. He will repeat the procedure until he paves the whole floor, whose dimensions are 10<sup>7</sup> × 10<sup>7</sup> square millimeters.</p>

<p>Besides being a good programmer and ceramist, Vinko is also an excellent musician. Because of that, he knows that there are n points on the floor that are crucial for good acoustics in the hall. The hall’s acoustics would improve significantly if a tile’s corner is at one of the n points.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/52607d33-cd75-4f4c-8967-dc65b572c28f/-/preview/" style="width: 491px; height: 212px;"></p>

<p style="text-align: center;">The left image shows the paving whose tiles have a diagonal of length 4. The point (2, 4) at on the corner of a tile, and for it the acoustics are good, but for the points (4, 3) and (5, 1) are not.</p>

<p style="text-align: center;">The right image shows the paving whose tiles have a diagonal of length 2. The point (4, 3) is at the corner of a tile, while points (2, 4) and (5, 1) are not.</p>

<p>Help Vinko determine for each of the n points in how many ways can he pave the floor (that is, how many different dimensions of the tiles can he choose) so that the i-th point is at a tile corner.</p>

### 입력 

 <p>The first line contains the integer n (1 ≤ n ≤ 10<sup>6</sup>), the number of acoustic points.</p>

<p>The following n lines contain two integers x<sub>i</sub>, y<sub>i</sub> (0 ≤ x<sub>i</sub>, y<sub>i</sub> ≤ 10<sup>7</sup>), which indicates that the i-th point is x<sub>i</sub> millimeters away from the left wall, and y<sub>i</sub> millimeters away from the lower wall of the hall.</p>

### 출력 

 <p>In the i-th of n lines print the number from the task statement for the i-th point.</p>

