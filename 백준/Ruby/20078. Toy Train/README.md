# [Ruby V] Toy Train - 20078 

[문제 링크](https://www.acmicpc.net/problem/20078) 

### 성능 요약

메모리: 3264 KB, 시간: 36 ms

### 분류

애드 혹(ad_hoc), 게임 이론(game_theory), 그래프 이론(graphs)

### 문제 설명

<p>Arezou and her brother Borzou are twins. They have received an amazing toy train set for their birthday, and they used it to build a railway system with $n$ stations and $m$ <em>one-way</em> tracks. The stations are numbered from $0$ to $n-1$. Each track starts at one station and ends at the same or a different station. There is at least one track starting at each station.</p>

<p>Some stations are <em>charging stations</em>. Whenever the train arrives at a charging station, it gets fully charged. A fully charged train has enough energy to travel along $n$ consecutive tracks. That is, the train runs out of energy just when it enters the $(n+1)$-st track after last being charged.</p>

<p>On each station there is a switch that can be pointed to any of the tracks that start at that station. When a train is at a station, it leaves it using the track that is pointed to by the switch on that station.</p>

<p>The twins are going to play a game with their train. They have already divided all the stations between themselves: each station is either owned by Arezou or by Borzou. There is a single train. At the beginning of the game the train is at station $s$ and it is fully charged. To start the game, the owner of station $s$ points the switch on station $s$ to one of the tracks that start at station $s$. Then, they turn the train on and the train starts traveling along the tracks.</p>

<p>Whenever the train enters a station for the first time, the owner of that station sets the switch on that station. Once a switch is set, it stays in the same position for the rest of the game. Thus, if a train re-enters a station it visited before, it will leave that station along the same track as before.</p>

<p>Since there is a finite number of stations, the train will eventually start going along a <em>cycle</em>. A cycle is a sequence of <em>distinct</em>stations $c[0], c[1], \cdots, c[k-1]$ such that the train leaves station $c[i]$ (for $0 \leq i < k-1$) using a track going to station $c[i+1]$, and it leaves station $c[k-1]$ using a track going to station $c[0]$. Note that a cycle may consist of a single station (i.e., have $k=1$) if the train leaves the station $c[0]$ using a track that goes back to $c[0]$.</p>

<p>Arezou wins the game if the train continues going indefinitely, and Borzou wins if the train runs out of energy. In other words, if there is at least one charging station among $c[0], c[1], \cdots, c[k-1]$, the train can recharge and cycle indefinitely, and Arezou wins. Otherwise, it will run out of energy (possibly after turning around the cycle several times), and Borzou wins.</p>

<p>You are given the description of the railway system. Arezou and Borzou are going to play $n$ games. In the $s$-th game, for $0 \leq s \leq n-1$, the train will initially be at station $s$. Your task is to find, for each game, whether there is a strategy for Arezou that guarantees she wins, regardless of how Borzou plays.</p>

### 입력 

 Empty

### 출력 

 Empty

