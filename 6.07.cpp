#include <iostream>
#include <string>
#include <unistd.h>
#include <random>
#include <cmath>
#define len_field 30
#define max_step 1000
#define position_x 0
#define map_comp 7

using namespace std;

int main(){
  string field_map[len_field][len_field];
  string mixed_map[len_field][len_field];

string esa_map[len_field][len_field];


  int i;
  int j;
  int sign = 1;

  random_device seed;
  mt19937 srand( seed() );
  uniform_int_distribution<int> rand(-1,2);
  int right_left;

  uniform_int_distribution<int> sign_rand(0,1);

  switch(sign_rand(srand)){
  case 0: sign = -1; break;
  case 1: sign =  1; break;
  }
  int sign_tate = sign;
  switch  (sign_rand(srand)){ 
  case 0: sign = -1; break;
  case 1: sign = 1; break;
  }
  int sign_yoko = sign;

  for(i=0;i<len_field; i++){
    for (j=0; j < len_field; j++){
    field_map[i][j] = "O";
  }
  }

  for(i=0; i<len_field; i++){
    for (j=0; j< len_field; j++){
    cout << field_map[i][j];
  }
  cout << endl;
  }


  string field_list[map_comp]={" "," "," "," "," ","O","#"};
  uniform_int_distribution<int> map_rand(0,map_comp-1);


  for(i=0; i<len_field; i++){
    for(j=0; j<len_field; j++)  {
	field_map[i][j] = field_list[ map_rand(srand) ];
      }
	  }

    field_map[0][0] = "S"; field_map[len_field -1][len_field -1] = "G";
    
    for(i=0; i<len_field; i++){
      for(j=0; j<len_field; j++){
	cout << field_map[i][j];
      }
      cout << endl;
    }
  

  string characterA = "A";
  char key;
  bool run = true;
  
  string characterB1 = "B";
  int imove_B1=10; int jmove_B1=10;
  int ku_map[len_field][len_field];
  for (i=0; i<len_field; i++){
    for (j=0; j<len_field; j++){
      ku_map[i][j]=0;
    }
  }
  ku_map[imove_B1][jmove_B1] = 1;

  string characterB2 = "R";
  int imove_B2=9; int jmove_B2=9;
  int Ku_map[len_field][len_field];
  for (i=0; i<len_field; i++){
    for (j=0; j<len_field; j++){
      Ku_map[i][j]=0;
    }
  }
  Ku_map[imove_B2][jmove_B2] = 5;

  int steps = max_step;
  int istep = 0;
  int imove = position_x;
  int jmove = position_x;
  int move;
  int tate_yoko;


  do{
     if(field_map[imove][jmove]=="O"){
      field_map[imove][jmove] = " ";}
    cout << "\033[2J";
    for(i=0;i<len_field;i++){
      for (j=0; j< len_field; j++){
      mixed_map[i][j] = field_map[i][j];
     }
    }

    mixed_map[imove][jmove] = characterA;
    esa_map[imove][jmove]  =" "; // 空白
    mixed_map[imove_B1][imove_B1] = characterB1;
    mixed_map[imove_B2][imove_B2] = characterB2;
    for(i=0; i<len_field; i++){
      for(j=0; j<len_field; j++){
      cout << mixed_map[i][j];
     }
    
    cout << endl;
    }
    if(field_map[imove][jmove] == "G"){cout << "無事到着" << endl; break;}
    if(field_map[imove][jmove] == "#"){cout << "落とし穴に落ちた" << endl; break;}
    if(ku_map[imove][jmove] == 1){cout << "熊に食べられた" << endl; break;}
    ku_map[imove_B1][jmove_B1] = 0;
    if(Ku_map[imove][jmove] == 5){cout << "うさぎをもふもふしていたら日が暮れた" << endl; break;}
    Ku_map[imove_B2][jmove_B2] = 0;
    //istep++;
      
    tate_yoko = sign_rand(srand);
    switch(tate_yoko){
    case 0: move = imove_B1; break;
    case 1: move = jmove_B1; break;
    }

    switch(tate_yoko){
    case 0: move = imove_B2; break;
    case 1: move = jmove_B2; break;
    }

    cout << "Input key and Enter: "; cin >> key;
    switch(key){
    case 'h': jmove = abs(jmove -1); break;
    case 'l': jmove = len_field -1 -abs(jmove +2 -len_field); break;
    case 'k': imove = abs(imove -1); break;  
    case 'j': imove = len_field -1 -abs(imove +2 -len_field); break;
    default : run = false;
    }
       
    right_left = rand(srand);

    // if(right_left > 0){ right_left = 1 ;
    // }else if(right_left < 0){ right_left = -1;
    // }else { right_left = 0;}
    switch(right_left){
      //case  3:
    case  2: 
    case  1: right_left= 1; break;
    case  0: right_left= 0; break;
    case -1: right_left=-1; break;
    }

 
     switch(move){
    case len_field -1: sign = -1; right_left = abs(right_left); break;
    case            0: sign =  1; right_left = abs(right_left); break;
    }

    // if( imove  == len_field -1 ) { right_left = -1* abs(right_left); }
    //switch(imove){
    //case len_field -1: sign = -1;
     //right_left =  abs(right_left);break;
     //case            0: sign =  1;
     //right_left =  abs(right_left);break;
     //}
    
     //imove=imove + sign * right_left;
     switch  (tate_yoko){
     case 0: if(move == len_field -1 || move ==0 ){sign_yoko = sign ; };
       imove_B1 = imove_B1 + sign_yoko * right_left; break;
     case 1: if(move == len_field -1 || move ==0 ){sign_tate = sign ; };
                   jmove_B1 = jmove_B1 + sign_tate * right_left; break;
     }

     switch  (tate_yoko){
     case 0: if(move == len_field -1 || move ==0 ){sign_yoko = sign ; };
       imove_B2 = imove_B2 + sign_yoko * right_left; break;
     case 1: if(move == len_field -1 || move ==0 ){sign_tate = sign ; };
                   jmove_B2 = jmove_B2 + sign_tate * right_left; break;
     }
     ku_map[imove_B1][jmove_B1] = 1;
     Ku_map[imove_B2][jmove_B2] = 5;
     //usleep(100000);
  }while(run);
  
}
  
