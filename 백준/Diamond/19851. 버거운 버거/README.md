# [Diamond V] 버거운 버거 - 19851 

[문제 링크](https://www.acmicpc.net/problem/19851) 

### 성능 요약

메모리: 128000 KB, 시간: 664 ms

### 분류

자료 구조, 느리게 갱신되는 세그먼트 트리, 세그먼트 트리

### 문제 설명

<p>드디어 산업기능요원 복무를 마친 키파는 <span style="font-style: italic;">버거</span>운 직장에서 벗어나 새로운 직업에 도전하고자 햄<span style="font-style: italic;">버거</span>집을 차렸다. 키파는 케이크를 여러 차례 만들면서 빵은 좀 구워 봤지만 햄버거를 만드는 것은 처음이었기 때문에, 위아래의 구분이 있는 빵을 적당히 구워서 햄버거 패티로 햄버거가 들어간 탄수화물 폭탄의 <strong>버거운 버거</strong>를 만들어 팔기로 했다.</p>

<p style="margin-top: 15px;"><img alt="burgerish-burger" src="https://upload.acmicpc.net/de1597d0-0fc2-404e-90cc-ef970d35d1cc/-/preview/" style="display: block; margin-left: auto; margin-right: auto; width: 100%; max-width: 500px;"></p>

<p style="margin-bottom: 15px; text-align: center;">버거운 버거의 예시.</p>

<p>버거운 버거의 엄밀한 정의는 다음과 같다.</p>

<ul>
	<li>속이 위로 온 빵 X 위에 속이 아래로 온 빵 Y를 올린 것은 버거운 버거이다. 이때 X를 Y의 <strong>대응하는 쌍</strong>, Y를 X의 <strong>대응하는 쌍</strong>이라 정의하자.</li>
	<li>속이 위로 온 빵 X 위에 버거운 버거를 올리고, 그 위에 속이 아래로 온 빵 Y를 올린 것은 버거운 버거이다. 마찬가지로 이때 X를 Y의 <strong>대응하는 쌍</strong>, Y를 X의 <strong>대응하는 쌍</strong>이라 정의하자.</li>
	<li>버거운 버거 위에 버거운 버거를 올린 것은 버거운 버거이다.</li>
	<li>위 세 규칙으로 만들 수 없는 것은 버거운 버거가 아니다.</li>
</ul>

<p>키파는 총 <span style="font-style: italic;">N</span>개의 빵 굽는 기계를 일렬로 세워 두고 동시에 다루고 있다. 하나의 기계는 빵을 하나만 구울 수 있다. 가장 왼쪽의 것부터 오른쪽으로 순서대로 1부터 번호를 붙이자. 키파가 가게를 운영하는 도중에 다음 둘 중 하나의 상황이 <span style="font-style: italic;">Q</span>번 발생할 수 있다.</p>

<ul>
	<li><span style="font-style: italic;">a</span>번 기계부터 <span style="font-style: italic;">b</span>번 기계까지의 빵이 곧 타려고 하기 때문에, 각각 뒤집어 줘야 한다.</li>
	<li>손님이 <span style="font-style: italic;">a</span>번 기계부터 <span style="font-style: italic;">b</span>번 기계까지의 빵을 차곡차곡 쌓아 주기를 원한다. 즉, 이 과정 중 <strong>빵을 뒤집어 쌓으면 안 되고</strong>, 가장 아래에 <span style="font-style: italic;">a</span>번 기계에서 나온 빵, 그 위에 (<span style="font-style: italic;">a</span>+1)번 기계에서 나온 빵, 이렇게 하여 가장 위에 <span style="font-style: italic;">b</span>번 기계에서 나온 빵이 <strong>순서대로</strong> 쌓여야 한다. 키파는 기계에 빵이 없으면 재료가 다 떨어진 것처럼 보인다고 생각했기 때문에, 한 주문이 끝난 이후 그 주문을 받기 이전의 상태대로 빵의 위아래를 맞춰서 채워 둔다.</li>
</ul>

<p>그러나 손님들이 햄버거를 만들기를 원하는 빵을 쌓았을 때, 어떤 빵은 대응하는 쌍이 존재하지 않아 버거운 버거로서 실격일 수 있다. 키파는 각 손님의 주문대로 빵을 쌓은 뒤, 이 빵을 버거운 버거로 만들기 위해 쌓아둔 빵의 순서를 유지하면서 미리 구워 둔 빵을 최소한으로 집어넣고자 한다. 키파는 손님들의 건강에 관심이 많기 때문에 각 주문마다 버거운 버거의 높이, 즉 버거운 버거에 들어간 빵의 개수를 알고자 한다. 이를 구하는 프로그램을 작성해서 키파를 도와 주자.</p>

### 입력 

 <p>첫 줄에 양의 정수 <span style="font-style: italic;">N</span>이 주어진다.</p>

<p>둘째 줄에 길이가 <span style="font-style: italic;">N</span>이고 <code>(</code>와 <code>)</code>로만 구성된 문자열이 주어진다. 모든 1 ≤ <span style="font-style: italic;">i</span> ≤ <span style="font-style: italic;">N</span>에 대해 <span style="font-style: italic;">i</span>번째 문자가 <code>(</code>인 경우 속이 위로 온 빵이 <span style="font-style: italic;">i</span>번 기계에, <code>)</code>인 경우 속이 아래로 온 빵이 <span style="font-style: italic;">i</span>번 기계에 들어 있다는 의미이다.</p>

<p>셋째 줄에 양의 정수 <span style="font-style: italic;">Q</span>가 주어진다.</p>

<p>넷째 줄부터 <span style="font-style: italic;">Q</span>개의 줄에 세 개의 양의 정수 <span style="font-style: italic;">t</span>, <span style="font-style: italic;">a</span>, <span style="font-style: italic;">b</span>로 상황이 주어진다. <span style="font-style: italic;">t</span>는 2 이하이며, 1 ≤ <span style="font-style: italic;">a</span> ≤ <span style="font-style: italic;">b</span> ≤ <span style="font-style: italic;">N</span>이다.</p>

<p><span style="font-style: italic;">t</span> = 1인 경우 <span style="font-style: italic;">a</span>번 기계부터 <span style="font-style: italic;">b</span>번 기계까지의 빵을 뒤집어 줘야 함을 의미한다.</p>

<p><span style="font-style: italic;">t</span> = 2인 경우 <span style="font-style: italic;">a</span>번 기계부터 <span style="font-style: italic;">b</span>번 기계까지의 빵을 꺼내 버거운 버거로 만들어 달라는 주문이 들어왔음을 의미한다.</p>

### 출력 

 <p>각 주문(<span style="font-style: italic;">t</span> = 2)마다 버거운 버거의 높이를 한 줄에 하나씩 출력한다.</p>

