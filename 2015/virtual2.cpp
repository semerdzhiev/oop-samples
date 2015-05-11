// virtual2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

class Line {
	protected:
		float x, y,
			  x1, y1;
	public:
		Line() {
			cout << "construct Line" << endl;
		};

		Line(float _x, float _y, float _x1, float _y1) :
			x(_x), y(_y), x1(_x1), y1(_y1) {
			cout << "construct Line" << endl;
		};

		virtual const char *whatami() {
			return "Line";
		}

		virtual void read(ifstream &ifs) {
			ifs >> x >> y >> x1 >> y1;
		}

		virtual void write(ofstream &ofs) {
			ofs << x << ' ' << y << ' '
				<< x1 << ' ' << y1 << ' ' << endl;
		}
};

typedef unsigned int uint32;

class ColorLine : public Line {
	protected:
		uint32 color;
		float thck;
	public:
		ColorLine() {
			cout << "construct ColorLine" << endl;
		};

		ColorLine(float _x, float _y, float _x1, float _y1,
				uint32 _color, float _thck) :
				Line(_x, _y, _x1, _y1),
				color(_color), thck(_thck) {
			cout << "construct ColorLine" << endl;
		};

		virtual const char *whatami() {
			return "ColorLine";
		}

		virtual void read(ifstream& ifs) {
			Line::read(ifs);
			ifs >> color >> thck;
		}

		virtual void write(ofstream& ofs) {
			Line::write(ofs);
			ofs << color << ' ' << thck << endl;
		}
};

void writedata() {
	Line** lines = new Line*[5];
	cout << "Writing data... " << endl;

	lines[0] = new Line(0, 0, 10, 10);
	lines[1] = new ColorLine(10, 10, 10, 0, (1<<16) + (100<<8) + 235, 0.235);
	lines[2] = new ColorLine(10, 0, 0, 0, (1<<16) + (100<<8) + 235, 0.135);

#ifdef __GNUC__
	ofstream ofs("/tmp/storage.txt");
#else
	ofstream ofs("c:\\temp\\storage.txt");
#endif

	ofs << 3 << endl;

	for (int i = 0; i < 3; i++) {
		ofs << lines[i]->whatami() << endl;
		lines[i]->write(ofs);
	}
}

void readdata() {
	Line** lines;
	cout << "Reading data... " << endl;
#ifdef __GNUC__
	ifstream ifs("/tmp/storage.txt");
#else
	ifstream ifs("c:\\temp\\storage.txt");
#endif
	int lcount;

	ifs >> lcount;

	lines = new Line*[lcount];

	char buf[32];

	for (int i = 0; i < lcount; i++)
	{
		//		ifs.getline(buf, 32);
		ifs >> buf;
		if (! strcmp(buf, "Line")	) {
			lines[i] = new Line();
		}

		if (! strcmp(buf, "ColorLine")) {
			lines[i] = new ColorLine();
		}

		lines[i]->read(ifs);
	}

}

// for the sake of demostration below

class Wine {
	public:
		virtual const char *whatami() {
			return "Wine";
		}
};

//

int main()
{
	writedata();
	readdata();
	return 0;

	// paradox !
	// object knows its class even though
	// we cast it to completely different
	// inheritance tree

	Line* a = new Line(1,2,4,6);
	Wine* b = (Wine*)a;
	cout << b->whatami();

}


