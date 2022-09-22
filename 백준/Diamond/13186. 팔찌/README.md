# [Diamond V] 팔찌 - 13186 

[문제 링크](https://www.acmicpc.net/problem/13186) 

### 성능 요약

메모리: 64520 KB, 시간: 672 ms

### 분류

번사이드 보조정리(burnside), 조합론(combinatorics), 오일러 피 함수(euler_phi), 분할 정복을 이용한 거듭제곱(exponentiation_by_squaring), 수학(math), 모듈로 곱셈 역원(modular_multiplicative_inverse), 정수론(number_theory)

### 문제 설명

<p>그는 여러 가지 색을 지닌 구슬을 엮어 팔찌를 만드는 취미에 빠졌다. 그가 만드는 팔찌는 여러 개의 구슬을 일렬로 놓은 다음 실로 꿰어 실의 양 끝을 묶어 원형으로 만든 것이다. 그가 만들 수 있는 팔찌의 종류는 무궁무진하지만 비슷한 것을 싫어하는 그는 팔찌를 회전시키거나 뒤집어서 사용된 구슬의 색 순서가 같으면 같은 종류로 취급하기로 했다.</p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/13186/1.png" style="height:154px; width:348px"></p>

<p>위의 그림은 빨간 구슬과 파란 구슬을 교대로 엮어 구슬을 네 개 사용한 팔찌를 만든 경우이다. 어떤 색 구슬을 기준으로 보느냐에 따라 두 가지 종류로 볼 수 있다. 그러나 왼쪽의 팔찌를 시계방향으로 조금 회전시키면 오른쪽에 있는 팔찌와 같은 구성이 되므로, 한 가지 종류로 생각해야 한다.</p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/13186/2.png" style="height:154px; width:334px"></p>

<p>또 다른 예로, 위의 그림은 다섯 개의 구슬을 사용하여 팔찌를 만든 경우이다. 왼쪽의 팔찌를 좌우로 뒤집으면 오른쪽에 있는 팔찌를 만들 수 있으므로, 위의 두 팔찌는 한 가지 종류로 생각해야 한다.</p>

<p>그가 가진 구슬 색의 종류는 현재 K종류이고, 각 종류의 구슬은 무한히 많이 준비되어 있다. 구슬을 N개 이하만 사용해서 만들 수 있는 서로 다른 팔찌의 종류의 수를 구하는 프로그램을 작성하라. 구슬을 하나도 사용하지 않은 팔찌도 하나의 종류로 생각한다.</p>

### 입력 

 <p>첫 번째 줄에는 사용할 수 있는 구슬의 개수와 구슬 색의 종류를 나타내는 두 자연수 N, K가 공백으로 구분되어 주어진다. (1 ≤ N ≤ 10<sup>6</sup>, 1 ≤ K ≤ 10<sup>6</sup>)</p>

### 출력 

 <p>첫 번째 줄에 구슬을 N 개 이하만 사용해서 만들 수 있는 팔찌의 종류 개수를 출력한다. 이 수는 매우 커질 수 있으므로 1,000,000,007로 나눈 나머지를 출력해야 한다.</p>

