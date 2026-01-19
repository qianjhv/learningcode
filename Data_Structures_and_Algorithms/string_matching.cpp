#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;


/** 
 * 字符串模式匹配算法：
 * 主串：T，长度：ｎ
 * 模式串：P，长度：m
 * 目标：返回主串中第一个完全匹配模式串的第一个字符在主串中的下标，否则返回 －１；
 */

// 朴素字符串匹配算法（Naive / Brute Force）
int BFSearch(const string&, const string&);

// KMP 算法 
int KMPSearch(const string&, const string&);

// 前缀函数
void BFPrefixFunciton(const string&, vector<int>&);

// BFPrefixFunciton 优化 1
void BFPrefixFunciton1(const string&, vector<int>&);

// BFPrefixFunciton 优化 2
void BFPrefixFunciton2(const string&, vector<int>&);

//
void BuildNext(const string&, vector<int>&);

// Time Complexity: O((n - m + 1) * m) = O(n * m)
// Space Complexity: O(1)
int BFSearch(const string& T, const string& P) {
  if (T.length() < P.length()) return -1;
  for (int i = 0; i <= T.length() - P.length(); i++) {
    int j = 0;
    while (T[i + j] == P[j] && j < P.length()) {
      j++;
    }
    if (j == P.length()) return i;
  }
  return -1;     
}

// Time Complexity: O()
// Space Complexity: O()
int KMPSearch(const string& T, const string& P) {
  int n = T.size();
  int m = P.size();

  vector<int> next(m);
  BuildNext(P, next);
  
  for (int i = 0, j = 0; i < n; i++) {
    while (j > 0 && T[i] != P[j]) {
      j = next[j - 1];
    }
    if (T[i] == P[j]) j++;
    if (j == m) return i - m + 1;
  }

  return -1;
}

// O(n^3)
void BFPrefixFunciton(const string& P, vector<int>& pi) {
  int n = P.length();
  for (int i = 1; i < n; i++) {
    for (int j = i; j >= 0 ; j--) {
      if (P.substr(0, j) == P.substr(i - j + 1, j)) {
        pi[i] = j;
        break;
      }
    }
  }
}

// 一般时间复杂度为：O(n^2)
// 关键在于理解 j = pi[i - 1] + 1
void BFPrefixFunciton1(const string& P, vector<int>& pi) {
  int n = P.length();
  for (int i = 1; i < n; i++) {
    for (int j = pi[i - 1] + 1; j >= 0; j--) {
      if (P.substr(0, j) == P.substr(i - j + 1, j)) {
        pi[i] = j;
        break;
      }
    }
  }
}

// O(n) 
void BFPrefixFunciton2(const string& P, vector<int>& pi) {
  int n = P.length();
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (P[i] != P[j] && j > 0) j = pi[j - 1];
    if (P[i] == P[j]) j++;
    pi[i] = j;
  }
}

// Error code
void BFPrefixFunciton3(const string& P, vector<int>& pi) {
  int n = P.length();
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (P[i] != P[j] && j > 0) {
      while (j > 0) {
        if (P.substr(0, j) != P.substr(i - j + 1, j)) {
          j--;
        } else {
          j--;
          break;
        }
      }
    }
    if (P[i] == P[j]) j++;
    pi[i] = j;
  }
}

//
void BuildNext(const string& P, vector<int>& next) {
  
}

int main(void) {
  string s = "abacabadabacabab";
  vector<int> n(s.size(), 0);
  vector<int> n1(s.size(), 0);


  BFPrefixFunciton2(s, n);
  BFPrefixFunciton3(s, n1);

  if (n == n1) {
    std::cout << "Yes\n";
  }

  return 0;
}
