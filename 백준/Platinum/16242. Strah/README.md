# [Platinum II] Strah - 16242 

[문제 링크](https://www.acmicpc.net/problem/16242) 

### 성능 요약

메모리: 222764 KB, 시간: 220 ms

### 분류

조합론, 자료 구조, 분할 정복, 수학, 스택

### 문제 설명

<p>Everyone is afraid of something. Someone is afraid of darkness, someone is afraid of heights, someone is afraid of Vinnie Jones (all of us are afraid of Vinnie Jones), someone is afraid of singing before eating something...</p>

<p>There are many fears, but the greatest among all for Mirko is choosing a land for planting strawberries. Mirko's land can be described as a matrix with N rows and M columns. Some of the fields in the matrix are suitable for planting strawberries and some are not – weeds grow there. Mirko is looking for rectangular parts of the land that are completely filled with fields suitable for strawberry planting. Those kind of rectangles are called suitable rectangles. Also, Mirko is interested in the potential value of all fields in the matrix. The potential value of each field in the matrix is defined as the number of suitable rectangles that contain that field.</p>

<p>Since Mirko has troubles facing his fears, he asks you to only calculate the sum of all the fields' potential values.</p>

### 입력 

 <p>The first line contains two positive integers N and M (1 ≤ N, M ≤ 2 000), dimensions of the land. The next N lines contains M characters each, representing the landscape. Each character can be either a ‘.’ (dot) which represents a field suitable for planting or a ‘#’ which represents weeds.</p>

### 출력 

 <p>Output the sum of all potential values of the matrix’s fields.</p>

