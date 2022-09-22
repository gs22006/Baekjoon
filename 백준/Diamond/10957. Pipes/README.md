# [Diamond V] Pipes - 10957 

[문제 링크](https://www.acmicpc.net/problem/10957) 

### 성능 요약

메모리: 20584 KB, 시간: 1252 ms

### 분류

단절점과 단절선(articulation), 자료 구조(data_structures), 분리 집합(disjoint_set), 그래프 이론(graphs)

### 문제 설명

<p>In the land of the Cahoots, Lomikel is a god of pipes. He governs water pipes, drains, sewers, and maybe even subway tunnels. The Cahoots worship him at numerous sacred springs, which are connected by a huge network of ceremonial pipes. Each pipe directly connects two springs.</p>

<p>On every holiday, the Supreme Plumber (the highest of Lomikel’s priests) conducts complicated rituals which involve transport of water through the pipes.</p>

<p>Sometimes, Lomikel’s wrath causes a pipe to break, so the Plumber has to use other pipes to make the water flow around the broken pipe. This is not always possible – for some pipes, a different path does not exist. These pipes are called critical and the Plumber has to pay special attention to them. You can see critical pipes drawn in bold in the picture below.</p>

<p>Your task is to read a description of the network and find all critical pipes. However, the network is vast and you have only a limited amount of memory. Memory limit for this task is only 16 MB.</p>

### 입력 

 <p>The first line of the standard input contains two space-separated integers N and M. Here N is the number of springs (1 ≤ N ≤ 100 000) and M is the number of pipes (1 ≤ M ≤ 6 000 000).</p>

<p>Each of the following M lines describes a single pipe. It contains two space-separated integers u and v (1 ≤ u, v ≤ N) – the springs connected by the given pipe.</p>

<p>Two springs can be connected by multiple pipes, but endpoints of a single pipe are always different springs.</p>

<p>Technical note: It is possible to seek on the standard input (for example to rewind it back to the beginning), but seeking is not necessary to solve the task. Also, reading the input multiple times could be too slow.</p>

### 출력 

 <p>The standard output consists of a sequence of lines. Each line describes a single critical pipe and it contains two space-separated integers: the endpoints of the pipe.</p>

<p>Critical pipes can be listed in an arbitrary order and so do the endpoints of any single pipe.</p>

