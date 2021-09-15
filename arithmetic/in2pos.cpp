/** @author Matt McAdams
  * @author Connor Allamby
  **/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stack>




//    $ ./in2pos "-10 + 20 * ( 30 / 2 )"
//        -10 20 30 2 / * +


int main(int argc, char *argv[]) {

  std::string eq = argv[1];
  std::istringstream myss(eq);

  std::string op;
  std::stack<std::string> stack;

  while( myss >> op ) {

  if(!stack.empty()) {
    std::cout << "stack top:" << stack.top() << std::endl;
  }
  
    
//if left parenthesis
    if (op.compare("(") == 0) {
      //push it onto the stack
      stack.push(op);
    }
    
//if operator
    else if (op.compare("^") == 0) {
      while(!stack.empty() && (stack.top().compare("^") == 0)) {
        std::cout << stack.top() << " ";
        stack.pop();
      }
      stack.push(op);
    } else if (op.compare("*") == 0) {
        while(!stack.empty() && (stack.top().compare("*") == 0 || stack.top().compare("^") == 0)) {
        std::cout << stack.top() << " ";
        stack.pop();
      }
      stack.push(op);
    } else if (op.compare("/") == 0) {
        while(!stack.empty() && (stack.top().compare("/") == 0 || stack.top().compare("*") == 0 || stack.top().compare("^") == 0)) {
        std::cout << stack.top() << " ";
        stack.pop();
      }
      stack.push(op);
    } else if (op.compare("+") == 0) {
        while(!stack.empty() && (stack.top().compare("+") == 0 || stack.top().compare("/") == 0 || stack.top().compare("*") == 0 || stack.top().compare("^") == 0)) {
        std::cout << stack.top() << " ";
        stack.pop();
      }
      stack.push(op);
    } else if (op.compare("-") == 0) {
        while(!stack.empty() && (stack.top().compare("-") == 0 || stack.top().compare("+") == 0 || stack.top().compare("/") == 0 || stack.top().compare("*") == 0 || stack.top().compare("^") == 0)) {
        std::cout << stack.top() << " ";
        stack.pop();
      }
      stack.push(op);
    }
    //pop and write to the output string all consecutive operators that are //either operators of higher precedence; or left-associative operators of //equal precedence
    //push the operator onto the stack


//if right parenthesis
    else if (op.compare(")") == 0) {
      //pop and write to the output string all operators until a left parenthesis is popped off the stack
     
      while (stack.top().compare("(") != 0) {
        std::cout << stack.top() << " ";
        stack.pop();
      }
      stack.pop();
      
      
    }
    //pop and write to the output string all operators until a left parenthesis //is popped off the stack
//if number
    else {
    //it may be immediately written to the output string

      std::cout << op << " ";
    }
  }
  //if end of the string
    //pop and write to the output string all operators until the stack is empty
  while (!stack.empty()){
    std::cout << stack.top() << " ";
    stack.pop();
  }

  std::cout << std::endl;
  return 0;
}