//---------------------------------------------------------------------------

#pragma hdrstop

#include "container.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void Container::SetDate(String date, int i)
{
	cashbox[i].date = date;
}

void Container::SetNumber(int number, int i)
{
	cashbox[i].number = number;
}

void Container::SetDestination(String destination, int i)
{
	cashbox[i].destination = destination;
}

void Container::SetTime(String time, int i)
{
	cashbox[i].time = time;
}

void Container::SetNumberOfCompartments(int numberOfCompartments, int i)
{
	cashbox[i].numberOfCompartments = numberOfCompartments;
}

void Container::SetNumberOfReservedSeats(int numberOfReservedSeats, int i)
{
	cashbox[i].numberOfReservedSeats = numberOfReservedSeats;
}

void Container::SetFreeCompartments(int freeCompartments, int i)
{
	cashbox[i].freeCompartments = freeCompartments;
}

void Container::SetFreeReservedSeats(int freeReservedSeats, int i)
{
	cashbox[i].freeReservedSeats = freeReservedSeats;
}

String Container::GetDate(int i)
{
	return cashbox[i].date;
}

int Container::GetNumber(int i)
{
	return cashbox[i].number;
}

String Container::GetDestination(int i)
{
	return cashbox[i].destination;
}

String Container::GetTime(int i)
{
	return cashbox[i].time;
}

int Container::GetNumberOfCompartments(int i)
{
	return cashbox[i].numberOfCompartments;
}

int Container::GetNumberOfReservedSeats(int i)
{
	return cashbox[i].numberOfReservedSeats;
}

int Container::GetFreeCompartments(int i)
{
	return cashbox[i].freeCompartments;
}

int Container::GetFreeReservedSeats(int i)
{
	return cashbox[i].freeReservedSeats;
}

void Container::Edit(int N)
{
	  Flight* newCashbox = new Flight[N];

	  delete[] cashbox;
	  cashbox = newCashbox;
}

void Container::Sort(int N)
{
	Flight temp;
	for(int i = 1; i < N; i++)
	{
		for(int j=i; j>0 && cashbox[j-1].freeCompartments>cashbox[j].freeCompartments; j--)
		{
			temp = cashbox[j-1];
			cashbox[j-1] = cashbox[j];
			cashbox[j] = temp;
		}
	}
}
