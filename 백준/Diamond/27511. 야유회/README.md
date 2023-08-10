# [Diamond I] 야유회 - 27511 

[문제 링크](https://www.acmicpc.net/problem/27511) 

### 성능 요약

메모리: 202704 KB, 시간: 1848 ms

### 분류

애드 혹, 해 구성하기, 수학

### 문제 설명

<p><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>명의 마법사들이 모여 친목을 도모하고 서로의 마법을 공유하는 야유회를 가지려고 한다. 이 야유회에서는 하루 동안 재미있는 게임을 한다.</p>

<p>게임은 거대한 회의실에서 진행된다. 이 회의실에는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 자리가 있는 원탁이 있다. 원탁의 각 자리는 모두 동일하게 생겼고, 마법사들 역시 모두 동일하게 생겨서 서로 구분할 수 없다. 마법사들은 게임이 진행되는 중 <strong>아무 말도 할 수 없다</strong>.</p>

<p>게임은 세 단계로 진행되는데, 각 단계는 다음과 같다.</p>

<ul>
	<li><strong>아침</strong>에 마법사들은 원탁에 둘러앉는다. 각 자리에는 빈 종이 한 장과, <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>0</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$0$</span></mjx-container> 이상 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mo>−</mo><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N -1$</span></mjx-container> 이하의 정수가 적힌 종이 한 장이 놓여 있다. 각 종이에 적힌 정수는 <strong>서로 다르다</strong>. 마법사들은, 원탁에서 자신과 자신의 <strong>오른쪽</strong>에 앉은 사람의 종이에 적혀 있는 정수를 볼 수 있다. 이를 토대로, 마법사들은 빈 종이에 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>0</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$0$</span></mjx-container> 이상 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msup><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c39"></mjx-c></mjx-mn></mjx-script></mjx-msup></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msup><mn>10</mn><mn>9</mn></msup></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$10^9$</span></mjx-container> 미만의 정수를 쓴다. 이 정수는 자신만이 볼 수 있게 조심스럽게 적는다. 이후 방금 정수를 쓴 종이를 접어 자리 위에 놓고, 처음 자리에 놓여 있던 정수가 적힌 종이를 들고 회의실을 떠난다.</li>
	<li><strong>점심</strong>에 마법사들은 원탁에 둘러앉는다. 각 자리에는 빈 종이 한 장과, 아침에 자신이 수를 적은 종이 한 장이 놓여 있다. 마법사들은, 원탁에서 자신과 자신의 <strong>왼쪽과 오른쪽</strong>에 앉은 사람의 종이에 적혀 있는 정수를 볼 수 있다. 이를 토대로, 마법사들은 빈 종이에 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>0</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$0$</span></mjx-container> 이상 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msup><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c39"></mjx-c></mjx-mn></mjx-script></mjx-msup></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msup><mn>10</mn><mn>9</mn></msup></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$10^9$</span></mjx-container> 미만의 정수를 쓴다. 이 정수는 자신만이 볼 수 있게 조심스럽게 적는다. 이후 방금 정수를 쓴 종이를 접어 자리 위에 놓고, 아침에 수를 적은 종이를 들고 회의실을 떠난다.</li>
	<li><strong>저녁</strong>에 마법사들은 원탁에 둘러앉는다. 각 자리에는 빈 종이 한 장과, 점심에 자신이 수를 적은 종이 한 장이 놓여 있다. 마법사들은, 원탁에서 자신과 자신의 <strong>왼쪽과 오른쪽</strong>에 앉은 사람의 종이에 적혀 있는 정수를 볼 수 있다. 이를 토대로, 마법사들은 빈 종이에 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>0</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$0$</span></mjx-container> 이상 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c34"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>40</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$40$</span></mjx-container> 미만의 정수를 쓴다. 이 정수는 자신만이 볼 수 있게 조심스럽게 적는다. 이후 방금 정수를 쓴 종이를 접어 자리 위에 놓고, 점심에 수를 적은 종이를 들고 회의실을 떠난다.</li>
</ul>

<p>회의실을 떠나면, 손에 들고 있는 종이가 마법의 힘으로 사라지며, 회의실에서 했던 모든 행동을 잊게 된다. 아침, 점심, 저녁에 각 마법사가 앉는 자리의 위치는 동일하다.</p>

<p>마법사들은 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>을 모르지만, <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>10</mn><mo>≤</mo><mi>N</mi><mo>≤</mo><mn>100</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>000</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$10 ≤ N ≤ 100\,000$</span></mjx-container> 이라는 사실은 알고 있다.</p>

<p>게임이 끝난 후, 야유회 운영진들은 자리 위에 올려둔 종이들을 모두 편다. 마법사들이 게임을 승리하기 위해서는, 원탁 위의 인접한 자리에 있는 종이에 적힌 수들이 서로 달라야 한다. 또한, 게임이 끝났을 때 (즉, 저녁이 끝나고) 가능한 작은 수만이 종이에 적혀 있으면 좋다.</p>

<p>마법사들은 게임이 진행되는 중에는 아무 말도 할 수 없으나, 게임이 진행되기 전에 공통된 전략을 사용할 것을 합의할 수 있다. 당신은 마법사들을 대신하여 최종적으로 가능한 작은 수를 종이에 적는 전략을 고안해야 한다.</p>

### 입력 

 Empty

### 출력 

 Empty

