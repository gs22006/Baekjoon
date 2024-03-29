# [Ruby V] 트리와 쿼리 14 - 18372 

[문제 링크](https://www.acmicpc.net/problem/18372) 

### 성능 요약

메모리: 310852 KB, 시간: 1632 ms

### 분류

센트로이드, 센트로이드 분할, 자료 구조, 분할 정복, 포함 배제의 원리, 최소 공통 조상, 누적 합, 희소 배열, 트리

### 문제 설명

<p>N개의 정점으로 이루어진 트리가 있다. 정점은 1번부터 N번까지 번호가 매겨져 있다. 간선의 가중치는 모두 1이다.</p>

<p>아래의 쿼리를 수행하는 프로그램을 작성하시오.</p>

<ul>
	<li><font face="monospace">k v<sub>1</sub> r<sub>1</sub> v<sub>2</sub> r<sub>2</sub> ... v<sub>k</sub> r<sub>k</sub></font>: 어떠한 정점 x가 v<sub>i</sub>와 거리 r<sub>i</sub> 이내에 있다면 (거리가 r<sub>i</sub>보다 작거나 같다면), x가 i번 조건을 만족한다고 하자. 트리에 있는 모든 정점들 중, 쿼리로 주어진 k개 조건 중 k-1개 이상의 조건을 만족하는 정점의 개수를 출력하라.</li>
</ul>

### 입력 

 <p>첫 번째 줄에 정수 N이 주어진다. (1 ≤ N ≤ 100,000)</p>

<p>이후 N-1개의 줄에는 각 간선이 연결하는 두 정점 번호 u, v가 주어진다. (1 ≤ u, v ≤ N)</p>

<p>다음 줄에 정수 M이 주어진다. (1 ≤ M ≤ 300,000)</p>

<p>이후 M개의 줄에 위에서 설명한 것과 같은 쿼리가 주어진다. 각 쿼리는 지문과 다르게 한 줄에 들어오지 않으며, k + 1개의 줄로 분리되어 주어진다. 예제 입력을 참고하라. (1 ≤ v<sub>i</sub> ≤ N, 0 ≤ r<sub>i </sub>< N, 1 ≤ k)</p>

<p>쿼리로 주어지는 k의 합은 300000을 넘지 않는다.</p>

### 출력 

 <p>쿼리의 결과를 한 줄에 하나씩 출력한다.</p>

