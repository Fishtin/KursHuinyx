#include "Station.hpp"
#include "Program.hpp"

Station::Station()
{
	array[0].setnext(0);
	array[0].setNumR(NULL);
	array[0].setMark("");
	for (int i = 1; i < 10; i++)
		array[i].setnext(-1);
}

Station::Station(int number)
{
	this->number = number;
	this->next = nullptr;
	this->prev = nullptr;
	array[0].setnext(0);
	array[0].setNumR(NULL);
	array[0].setMark("");
	for (int i = 1; i < 10; i++)
		array[i].setnext(-1);
}

Station::~Station()
{
	for (int i = 0; i < 10; i++)
	{
		array[i].setNumR(NULL); 
		array[i].setMark(""); 
		array[i].setnext(NULL);
	}
}

Station* Station::getPrev() 
{
	return prev;
}

Station* Station::getNext()
{
	return next;
}

void Station::setNext(Station* _next)
{
	this->next=_next;
}
void Station::setPrev(Station* _prev)
{
	this->prev = _prev;
}

int Station::getNumber()
{
	return number;
}

bool Station::isEmpty()
{
	if (array[0].getnext() == 0)
	{
		return true;
	}
	return false;
}

bool Station::add(int number, std::string fuel)
{
	if (getFreePos() == -999) 
	{
		std::cout << "Список заполнен на максимум " << std::endl;
		return false;
	}
	int P;
	int tmp = array[0].getnext();
	P = getFreePos();
	if (array[0].getnext() == 0)
	{
		array[0].setnext(P);
	}
	array[P].setNumR(number);
	array[P].setMark(fuel);
	array[P].setnext(0);
	while (tmp != 0) 
	{
		if (array[tmp].getnext() == 0)
		{
			array[tmp].setnext(P);
			break;
		}
		tmp = array[tmp].getnext();
	}
	return true;
}

bool Station::del(int _number)// передача
{
	if (array[0].getnext() == 0)
	{
		return false;
	}
	int tmp = array[0].getnext();
	int tmp_prev=0;
	int i;
	int j;
	while (tmp != 0)
	{
		if (array[tmp].getNumR() == _number)
		{
			i = tmp_prev;
			j = array[i].getnext();
			array[i].setnext(array[j].getnext());
			array[j].setnext(-1);
			array[j].setNumR(0);
			array[j].setMark("");
			break;
		}
		tmp_prev = tmp;
		tmp = array[tmp].getnext();
	}
}

int Station::getFreePos() 
{
	for (int i = 0; i < 10; i++)
		if (array[i].getnext() == -1)
		{
			return i;
		}
	return (-999);
}

bool Station::find(int _number)
{
	int tmp = array[0].getnext();

	while (tmp != 0)
	{
		if (array[tmp].getNumR() == _number)
		{
			return true;
		}
		tmp = array[tmp].getnext();
	}

	return false;
}

void Station::show()
{
	/*for (int i = 0; i < 10; i++) 
	{
		std::cout << array[i].getNumR() << "  " << array[i].getMark() << "  " << array[i].getnext() << std::endl;
	}*/
	int tr = array[0].getnext();
	do
	{
		if (array[tr].getNumR() == 0)
		{
			std::cout << std::setw(19) << " " << "|" << std::setw(16) << "|";
			break;
		}

		std::cout << std::setw(13) << array[tr].getNumR()
			<< std::setw(6) << " " << "|" << std::setw(10) << array[tr].getMark() << std::setw(6) << "|" << std::endl << "|" << std::setw(16) << "|";
		tr = array[tr].getnext();
	} while (tr != 0);
}

void Station::setNumber(int number)
{
	this->number = number;
}

std::string Station::getString()
{
	int temp;
	std::string str = "";
	if (!isEmpty())
	{
		int current =array[0].getnext();
		do
		{
			if (current==0)
			{
				break;
			}
			std::stringstream ss;
			temp = array[current].getNumR();
			str += " ";
			ss << temp;
			str += ss.str();
			str += " ";
			str += array[current].getMark();
			current = array[current].getnext();
		}while (true);
	}
	return str;
}