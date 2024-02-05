# [Diamond II] Aliens - 20090 

[문제 링크](https://www.acmicpc.net/problem/20090) 

### 성능 요약

메모리: 20320 KB, 시간: 200 ms

### 분류

Aliens 트릭, 이분 탐색, 볼록 껍질을 이용한 최적화, 다이나믹 프로그래밍

### 제출 일자

2024년 2월 5일 21:27:53

### 문제 설명

<p>Our satellite has just discovered an alien civilization on a remote planet. We have already obtained a low-resolution photo of a square area of the planet. The photo shows many signs of intelligent life. Our experts have identified <em>n</em> points of interest in the photo. The points are numbered from 0 to <em>n</em> - 1. We now want to take high-resolution photos that contain all of those <em>n</em> points.</p>

<p>Internally, the satellite has divided the area of the low-resolution photo into an <em>m</em> by <em>m</em> grid of unit square cells. Both rows and columns of the grid are consecutively numbered from 0 to <em>m</em> - 1 (from the top and left, respectively). We use (<em>s</em>, <em>t</em>) to denote the cell in row <em>s</em> and column <em>t</em>. The point number <em>i</em> is located in the cell (<em>r<sub>i</sub></em>, <em>c<sub>i</sub></em>). Each cell may contain an arbitrary number of these points.</p>

<p>Our satellite is on a stable orbit that passes directly over the <em>main</em> diagonal of the grid. The main diagonal is the line segment that connects the top left and the bottom right corner of the grid. The satellite can take a high-resolution photo of any area that satisfies the following constraints:</p>

<ul>
	<li>the shape of the area is a square,</li>
	<li>two opposite corners of the square both lie on the main diagonal of the grid,</li>
	<li>each cell of the grid is either completely inside or completely outside the photographed area.</li>
</ul>

<p>The satellite is able to take at most high-resolution photos. Once the satellite is done taking photos, it will transmit the high-resolution photo of each photographed cell to our home base (regardless of whether that cell contains some points of interest). The data for each photographed cell will only be transmitted <em>once</em>, even if the cell was photographed several times.</p>

<p>Thus, we have to choose at most <em>k</em> square areas that will be photographed, assuring that:</p>

<ul>
	<li>each cell containing at least one point of interest is photographed at least once, and</li>
	<li>the number of cells that are photographed at least once is minimized.</li>
</ul>

<p>Your task is to find the smallest possible total number of photographed cells.</p>

### 입력 

 Empty

### 출력 

 Empty

