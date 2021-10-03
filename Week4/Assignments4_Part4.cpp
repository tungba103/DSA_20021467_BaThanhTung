#include <iostream>
using namespace std;

class student{
	private:
		string ID,Name,Class;
	public:
		student( string _ID, string _Name, string _Class)
		{
			ID = _ID;
			Name = _Name;
			Class = _Class;
		}
		string getID()
		{
			return ID;
		}
		string getName()
		
		{
			return Name;
		}
		string getClass()
		{
			return Class;
		}
		void setStudent( student St )
		{
			ID = St.getID();
			Name = St.getName();
			Class = St.getClass();
			return;
		}
};

class StudentMng{
	private:
		student s[1000];
		int number =0;
	public:
		void Insert( string ID, string Name, string Class)
		{
			for(int i=0 ; i < number ; i++)
			{
				if( s[i].getID() == ID) return;
			}
			student temp(ID,Name,Class);
			s[number++] = temp;
			return;
		}
		
		void Delete( string ID)
		{
			int index=0;
			for(int i=0 ; i < number ; i++)
			{
				if( s[i].getID() == ID) index = i;
			}
			if( 0 == index) return;
			else
			{
				for(int j= index ; j < number-1; j++)
				{
					s[j].setStudent(s[j+1]);
				}
			}
			return;
		}
		void Infor( string ID)
		{
			for(int i=0 ; i < number ; i++)
			{
				if( s[i].getID() == ID) {
					cout << s[i].getID() << endl;
					cout << s[i].getName() << endl;
					cout << s[i].getClass() << endl;
				}
			}

		}
};



int main()
{
	StudentMng StuMng;
	StuMng.Insert("001","Ba Tung","N-CLC");
	StuMng.Insert("002","Kien Vu","FPT");
	StuMng.Infor("001");
	return 0;
}
