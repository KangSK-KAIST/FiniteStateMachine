#ifndef INCLUDE_STATE_H_
#define INCLUDE_STATE_H_

#include <iostream>
#include <string>
#include <vector>

#include "FSM.hpp"

template <typename inT, typename outT> class FSM;

template <typename inT, typename outT>
class State
{
private:
	State *pParent;
	int iKey;
	std::string sName;
	outT (*pFunc)(inT);
	bool isLocked = false;

public:
	State();
	~State();
	State operator()(inT input);

	void setName(std::string name);
	void setFunction(outT (*func)(inT));

	outT giveInput(inT input){ return pFunc(input); };
};


/*
 * Constructor of State class
 * 
 * A templated State class constructor.
 * Template holds the input and output type.
 */
template <typename inT, typename outT>
State<inT, outT>::State()
{
	std::cout << "Constructor" << std::endl;
}

/*
 * Deconstructor of State class
 * 
 * A templated State class deconstructor.
 * Template holds the input and output type.
 */
template <typename inT, typename outT>
State<inT, outT>::~State()
{
	std::cout << "Deconstructor" << std::endl;
}

/*
 * setName of State class
 * 
 * Checks whether the instance is locked and changes the name
 * 
 * @param std::string value of new name
 * @return void / prints out error if locked
 */
template <typename inT, typename outT>
State<inT, outT>::setName(std::string name)
{
	if (!isLocked)
		sName = name;
	else
		std::cerr << "The state is locked. You should not modify the state after FSM running." << std::endl;
}

/*
 * setFunction of State class
 * 
 * Checks whether the instance is locked and changes the function
 * 
 * @param function pointer of new function
 * @return void / prints out error if locked
 */
template <typename inT, typename outT>
State<inT, outT>::setFunction(outT (*func)(inT))
{
	if (!isLocked)
		pFunc = func;
	else
		std::cerr << "The state is locked. You should not modify the state after FSM running." << std::endl;
}

#endif // INCLUDE_STATE_H_