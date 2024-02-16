# [Diamond IV] Event Hopping 2 - 21793 

[문제 링크](https://www.acmicpc.net/problem/21793) 

### 성능 요약

메모리: 30492 KB, 시간: 272 ms

### 분류

자료 구조, 그리디 알고리즘, 희소 배열

### 제출 일자

2024년 2월 17일 00:41:46

### 문제 설명

<p>In IOI Park, N events will be held soon. The events are numbered from 1 to N. The i-th event (1 ≤ i ≤ N) will start at time L<sub>i</sub> + 0.1 and finish at time R<sub>i</sub> − 0.1. Here L<sub>i</sub> and R<sub>i</sub> are integers.</p>

<p>JOI-kun will attend exactly K events among them. It is forbidden to enter an event after it starts, or to leave an event before it finishes. We ignore the time to move between the locations of events.</p>

<p>JOI-kun wants to attend events with small indices. More precisely, let a<sub>1</sub>, . . . , a<sub>K</sub> (1 ≤ a<sub>1</sub> < · · · < a<sub>K</sub> ≤ N) be the indices of the events JOI-kun will attend. Then (a<sub>1</sub>, . . . , a<sub>K</sub>) should be the smallest possible sequence in lexicographic order. Here, a sequence (a<sub>1</sub>, . . . , a<sub>K</sub>) is smaller than another sequence (b<sub>1</sub>, . . . , b<sub>K</sub>) in <strong>lexicographic order</strong> iff there exists j (1 ≤ j ≤ K) satisfying both “a<sub>ℓ</sub> = b<sub>ℓ</sub> for every 1 ≤ ℓ ≤ j − 1” and “a<sub>j</sub> < b<sub>j</sub>.”</p>

<p>Write a program which, given the information of the events and the number K of events JOI-kun will attend, determines whether JOI-kun will be able to attend K events or not. If it is possible for JOI-kun to attend K events, the program should calculate the K events JOI-kun will attend.</p>

### 입력 

 <p>Read the following data from the standard input. Given values are all integers.</p>

<pre>N K
L<sub>1</sub> R<sub>1</sub>
.
.
.
L<sub>N</sub> R<sub>N</sub></pre>

### 출력 

 <p>If JOI-kun will not be able to attend K events, output one line containing -1 to the standard output.</p>

<p>If JOI-kun will be able to attend K events, output K lines to the standard output. Let a<sub>1</sub>, . . . , a<sub>K</sub> (1 ≤ a<sub>1</sub> < · · · < a<sub>K</sub> ≤ N) be the indices of the events JOI-kun will attend. The j-th line (1 ≤ j ≤ K) of output should contain a<sub>j</sub>. Here (a<sub>1</sub>, . . . , a<sub>K</sub>) should be the smallest possible sequence in lexicographic order.</p>

