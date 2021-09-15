/** @author Matt McAdams
  * @author Connor Allamby
  **/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stack>
#include <locale>
#include <cmath>

//http://www.cplusplus.com/reference/string/to_string

int main(int argc, char *argv[]) {

  std::locale loc;

  std::string eq = argv[1];
  std::istringstream myss(eq);

  std::string op;
  std::stack<std::string> stack;
  float a, b, c;

  char operands[] = {'^', '*', '/', '+', '-'};

  while( myss >> op) {

    if (!stack.empty()){
        std::cout << "top: " << stack.top() << std::endl;
    }
    std::cout << "op: " << op << std::endl;

    //if number
    if (isdigit(op[0], loc) || isdigit(op[1], loc)) {
      //push it onto the stack
      stack.push(op);
    }
    //if operator
    else if (op[0]== operands[0]){    //if ^
      b = std::stoi(stack.top());
      stack.pop();
      a = std::stoi(stack.top());
      stack.pop();
      c = pow(a,b);
      stack.push(std::to_string(c));

    } else if (op[0]== operands[1]){  //if *
      b = std::stoi(stack.top());
      stack.pop();
      a = std::stoi(stack.top());
      stack.pop();
      c = a * b;
      stack.push(std::to_string(c));

    } else if (op[0]== operands[2]){  //if /
      b = std::stoi(stack.top());
      stack.pop();
      a = std::stoi(stack.top());
      stack.pop();
      c = a / b;
      stack.push(std::to_string(c));

    } else if (op[0]== operands[3]){  //if +
      b = std::stoi(stack.top());
      stack.pop();
      a = std::stoi(stack.top());
      stack.pop();
      c = a + b;
      stack.push(std::to_string(c));

    } else if (op[0]== operands[4]){  //if -
      b = std::stoi(stack.top());
      stack.pop();
      a = std::stoi(stack.top());
      stack.pop();
      c = a - b;
      stack.push(std::to_string(c));
    }
    std::cout << "pushed " << c << std::endl;

      //pop two numbers (operands) from the stack, evaluate the operator on those numbers and push the result back to the stack

  }
  //if end of the string
    //pop[0]the number from the stack and return it
  std::cout << ceil(std::stof(stack.top())) << std::endl;
  stack.pop();

}

//in the failed example, -36 doesn't seem to want to divide by 12 (pushes 0)