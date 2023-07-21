 #include  <iostream> 

int main() {
   char op;
   double number1;
   double number2;
   bool open = true;

   while(open == true){
      std::cout << "Enter the expression: " << std::endl;
      std::cin >> op;
      if(op != 'q'){
         std::cin >> number1;
         std::cin >> number2;
      }

      switch(op) {
      case '+':
       std::cout << number1 << " + " << number2 << " = " << number1 + number2 << std::endl;
       break;
      case '-':
       std::cout << number1 << " - " << number2 << " = " << number1 - number2 << std::endl;
       break;
      case '*':
       std::cout << number1 << " * " << number2 << " = " << number1 * number2 << std::endl;
       break;
      case '/':
       std::cout << number1 << " / " << number2 << " = " << number1 / number2 << std::endl;
       break;
      case 'q':
       open = false;
       break;
   }
   }

   return 0;
}