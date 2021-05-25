//---------------------------------------------------------------------------

#ifndef containerH
#define containerH
//---------------------------------------------------------------------------
#endif

#include "trains.h"

class Container
{
	private:
		Flight* cashbox;
	public:
		Container(int count)
		{
			cashbox = new Flight[count];
		}

	   void SetDate(String date, int i);

	   void SetNumber(int number, int i);

	   void SetDestination(String destination, int i);

	   void SetTime(String time, int i);

	   void SetNumberOfCompartments(int numberOfCompartments, int i);

	   void SetNumberOfReservedSeats(int numberOfReservedSeats, int i);

	   void SetFreeCompartments(int freeCompartments, int i);

	   void SetFreeReservedSeats(int freeReservedSeats, int i);

	   String GetDate(int i);

	   int GetNumber(int i);

	   String GetDestination(int i);

	   String GetTime(int i);

	   int GetNumberOfCompartments(int i);

	   int GetNumberOfReservedSeats(int i);

	   int GetFreeCompartments(int i);

	   int GetFreeReservedSeats(int i);

	   void Edit(int N);

       void Sort(int N);

		~Container()
		{
			delete[] cashbox;
		}

};
