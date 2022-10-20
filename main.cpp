#include <iostream>
#include<cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main() {
int count = 0;
  int a;
  string name;
  string me;
  string you;
  int draw = 0;
  int win = 0;
  int lose = 0;

 cout << "じゃんけん5回勝負" << endl;  
 cout << "名前を入力してください" << endl;
  cin >> name;
  
  do{
     cout << "何を出す？(1:グー 2:チョキ 3:パー)" << endl;
     cin >> a;
    
    if(a < 1 || a >= 4){
      cout << "もう一度考えよう" << endl;
      
      }
    
  srand(static_cast<unsigned int>(time(0)));
  int randomNumber = rand();
  int b = (randomNumber % 3) + 1;
  if (b == 1)
    you = "グー";
  else if (b == 2)
    you= "チョキ";
  else if (b == 3)
    you == "パー";
  
   cout << "じゃんけんぽん" << endl;
   if(a == 1)
     me = "グー";
  else if(a == 2)
     me = "チョキ";
   else if(a == 3)
     me = "パー";
    cout << name << "：" << me << endl;
    cout << "相手：" << you << endl;

if(a == b){
  draw++;
}else if(a == 1 && b == 2 || a == 2 && b == 3 ||
  a == 3 && b == 1){
  win++;
}else{
  lose++;
}
    count++;
    }while(count < 5);

    cout << "結果は勝ち:"<<win <<"負け"<<lose<<"引き分け"<<draw<<"です"<< endl;
}
