# [Gold I] Connect3 - 14952 

[문제 링크](https://www.acmicpc.net/problem/14952) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

구현, 브루트포스 알고리즘, 런타임 전의 전처리

### 문제 설명

<p>Connect3 is a simplified version of a well-known Connect4 game. Connect3 is a game for two players, black and white, who take turns placing their colored stones in a 4 x 4 grid board shown in Fig.B.1. Each square (or box) in the grid is represented by a pair of numbers (<em>a,</em> <em>b</em>) where <em>a</em> is for a row and <em>b</em> is for a column. The lower left corner of the board is (1, 1), and the upper right corner is (4, 4). Each player selects a column to place a stone which is then placed on the lowest empty square in the column. For example, square (3, 1) is to be taken only when squares (2, 1) and (1, 1) are occupied beforehand. The game ends if three stones with the same color connect in either horizontally, diagonally, or vertically in a row and the player of the color wins.</p>

<table class="table table-bordered">
	<tbody>
		<tr>
			<td style="height:46px; width:54px">
			<p style="text-align:center">(4, 1)</p>
			</td>
			<td style="height:46px; width:54px">
			<p style="text-align:center">(4, 2)</p>
			</td>
			<td style="height:46px; width:54px">
			<p style="text-align:center">(4, 3)</p>
			</td>
			<td style="height:46px; width:54px">
			<p style="text-align:center">(4, 4)</p>
			</td>
		</tr>
		<tr>
			<td style="height:46px; width:54px">
			<p style="text-align:center">(3, 1)</p>
			</td>
			<td style="height:46px; width:54px">
			<p style="text-align:center">(3, 2)</p>
			</td>
			<td style="height:46px; width:54px">
			<p style="text-align:center">(3, 3)</p>
			</td>
			<td style="height:46px; width:54px">
			<p style="text-align:center">(3, 4)</p>
			</td>
		</tr>
		<tr>
			<td style="height:46px; width:54px">
			<p style="text-align:center">(2, 1)</p>
			</td>
			<td style="height:46px; width:54px">
			<p style="text-align:center">(2, 2)</p>
			</td>
			<td style="height:46px; width:54px">
			<p style="text-align:center">(2, 3)</p>
			</td>
			<td style="height:46px; width:54px">
			<p style="text-align:center">(2, 4)</p>
			</td>
		</tr>
		<tr>
			<td style="height:46px; width:54px">
			<p style="text-align:center">(1, 1)</p>
			</td>
			<td style="height:46px; width:54px">
			<p style="text-align:center">(1, 2)</p>
			</td>
			<td style="height:46px; width:54px">
			<p style="text-align:center">(1, 3)</p>
			</td>
			<td style="height:46px; width:54px">
			<p style="text-align:center">(1, 4)</p>
			</td>
		</tr>
	</tbody>
</table>

<p style="text-align:center">Fig.B.1. Board of Connect3. Each grid square is represented by (<em>a,</em> <em>b</em>) where <em>a</em> is for a row and <em>b</em> is for a column.</p>

<p>The game starts by a player placing a black stone on square (1, <em>x</em>). If the game ends by the white player placing a stone on square (<em>a</em>, <em>b</em>), let the final state of the board be <em>s</em>. You are to write a program to find the number of all possible unique states of <em>s</em>. Note that the order of stones placed is irrelevant.</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with a line containing an integer <em>x</em> (1 ≤ <em>x</em> ≤ 4), representing the column of the first stone placed on the board. The next line of input shows two integers, <em>a</em> and <em>b</em> for square (<em>a,</em> <em>b</em>) which is the position of the last stone placed on the board.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one number that corresponds to the answer.</p>

