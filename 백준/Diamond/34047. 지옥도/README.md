# [Diamond V] 지옥도 - 34047 

[문제 링크](https://www.acmicpc.net/problem/34047) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

수학, 애드 혹, 정수론, 소수 판정

### 제출 일자

2025년 7월 13일 02:44:23

### 문제 설명

<p><strong>일반적인 시간제한이 아님에 유의하라.</strong></p>

<p>지옥도의 호반우들은 음이 아닌 정수 $N$과 양의 정수 $M$이 주어지면 다음을 만족하는 음이 아닌 정수 $X$와 양의 정수 $Y$로 구성된 $(X, Y)$ 쌍 중 사전 순으로 가장 작은 $(X, Y)$쌍을 찾아야 한다.</p>

<ul>
	<li>$10^{9}$ 이하의 모든 양의 정수 $i$에 대해 $\displaystyle \min(\left \lfloor \frac{N}{i} \right \rfloor i + i  - N, N - \left \lfloor \frac{N}{i} \right \rfloor i) \mod M = \min(\left \lfloor \frac{X}{i} \right \rfloor i + i  - X, X - \left \lfloor \frac{X}{i} \right \rfloor i) \mod Y$를 만족한다.</li>
</ul>

<p>호반우를 도와 지옥도에서 깨달음을 얻어보자.</p>

### 입력 

 <p>첫째 줄에 $N$과 $M$이 주어진다. $(0 \leq N \leq 10^{9} ; 1 \leq M \leq 10^{9})$</p>

### 출력 

 <p>첫째 줄에 사전 순으로 가장 작은 $(X, Y)$ 쌍을 출력한다.</p>

