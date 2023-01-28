# [Diamond IV] Nawiasowania - 26805 

[문제 링크](https://www.acmicpc.net/problem/26805) 

### 성능 요약

메모리: 31732 KB, 시간: 192 ms

### 분류

애드 혹(ad_hoc), 자료 구조(data_structures), 그리디 알고리즘(greedy), 우선순위 큐(priority_queue)

### 문제 설명

<p>Bajtazar opracowuje nową sztuczkę karcianą. Ma talię n kart ponumerowanych od 1 do n. Na każdej karcie chce narysować nawias otwierający lub zamykający w taki sposób, że gdy ułoży te karty po kolei, to utworzą one poprawne nawiasowanie.</p>

<p>Bajtazar ma dużą wprawę w tasowaniu kart i za każdym razem wychodzi mu to tak samo: po potasowaniu na i-tym miejscu znajduje się karta o numerze p<sub>i</sub>. Sztuczka ma polegać na tym, żeby po potasowaniu kart nadal tworzyły one poprawne nawiasowanie.</p>

<p>Dla przykładu, dla n = 6 kart i permutacji p = 4, 6, 1, 2, 3, 5 możemy nawiasy narysować tak, żeby przed potasowaniem karty tworzyły nawiasowanie <code>(()())</code>, a po potasowaniu – nawiasowanie <code>()(())</code>:</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/938990b0-345a-4168-aaab-906dc883a4e6/-/preview/" style="width: 797px; height: 61px;"></p>

<p>Pomóż Bajtazarowi i napisz program, który dla danej permutacji p odpowie, czy da się wykonać sztuczkę, i jeśli tak, to znajdzie poprawne narysowanie nawiasów.</p>

### 입력 

 <p>W pierwszym wierszu wejścia znajduje się parzysta liczba całkowita n (2 ≤ n ≤ 1 000 000) oznaczająca liczbę kart. W drugim wierszu znajduje się permutacja p<sub>1</sub>, p<sub>2</sub>, . . . , p<sub>n</sub> liczb od 1 do n.</p>

### 출력 

 <p>Twój program powinien wypisać jedno słowo <code>NIE</code>, jeśli nie da się narysować na kartach nawiasów tak, by spełniały wymagania zadania. W przeciwnym wypadku należy wypisać słowo złożone z n znaków <code>(</code> i <code>)</code>, oznaczających nawiasy, które należy narysować na kolejnych kartach. Jeśli jest więcej niż jedna poprawna odpowiedź, Twój program może wypisać dowolną z nich.</p>

