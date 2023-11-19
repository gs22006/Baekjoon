# [Gold I] Checkpoints - 27478 

[문제 링크](https://www.acmicpc.net/problem/27478) 

### 성능 요약

메모리: 2024 KB, 시간: 8 ms

### 분류

해 구성하기, 그리디 알고리즘, 수학, 확률론

### 제출 일자

2023년 11월 19일 22:56:35

### 문제 설명

<p>Gildong is developing a game consisting of $n$ stages numbered from $1$ to $n$. The player starts the game from the $1$-st stage and should beat the stages in increasing order of the stage number. The player wins the game after beating the $n$-th stage.</p>

<p>There is at most one checkpoint on each stage, and there is always a checkpoint on the $1$-st stage. At the beginning of the game, only the checkpoint on the $1$-st stage is activated, and all other checkpoints are deactivated. When the player gets to the $i$-th stage that has a checkpoint, that checkpoint is activated.</p>

<p>For each try of a stage, the player can either beat the stage or fail the stage. If they beat the $i$-th stage, the player is moved to the $i+1$-st stage. If they fail the $i$-th stage, the player is moved to the most recent checkpoint they activated, and they have to beat the stages after that checkpoint again.</p>

<p>For example, assume that $n=4$ and the checkpoints are on the $1$-st and $3$-rd stages. The player starts at the $1$-st stage. If they fail on the $1$-st stage, they need to retry the $1$-st stage because the checkpoint on the $1$-st stage is the most recent checkpoint they activated. If the player beats the $1$-st stage, they’re moved to the $2$-nd stage. If they fail it, they’re sent back to the $1$-st stage again. If they beat both the $1$-st stage and the $2$-nd stage, they get to the $3$-rd stage and the checkpoint on the $3$-rd stage is activated. Now whenever they fail on the $3$-rd stage, or the $4$-th stage after beating the $3$-rd stage, they’re sent back to the $3$-rd stage. If they beat both the $3$-rd stage and the $4$-th stage, they win the game.</p>

<p>Gildong is going to build the stages to have equal difficulty. He wants you to find any series of stages and checkpoints using at most $2000$ stages, where the <a href="https://en.wikipedia.org/wiki/Expected_value">expected number</a> of tries over all stages is exactly $k$, for a player whose probability of beating each stage is exactly $\cfrac{1}{2}$.</p>

### 입력 

 <p>Each test contains one or more test cases. The first line contains the number of test cases $t$ ($1\le t\le 50$).</p>

<p>Each test case contains exactly one line. The line consists of a single integer $k$ ($1\le k\le 10^{18}$) --- the expected number of tries over all stages Gildong wants to set for a player whose probability of beating each stage is exactly $\cfrac{1}{2}$.</p>

### 출력 

 <p>For each test case, print $-1$ if it’s impossible to construct such a series of stages and checkpoints using at most $2000$ stages.</p>

<p>Otherwise, print two lines. The first line should contain a single integer $n$ ($1\le n\le 2000$) -- the number of stages. The second line should contain $n$ integers, where the $i$-th integer represents whether the $i$-th stage has a checkpoint. The $i$-th integer should be $0$ if the $i$-th stage doesn’t have a checkpoint, and $1$ if it has a checkpoint. Note that the first integer must be $1$ according to the description.</p>

