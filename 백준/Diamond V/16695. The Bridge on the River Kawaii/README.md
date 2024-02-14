# [Diamond V] The Bridge on the River Kawaii - 16695 

[문제 링크](https://www.acmicpc.net/problem/16695) 

### 성능 요약

메모리: 95196 KB, 시간: 528 ms

### 분류

자료 구조, 분리 집합, 분할 정복, 그래프 이론, 오프라인 동적 연결성 판정, 오프라인 쿼리

### 제출 일자

2024년 2월 14일 18:30:54

### 문제 설명

<p>In a very distant land called Midsommer, there is a cute little river delta. Deep purple acid flows in the river, so it is impossible to swim there. There are several islands in the delta and bridges connecting some pairs of them. Every bridge is assigned a danger level, which measures how dangerous it is to travel across that bridge, higher levels being more dangerous.</p>

<p>A detective, and as matter of coincidence also a mystery novels author, Richard Hradecki often needs to travel between the islands to pursue his detective cases. Among all possible paths, he prefers to choose the safest one, which means the highest danger level of a bridge on the path must be as low as possible.</p>

<p>For planning purposes, Richard usually asks you to find him the safest path from one island to another island where he is investigating. To be able to satisfy his requests, you have to continuously register three types of events:</p>

<ul>
	<li>A new bridge between two islands was just built by members of a local tribe.</li>
	<li>A big pink fluffy acid bear Lug appears and destroys a bridge.</li>
	<li>Richard asks you to find the safest path between two islands.</li>
</ul>

### 입력 

 <p>The first line of input contains two integers N and Q (2 ≤ N ≤ 10<sup>5</sup> and 1 ≤ Q ≤ 10<sup>5</sup>). N is the number of islands (which are labeled 0, 1, . . . , N − 1) and Q is the number of events to follow.</p>

<p>Each of the next Q lines represents one event and it contains three or four integers, interpreted as follows:</p>

<ul>
	<li>0 X Y V : A bridge of danger level V (0 ≤ V < 10) has just been built between islands X and Y .</li>
	<li>1 X Y : The bridge connecting islands X and Y has just been destroyed.</li>
	<li>2 X Y : Richard asks what is the safest path from island X to island Y .</li>
</ul>

<p>For all types of events, X and Y denote a valid pair of islands (0 ≤ X, Y < N and X ≠ Y ). There is always at most one bridge between any pair of islands. A bridge to be destroyed always exists at that moment.</p>

### 출력 

 <p>For each event of type 2, output a line with the danger level of the most dangerous bridge on the safest path from X to Y . If there is no path between X and Y , output −1.</p>

