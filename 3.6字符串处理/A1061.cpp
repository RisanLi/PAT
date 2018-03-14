 #include <iostream>
 #include <cstdio>
  using namespace std;
  
  int main(){
      char str[4][80];    //每个字符串不超过60个字符
      for (int i = 0; i < 4 ;i++){
          cin >> str[i];
      }  
      int position = 0;
      char DAY;
      char HH;
      int p = 0;
      while(true){ 		//查找A～G的相同字母
          if (str[0][position] == str[1][position] && str[0][position]<='G' && str[0][position]>='A'){
              DAY = str[0][position];
              break;
          }
          position++;
      }   
      position++;
      while(true){		//查找0~9 或者 A～N的字符
          if(str[0][position] == str[1][position]&&((str[0][position]>='A'&&str[0][position]<='N')||(str[0][position]>='0'&&str[0][position]<='9'))){
              HH = str[0][position];
              break;
          }
          position++;
      }
      while(true){
          if(str[2][p] == str[3][p]&& ((str[2][p]>='a'&&str[2][p]<='z') ||(str[2][p]>='A' && str[2][p]<='Z'))){
              break;
          }
          p++;
      }
     
      char Day[7][4] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
      int hour = (HH>='0'&&HH<='9')?(HH-'0'):(HH-'A'+10);
      printf("%s %02d:%02d",Day[DAY-'A'],hour,p);
     
      return 0;
  }  


