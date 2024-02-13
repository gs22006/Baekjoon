# [Diamond V] Alpine Valley - 17185 

[문제 링크](https://www.acmicpc.net/problem/17185) 

### 성능 요약

메모리: 52776 KB, 시간: 264 ms

### 분류

자료 구조, 깊이 우선 탐색, 다이나믹 프로그래밍, 트리에서의 다이나믹 프로그래밍, 오일러 경로 테크닉, 그래프 이론, 그래프 탐색, 희소 배열, 트리

### 제출 일자

2024년 2월 13일 21:44:46

### 문제 설명

<p>In an Alpine valley there are N villages (numbered 1 . . . N) connected by only N − 1 roads. While it is still possible to get from any village to any other village, this might take quite some time. This gets particularly annoying if you have to buy basic supplies, as there is a shop in only S of the N villages.</p>

<p>This winter the situation got even worse due to heavy snowfall. It would therefore be advisable to either leave the valley, i.e. get to the only village E at the mountain pass connecting the valley to the outside world, or at least buy enough supplies for the next months. You overheard on the radio this morning that the snow has rendered one of the N − 1 roads unusable — however, you couldn’t clearly understand which one.</p>

<p>You now want to know whether you and your friends can leave the valley and, if not, how far each of you has to drive at least to get to a village with a shop. As you are not sure yet which road is blocked and as your friends live in different villages across the valley, you should write a program that answers this question for Q given combinations of village and blocked road.</p>

### 입력 

 <p>The first line contains the integers N, S, Q, and E, where N is the number of villages, S (1 ≤ S ≤ N) is the number of shops, Q is the number of queries to your program, and E (1 ≤ E ≤ N) is the village you have to reach in order to leave the valley.</p>

<p>Each of the following N − 1 lines consists of three integers A, B, and W. This means that there is a road of length W (1 ≤ W ≤ 10<sup>9</sup>) connecting villages A and B (1 ≤ A ≤ N, 1 ≤ B ≤ N).</p>

<p>Then S lines follow, each consisting of a single integer C, meaning that there is a shop in village C (1 ≤ C ≤ N). Note that all of these lines are different, i.e. there is never more than one shop in a village.</p>

<p>Finally, there are Q lines, each containing two integers I and R, meaning that the I-th road from the input (1 ≤ I < N, numbered in the order they are listed) is no longer usable and you want to know if your friends in village R (1 ≤ R ≤ N) can leave the valley and if not, how far the closest village with a shop is.</p>

### 출력 

 <p>Your output should consist of Q lines. The i-th line should contain the answer to the i-th query from the input. More precisely, the respective line should contain the string “escaped” (without quotes) if it is possible to leave the valley; if not, then it should contain the distance to the closest village with a shop, or the string “oo” if no shop is reachable anymore.</p>

