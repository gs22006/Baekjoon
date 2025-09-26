# [Platinum II] Fabricating Sculptures - 18034 

[문제 링크](https://www.acmicpc.net/problem/18034) 

### 성능 요약

메모리: 198116 KB, 시간: 240 ms

### 분류

다이나믹 프로그래밍, 포함 배제의 원리

### 제출 일자

2025년 9월 27일 01:45:32

### 문제 설명

<p>Miguel Angelo is a great sculptor, widely recognized for his outdoor sculptures. In his hometown, it is very common to find one of his creations in squares and gardens. People love his sculptures, not only for their beauty, but also because they look like new even after decades. The sculptures do not degrade easily due to the material and technique developed by Miguel and his staff over the years.</p>

<p>To build the sculptures, he first constructs its base by stacking blocks of waterproof plaster (his secret material), forming several stacks of blocks in a straight line. He always uses identical blocks, and each stack has at least one block. To stabilize the structure, he surrounds it by two big glass panes, one behind the stacks and one in front of them. Then he waits for the rain for as long as it takes. If the structure is such that it doesn’t accumulate water during this procedure, Miguel is sure that the base can be used to obtain a piece of long-lasting artwork. Notice that water will accumulate on a block if there are obstacles (other blocks) on both sides (to the left and to the right).</p>

<p>The following picture shows the front view of several different bases. All of them consist of three stacks made of a total of six blocks, with each stack having at least one block as required. However, the eight bases on the left will lead to long-lasting artwork, while the two bases on the right will not.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/63e634c5-3661-424a-adf3-6e93778438f1/-/preview/" style="width: 394px; height: 251px;"></p>

<p>Miguel Angelo is receiving a lot of sculpture requests. Although he has all the freedom to create the artwork, he wants to be fair and use the same number of stacks and the same number blocks in each of the sculptures. Since he doesn’t want to sell identical sculptures to different clients, he will construct a different base each time.</p>

<p>He worries that he won’t be able to fulfill all the requests. Help him calculate the number of different bases given the number of stacks and the number of blocks that the base must have.</p>

### 입력 

 <p>The input consists of a single line that contains two integers S and B (1 ≤ S ≤ B ≤ 5000) indicating respectively the number of stacks and the number of blocks that the base must have.</p>

### 출력 

 <p>Output a single line with an integer indicating the number of different bases that don’t accumulate water which Miguel can construct. Because this number can be very large, output the remainder of dividing it by 10<sup>9</sup> + 7.</p>

