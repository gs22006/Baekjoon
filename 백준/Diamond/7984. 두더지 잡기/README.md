# [Diamond V] 두더지 잡기 - 7984 

[문제 링크](https://www.acmicpc.net/problem/7984) 

### 성능 요약

메모리: 64856 KB, 시간: 92 ms

### 분류

다이나믹 프로그래밍(dp)

### 문제 설명

<p>요즘 이상한 뉴스가 너무 많아서 그런지, 재현이의 성격은 점점 반사회적이고 폭력적으로 변했다. 얼마 전, 재현 이는 결국 학교의 3D 프린터를 사용해서 모형 권총을 프린트하고, 혼자 이상한 게임을 하기 시작했다.</p>

<p>재현이는 많은 두더지굴이 있는 잔디밭에서 게임을 시작했다. 잔디밭에는 n개의 두더지굴이 있으며, 두더지굴은 1번부터 n번까지 순서대로 번호가 부여되어 있다. 원형으로 늘어져 있으니, 1번 굴과 2번 굴, 2번 굴과 3번 굴, ..., n번 굴과 1번 굴은 인접해 있다.</p>

<p>현재 각각의 굴에는 a<sub>i</sub> 마리의 두더지가 있고, 재현이는 모형 권총으로 이들을 쫓아낼 계획이다. 재현이가 모형 권총을 쏴서 i번 굴에 있는 두더지에게 겁을 주면, 그 굴에 있는 두더지들이 겁을 먹고 도망가게 된다. (모형이라 죽지는 않는다.) 뿐만 아니라, 그 굴과 인접한 양 옆 두개의 굴에 있는 두더지들도 겁을 먹어서, 인접한 굴로 이동하게 된다. 당연히, 인접한 굴이라 하면 i번 굴은 아니다.</p>

<p>예를 들어, 10번 굴에 겁을 줬다면, 10번 굴에 있는 두더지는 모두 굴을 탈출하고, 9번 굴에 있는 두더지는 8번 굴로 도망가고, 11번 굴에 있는 두더지는 12번 굴로 도망간다.</p>

<p>재현이는 3D 프린터로 k개의 총알을 만들었고, 최대한 많은 두더지를 쫓아내고 싶다. 총을 k번 이하로 사용했을 때, 최대 몇 마리의 두더지가 굴을 탈출하는가?</p>

### 입력 

 <p>첫 번째 줄에 두더지굴의 수 n, 총의 최대 사용 가능 수 k가 주어진다. (5 ≤ n ≤ 2000, 1 ≤ k ≤ n)</p>

<p>이후 n개의 정수 a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub>가 주어진다. (0 ≤ a<sub>i</sub> ≤ 10<sup>6</sup>) i번째 굴에 a<sub>i</sub>마리의 두더지가 산다는 것을 의미한다.</p>

### 출력 

 <p>총을 k번 이하로 사용했을 때, 탈출시킬 수 있는 두더지 수의 최댓값을 출력한다.</p>

