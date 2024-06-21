#include "Table.h"

Table::Table(Cell& cell)
{
	table.back().push_back(cell);
}

Table::Table()
{
	row = 0;
	col = 0;

	for (int i = 0; i < row; ++i)
		table[i].push_back(Cell());
	
	
}
int Table::getRow() const
{
	return row;
}
int Table::getCol() const
{
	return col;
}
int Table::maxCellsPerRow() const
{
	int maxRowLen = 0;
	for (int i = 0; i < row; i++)
	{
		int rowCells = table.at(i).size();
		if (maxRowLen < rowCells)
		{
			maxRowLen = rowCells;
		}
	}
	return maxRowLen;
}
void Table::manageLine(const int curRow, const char* buff)
{
	char* smallBuff = new char[MAX];
	int i = 0;
	int n = 0;
	int column = 0;
	int quotesCounter = 0;
	while (buff[n] != '\0')
	{
		if (buff[n] == '"')
		{
			if (n != 0) 
			{
				if (buff[n - 1] != '\\')
					quotesCounter++;
			}
			else {
				quotesCounter++;
			}
		}

		if (buff[n] == ',')
		{
			if (quotesCounter % 2 == 0) 
			{
				smallBuff[i] = '\0';
				if (i != 0)
					table.at(curRow).at(column).fillCell(smallBuff);

				smallBuff = new char[MAX];
				column++;
				i = 0;
			}
			else {
				smallBuff[i] = buff[n]; 
				i++;
			}
		}
		else {
			if (buff[n] == ' ') 
			{
				if (quotesCounter % 2 == 1)
				{
					smallBuff[i] = buff[n];
					i++;
				}
			}
			else {
				smallBuff[i] = buff[n];
				i++;
			}
		}
		if (buff[n + 1] == '\0')
		{

			smallBuff[i] = '\0';
			if (i != 0)
				table.at(curRow).at(column).fillCell(smallBuff);

		}

		n++;
	}

	delete[] smallBuff;

}
void Table::readFromFile(std::ifstream& file)
{
	int rCounter = 0;
	char* buffer = new char[MAX];
	while (file)
	{
		file.getline(buffer, MAX);
		manageLine(rCounter, buffer);
		buffer = new char[MAX];
		rCounter++;
	}
	delete[] buffer;
}

void Table::writeToFile(std::fstream& file)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; i++)
			table[i][j].writeToFile(file);
		file << "\n";
	}

}

void Table::editTableCell(int row, int col, const char* filling)
{
	table.at(row).at(col).editCell(filling);
}

void Table::printElement(int i, int j)
{
	table.at(i).at(j).print();
}
