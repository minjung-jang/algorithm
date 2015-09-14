1. 추가하고자 하는 알고리즘의 선언은 header 파일에 작성
- 숫자 관련 알고리즘은 MathAlgorithm.h
- 문자열 관련 알고리즘은 StringAlgorithm.h

2. 선언된 알고리즘의 구현은 소스파일에 작성
- 숫자 관련 알고리즘의 구현부는 MathAlgorithm.cpp
- 문자열 관련 알고리즘은 StringAlgorith.cpp

3.1 Menu.h 파일의 Menu 클래스의 열거체 MENU_CL에 추가한 알고리즘 상수 추가
3.2 Menu.h 파일의 Menu 클래스의 멤버 함수에 execute알고리즘상수(); 이런식으로 추가

4.1 Menu.cpp 파일의 printMenuList() 함수에 출력문을 추가한 알고리즘 상수를 이용하여 추가한다.
4.2 Menu.cpp 파일의 executeAlgorithm() 함수의 case 문에 추가한 알고리즘 상수를 추가한다. 
4.3 Menu.h 파일에 추가한 멤버함수를 완성한다. 

5. 실행해서 결과 확인 (Main.cpp 파일에 main함수있음)

## 이게 버그가 하나있는데
printMenuList() 함수에서 메뉴를 고를 때, 잘못된 값을 입력할 경우 프로그램이 죽거나 무한루프 돔
try 같은 예외처리를 써보았으나 ㅋㅋㅋ 실패욧
