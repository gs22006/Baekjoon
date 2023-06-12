# [Platinum I] Addition Robot - 19165 

[문제 링크](https://www.acmicpc.net/problem/19165) 

### 성능 요약

메모리: 17752 KB, 시간: 484 ms

### 분류

자료 구조, 느리게 갱신되는 세그먼트 트리, 선형대수학, 수학, 세그먼트 트리

### 문제 설명

<p>Adding two numbers several times is a time-consuming task, so you want to build a robot. The robot should have a string S = S<sub>1</sub>S<sub>2</sub>. . .S<sub>N</sub> of N characters on its memory that represents addition instructions. Each character of the string, S<sub>i</sub>, is either ‘<code>A</code>’ or ‘<code>B</code>’.</p>

<p>You want to be able to give Q commands to the robot, each command is either of the following types:</p>

<ul>
	<li>1 L R. The robot should toggle all the characters of S<sub>i</sub> where L ≤ i ≤ R. Toggling a character means changing it to ‘<code>A</code>’ if it was previously ‘<code>B</code>’, or changing it to ‘<code>B</code>’ if it was previously ‘<code>A</code>’.</li>
	<li>2 L R A B. The robot should call f(L, R, A, B) and return two integers as defined in the following pseudocode:
	<pre>function f(L, R, A, B):
  FOR i from L to R
    if S[i] = 'A'
      A = A + B
    else
      B = A + B
  return (A, B)
</pre>
	</li>
</ul>

<p>You want to implement the robot’s expected behavior.</p>

### 입력 

 <p>Input begins with a line containing two integers: N Q (1 ≤ N, Q ≤ 100 000) representing the number of characters in the robot’s memory and the number of commands, respectively. The next line contains a string S containing N characters (each either ‘<code>A</code>’ or ‘<code>B</code>’) representing the initial string in the robot’s memory. The next Q lines each contains a command of the following types.</p>

<ul>
	<li>1 L R (1 ≤ L ≤ R ≤ N)</li>
	<li>2 L R A B (1 ≤ L ≤ R ≤ N; 0 ≤ A, B ≤ 10<sup>9</sup>)</li>
</ul>

<p>There is at least one command of the second type.</p>

### 출력 

 <p>For each command of the second type in the same order as input, output in a line two integers (separated by a single space), the value of A and B returned by f(L, R, A, B), respectively. As this output can be large, you need to modulo the output by 1 000 000 007.</p>

