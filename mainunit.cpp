//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mainunit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#include "container.h"
TForm9 *Form9;
int N = 6;
Container container(N);
//---------------------------------------------------------------------------
__fastcall TForm9::TForm9(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm9::Button1Click(TObject *Sender)
{
      Memo1->Lines->Clear();
	  if(FileOpenDialog1->Execute())
	  {
	  TFileStream *tfile = new TFileStream(FileOpenDialog1->FileName, fmOpenReadWrite);
	  TStringList *ts = new TStringList;
	  ts->LoadFromStream(tfile);
	  int t = 0;
	  for(int i = 0; i < N; i++)
	  {
		container.SetDate(ts->Strings[t], i);
		t++;
		container.SetNumber(StrToInt(ts->Strings[t]), i);
		t++;
		container.SetDestination(ts->Strings[t], i);
		t++;
		container.SetTime(ts->Strings[t], i);
		t++;
		container.SetNumberOfCompartments(StrToInt(ts->Strings[t]), i);
		t++;
		container.SetNumberOfReservedSeats(StrToInt(ts->Strings[t]), i);
		t++;
		container.SetFreeCompartments(StrToInt(ts->Strings[t]), i);
		t++;
		container.SetFreeReservedSeats(StrToInt(ts->Strings[t]), i);
		t++;
		Memo1->Lines->Add("date: " + container.GetDate(i));
		Memo1->Lines->Add("flight number: " + IntToStr(container.GetNumber(i)));
		Memo1->Lines->Add("destination: " + container.GetDestination(i));
		Memo1->Lines->Add("time: " + container.GetTime(i));
		Memo1->Lines->Add("compartments: " + IntToStr(container.GetNumberOfCompartments(i)));
		Memo1->Lines->Add("reserved seats: " + IntToStr(container.GetNumberOfReservedSeats(i)));
		Memo1->Lines->Add("free compartments: " + IntToStr(container.GetFreeCompartments(i)));
		Memo1->Lines->Add("free reserved seats: " + IntToStr(container.GetFreeReservedSeats(i)));
	  }
	  delete tfile;
	  }
}
//---------------------------------------------------------------------------
void __fastcall TForm9::ComboBox1Change(TObject *Sender)
{
	ComboBox1->Items->Add("flight number");
	ComboBox1->Items->Add("reserved seat");
	ComboBox1->Items->Add("compartment");
}
//---------------------------------------------------------------------------

void __fastcall TForm9::Button2Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	if(ComboBox1->ItemIndex == 0)
	{
		for(int i = 0; i < N; i++)
		{

			Memo1->Lines->Add("flight number: " + IntToStr(container.GetNumber(i)));
			Memo1->Lines->Add("free compartments: " + IntToStr(container.GetFreeCompartments(i)));
			Memo1->Lines->Add("free reserved seats: " + IntToStr(container.GetFreeReservedSeats(i)) + "\n");
		}
	}

	if(ComboBox1->ItemIndex == 1)
	{
		for(int i = 0; i < N; i++)
		{
			Memo1->Lines->Add("flight number: " + IntToStr(container.GetNumber(i)));
			Memo1->Lines->Add("free reserved seats: " + IntToStr(container.GetFreeReservedSeats(i)) + "\n");
		}
	}

	if(ComboBox1->ItemIndex == 2)
	{
		for(int i = 0; i < N; i++)
		{
			Memo1->Lines->Add("flight number: " + IntToStr(container.GetNumber(i)));
			Memo1->Lines->Add("free compartments: " + IntToStr(container.GetFreeCompartments(i)) + "\n");
		}
	}
	ComboBox1->Items->Clear();
}
//---------------------------------------------------------------------------


void __fastcall TForm9::Button3Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	String city = Edit1->Text;
	int seats;
	int tickets;
	int a, b, check = 0;
    for(int i = 0; i < N; i++)
	  {
		seats = 0;
		tickets = 0;
		if(city == container.GetDestination(i))
		{
			Memo1->Lines->Add("date: " + container.GetDate(i));
			Memo1->Lines->Add("flight number: " + IntToStr(container.GetNumber(i)));
			Memo1->Lines->Add("destination: " + container.GetDestination(i));
			Memo1->Lines->Add("time: " + container.GetTime(i));
			seats += container.GetFreeCompartments(i);
			seats += container.GetFreeReservedSeats(i);
			a = container.GetNumberOfCompartments(i);
			b = container.GetFreeCompartments(i);
			tickets += a - b;
			a = container.GetNumberOfReservedSeats(i);
			b = container.GetFreeReservedSeats(i);
			tickets += a - b;
			Memo1->Lines->Add("free seats: " + IntToStr(seats));
			Memo1->Lines->Add("sold tickets: " + IntToStr(tickets));
			check = 1;
		}

	  }
	if (check == 0)
	{
		Memo1->Lines->Add("No flights");
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm9::Button4Click(TObject *Sender)
{
	 String dateMon = container.GetDate(0);
	 String dayBefore = container.GetDate(0);
	 String date;
     Memo1->Lines->Clear();
	 String dayOfWeek = "Monday:";
	 int i = 0;
	 date = container.GetDate(i);
	 while (i != N)
	 {
		 //Memo1->Lines->Add(StrToInt(date[2]) - StrToInt(dateMon[2]));
		 switch(StrToInt(date[2]) - StrToInt(dateMon[2]))
		 {
			 case 0: break;
			 case 1: dayOfWeek = "Tuesday:"; break;
			 case 2: dayOfWeek = "Wednesday:"; break;
			 case 3: dayOfWeek = "Thursday:"; break;
			 case 4: dayOfWeek = "Friday:"; break;
			 case 5: dayOfWeek = "Saturday:"; break;
			 case 6: dayOfWeek = "Sunday:"; break;
			 default: dayOfWeek = "It is another week"; break;
		 }

		 while(dayBefore[2] == date[2])
		 {
			 Memo1->Lines->Add(dayOfWeek);
			 Memo1->Lines->Add("date: " + container.GetDate(i));
			 Memo1->Lines->Add("flight number: " + IntToStr(container.GetNumber(i)));
			 Memo1->Lines->Add("destination: " + container.GetDestination(i));
			 Memo1->Lines->Add("time: " + container.GetTime(i));
			 i++;
             if(i == N)
			 {
				break;
			 }
			 date = container.GetDate(i);
		 }
         dayBefore = date;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TForm9::Button5Click(TObject *Sender)
{
		Memo1->Lines->Clear();
		for(int i = 0; i < N; i++)
		{
			Memo1->Lines->Add(container.GetDate(i));
			Memo1->Lines->Add(container.GetNumber(i));
			Memo1->Lines->Add(container.GetDestination(i));
			Memo1->Lines->Add(container.GetTime(i));
			Memo1->Lines->Add(container.GetNumberOfCompartments(i));
			Memo1->Lines->Add(container.GetNumberOfReservedSeats(i));
			Memo1->Lines->Add(container.GetFreeCompartments(i));
			Memo1->Lines->Add(container.GetFreeReservedSeats(i));
		}
}
//---------------------------------------------------------------------------

void __fastcall TForm9::Button6Click(TObject *Sender)
{
		if(FileSaveDialog1->Execute())
		{
			Memo1->Lines->Add("end");
			Memo1->Lines->SaveToFile(FileSaveDialog1->FileName);
		}

		TFileStream *tfile = new TFileStream("oaip.txt", fmOpenReadWrite);
		TStringList *ts = new TStringList;
		ts->LoadFromStream(tfile);
		int line = 0;

		String temp = ts->Strings[line];
		while(temp != "end")
		{
			line++;
			temp = ts->Strings[line];
		}
		int Temp = N;
		if(line%8 != 0)
		{
		   Memo1->Lines->Clear();
		   Memo1->Lines->Add("insufficient data");
		} else
		{
			N = line / 8;
            Memo1->Lines->Clear();
			Memo1->Lines->Add("Edit complete");
		}

		container.Edit(N);

		Memo1->Lines->Clear();
		delete tfile;
}
//---------------------------------------------------------------------------


void __fastcall TForm9::Button7Click(TObject *Sender)
{
	container.Sort(N);
	Memo1->Lines->Clear();
	for(int i = 0; i < N; i++)
	  {
		Memo1->Lines->Add("date: " + container.GetDate(i));
		Memo1->Lines->Add("flight number: " + IntToStr(container.GetNumber(i)));
		Memo1->Lines->Add("destination: " + container.GetDestination(i));
		Memo1->Lines->Add("time: " + container.GetTime(i));
		Memo1->Lines->Add("compartments: " + IntToStr(container.GetNumberOfCompartments(i)));
		Memo1->Lines->Add("reserved seats: " + IntToStr(container.GetNumberOfReservedSeats(i)));
		Memo1->Lines->Add("free compartments: " + IntToStr(container.GetFreeCompartments(i)));
		Memo1->Lines->Add("free reserved seats: " + IntToStr(container.GetFreeReservedSeats(i)));
	  }
}
//---------------------------------------------------------------------------


