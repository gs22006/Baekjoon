# [Diamond V] 진화 - 25016 

[문제 링크](https://www.acmicpc.net/problem/25016) 

### 성능 요약

메모리: 158264 KB, 시간: 960 ms

### 분류

다이나믹 프로그래밍, 트리에서의 다이나믹 프로그래밍, Heavy-light 분할, 트리

### 제출 일자

2023년 11월 28일 01:21:13

### 문제 설명

<p>여러 생명체들을 대상으로 진화 과정을 다루는 연구를 진행하려고 한다. <strong>최초 생명체</strong>를 제외한 모든 다른 생명체들은 기존에 존재하던 생명체가 진화하면서 새롭게 탄생하게 된다. 이 때, 기존에 존재하던 생명체를 <strong>부모 생명체</strong>, 새롭게 탄생한 생명체를 <strong>자식 생명체</strong>라고 정의한다. </p>

<p>생명체들이 진화를 통해 탄생하는 과정은 생명체들을 정점, 진화 과정을 부모 생명체와 자식 생명체를 잇는 간선으로 나타내 최초 생명체를 루트로 한 트리 구조로 표현할 수 있다. 예를 들어, 아래 그림은 1번 생명체가 진화해 2, 3번 생명체가 탄생하고, 2번 생명체가 진화해 4, 5, 6번 생명체가 탄생하며, 3번 생명체가 진화해 7번 생명체가 탄생하며 6번 생명체가 진화해 8, 9번 생명체가 탄생하는 과정을 1번 생명체를 루트로 한 트리 구조로 표현한 것이다. 이러한 트리를 <strong>진화 트리</strong>라고 부르자.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/9610accb-9c63-45a3-ac5b-894c212e65d3/-/preview/" style="width: 210px; height: 217px;"></p>

<p>자식 진화체가 존재하는 생명체 각각에 대해, 가능한 진화 방법들 중 하나의 진화 방법을 집중적으로 분석할 <strong>주요 진화</strong>, 나머지 진화 방법들을 <strong>부가 진화</strong>로 분류하려고 한다.</p>

<p>이러한 분류 방법의 효율성은 <strong>진화 복잡도</strong>를 측정하여 구할 수 있다. 두 생명체 A와 B 간의 진화 복잡도는 진화 트리에서 생명체 A와 B를 잇는 단순 경로 상에서 지나는 \underline{부가 진화}의 개수로 정의한다. 진화 트리의 진화 복잡도는 모든 생명체 쌍에 대한 진화 복잡도의 최댓값으로 정의한다. </p>

<p>진화 복잡도가 커질수록 두 생명체들간의 연관성을 분석하기가 어려워지기에, 진화 트리의 진화 복잡도가 낮을수록 효율적인 방식이다. 따라서, 적절히 주요 진화와 부가 진화로 분류하여 진화 트리의 진화 복잡도를 최소화해야 한다.</p>

<p><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="3"><mjx-c class="mjx-c1D444 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mo>+</mo><mi>Q</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N+Q$</span></mjx-container>일동안 연구를 진행한다. 연구를 진행하는 첫 날에는 1번 생명체의 발견만이 이루어져 있으며, 각 날에는 다음의 두 가지 연구 중 하나를 진행한다.</p>

<ul>
	<li>기존에 발견된 생명체에서 진화하여 탄생하는 새로운 생명체를 발견한다. 기존에 발견된 생명체의 수가 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D447 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>T</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$T$</span></mjx-container>였다면, 이 생명체는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D447 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>T</mi><mo>+</mo><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$T+1$</span></mjx-container>번 생명체로 명명한다. 이 연구는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>번 일어난다.</li>
	<li>한 생명체에 대해, 해당 생명체에서 0번 이상의 진화를 거쳐 탄생하는 생명체들을 분석한다. 해당 생명체를 최초 생명체로 두어 만들어지는 진화 트리에 대해, 진화 트리의 진화 복잡도의 최솟값을 구해야 한다. 각 분석은 독립적이며, 이 분석에서 분류한 방법이 나중의 분석들에 영향을 미치지 않는다는 점에 유의하라. 이 연구는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D444 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>Q</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$Q$</span></mjx-container>번 일어난다.</li>
</ul>

<p>해당 연구 계획을 진행하는 프로그램을 작성하여라.</p>

### 입력 

 Empty

### 출력 

 Empty

