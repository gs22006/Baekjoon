# [Diamond V] Stations - 19938 

[문제 링크](https://www.acmicpc.net/problem/19938) 

### 성능 요약

메모리: 48452 KB, 시간: 16756 ms

### 분류

오일러 경로 테크닉(euler_tour_technique), 트리(trees)

### 문제 설명

<p>Singapore's Internet Backbone (SIB) consists of $n$ stations, which are assigned <strong>indices</strong> from $0$ to $n-1$. There are also $n-1$ bidirectional links, numbered from $0$ to $n-2$. Each link connects two distinct stations. Two stations connected with a single link are called neighbours.</p>

<p>A path from station $x$ to station $y$ is a sequence of distinct stations $a_0,a_1,\cdots,a_p$, such that $a_0=x$, $a_p=y$, and every two consecutive stations in the path are neighbours. There is <strong>exactly one</strong> path from any station $x$ to any other station $y$.</p>

<p>Any station $x$ can create a packet (a piece of data) and send it to any other station $y$, which is called the packet's <strong>target</strong>. This packet must be routed along the unique path from $x$ to $y$ as follows. Consider a station $z$ that currently holds a packet, whose target station is $y$ ($z \neq y$). In this situation station $z$: 1. executes a <strong>routing procedure</strong> that determines the neighbour of $z$ which is on the unique path from $z$ to $y$, and 2. forwards the packet to this neighbour.</p>

<p>However, stations have limited memory and do not store the entire list of the links in SIB to use it in the routing procedure.</p>

<p>Your task is to implement a routing scheme for SIB, which consists of two procedures.</p>

<ul>
	<li>The first procedure is given $n$, the list of the links in the SIB and an integer $k \geq n-1$ as the inputs. It assigns each station a <strong>unique</strong> integer <strong>label</strong> between $0$ and $k$, inclusive. </li>
	<li>
	<p>The second procedure is the routing procedure, which is deployed to all stations after labels are assigned. It is given <strong>only</strong> the following inputs:</p>

	<ul>
		<li>$s$, the <strong>label</strong> of the station that currently holds a packet,</li>
		<li>$t$, the <strong>label</strong> of the packet's target station ($t \neq s$),</li>
		<li>$c$, the list of the <strong>labels</strong> of all neighbours of $s$.</li>
	</ul>

	<p>It should return the <strong>label</strong> of the neighbour of $s$ that the packet should be forwarded to.</p>
	</li>
</ul>

<p>In one subtask, the score of your solution depends on the value of the maximum label assigned to any station (in general, smaller is better).</p>

### 입력 

 Empty

### 출력 

 Empty

