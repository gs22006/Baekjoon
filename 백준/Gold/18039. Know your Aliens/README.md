# [Gold III] Know your Aliens - 18039 

[문제 링크](https://www.acmicpc.net/problem/18039) 

### 성능 요약

메모리: 2168 KB, 시간: 0 ms

### 분류

수학, 사칙연산, 분할 정복

### 제출 일자

2025년 9월 28일 01:58:10

### 문제 설명

<p>Our world has been invaded by shapeshifting aliens that kidnap people and steal their identities. You are an inspector from a task force dedicated to detect and capture them. As such, you were given special tools to detect aliens and differentiate them from real humans. Your current mission is to visit a city that is suspected of have been invaded, secretly inspect every person there so as to know whose are aliens and whose aren’t, and report it all to Headquarters. Then they can send forces to the city by surprise and capture all the aliens at once.</p>

<p>The aliens are aware of the work of inspectors like you, and are monitoring all radio channels to detect the transmission of such reports, in order to anticipate any retaliation. Therefore, there have been several efforts to encrypt the reports, and the most recent method uses polynomials.</p>

<p>The city you must visit has N citizens, each identified by a distinct even integer from 2 to 2N. You want to find a polynomial P such that, for every citizen i, P(i) > 0 if citizen i is a human, and P(i) < 0 otherwise. This polynomial will be transmitted to the Headquarters. With the aim of minimizing bandwidth, the polynomial has some additional requirements: each root and coefficient must be an integer, the coefficient of its highest degree term must be either 1 or −1, and its degree must be the lowest possible.</p>

<p>For each citizen, you know whether they’re a human or not. Given this information, you must find a polynomial that satisfies the described constraints.</p>

### 입력 

 <p>The input consists of a single line that contains a string S of length N (1 ≤ N ≤ 10<sup>4</sup>), where N is the population of the city. For i = 1, 2, . . . , N, the i-th character of S is either the uppercase letter “H” or the uppercase letter “A”, indicating respectively that citizen 2i is a human or an alien.</p>

### 출력 

 <p>The first line must contain an integer D indicating the degree of a polynomial that satisfies the described constraints. The second line must contain D + 1 integers representing the coefficients of the polynomial, in decreasing order of the corresponding terms. It’s guaranteed that there exists at least one solution such that the absolute value of each coefficient is less than 2<sup>63</sup>.</p>

