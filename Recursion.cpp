#include "Recursion.h"
#include <stack>
#include <stdbool.h>
#include<iostream>
#include<sstream>
#include<string>

using namespace std;

// 3! = 3 * 2 * 1
// 4! = 4 * 3 * 2 * 1

int FactorialByRecursion::CalculateFactorial(int num) 
{

	int answer;

	if (num == 0){
		return 1;
	}

	answer = num * CalculateFactorial(num-1);
	
	return answer;

}


int FactorialByStack::CalculateFactorial(int num) {
	
	for(int i = num; i > 0; --i){
		s.push(i);
	}

	int answer = 1;

	while (!s.empty()){
		answer *= s.top();
		s.pop();
	}

	return answer;
}

bool ChessBoard::Solve(ChessBoard chessBoard, int col) {

	stack<int> rStack;
    stack<int> cStack;

    int fill = 0,row = 0;

    rStack.push(row);
    cStack.push(col);

    m_board[row][col]=1;
    row++;
    
    while (fill < 7)
    {
        if(!CheckSafeQueens(chessBoard, row, col))
        {
            fill++;
            rStack.push(row);
            cStack.push(col);
            m_board[row][col] = 1;
            row++;
            col = 0;
        }
        else
        {
            col++;
            if (col > 7)
            {
                
                row = rStack.top();
                col = cStack.top();
                rStack.pop();
                cStack.pop();
                
                m_board[row][col] = 0;
                col++;
                fill--;
                
            }
        }
        

    }
    return true;
}


bool ChessBoard::CheckSafeQueens(ChessBoard chessBoard, int row, int col) 
{
	
	// Check horizontally aligned queens
	for (int i = 0; i < 8; i++){
		if (m_board[i][col] == 1 || m_board[row][i] == 1) return true; // Queen horizontal! Uh Oh!
	}

	//Check diagonally aligned queens
	for(int currR = 0; currR < 8; currR++){
		for (int currC = 0; currC < 8; currC++){

			int dr = row - currR;
			int dc = col - currC;

			if (dr == dc || dr == -dc){
				if(m_board[currR][currC]) return true; // Queen diagonal! Uh Oh!
			}


		}

	}
	return false;


}


string ChessBoard::ToString() {

	string answer = "";
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			int temp = m_board[i][j];

			stringstream ss;

			if (temp == 0){
				ss << "◻ ";
			} else {
				ss << "◼ ";
			}

			string str = ss.str();
			answer = answer + str;
		}
		answer = answer + "\n";
	}
	return answer;
}

extern std::string CallSimpleExceptionMethod(int i)
{    
    // TODO:
    // Note this is starter code that is not safe.  
    // As Simple exceptin method will throw an exception
    // which will not be handled, and we will also leak resources.
    // Make this method safer and handle all possible exceptions 
    // And also return a string of the exception recieved
    // The tests will tell you what to string to return.


	std::string retVal;
	MyFakeClass* resourceThatNeedsToBeCleanedup = nullptr;

	resourceThatNeedsToBeCleanedup = new MyFakeClass();

	try {
		SimpleExceptionMethod(i);
		retVal = "I did not get an Exception";
		
	} catch (MyException1){
		retVal = "I got Exception 1";

	} catch (MyException2){
		retVal = "I got Exception 2";

	} catch (MyException3){
		retVal = "I got Exception 3";
		
	}

	delete resourceThatNeedsToBeCleanedup;

	return retVal;
}

// NOTE this function should not be editted.
extern void SimpleExceptionMethod(int i)
{
	int retVal = 0;

	if (i == 1)
	{
		throw MyException1();
	}
	else if (i == 2)
	{
		throw MyException2();

	}
	else if (i == 3)
	{
        // TODO uncomment line below, as you need to have all three exceptions working here
		throw MyException3();
	}
	else
	{
		retVal = 20;
	}

	return;

}



char const* MyBaseException::what() const throw() {
	return "MyBaseException";
}
char const* MyException1::what() const throw() {
	return "MyException1";
}
char const* MyException2::what() const throw() {
	return "MyException2";
}
char const* MyException3::what() const throw() {
	return "MyException3";
}
