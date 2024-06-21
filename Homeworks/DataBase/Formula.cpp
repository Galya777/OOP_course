#include "Formula.h"
#include <iostream>
#include "Table.h"

Formula::Formula(char* formula): Cell(formula)
{
	char* par = content + 1;
	int end = 0;
	for (par; *par == ' '; ++par);
	if (isdigit(*par))
	{
		first = read(par, end);
	}
	else
	{
		std::cout << "Could not read the information!";
		
	}

	par += end;
	for (par; !operation(*par); par++);
	sign = *par;
	for (++par; *par == ' '; ++par);
	if (!isalpha(*par))
	{
		second = read(par, end);
	}
	else
	{
		std::cout << "Could not read the information!";
	}
}

double Formula::calculate() const
{
	switch (sign)
	{
	case '+':
		return first + second;
		break;
	case '-':
		return first - second;
		break;
	case '*':
		return first * second;
		break;
	case '/':
		return first / second;
	case '^':
		return pow(first, second);
		break;
	}
}

double Formula::read(char* reader, int& end) const
{
	Cell red(reader);
	char buffer[MAX];
	size_t index = 0;
		for (index; reader[index] != '\0' && (index == 0 || !red.operation(reader[index])); index++)
	{
		buffer[index] = reader[index];
	}
	buffer[index] = '\0';
	end = index - 1;
	Cell cell(buffer);
	Data dat = cell.findType(buffer);
	switch (dat)
	{
	case Data::INTIGER:
		for (index = 0; buffer[index] != ' ' && buffer[index] != '\0'; ++index);
		buffer[index] = '\0';
		return atof(buffer);
	case Data::DOUBLE:
		for (index = 0; buffer[index] != ' ' && buffer[index] != '\0'; ++index);
		buffer[index] = '\0';
		return atoi(buffer);
	default:
		return 0;
	}
}

void Formula::writeToFile(std::fstream& out) const
{
	if (sign == '/' && second == 0)
	{
		out << "#ERROR";
	}
	else
	{
		out << calculate();
	}
}

 


