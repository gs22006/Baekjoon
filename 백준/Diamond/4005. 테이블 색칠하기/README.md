# [Diamond V] 테이블 색칠하기 - 4005 

[문제 링크](https://www.acmicpc.net/problem/4005) 

### 성능 요약

메모리: 15488 KB, 시간: 40 ms

### 분류

자료 구조, 깊이 우선 탐색, 분리 집합, 그래프 이론, 그래프 탐색, 수학

### 문제 설명

<p>
	Sam과 여동생 Sara는 n × m 테이블의 모든 셀을 빨간색과 파란색으로 색칠하고자 한다. 이들은 개인적인 믿음 때문에, 테이블의 모든 2 × 2 격자에는 빨간색 셀의 개수가 홀수(즉, 1 혹은 3)가 되기를 원한다. 예를 들어, 3 × 5 테이블에 이 조건을 만족하는 색칠의 예가 다음 그림에 있다.</p>

<p>
	<img alt="" src="https://www.acmicpc.net/upload/images/tbl.png" style="width: 110px; height: 69px; float: right;">불행히도, 지난 저녁에 누군가가 테이블의 어떤 셀들을 빨간색으로, 또 다른 어떤 셀들은 파란색으로 칠해놓았다. Sam과 Sara는 모든 2 × 2 격자에 빨간색 셀의 개수가 홀수가 되도록 테이블의 나머지를 색칠할 수 있는지를 알려고 한다. 만약 가능하다면, 모든 2 × 2 격자에 빨간색 셀의 개수가 홀수가 되도록 색칠할 수 있는 방법이 몇 개가 있는지를 알려고 한다.</p>

### 입력 

 <p>
	입력의 첫 번째 줄에 세 정수 n,m,k가 주어진다. 이들은 각각 테이블의 행의 수, 열의 수, 초기에 색칠되어진 셀의 수이다. 다음의 k 개 줄에 색칠된 셀들의 정보가 주어진다. 이들 k개 줄의 각 i번째 줄에는 세 정수 x<sub>i</sub>, y<sub>i</sub>, c<sub>i</sub>를 포함한다. x<sub>i</sub>, y<sub>i</sub>는 각각 초기에 i-번째 색칠된 셀의 행 번호, 열 번호이고, c<sub>i</sub>는 이 셀의 색이다. 이 셀이 빨간색으로 칠해져 있으면 c<sub>i</sub>는 1이고 파란색으로 칠해져 있으면 c<sub>i</sub>는 0이다. k개의 셀들의 위치는 모두 다르다.</p>
<p>
	2 ≤ n,m ≤ 10<sup>5</sup><br>
	0 ≤ k ≤ 10<sup>5</sup><br>
	1 ≤ x<sub>i</sub> ≤ n<br>
	1 ≤ y<sub>i</sub> ≤ m</p>

### 출력 

 <p>
	테이블을 색칠할 수 있는 방법의 수를 W라 할 때, W modulo 10<sup>9</sup>를 한 줄에 출력한다. (즉, W가 10<sup>9</sup>보다 같거나 클 경우에는 W를 10<sup>9</sup>으로 나눈 나머지를 출력한다.)</p>

