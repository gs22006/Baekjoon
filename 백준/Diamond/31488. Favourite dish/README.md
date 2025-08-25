# [Diamond V] Favourite dish - 31488 

[문제 링크](https://www.acmicpc.net/problem/31488) 

### 성능 요약

메모리: 63088 KB, 시간: 748 ms

### 분류

기하학, 볼록 껍질, 볼록 껍질을 이용한 최적화

### 제출 일자

2025년 8월 26일 01:00:06

### 문제 설명

<p>France is a country of gastronomy. For a dish, both the taste and plating are important. Nevertheless, when different people evaluate a dish, some focus more on taste and some focus more on plating. At the Olympic Village dining hall, there are $N$ dishes, numbered from $1$ to $N$; each dish has a score on its taste and a score on its plating. There are also $M$ persons, numbered from $1$ to $M$; each person has a weight on taste and a weight on plating. One person’s final score of a dish is the weighted average of the dish’s scores on taste and plating.</p>

<p>The chefs at the Olympics want to provide everyone with their favourite dish on the evening of the closing ceremony. Your task is to calculate everyone’s favourite dish. If multiple dishes tie for the highest score as a person’s favourite, choose the one with the smallest number.</p>

### 입력 

 <p>Each line contains two space-separated integers. The first line contains the numbers $N$ and $M$. Then follow $N$ lines; the $k$<sup>th</sup> such line contains two integers $t_k$ and $p_k$, which are the scores of the dish $k$ on taste and on plating. Then come $M$ more lines; the $\ell$<sup>th</sup> such line contains two integers $T_\ell$ and $P_\ell$, which are the weights of person $\ell$ on taste and on plating.</p>

### 출력 

 <p>The output should contain $M$ lines. The $\ell$<sup>th</sup> such line should contain one number: the number of the favourite dish of person $\ell$.</p>

