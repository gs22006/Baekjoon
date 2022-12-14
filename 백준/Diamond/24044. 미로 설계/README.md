# [Diamond IV] 미로 설계 - 24044 

[문제 링크](https://www.acmicpc.net/problem/24044) 

### 성능 요약

메모리: 88280 KB, 시간: 764 ms

### 분류

구성적(constructive), 다이나믹 프로그래밍(dp), 그래프 이론(graphs), 수학(math), 위상 정렬(topological_sorting)

### 문제 설명

<p>주원이는 매년 1월 1일에만 개방하는 주때미로의 관리자이다. 주때미로에는 $1$번부터 $N$번까지 번호가 붙은 총 $N$ 개의 방이 존재하며, 어떤 한 방에서 다른 어떤 방으로 이동할 수 있는 일방통행 통로가 $M$ 개 있다.</p>

<p>미로의 출발지는 $1$번 방이고, 도착지는 $N$번 방이다. 따라서 미로를 찾는 손님들의 이동 경로는 $1$번 방에서 시작해 $N$번 방에서 끝나게 된다.</p>

<p>미로는 다음 3가지 조건을 만족하게 설계된다.</p>

<ol>
	<li>미로가 너무 작으면 사람들이 실망하기 때문에, <strong>미로의 방 개수는 $100$개 이상이다.</strong></li>
	<li>미로의 각 방에 대해, 손님들이 미로를 통과할 수 있는 여러 방법 중 적어도 하나의 경로는 그 방을 포함한다. </li>
	<li>자칫하다, 손님들이 영원히 길을 잃을 수 있으므로, 어떤 방에서 출발해 다시 그 방으로 돌아올 수 있는 방법은 없다.</li>
</ol>

<p>주때미로에는 그해의 행운의 수 $K$에 맞게 미로의 경로의 개수를 $K$의 배수로 만드는 전통이 있다. 그런데 주원이는 당장 내일 사용해야 할 미로를 작년 이후로 아직 고치지 않았다는 것을 깨달았다! 주원이는 헐레벌떡 남아있던 $120$개 이하의 통로를 추가해서 경로의 개수를 맞추려고 한다. 단, 원래 미로에는 같은 방을 연결하는 통로가 유일하지만 급한 만큼 새로 추가하는 통로에 대해서는 이 조건을 무시하기로 마음먹었다. </p>

<p>작년 미로를 보고, 주원이가 미로를 고칠 수 있게 도와주자! </p>

### 입력 

 <p>첫 번째 줄에 작년 미로의 방 개수 $N$, 통로의 개수 $M$, 올해의 행운의 수 $K$가 공백으로 구분되어 주어진다.</p>

<p>두 번째 줄부터 $M$개의 줄에 걸쳐 $i$번째 통로의 정보 $u_i$, $v_i$가 공백으로 구분되어 주어진다. 이는 $u_i$번 방에서 $v_i$번 방으로 가는 일방통행 통로가 존재한다는 뜻이다.</p>

### 출력 

 <p>첫 번째 줄에 추가한 통로의 개수 $X$를 출력한다. <strong>추가하는 통로의 개수가 최소가 될 필요는 없다.</strong></p>

<p>두 번째 줄부터 $X$ 개의 줄을 출력한다. 이 중 $i$ 번째 줄에는 통로의 정보 $x_i$와 $y_i$를 공백으로 구분하여 출력한다. 이는 $i$ 번째로 추가한 일방통행 통로가 $x_i$번 방에서 $y_i$번 방으로 가는 통로라는 의미이다.</p>

