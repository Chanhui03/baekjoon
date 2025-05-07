#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

//팰린드롬 만들기
int main() {
  string input;
  getline(cin, input);

  map<char, int> m;
  for(char c : input) m[c]++; //문자 갯수 저장

  int odd_count = 0; //홀수 카운트
  char mid_char = 0; //중간에 넣을 문자

  //m에 있는 요소만큼 반복
  for(auto c : m)  {
    //한 문자의 갯수가 홀수일 때
    if(c.second % 2 == 1) {
      //홀수 카운트 ++, 중간에 넣을 문자 저장장
      odd_count++;
      mid_char = c.first;
    }
  }

  //홀수 카운트가 1보다 크면 im sorry 후 메인문 종료
  if(odd_count > 1) {
    cout << "I'm Sorry Hansoo" << '\n';
    return 0;
  }

  //반쪽 출력용 m에 있는거 붙이기
  string half = "";
  for(auto c : m) {
    half += string(c.second / 2, c.first);
  }

  //나머지 반쪽 출력용
  string reversed_half = half;
  reverse(reversed_half.begin(), reversed_half.end());

  //중간에 넣을 문자 있으면 실행 후 종료
  if(mid_char) {
    cout << half + mid_char + reversed_half << '\n';
    return 0;
  }

  //중간에 넣을 문자 없으면 실행 후 종료
  cout << half + reversed_half << '\n';
  return 0;
}
