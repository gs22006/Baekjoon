# [Platinum II] Gluing Pictures - 18035 

[문제 링크](https://www.acmicpc.net/problem/18035) 

### 성능 요약

메모리: 100712 KB, 시간: 60 ms

### 분류

그리디 알고리즘, 문자열, 접미사 배열과 LCP 배열

### 제출 일자

2025년 10월 2일 13:46:10

### 문제 설명

<p>Enzo recently traveled to the city of Montevideo, where he saw a big sign with the name of the city. He decided to take pictures of the sign to make a collage and send it to his friend Demonio. Enzo wants to form the name of his friend by taking one or several pictures of sections of the sign. For example, with the string “MONTEVIDEO”, he might form the name of his friend by putting together “DE-MON-I-O”, using four pictures to form the entire name. It is easy to show that the result cannot be achieved with fewer pictures.</p>

<p>You will be given the name of a city and a list of friends’ names. Return the minimum number of pictures needed to form the name of each friend. When forming the names, pictures cannot be rotated, reflected or modified in any way.</p>

### 입력 

 <p>The first line contains a string C indicating the name of the city. The second line contains a positive integer N representing the number of friends. Each of the following N lines contains a string indicating the name of a friend. All strings are non-empty and consist only of uppercase letters. The sum of the lengths of all strings is at most 2 × 10<sup>5</sup>.</p>

### 출력 

 <p>Output N lines, each line with an integer indicating the minimum number of needed pictures to form the corresponding name in the input, or the value “-1” if it is not possible to generate the name.</p>

