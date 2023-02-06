# [Platinum II] Destabilized Drone - 20348 

[문제 링크](https://www.acmicpc.net/problem/20348) 

### 성능 요약

메모리: 13808 KB, 시간: 76 ms

### 분류

애드 혹(ad_hoc), 이분 탐색(binary_search), 기하학(geometry), 수학(math)

### 문제 설명

<p>Your brand new drone company is planning to beat the competition with an amazing new piece of software, called the Bank And Pitch Controller. This software will make sure the drone is always horizontal, a must have feature for high end drones. In order to do so, it needs to measure the <em>bank</em> and <em>pitch</em> of the drone. Since the drone already has a front facing camera, this will be used to measure these numbers.</p>

<p>Given a single frame (image) from this camera, the software runs a highly advanced machine learning model to determine whether each pixel in the frame is sky, sea, or exactly on the horizon. The machine learning model is rather slow and can process only <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c39"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>900</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$900$</span></mjx-container> pixels before the next video frame comes in. To stabilize the drone quickly enough, you need to create an efficient algorithm that can find the horizon by querying at most <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c39"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>900</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$900$</span></mjx-container> pixels. Using this information, the rest of the BAPC will be able to compute the bank and pitch.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/9be68fd4-491d-4c0e-9243-680d59bdee5f/-/preview/" style="width: 250px; height: 250px;"></p>

<p style="text-align: center;">Figure D.1: Visualisation of Sample 1 showing the queried pixels, including two pixels on the horizon marked in white.</p>

<p>It is given that the horizon can be modelled by an exact straight line, and that at least two pixels in the image will be classified as horizon. Furthermore, the drone is usually flying roughly horizontal, so you may assume that the top row of the picture is always sky and that the bottom row of the picture only contains sea pixels.</p>

<p>A visualisation of the first sample can be seen in Figure D.1.</p>

### 입력 

 Empty

### 출력 

 Empty

