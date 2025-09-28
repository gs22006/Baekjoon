# [Gold V] Eggfruit Cake - 18033 

[문제 링크](https://www.acmicpc.net/problem/18033) 

### 성능 요약

메모리: 4876 KB, 시간: 0 ms

### 분류

수학, 이분 탐색, 조합론, 두 포인터

### 제출 일자

2025년 9월 29일 00:41:22

### 문제 설명

<p>Today is Jaime’s birthday and, to celebrate, his friends ordered a cake decorated with eggfruits and persimmons. When the cake arrived, to their surprise, they noticed that the bakery didn’t use equal amounts of eggfruits and persimmons, but just randomly distributed the fruits over the cake’s border instead.</p>

<p>Jaime eats persimmons every day, so he was eager to try some eggfruit on his birthday. However, as he doesn’t want to eat too much, his cake slice should be decorated with at most S fruits. Since Jaime doesn’t like when a fruit is cut into parts, each fruit should either be entirely in his slice or be left in the rest of the cake. The problem is, with the fruits distributed in such a chaotic order, his friends are having trouble cutting a suitable slice for him.</p>

<p>Jaime is about to complain that his friends are taking too long to cut his slice, but in order to do so, he needs to know how many different slices with at least one eggfruit and containing at most S fruits there are. A slice is defined just based on the set of fruits it contains. As Jaime is quite focused on details, he is able to distinguish any two fruits, even if both fruits are of the same type. Hence, two slices are considered different when they do not contain exactly the same set of fruits. The following picture shows a possible cake, as well as the six different slices with at most S = 2 fruits that can be cut from it.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/a5f1e55c-7b31-41ad-ace5-5ca3317432c8/-/preview/" style="width: 305px; height: 220px;"></p>

### 입력 

 <p>The first line contains a circular string B (3 ≤ |B| ≤ 10<sup>5</sup>) describing the border of the cake. Each character of B is either the uppercase letter “E” or the uppercase letter “P”, indicating respectively that there’s an eggfruit or a persimmon at the border of the cake. The second line contains an integer S (1 ≤ S < |B|) representing the maximum number of fruits that a slice can contain.</p>

### 출력 

 <p>Output a single line with an integer indicating the number of different slices with at most S fruits and at least one eggfruit.</p>

