#include <cmath>
#include <iostream>

using namespace std;
#define DBL_EPSILON 1e-12
//#define M_PI 3.14

class triangle
{
	float a, b;
	int angC;
public:
	triangle();											 
	triangle(float first, float second, int ang);						 
	triangle(const triangle &src);										 
	~triangle();														
	void type();														
	float third_side();													 
	void perimeter();													 
	void opis_radius();													
	void corner();														 
	triangle &operator==(double x);										 
	friend std::istream &operator>>(std::istream &in, triangle &tr);	 
	friend std::ostream &operator<<(std::ostream &stream, triangle &tr); 
};

triangle::triangle()
{
	this->a = 0;
	this->b = 0;
	this->angC = 0;
}

triangle::triangle(float first, float second, int ang)
{ 
	if (first <= DBL_EPSILON || second <= DBL_EPSILON || ang <= 1 || ang >= 178)
	{
		cout << ":)>Wrong initialization" << endl;
	}
	else
	{
		this->a = first;
		this->b = second;
		this->angC = ang;
	}
}
triangle::triangle(const triangle &src)
{
	this->a = src.a;
	this->b = src.b;
	this->angC = src.angC;
}
triangle &triangle::operator==(double x)
{
	this->a == x;
	this->b == x;
	return *this;
}
triangle::~triangle()
{
	this->a = 0;
	this->b = 0;
	this->angC = 0;
	delete this;
}

float triangle::third_side()
{
	float c, a;
	a = sqrt(this->a * this->a + this->b * this->b - 2 * this->a * this->b * cos(this->angC * M_PI / 180));
	c = round(a * 10) / 10;
	return c;
}
void triangle::type()
{
	float a, b, c;
	double angle0, angle1, angle2, maxAngle;
	a = this->a;
	b = this->b;
	c = this->third_side();
	angle0 = acos((b * b + c * c - a * a) / (2 * b * c));
	angle1 = acos((c * c + a * a - b * b) / (2 * a * c));
	angle2 = acos((a * a + b * b - c * c) / (2 * a * b));
	maxAngle = angle0 > angle1 ? (angle0 > angle2 ? angle0 : angle2) : (angle1 > angle2 ? angle1 : angle2);
	if (a + b > c || b + c > a || c + a > b)
	{
		if (maxAngle == M_PI / 2)
		{
			cout << ":)>right\n";
		}
		else if (maxAngle > M_PI / 2)
		{
			cout << ":)>obtuse\n";
		}
		else
		{
			cout << ":)>ocute\n";
		}
	}
	else
		cout << ":)>impossible\n"; 
	getchar();
}
void triangle::perimeter()
{
	float P, c, a;
	c = this->third_side();
	a = (this->a + this->b + c);
	P = round(a * 10) / 10;
	cout << ":)>perimeter : " << P << endl;
	getchar();
}
void triangle::opis_radius()
{
	float r, p, c;
	c = this->third_side();
	p = (this->a + this->b + c) / 2;
	r = this->a * this->b * c / (4 * sqrt(p * (p - this->a) * (p - c) * (p - this->b)));
	cout << ":)>Radius opisannoy okryzhnosti : " << round(r * 10) / 10 << endl;
	getchar();
}
void triangle::corner()
{
	float a, b, c, h;
	double angle0, angle1, angle2, minAngle;
	a = this->a;
	b = this->b;
	c = this->third_side();
	angle0 = acos((b * b + c * c - a * a) / (2 * b * c));
	angle1 = acos((c * c + a * a - b * b) / (2 * a * c));
	angle2 = acos((a * a + b * b - c * c) / (2 * a * b));
	if (angle0 < angle1 || angle0 < angle2)
	{
		h = angle0;
	}
	else if (angle1 < angle2 || angle1 < angle0)
	{
		h = angle1;
	}
	else
	{
		h = angle2;
	}
	cout << ":)>smallest angle : " << h << endl;
	getchar();
}

istream &operator>>(istream &in, triangle &tr)
{ 
	cout << "Enter side A : ";
	in >> tr.a;
	if (tr.a < DBL_EPSILON)
	{
		cout << ":)>Wrong data. Enter again : ";
		in >> tr.a;
	}
	cout << "Enter side B : ";
	in >> tr.b;
	if (tr.b < DBL_EPSILON)
	{
		cout << ":)>Wrong data. Enter again : ";
		in >> tr.b;
	}
	cout << "Enter angle between sides A and B : ";
	in >> tr.angC;
	if (tr.angC <= 0 || tr.angC >= 178)
	{
		cout << ":)>Wrong data. Enter again : ";
		in >> tr.angC;
	}
	return in;
}
ostream &operator<<(ostream &stream, triangle &tr)
{ 
	stream << "A = " << tr.a << ", B = " << tr.b << ", Between angle = " << tr.angC << endl;
	return stream;
}

using namespace std;

int main(int argc, const char * argv[]) {
    triangle pipka(3,4,90), B;
    float third=pipka.third_side();
    int menu;
    do {
        system("CLS");
        cout << "1. triangle first and second side, angC" << endl;
        cout << "2. triangle B " << endl;
        cout << "3. third_side " << endl;
        cout << "4. type triangle " << endl;
        cout << "5. perimeter " << endl;
        cout << "6. opis_radius " << endl;
        cout << "7. small corner " << endl;
        cout << "0. Exit" << endl;
        cin >> menu;
        cin.ignore(32767, '\n');
        system("CLS");
        switch (menu) {
            case 1:
                cin >> B;
                break; 
            case 2:
                cout << B;
                getchar();                
                break;
            case 3:
                cout << ":)>third_side : " << B.third_side();
                getchar();                
                break; 
            case 4:
                B.type();                
                break; 
            case 5:
                B.perimeter();
                break; 
            case 6:
                B.opis_radius();
                break; 
            case 7:
                B.corner();
                break; 
            default:
                break;
            }
    } while (menu != 0);
    return 0;
}