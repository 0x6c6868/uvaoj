#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int INF = 0x3f3f3f;
map<char, string> morse;
map<string, string> dic;

int judge(string a, string b) {
  if (a == b)
    return 0; //相等
  if (a.size() > b.size())
    swap(a, b); //如果保证a的长度小于b
  if (a == b.substr(0, a.size()))
    return b.size() -
           a.size(); //如果a和b的前边一样，那么就可以增加或删减字符使它们一样，返回长度差
  return INF; //如果不一样，那就不能通过增加或删除使它们一样，那么就返回最大值
}

string solve(const string &s) {
  string ans = "";
  int mmin = INF; //初始化
  for (map<string, string>::iterator it = dic.begin(); it != dic.end(); ++it) {
    int d = judge(s, it->second);
    if (!d && !mmin && *ans.rbegin() != '!') {
      ans += "!";
      return ans;
    } //说明精确匹配两次了，直接返回就ok了
    else if (d <= mmin)
      ans = it->first; //不精确匹配，
    mmin = min(d, mmin);
  }

  if (mmin)
    ans += "?"; //如果是不精确匹配
  return ans;
}

int main() {
  string s, ch;
  while (cin >> ch && ch != "*") {
    cin >> s;
    morse[ch[0]] = s; //构造字符map
  }

  while (cin >> s && s != "*") {
    for (int i = 0; i < s.size(); ++i)
      dic[s] += morse[s[i]]; //构造字典
  }

  while (cin >> s && s != "*")
    cout << solve(s) << endl;
  return 0;
}