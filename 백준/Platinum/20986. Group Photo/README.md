# [Platinum I] Group Photo - 20986 

[문제 링크](https://www.acmicpc.net/problem/20986) 

### 성능 요약

메모리: 2216 KB, 시간: 712 ms

### 분류

다이나믹 프로그래밍, 누적 합

### 문제 설명

<p>At the end of a training camp, a group photo is taken with the N participants.The participants are numbered from 1 to N, in order of height. The height of the participant h is h (1 ≤ h ≤ N).</p>

<p>The participants stand on the stairs for the photo. There are N steps in the stairs. The steps are numbered from 1 to N, from a lower place to a higher place.</p>

<p>The step i + 1 is higher than the step i by 2 (1 ≤ i ≤ N − 1). Since the steps of the stairs are narrow, only one participant will stand on each step. A group photo will be taken when the participants are lined up behind each other.</p>

<p>A group photo will be taken soon. One participant stands on each step. Now, the participant Hi stands on the step i (1 ≤ i ≤ N). However, since the difference of the heights of the participants are too large, if a photo is taken with the current order of the participants, some participants might be hidden behind other participants. Hence, you want to change the order of the participants so that at least the head of every participant shows on the photo. In other words, the following condition should be satisfied.</p>

<p>Let a<sub>i</sub> be the height of the participant on the step i (1 ≤ i ≤ N). Then, the inequality a<sub>i</sub> < a<sub>i+1</sub> + 2 is satisfied for every i (1 ≤ i ≤ N − 1).</p>

<p>You can only swap two consecutive participants. In other words, by an operation, you choose a step i (1 ≤ i ≤ N − 1) arbitrarily, and you swap the participant on the step i and the participant on the step i + 1.</p>

<p>You want to minimize the number of operations so that the above condition is satisfied.</p>

<p>Write a program which, given the order of the participants, calculates the minimum number of operations.</p>

### 입력 

 <p>Read the following data from the standard input. Given values are all integers.</p>

<pre>N
H<sub>1</sub> · · · H<sub>N</sub></pre>

### 출력 

 <p>Write one line to the standard output. The output should contain the minimum number of operations.</p>

