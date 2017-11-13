/*
   CARRO CONTROLADO POR JOYSTICK
       
   Autores(as): Hemerson Rafael e Maria Luiza  Data: junho de 2017
     
*/
 
//Bibliotecas 
#include <AFMotor.h> 
 

// Seleção dos Motores 
AF_DCMotor motor1(1); //Seleção do Motor 1
AF_DCMotor motor4(4); //Seleção do Motor 4

//Variáveis Globais 
unsigned char velocidade = 0x00; //Armazena a velocidade do motor1 (8 bits)
int vrx = A4, vry = A0, x,y;
//Declarações das Funções
  void drive();
  void parking();
  void left();
  void rigth();
 
//Configurações Iniciais 
void setup(){
  
   //A biblioteca se encarrega de setar entradas e saídas!
  Serial.begin(9600);
} //end setup
 
 
// Loop Infinito 
void loop(){  
  
  // leitura de sinal do joystick
  x = analogRead(vrx);
  y = analogRead(vry);

  // Compara as leituras e de acordo com os valores realizar os movimentos do carro por meio das funções  
  if( x >= 110 && x <= 690 && y >= 110 && y <= 690){
        stopcar();
  }
  
  else if( x > 690 ){
        drive();
  }
  
  else if( x < 110 ){
        parking();
  }

   else if( y > 690 ){
        rigth();
  }
  
  else if( y < 110 ){
        left();
  }
  
   
   
  
} //end loop

//Funnção para mover o carro para frente
void drive(){
  
  unsigned char velocidade = 0x99;      //Velocidade recebe o valor máximo
  motor1.setSpeed(velocidade);          //Seleciona velocidade atual
  motor1.run(FORWARD);                  //Movimenta motor no sentido horário
  motor4.setSpeed(velocidade);          //Seleciona velocidade atual
  motor4.run(FORWARD);                  //Movimenta motor no sentido horário
     
  
  
}

//Funnção para mover o carro para trás
void parking(){
  
  unsigned char velocidade1 = 0x99;     //Velocidade recebe o valor máximo
  motor1.setSpeed(velocidade1);         //Seleciona velocidade atual
  motor1.run(BACKWARD);                 //Movimenta motor no sentido anti-horário
  motor4.setSpeed(velocidade1);         //Seleciona velocidade atual
  motor4.run(BACKWARD);                 //Movimenta motor no sentido anti-horário
     
}

//Funnção para mover o carro para esquerda
void left(){
      
  unsigned char velocidade1 = 0x99;     //Velocidade recebe o valor máximo
  motor1.setSpeed(velocidade1);         //Seleciona velocidade atual
  motor1.run(FORWARD);                  //Movimenta motor no sentido horário
  unsigned char velocidade2 = 0x00;     //Velocidade recebe o valor mínimo
  motor4.setSpeed(velocidade2);         //Seleciona velocidade atual
  motor4.run(RELEASE);                  //Motor parado
     
}

 //Funnção para mover o carro para direita
void rigth(){
      
  unsigned char velocidade1 = 0x99;     //Velocidade recebe o valor máximo
  motor4.setSpeed(velocidade1);         //Seleciona velocidade atual
  motor4.run(FORWARD);                  //Movimenta motor no sentido horário
  unsigned char  velocidade2 = 0x00;    //Velocidade recebe o valor mínimo
  motor1.setSpeed(velocidade2);         //Seleciona velocidade atual
  motor1.run(RELEASE);                  //Motor parado
     
}

//Funnção para parar 
void stopcar(){
  
  unsigned char  velocidade = 0x00;     //Velocidade recebe o valor mínimo
  motor1.setSpeed(velocidade);          //Seleciona velocidade atual
  motor1.run(RELEASE);                  //Motor parado
  motor4.setSpeed(velocidade);          //Seleciona velocidade atual
  motor4.run(RELEASE);                  //Motor parado
  
}











