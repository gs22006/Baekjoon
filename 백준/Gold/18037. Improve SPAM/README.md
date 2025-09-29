# [Gold IV] Improve SPAM - 18037 

[문제 링크](https://www.acmicpc.net/problem/18037) 

### 성능 요약

메모리: 15764 KB, 시간: 192 ms

### 분류

다이나믹 프로그래밍, 그래프 이론, 그래프 탐색, 깊이 우선 탐색

### 제출 일자

2025년 9월 30일 02:01:13

### 문제 설명

<p>After the amazing job you did cleaning up duplicate users from the client database, your boss is eager to be impressed by your improvements to the company SPAM (System for Publishing Amazing Marketing).</p>

<p>Despite the marketing campaigns being extremely useful for clients, some complaints were received by the customer service indicating that too many messages are being sent, and that certain clients even receive the same message multiple times.</p>

<p>SPAM is based on mailing lists. Each mailing list is composed of client emails and/or other mailing lists. Client emails might be added to existing mailing lists at any point in time, while only when a mailing list is created it can be added to any number of existing mailing lists. Notice that it is not possible to create several mailing lists at the same time.</p>

<p>When a message is sent to a mailing list, the system sends the message to each address in the list. If the address in the list is a client email, then the message is sent to that client email; if instead the address is a mailing list, then the process is started for that mailing list.</p>

<p>Due to privacy reasons, in the following example mailing lists and client emails are represented by integers. Suppose that 1, 2 and 3 are mailing lists, while 4 and 5 are client emails. Moreover, mailing list 1 contains mailing lists 2 and 3, mailing list 2 contains client emails 4 and 5, while mailing list 3 contains client email 4 and mailing list 2. Now suppose that a message is sent to mailing list 1. This means that the list is processed as described above, and then mailing lists 2 and 3 are also processed. When mailing list 2 is processed, the message is sent to client emails 4 and 5. When mailing list 3 is processed, a second message is sent to client email 4, and mailing list 2 is processed again, which yields a third message sent to client email 4 and a second message sent to client email 5. Thus, a total of five messages are sent to client emails.</p>

<p>Your task is to optimize SPAM in such a way that no client receives the same message multiple times. As a first step, your boss wants to know the number of messages sent before and after your improvements. In the above example, just two messages should be sent to client emails after your work is done.</p>

### 입력 

 <p>The first line contains two integers N and L (2 ≤ N ≤ 2000, 1 ≤ L ≤ min(N − 1, 1000)), representing respectively the number of addresses in the system, and the number of addresses that are mailing lists. Addresses are identified by distinct integers from 1 to N. Addresses from 1 to L are mailing lists, while the rest are client emails. For i = 1, 2, . . . , L, the i-th of the next L lines describes mailing list i with an integer K (1 ≤ K < N) followed by K different integers M<sub>1</sub>, M<sub>2</sub>, . . . , M<sub>K</sub> (1 ≤ M<sub>i</sub> ≤ N for i = 1, 2, . . . , K), indicating that the mailing list contains the K addresses M<sub>1</sub>, M<sub>2</sub>, . . . , M<sub>K</sub>. Each client address appears in at least one mailing list.</p>

### 출력 

 <p>Output a single line with two integers B and A indicating respectively the number of messages sent to client emails before and after your improvements, if a message is sent to mailing list 1. Because these numbers can be very large, output the remainder of dividing them by 10<sup>9</sup> + 7.</p>

