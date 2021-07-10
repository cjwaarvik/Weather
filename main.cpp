#include <iostream>
using namespace std;



const short months = 12;
char MONTHS[months][10] = { "January", "February", "March", "April", "May",
						  "June", "July", "August", "September", "October",
						  "November", "December" } ;


struct Weather
{
	double rainfall;
	double hightemp;
	double lowtemp;
	double avgtemp;
};

//Function prototypes
void setAverage(Weather [], int);
double arrayAverage(Weather [], char[]);
void max_min_temp(Weather[], short&, short&);
void getData(Weather []);
void lastBits(Weather[]);

int main()
{

	Weather array[months];

	getData(array);


	lastBits(array);

	return 0;
}


void setAverage(Weather array[], int i)
{
	array[i].avgtemp = (array[i].hightemp + array[i].lowtemp) / 2;
}


double arrayAverage(Weather array [], char choice[])
{
	double average = 0;


	if(choice == "temp")
	{

		for(int i = 0; i < months; i++)
			average += array[i].avgtemp;


		return (average / months);
	}


	if(choice == "rain")
	{

		for(int i = 0; i < months; i++)
			average += array[i].rainfall;

		return (average / months);
	}
}


void max_min_temp(Weather array [], short & max_pos, short & min_pos)
{

	double min = array[0].lowtemp, max = array[0].hightemp;
	min_pos = 0;
	max_pos = 0;


	for(int i = 1; i < months; i++)
	{
		if(min > array[i].lowtemp)
		{
			min = array[i].lowtemp;
			min_pos = i;
		}

		if(max < array[i].hightemp)
		{
			max = array[i].hightemp;
			max_pos = i;
		}
	}
}


void getData(Weather array[])
{
	cout << "Let's do some weather statistics. " << endl << endl;

	cout << "We'll do the total rainfall plus "
		 << "highest and lowest temperatures" << endl
		 << "according to months ranging from -100 to 140 degrees "
		 <<	"Fahrenheit." << endl << endl;


	for(int i = 0; i < months; i++)
	{

		cout << "From " << MONTHS[i] << ": " << endl << endl;

		cout << "Total rainfall: \t";

		cin >> array[i].rainfall;


		while(array[i].rainfall < 0)
		{
			cout << endl << "Please enter something that isn't negative. "
				 << endl << endl;

			cout << "Total rainfall: \t";

			cin >> array[i].rainfall;
		}

		cout << "Highest temperature: \t";

		cin >> array[i].hightemp;


		while((array[i].hightemp < -100) or (array[i].hightemp > 140))
		{
			cout << endl << "Input a temperature "
				 << "ranging from -100 to 140 degrees Fahrenheit. "
				 << endl << endl;

			cout << "Highest temperature: \t";

			cin >> array[i].hightemp;
		}

		cout << "Lowest temperature: \t";

		cin >> array[i].lowtemp;


		while((array[i].lowtemp < -100) or (array[i].lowtemp > 140)
			   or (array[i].lowtemp > array[i].hightemp))
		{
			cout << endl << "Either you need to input a temperature "
				 << "ranging from -100 to 140 degrees " << endl
				 << "Fahrenheit or your lowest is bigger than the highest. "
				 << endl << endl;

			cout << "Lowest temperature: \t";

			cin >> array[i].lowtemp;
		}


		setAverage(array, i);

		cout << endl;
	}
}


void lastBits(Weather array[])
{
	short max_pos, min_pos;

	max_min_temp(array, max_pos, min_pos);

	cout << "Now to show the last bits of the year. " << endl << endl;


	cout << "Average rainfall: \t " << arrayAverage(array, "rain") << endl
		 << "Highest temperature: \t " << array[max_pos].hightemp
		 << " (on " << MONTHS[max_pos] << ")" << endl
		 << "Lowest temperature: \t " << array[min_pos].lowtemp
		 << " (on " << MONTHS[min_pos] << ")" << endl
		 << "Average temperature: \t " << arrayAverage(array, "temp") << endl;
}
