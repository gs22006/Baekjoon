# [Platinum I] 보급 - 25382 

[문제 링크](https://www.acmicpc.net/problem/25382) 

### 성능 요약

메모리: 51004 KB, 시간: 396 ms

### 분류

자료 구조(data_structures), 그리디 알고리즘(greedy), 우선순위 큐(priority_queue), 세그먼트 트리(segtree), 정렬(sorting)

### 문제 설명

<p>2차원 평면에 N개의 군사 기지가 있는 구역이 있다. 각 i번째 부대의 위치는 좌표 (X<sub>i</sub>, Y<sub>i</sub>)로 알려져 있다. 이 구역을 담당한 보급 부대는 모든 기지에 보급을 수행하려고 한다. 각 i번째 기지가 보급을 받을 수 있는 날짜는 A<sub>i</sub>번째부터 B<sub>i</sub>번째 날짜까지이다. 전쟁 중이라, 보급 부대는 병력이 전체적으로 왼쪽 위에서 오른쪽 아래로 내려가는 모양의 대열을 유지하면서 오른쪽 위 방향으로 전진해야 한다. 따라서, 아래 조건들이 모두 만족되도록 각 i번째 기지가 보급을 받을 날짜 V<sub>i</sub>를 하루씩 지정해야 한다.</p>

<ul>
	<li>모든 i에 대해 A<sub>i</sub> ≤ V<sub>i</sub> ≤ B<sub>i</sub>이다.</li>
	<li>모든 i, j에 대해 X<sub>i</sub> < X<sub>j</sub>, Y<sub>i</sub> < Y<sub>j</sub> 인 경우 V<sub>i</sub> < V<sub>j</sub>라야 한다.</li>
	<li>모든 i, j에 대해 i ≠ j 이면 V<sub>i</sub> ≠ V<sub>j</sub>라야 한다.</li>
</ul>

<p>각 기지의 위치와 보급 받을 수 있는 날짜들의 범위를 입력으로 받아 조건을 만족하면서 모든 기지에 보급을 할 수 있는지 확인하는 프로그램을 작성하라.</p>

<p>아래 예는 6개의 기지가 있는 상황을 보여 준다. 각 점이 기지에 해당하며 점 오른쪽 위에 보급을 받을 수 있는 날짜 범위가 주어져 있다.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 251px; height: 243px;"></p>

<p>아래 그림은 위의 예에서 조건을 만족하도록 보급 날짜를 정한 예를 보여준다. 각 점 오른쪽 아래에 배정된 날짜가 표기되어 있다. 아래 그림의 곡선은 보급 부대의 대형이 2일째와 3일째 사이에 있을 수 있는 가능한 위치를 보여 준다.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 251px; height: 244px;"></p>

### 입력 

 <p>첫 번째 줄에 기지의 개수 N이 주어진다.</p>

<p>다음 N개의 줄 중 i번째 줄에 기지의 정보 X<sub>i</sub>, Y<sub>i</sub>, A<sub>i</sub>, B<sub>i</sub>가 공백을 사이에 두고 주어진다.</p>

### 출력 

 <p>보급 날짜 배정이 가능한 경우 첫 번째 줄에 <code>YES</code>를 출력한다. 다음 줄에 기지 번호 순서대로 배정된 날짜 들을 공백을 사이에 두고 출력한다.</p>

<p>보급 날짜 배정이 불가능한 경우 첫 번째 줄에 <code>NO</code>를 출력한다.</p>

