# [Unrated] Fruitful Compression - 34589 

[문제 링크](https://www.acmicpc.net/problem/34589) 

### 성능 요약

메모리: 33420 KB, 시간: 112 ms

### 분류

분류 없음

### 제출 일자

2025년 10월 8일 03:43:26

### 문제 설명

<p><img alt="" src="https://upload.acmicpc.net/568136ed-fded-4002-9af4-2a92a377287e/-/preview/" style="width: 250px; height: 235px; float: right;">Alice and Bob run a fruit business that delivers delicious fruits to customers around the world. Their brand showcases four iconic fruits from Taiwan: guava, lychee, mango, and sugar apple.</p>

<p>They’ve opened multiple branches, and each branch uses the same layout to display fruits. Each day, the storefront of every shop is arranged as a <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c34"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c34"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>4</mn><mo>×</mo><mn>4</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$4 \times 4$</span></mjx-container> grid. The grid displays fruits such that every row and every column contains exactly one of each of the four different fruits—no duplicates per row or column.</p>

<p>To ensure consistency across branches, every evening, Alice and Bob prepare a <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c34"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c34"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>4</mn><mo>×</mo><mn>4</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$4 \times 4$</span></mjx-container> fruit box with a valid display layout and have their employees deliver the boxes to each branch the next morning.</p>

<p>Alice and Bob have two children, Charlie and Dianne, who love eating fruit. One evening, they sneak into the office and find the prepared fruit boxes sitting on the table.</p>

<p>Charlie can’t resist—he grabs one fruit and eats it. “Mmm... I wish I could eat as many as possible without confusing the staff tomorrow,” he thinks.</p>

<p>Dianne, noticing her brother’s mischief and feeling hungry herself, takes another fruit. Soon, the two begin taking turns, each grabbing one fruit at a time from the box.</p>

<p>Their rule is simple: They can only take a fruit if, after removing it, the remaining fruits in the box still uniquely determine the original <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c34"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c34"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>4</mn><mo>×</mo><mn>4</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$4 \times 4$</span></mjx-container> display (i.e., there’s only one way to complete the display while preserving the distinct-fruit-per-row-and-column rule).</p>

<p>Neither Charlie nor Dianne wants to be the one who can’t grab a fruit anymore. So they both follow the same strategy:</p>

<p>“If there’s a way I can eventually grab the last fruit without violating the rule, I’ll take it, and I’ll try to maximize the total number of fruits I can eat. But if my sibling could outsmart me and grab the last fruit, I’ll instead try to minimize the number of fruits they can take.”</p>

<p>Now, you are given the current status of the fruit box. That is, some fruits are already taken under the rule. Your task is to write a program that predicts the total number of fruits that will remain in the box after both kids have played optimally.</p>

### 입력 

 <p>Each test contains multiple test cases. The first line contains the number of test cases <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D461 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>t</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$t$</span></mjx-container>. The description of the test cases follows.</p>

<p>Each test case contains four lines, the <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>i</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$i$</span></mjx-container>-th of which contains a string of length four, representing the <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>i</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$i$</span></mjx-container>-th row of the layout of the fruit box. Each character will be in the set {<code>G</code>, <code>L</code>, <code>M</code>, <code>S</code>, <code>X</code>}, indicating each of the four fruits, or an empty slot denoted by <code>X</code>.</p>

### 출력 

 <p>For each test case, please output the specified answer in each line.</p>

